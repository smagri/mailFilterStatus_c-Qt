#include "mailfilterstatus.hpp"

#include "ui_mailfilterstatus.h"



MailFilterStatus::MailFilterStatus(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MailFilterStatus)
{
  int i; // generic array index


  ui->setupUi(this);
  
  
  // Setup a slot/callback fn that is executed when the timer expires
  // and emits the timout() signal.
  connect(&timer, SIGNAL(timeout()), this, SLOT(timer_cbk()));
  timer.start(1000); // this is a 1ms timer



  // Initialise status of spool files, wrt colour indicator.
  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "bn.sbd/chat"), &fStats[0]);
  lastDeltaInBGcolourSize[0]= fStats[0].st_size;
  labelPtrs[0] = ui->bnChat;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "infoJunk"), &fStats[1]);
  lastDeltaInBGcolourSize[1]= fStats[1].st_size;
  labelPtrs[1] = ui->infoJunk;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/beagleboard"), &fStats[2]);
  lastDeltaInBGcolourSize[2]= fStats[2].st_size;
  labelPtrs[2] = ui->linuxBeagleBoard;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/slug"), &fStats[3]);
  lastDeltaInBGcolourSize[3]= fStats[3].st_size;
  labelPtrs[3] = ui->linuxSlug;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "strata"), &fStats[4]);
  lastDeltaInBGcolourSize[4]= fStats[4].st_size;
  labelPtrs[4] = ui->strata;

  // maybe just do this for debugging
  strcpy (&plain_stray[0], "/lu1/smagri/.evolution/mail/local/");
  stat(strcat(&plain_stray[0], "Inbox"), &fStats[5]);
  lastDeltaInBGcolourSize[5]= fStats[5].st_size;
  labelPtrs[5] = ui->Inbox;


  for (i=0; i<NUM_SPOOL_FILES; i++){
    if (fStats[i].st_size > 0){
      // Pre-existing mail in spool file, BG colour blue-green.
      labelPtrs[i]->
	setStyleSheet("QLabel {background-color: rgb(0, 150, 130);}");
    }
    else{
      // No pre-existing mail in spool file, BG colour white.
      labelPtrs[i]->setStyleSheet("QLabel { background-color: white}");
    }
  }
   
  // for debugging only
  // labelPtrs[5]->setStyleSheet("QLabel {background-color: salmon}");

  
  setWindowTitle("MS");

}

MailFilterStatus::~MailFilterStatus()
{
  cout<<"dbg: in SJMTimeRS destructor"<<endl;

  // Be nice, or for compleatness.  Instead of just stopping as main
  // exits.
  timer.stop();
  cout<<"dbg: stop timer for timer_cbk()"<<endl;

  delete ui;
}

void MailFilterStatus::changeEvent(QEvent *e)
{
  QWidget::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}


// Callback fn's **************************************************************
//
//
void MailFilterStatus::timer_cbk()
{
  int i; // generic array index


  cout<<"dbg: timer_cbk() fn called, ie slot or callback fn for the timer's";
  cout<<" timout signal"<<endl;
  
  cout<<"dbg: before conversions"<<endl;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "bn.sbd/chat"), &fStats[0]);
  labelPtrs[0] = ui->bnChat;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "infoJunk"), &fStats[1]);
  labelPtrs[1] = ui->infoJunk;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/beagleboard"), &fStats[2]);
  labelPtrs[2] = ui->linuxBeagleBoard;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/slug"), &fStats[3]);
  labelPtrs[3] = ui->linuxSlug;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  stat(strcat(&plain_stray[0], "strata"), &fStats[4]);
  labelPtrs[4] = ui->strata;

  // maybe just for debugging
  strcpy (&plain_stray[0], "/lu1/smagri/.evolution/mail/local/");
  stat(strcat(&plain_stray[0], "Inbox"), &fStats[5]);
  labelPtrs[5] = ui->Inbox;


  cout<<"dbg: before for loop"<<endl;

  for (i=0; i<NUM_SPOOL_FILES; i++){

    if (fStats[i].st_size > 0){
      if (fStats[i].st_size > lastDeltaInBGcolourSize[i]){
  	// New mail in spool file since last check, BG colour to pinkish.
  	cout<<"dbg: new mail colour"<<endl;
        labelPtrs[i]->setStyleSheet("QLabel {background-color: salmon}");
	lastDeltaInBGcolourSize[i] = fStats[i].st_size;
      }
      else if(fStats[i].st_size < lastDeltaInBGcolourSize[i]){
  	// Spool file decreased in size  from last check, BG colour to
  	// blue-green.   So it has  been modified  for sure,  not just
  	// accessed.
  	labelPtrs[i]->
  	  setStyleSheet("QLabel {background-color: rgb(0, 150, 130);}");
  	lastDeltaInBGcolourSize[i] = fStats[i].st_size;
      }
      else{
	// No change in size of spool file, keep BG colour as is, be
	// it pink or blue-green.
	cout<<"dbg: keep BG colour the same"<<endl;
      }
    }
    else{
      // no mail in spool folder
      cout<<"dbg: no mail colour"<<endl;
      labelPtrs[i]->setStyleSheet("QLabel { background-color: white}");
    }

  } // end for loop

  // Colours tried:
  // ui->label->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
  // ui->label->setStyleSheet("QLabel { background-color: turquoise}");
}

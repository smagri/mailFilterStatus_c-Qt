#include <unistd.h>
#include <stdio.h>


#include "mfs.hpp"

#include "ui_mfs.h"



MFS::MFS(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MFS)
{
  // flags  to  customise  the  look  of the  main  window(ie  QWidget
  // instance  that has  no parent)  that is  instantiated(or created)
  // here(this constructor).
  Qt::WindowFlags WinFlags = 0;

  int i; // generic array index
  //int left, top, right, bottom; // size of margins for QLineEdit widgets.

  FILE *fileSPtr;
  int sizeofMailFilter;
  


  ui->setupUi(this);
  
  
  // Setup a slot/callback fn that is executed when the timer expires
  // and emits the timout() signal.
  connect(&timer, SIGNAL(timeout()), this, SLOT(timer_cbk()));
  timer.start(1000); // this is a 1sec timer


  labelMarginSize = 2;

  // Initialise status of spool files, wrt background colour indicator.
  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "bn.sbd/chat"), &fStats[0]);
  lastDeltaInBGcolourSize[0]= fStats[0].st_size;
  labelPtrs[0] = ui->bnChat;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "infoJunk"), &fStats[1]);
  lastDeltaInBGcolourSize[1]= fStats[1].st_size;
  labelPtrs[1] = ui->infoJunk;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/beagleboard"), &fStats[2]);
  lastDeltaInBGcolourSize[2]= fStats[2].st_size;
  labelPtrs[2] = ui->linuxBeagleBoard;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/slug"), &fStats[3]);
  lastDeltaInBGcolourSize[3]= fStats[3].st_size;
  labelPtrs[3] = ui->linuxSlug;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "strata"), &fStats[4]);
  lastDeltaInBGcolourSize[4]= fStats[4].st_size;
  labelPtrs[4] = ui->strata;

  // maybe just do this for debugging
  strcpy (&plain_stray[0], "/lu1/smagri/.evolution/mail/local/");
  stat(strcat(&plain_stray[0], "Inbox"), &fStats[5]);
  lastDeltaInBGcolourSize[5]= fStats[5].st_size;
  labelPtrs[5] = ui->Inbox;


  // labelPtrs[i]->getTextMargins(left, top, right, bottom);
  // cout<<"dbg: ";
  // cout<<"left="<<left<<" top="<<top<<" right="<<right<<" bottom="<<bottom;
  
  for (i=0; i<NUM_SPOOL_FILES; i++){

    labelPtrs[i]->setMargin(labelMarginSize);

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

  
  // Customise main window.
  // WinFlags |= Qt::FramelessWindowHint;
  WinFlags |= Qt::CustomizeWindowHint; // turn off default features
  WinFlags |= Qt::WindowTitleHint; // add a title bar
  WinFlags &= ~Qt::WindowMaximizeButtonHint; // doesn't turn of button!!!
  WinFlags |= Qt::WindowStaysOnTopHint;
  // This should do the same thing too but doesnt
  // WinFlags |= (Qt::WindowMaximizeButtonHint & 0x00000000);
  // WinFlags &= 0xFFFF7FFF;

  // Normally these are the default hints for a window widget but I
  // don't want them in this case.
  //
  // WinFlags |= Qt::WindowCloseButtonHint;
  // WinFlags |= Qt::WindowMinimizeButtonHint;
  // WinFlags |= Qt::WindowMaximizeButtonHint;

  setWindowFlags(WinFlags);

  setWindowTitle("MailFilterStatus");

  // If you  fix the  width and  height here to  current .ui  size the
  // maximise button is finally turned  off.  I guess if size is fixed
  // there is no longer a need for a maximize button.  You can also do
  // this by fixing the size  of the gui from within qtdesigner first,
  // thus no longer requiring setFixedSize() here.
  //
  //  setFixedSize(width(), height());

  
  // getMFSsize is  a script that  determines the number of  emails in
  // each  mail filter  folder and  saves  these values  in a  newline
  // seperated list in MFSsizes.txt.  We execute this script here.
  system("~smagri/proj/mailFilterStatus/c++Qt/MFS/getMFSsizes");
  
  // Note, the file path must be an absolute path, so using ~smagri !wrks.
  if ( (fileSPtr =
     fopen("/lu1/smagri/proj/mailFilterStatus/c++Qt/MFS/MFSsizes.txt",
	   "r")) == NULL ){
    perror("MFS");
    fprintf(stderr, "MFS: Error Opening MFSsizes.txt\n");
    exit(1);
  }
  
  // Setup  pointers, into  an array,  to all  the label  widgets that
  // indicate the number of emails in a particular mail filter folder.
  labelSizePtrs[0] = ui->numEmailsInInbox;
  labelSizePtrs[1] = ui->numEmailsInBnChat;
  labelSizePtrs[2] = ui->numEmailsInInfojunk;
  labelSizePtrs[3] = ui->numEmailsInLinuxBeagleBoard;
  labelSizePtrs[4] = ui->numEmailsInLinuxSlug;
  labelSizePtrs[5] = ui->numEmailsInStrata;


  for (i=0; i<NUM_SPOOL_FILES; i++){
    //  BG colour, a shade of blue, of labels that indicate the number
    //  of emails in a mail filter folder.
    fscanf(fileSPtr, "%d\n", &sizeofMailFilter);
    labelSizePtrs[i]->setAlignment(Qt::AlignRight);
    labelSizePtrs[i]->setMargin(labelMarginSize);
    labelSizePtrs[i]->setText(QString::number(sizeofMailFilter));
    labelSizePtrs[i]->
      setStyleSheet("QLabel {background-color: rgb(100, 172, 216);}");
  }

  if (fclose(fileSPtr) != 0){
    // LATER: workout howto use argv[0] here for the app name.
    perror("MFS");
    fprintf(stderr,"MFS: error in closing MFSsizes.txt file.\n");
  }
  
}

MFS::~MFS()
{
  cout<<"dbg: in SJMTimeRS destructor"<<endl;

  // Be nice, or for compleatness.  Instead of just stopping as main
  // exits.
  timer.stop();
  cout<<"dbg: stop timer for timer_cbk()"<<endl;

  delete ui;
}

void MFS::changeEvent(QEvent *e)
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
void MFS::timer_cbk()
{
  int i; // generic array index
  FILE *fileSPtr;
  int sizeofMailFilter;



  // Check size and update the background(BG) colour of the individual
  // mail  filter spool folder  labels every  time the  timer expires.
 
  // On startup the BG colour of all labels is blue-geen.  The size of
  // the  folder  on  startup  also  sets  the  initial  size  of  the
  // individual spool folders.
 
  // If since the last check and change in BG colour the spool folder has
  // increased in size the BG  colour turns to a salmon colour.

  // If since the last check and  change in BG colour the spool folder
  // has  decreased in  size, the  BG clour  stays goes  back  to it's
  // original blue-green.

  // So  salmon BG  colour indicates  new mail  in spool  folder while
  // blue-green indicates exsisting/old mail in spool folder.  So that
  // when you  delete emails from a  spool folder it  either goes from
  // salmon to  blue-green or stays  blue-green.  Note also  that just
  // accessing the spool folder does not change it's size, hence no BG
  // colour of label changes.


  cout<<"dbg: timer_cbk() fn called, ie slot or callback fn for the timer's";
  cout<<" timout signal"<<endl;
  
  // cout<<"dbg: before conversions"<<endl;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "bn.sbd/chat"), &fStats[0]);
  labelPtrs[0] = ui->bnChat;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "infoJunk"), &fStats[1]);
  labelPtrs[1] = ui->infoJunk;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/beagleboard"), &fStats[2]);
  labelPtrs[2] = ui->linuxBeagleBoard;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "linux.sbd/slug"), &fStats[3]);
  labelPtrs[3] = ui->linuxSlug;

  strcpy (&plain_stray[0], SPOOLS_ROOT_DIR);
  stat(strcat(&plain_stray[0], "strata"), &fStats[4]);
  labelPtrs[4] = ui->strata;

  // maybe just for debugging
  strcpy (&plain_stray[0], "/lu1/smagri/.evolution/mail/local/");
  stat(strcat(&plain_stray[0], "Inbox"), &fStats[5]);
  labelPtrs[5] = ui->Inbox;


  // cout<<"dbg: before for loop"<<endl;

  for (i=0; i<NUM_SPOOL_FILES; i++){

    if (fStats[i].st_size > 0){
      if (fStats[i].st_size > lastDeltaInBGcolourSize[i]){
  	// New mail in spool file since last check, BG colour to pinkish.
  	//cout<<"dbg: new mail colour"<<endl;
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
	//cout<<"dbg: keep BG colour the same"<<endl;
      }
    }
    else{
      // no mail in spool folder
      //cout<<"dbg: no mail colour"<<endl;
      labelPtrs[i]->setStyleSheet("QLabel { background-color: white}");
    }

  } // end for loop

  // Colours tried:
  // ui->label->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
  // ui->label->setStyleSheet("QLabel { background-color: turquoise}");



  // Determine the number  of emails in each mail  filter spool folder
  // and display it in a label adjoining the label displaying the name
  // of the folder.

  // Setup  pointers, into  an array,  to all  the label  widgets that
  // indicate the number of emails in a mail filter folder.
  labelSizePtrs[0] = ui->numEmailsInInbox;
  labelSizePtrs[1] = ui->numEmailsInBnChat;
  labelSizePtrs[2] = ui->numEmailsInInfojunk;
  labelSizePtrs[3] = ui->numEmailsInLinuxBeagleBoard;
  labelSizePtrs[4] = ui->numEmailsInLinuxSlug;
  labelSizePtrs[5] = ui->numEmailsInStrata;

  // getMFSsize is  a script that  determines the number of  emails in
  // each  mail filter  folder and  saves  these values  in a  newline
  // seperated list in MFSsizes.txt.  We execute this script here.
  system("~smagri/proj/mailFilterStatus/c++Qt/MFS/getMFSsizes");

  // We open MFSsizes.txt, ready to read in its values.
  //
  // Note, the file path must be an absolute path, so using ~smagri !wrks.
  if ( (fileSPtr =
     fopen("/lu1/smagri/proj/mailFilterStatus/c++Qt/MFS/MFSsizes.txt",
	   "r")) == NULL ){
    perror("MFS");
    fprintf(stderr, "MFS: Error Opening MFSsizes.txt\n");
    exit(1);
  }
  
  // Read  in  each  mail  filter  spool folder's  current  size  from
  // MFSsizes.txt.
  for (i=0; i<NUM_SPOOL_FILES; i++){
    //  BG colour, a shade of blue, of labels that indicate the number
    //  of emails in a mail filter folder.
    fscanf(fileSPtr, "%d\n", &sizeofMailFilter);
    labelSizePtrs[i]->setAlignment(Qt::AlignRight);
    labelSizePtrs[i]->setMargin(labelMarginSize);
    labelSizePtrs[i]->setText(QString::number(sizeofMailFilter));
  }


  // Each time the  getMFSizes script gets called it  replaces the old
  // MFSsizes.txt file with a new version indicating the current spool
  // filter file sizes.  So here  we close the current file, ready for
  // reopening the next  version of the file when  the timer times out
  // next.
  if (fclose(fileSPtr) != 0){
    // LATER: how do I use argv[0] here, or argv.
    perror("MFS");
    fprintf(stderr,"MFS: error in closing MFSsizes.txt file.\n");
  }

  // LATER:  consider   that  maybe  i  can  get   away  with  opening
  // MFSsizes.txt  in   the  constructor,   and  closing  it   in  the
  // destructor. And just read from start to end each timer loop.  not
  // sure if I have to reopen each time the file is modified???


}

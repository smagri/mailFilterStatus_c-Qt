#include <sys/stat.h>

#include "mailfilterstatus.hpp"

#include "ui_mailfilterstatus.h"

#include <QLabel>

MailFilterStatus::MailFilterStatus(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MailFilterStatus)
{
  ui->setupUi(this);
  
  
  // Setup a slot/callback fn that is executed when the timer expires
  // and emits the timout() signal.
  connect(&timer, SIGNAL(timeout()), this, SLOT(timer_cbk()));
  timer.start(1000); // this is a 1ms timer

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
  cout<<"dbg: timer_cbk() fn called, ie slot or callback fn for the timer's";
  cout<<" timout signal"<<endl;
  
  char plain_stray[80];
  char *filename; /* mail filter file name, wrt MFILTER_ROOT_DIR */
  struct stat filename_stats; /* allocate storage for my local stat structure */
  //struct main_arg_struct main_arg;
  int i=0;
  int retval[5];
  // use new later??? not a class so maybe not.
  QLabel *labelPtrs[5];


  cout<<"dbg: before conversions"<<endl;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "bn.sbd/chat");
  retval[0] = stat(filename, &filename_stats);
  labelPtrs[0] = ui->bnChat;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "infoJunk");
  retval[1] = stat(filename, &filename_stats);
  labelPtrs[1] = ui->infoJunk;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "linux.sbd/beagleboard");
  retval[2] = stat(filename, &filename_stats);
  labelPtrs[2] = ui->linuxBeagleBoard;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "ilinux.sbd/slug");
  retval[3] = stat(filename, &filename_stats);
  labelPtrs[3] = ui->linuxSlug;

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "strata");
  retval[4] = stat(filename, &filename_stats);
  labelPtrs[4] = ui->strata;
 // filename = strcat(&plain_stray[0], main_arg.argv[i]);


  cout<<"dbg: before for loop"<<endl;

  for (i=0; i<5; i++){
    if (retval[i] == -1){
      // bg colour, white
      cout<<"dbg: no mail colour"<<endl;

      labelPtrs[i]->setStyleSheet("QLabel { background-color: white}");

    }
    else{
      cout<<"dbg: new mail colour"<<endl;

      labelPtrs[i]->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
    }
  }
  
  // Colours tried:
  // ui->label->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
  // ui->label->setStyleSheet("QLabel { background-color: turquoise}");
}

#include <sys/stat.h>

#include "mailfilterstatus.hpp"

#include "ui_mailfilterstatus.h"



MailFilterStatus::MailFilterStatus(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MailFilterStatus)
{
  ui->setupUi(this);

  connect(&timer, SIGNAL(timeout()), this, SLOT(timer_cbk()));
  timer.start(1000);

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
  cout<<"dbg: timout signal"<<endl;
  
  char plain_stray[80];
  char *filename; /* mail filter file name, wrt MFILTER_ROOT_DIR */
  struct stat filename_stats; /* allocate storage for my local stat structure */
  //struct main_arg_struct main_arg;
  //int i=1;
  int retval;
  static char flag4testing = 0;

  sleep(5); // for flag4testing, so colour changes are evident

  strcpy (&plain_stray[0], MFILTER_ROOT_DIR);
  filename = strcat(&plain_stray[0], "infoJunk");
 // filename = strcat(&plain_stray[0], main_arg.argv[i]);
  retval = stat(filename, &filename_stats);
    
  if (retval == -1){
    // bg colour, white
    ui->label->setStyleSheet("QLabel { background-color: turquoise}");
    sleep(5);
  }
  else{
    // Just for testing at this stage. This does not work as colour
    // are updated after timer_cbk() returns as that is when the main
    // event loop takes over again.
    if (flag4testing){
      ui->label->setStyleSheet("QLabel { background-color: white}");
      flag4testing = 0;
    }
    else{
      ui->label->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
      flag4testing = 1;
    }
  }
  // ui->label->setStyleSheet("QLabel {background-color: rgb(0,150,130);}");
  // ui->label->setStyleSheet("QLabel { background-color: turquoise}");
}

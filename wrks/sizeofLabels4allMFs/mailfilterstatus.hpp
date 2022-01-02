#ifndef MAILFILTERSTATUS_HPP
#define MAILFILTERSTATUS_HPP

// c++ system headers
#include <sys/stat.h>
#include <iostream>

// Qt system headers
#include <QLabel>
#include <QTimer>
#include <QWidget>

#define MFILTER_ROOT_DIR "/lu1/smagri/.evolution/mail/local/mfilter.sbd/"
#define NUM_SPOOL_FILES 6



// namespaces
using namespace std;

namespace Ui {
  class MailFilterStatus;
}



// Class declaration in this .hpp file.
class MailFilterStatus : public QWidget {
  Q_OBJECT

public:
  MailFilterStatus(QWidget *parent = 0);
  ~MailFilterStatus();

protected:
  void changeEvent(QEvent *e);

private slots:
  void timer_cbk();

private:
  Ui::MailFilterStatus *ui; // pointer to GUI
  QTimer timer; // periodic event timer

  char plain_stray[80]; // general purpose string, or array of characters

  /* allocate storage for my local stat structure */
  struct stat fStats[NUM_SPOOL_FILES];

  // an array of pointers to the label widgets in the GUI, ie like widget it's
  QLabel *labelPtrs[NUM_SPOOL_FILES];
  QLabel *labelSizePtrs[NUM_SPOOL_FILES];

  // The size of the spool file when the BG colour was last changed,
  // indicating a change in the status of the file.
  off_t lastDeltaInBGcolourSize[NUM_SPOOL_FILES];
};

#endif // MAILFILTERSTATUS_HPP

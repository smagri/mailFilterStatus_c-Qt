#ifndef MFS_HPP
#define MFS_HPP

// c++ system headers
#include <sys/stat.h>
#include <iostream>

// Qt system headers
#include <QLabel>
#include <QTimer>
#include <QWidget>


// Mail is filtered via evolution into 'spool' folders.
#define SPOOLS_ROOT_DIR "/lu1/smagri/.evolution/mail/local/mfilter.sbd/"
#define NUM_SPOOL_FILES 6

// Directory in which this program, MFS, is run.
//
// During developing:
// #define RUN_DIR "/lu1/smagri/proj/mailFilterStatus/c++Qt/MFS/"
//
// During production:
#define RUN_DIR "/lu1/smagri/bin/"



// namespaces
using namespace std;

namespace Ui {
  class MFS;
}



// Class declaration in this .hpp file.
class MFS : public QWidget {
  Q_OBJECT

public:
  MFS(QWidget *parent = 0);
  ~MFS();

protected:
  void changeEvent(QEvent *e);

private slots:
  void timer_cbk();

  void on_numEmailsInInbox_linkActivated(const QString &link);

private:
  Ui::MFS *ui; // pointer to GUI
  QTimer timer; // periodic event timer

  char plain_stray[80]; // general purpose string, or array of characters

  /* allocate storage for my local stat structure */
  struct stat fStats[NUM_SPOOL_FILES];

  // an array of pointers to the label widgets in the GUI, ie like widget it's
  QLabel *labelPtrs[NUM_SPOOL_FILES];
  QLabel *labelSizePtrs[NUM_SPOOL_FILES];
  int labelMarginSize;

  // The size of the spool file when the BG colour was last changed,
  // indicating a change in the status of the file.
  off_t lastDeltaInBGcolourSize[NUM_SPOOL_FILES];

  // The last time the access time changed from a previous value.
  time_t lastDeltaAccessTime[NUM_SPOOL_FILES];

  //
  int lastDeltaBGcolour[NUM_SPOOL_FILES];
};

#endif // MFS_HPP

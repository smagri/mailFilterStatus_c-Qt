#ifndef MAILFILTERSTATUS_HPP
#define MAILFILTERSTATUS_HPP

// c++ system headers
#include <iostream>

// Qt system headers
#include <QTimer>
#include <QWidget>

#define MFILTER_ROOT_DIR "/lu1/smagri/.evolution/mail/local/mfilter.sbd/"
#define MAX_SPOOLS_FILTERS 20

// namespaces
using namespace std;

namespace Ui {
  class MailFilterStatus;
}

struct main_arg_struct{
  int argc;
  char *argv[MAX_SPOOLS_FILTERS];
};


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
};

#endif // MAILFILTERSTATUS_HPP

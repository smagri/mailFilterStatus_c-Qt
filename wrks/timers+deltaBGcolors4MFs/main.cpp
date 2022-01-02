#include <QtGui/QApplication>

#include "mailfilterstatus.hpp"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  MailFilterStatus mainMFS;

  mainMFS.show();

  return a.exec();
}

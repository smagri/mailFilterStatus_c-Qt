#include <QtGui/QApplication>

#include "mfs.hpp"


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  MFS mainMFS;

  mainMFS.show();

  return a.exec();
}

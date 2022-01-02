/********************************************************************************
** Form generated from reading UI file 'mfs.ui'
**
** Created: Mon Aug 8 09:20:19 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFS_H
#define UI_MFS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MailFilterStatus
{
public:
    QGridLayout *gridLayout;
    QLabel *Inbox;
    QLabel *numEmailsInInbox;
    QLabel *bnChat;
    QLabel *numEmailsInBnChat;
    QLabel *infoJunk;
    QLabel *numEmailsInInfojunk;
    QLabel *linuxBeagleBoard;
    QLabel *numEmailsInLinuxBeagleBoard;
    QLabel *linuxSlug;
    QLabel *numEmailsInLinuxSlug;
    QLabel *strata;
    QLabel *numEmailsInStrata;

    void setupUi(QWidget *MailFilterStatus)
    {
        if (MailFilterStatus->objectName().isEmpty())
            MailFilterStatus->setObjectName(QString::fromUtf8("MailFilterStatus"));
        MailFilterStatus->resize(196, 174);
        MailFilterStatus->setMinimumSize(QSize(196, 174));
        MailFilterStatus->setMaximumSize(QSize(196, 174));
        gridLayout = new QGridLayout(MailFilterStatus);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Inbox = new QLabel(MailFilterStatus);
        Inbox->setObjectName(QString::fromUtf8("Inbox"));
        Inbox->setMinimumSize(QSize(141, 21));
        Inbox->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(Inbox, 0, 0, 1, 1);

        numEmailsInInbox = new QLabel(MailFilterStatus);
        numEmailsInInbox->setObjectName(QString::fromUtf8("numEmailsInInbox"));
        numEmailsInInbox->setMinimumSize(QSize(31, 21));
        numEmailsInInbox->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInInbox, 0, 1, 1, 1);

        bnChat = new QLabel(MailFilterStatus);
        bnChat->setObjectName(QString::fromUtf8("bnChat"));
        bnChat->setMinimumSize(QSize(141, 21));
        bnChat->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(bnChat, 1, 0, 1, 1);

        numEmailsInBnChat = new QLabel(MailFilterStatus);
        numEmailsInBnChat->setObjectName(QString::fromUtf8("numEmailsInBnChat"));
        numEmailsInBnChat->setMinimumSize(QSize(31, 21));
        numEmailsInBnChat->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInBnChat, 1, 1, 1, 1);

        infoJunk = new QLabel(MailFilterStatus);
        infoJunk->setObjectName(QString::fromUtf8("infoJunk"));
        infoJunk->setMinimumSize(QSize(141, 21));
        infoJunk->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(infoJunk, 2, 0, 1, 1);

        numEmailsInInfojunk = new QLabel(MailFilterStatus);
        numEmailsInInfojunk->setObjectName(QString::fromUtf8("numEmailsInInfojunk"));
        numEmailsInInfojunk->setMinimumSize(QSize(31, 21));
        numEmailsInInfojunk->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInInfojunk, 2, 1, 1, 1);

        linuxBeagleBoard = new QLabel(MailFilterStatus);
        linuxBeagleBoard->setObjectName(QString::fromUtf8("linuxBeagleBoard"));
        linuxBeagleBoard->setMinimumSize(QSize(141, 21));
        linuxBeagleBoard->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(linuxBeagleBoard, 3, 0, 1, 1);

        numEmailsInLinuxBeagleBoard = new QLabel(MailFilterStatus);
        numEmailsInLinuxBeagleBoard->setObjectName(QString::fromUtf8("numEmailsInLinuxBeagleBoard"));
        numEmailsInLinuxBeagleBoard->setMinimumSize(QSize(31, 21));
        numEmailsInLinuxBeagleBoard->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInLinuxBeagleBoard, 3, 1, 1, 1);

        linuxSlug = new QLabel(MailFilterStatus);
        linuxSlug->setObjectName(QString::fromUtf8("linuxSlug"));
        linuxSlug->setMinimumSize(QSize(141, 21));
        linuxSlug->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(linuxSlug, 4, 0, 1, 1);

        numEmailsInLinuxSlug = new QLabel(MailFilterStatus);
        numEmailsInLinuxSlug->setObjectName(QString::fromUtf8("numEmailsInLinuxSlug"));
        numEmailsInLinuxSlug->setMinimumSize(QSize(31, 21));
        numEmailsInLinuxSlug->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInLinuxSlug, 4, 1, 1, 1);

        strata = new QLabel(MailFilterStatus);
        strata->setObjectName(QString::fromUtf8("strata"));
        strata->setMinimumSize(QSize(141, 21));
        strata->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(strata, 5, 0, 1, 1);

        numEmailsInStrata = new QLabel(MailFilterStatus);
        numEmailsInStrata->setObjectName(QString::fromUtf8("numEmailsInStrata"));
        numEmailsInStrata->setMinimumSize(QSize(31, 21));
        numEmailsInStrata->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInStrata, 5, 1, 1, 1);


        retranslateUi(MailFilterStatus);

        QMetaObject::connectSlotsByName(MailFilterStatus);
    } // setupUi

    void retranslateUi(QWidget *MailFilterStatus)
    {
        MailFilterStatus->setWindowTitle(QApplication::translate("MailFilterStatus", "MailFilterStatus", 0, QApplication::UnicodeUTF8));
        Inbox->setText(QApplication::translate("MailFilterStatus", "Inbox", 0, QApplication::UnicodeUTF8));
        numEmailsInInbox->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
        bnChat->setText(QApplication::translate("MailFilterStatus", "bn/chat", 0, QApplication::UnicodeUTF8));
        numEmailsInBnChat->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
        infoJunk->setText(QApplication::translate("MailFilterStatus", "infoJunk", 0, QApplication::UnicodeUTF8));
        numEmailsInInfojunk->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
        linuxBeagleBoard->setText(QApplication::translate("MailFilterStatus", "linux/beagleboard", 0, QApplication::UnicodeUTF8));
        numEmailsInLinuxBeagleBoard->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
        linuxSlug->setText(QApplication::translate("MailFilterStatus", "linux/slug", 0, QApplication::UnicodeUTF8));
        numEmailsInLinuxSlug->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
        strata->setText(QApplication::translate("MailFilterStatus", "strata", 0, QApplication::UnicodeUTF8));
        numEmailsInStrata->setText(QApplication::translate("MailFilterStatus", "999", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MailFilterStatus: public Ui_MailFilterStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFS_H

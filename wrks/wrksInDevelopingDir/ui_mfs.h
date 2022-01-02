/********************************************************************************
** Form generated from reading UI file 'mfs.ui'
**
** Created: Mon Aug 8 22:34:27 2011
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

class Ui_MFS
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
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

    void setupUi(QWidget *MFS)
    {
        if (MFS->objectName().isEmpty())
            MFS->setObjectName(QString::fromUtf8("MFS"));
        MFS->setWindowModality(Qt::NonModal);
        MFS->resize(196, 201);
        MFS->setMinimumSize(QSize(196, 201));
        MFS->setMaximumSize(QSize(196, 201));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/lu1/smagri/proj/mailFilterStatus/c++Qt/MFS/envalope.png"), QSize(), QIcon::Normal, QIcon::Off);
        MFS->setWindowIcon(icon);
        gridLayout = new QGridLayout(MFS);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MFS);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(172, 21));
        label->setMaximumSize(QSize(172, 21));
        label->setPixmap(QPixmap(QString::fromUtf8(":/lu1/smagri/proj/mailFilterStatus/c++Qt/MFS/envalope.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        Inbox = new QLabel(MFS);
        Inbox->setObjectName(QString::fromUtf8("Inbox"));
        Inbox->setMinimumSize(QSize(141, 21));
        Inbox->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(Inbox, 1, 0, 1, 1);

        numEmailsInInbox = new QLabel(MFS);
        numEmailsInInbox->setObjectName(QString::fromUtf8("numEmailsInInbox"));
        numEmailsInInbox->setMinimumSize(QSize(31, 21));
        numEmailsInInbox->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInInbox, 1, 1, 1, 1);

        bnChat = new QLabel(MFS);
        bnChat->setObjectName(QString::fromUtf8("bnChat"));
        bnChat->setMinimumSize(QSize(141, 21));
        bnChat->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(bnChat, 2, 0, 1, 1);

        numEmailsInBnChat = new QLabel(MFS);
        numEmailsInBnChat->setObjectName(QString::fromUtf8("numEmailsInBnChat"));
        numEmailsInBnChat->setMinimumSize(QSize(31, 21));
        numEmailsInBnChat->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInBnChat, 2, 1, 1, 1);

        infoJunk = new QLabel(MFS);
        infoJunk->setObjectName(QString::fromUtf8("infoJunk"));
        infoJunk->setMinimumSize(QSize(141, 21));
        infoJunk->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(infoJunk, 3, 0, 1, 1);

        numEmailsInInfojunk = new QLabel(MFS);
        numEmailsInInfojunk->setObjectName(QString::fromUtf8("numEmailsInInfojunk"));
        numEmailsInInfojunk->setMinimumSize(QSize(31, 21));
        numEmailsInInfojunk->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInInfojunk, 3, 1, 1, 1);

        linuxBeagleBoard = new QLabel(MFS);
        linuxBeagleBoard->setObjectName(QString::fromUtf8("linuxBeagleBoard"));
        linuxBeagleBoard->setMinimumSize(QSize(141, 21));
        linuxBeagleBoard->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(linuxBeagleBoard, 4, 0, 1, 1);

        numEmailsInLinuxBeagleBoard = new QLabel(MFS);
        numEmailsInLinuxBeagleBoard->setObjectName(QString::fromUtf8("numEmailsInLinuxBeagleBoard"));
        numEmailsInLinuxBeagleBoard->setMinimumSize(QSize(31, 21));
        numEmailsInLinuxBeagleBoard->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInLinuxBeagleBoard, 4, 1, 1, 1);

        linuxSlug = new QLabel(MFS);
        linuxSlug->setObjectName(QString::fromUtf8("linuxSlug"));
        linuxSlug->setMinimumSize(QSize(141, 21));
        linuxSlug->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(linuxSlug, 5, 0, 1, 1);

        numEmailsInLinuxSlug = new QLabel(MFS);
        numEmailsInLinuxSlug->setObjectName(QString::fromUtf8("numEmailsInLinuxSlug"));
        numEmailsInLinuxSlug->setMinimumSize(QSize(31, 21));
        numEmailsInLinuxSlug->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInLinuxSlug, 5, 1, 1, 1);

        strata = new QLabel(MFS);
        strata->setObjectName(QString::fromUtf8("strata"));
        strata->setMinimumSize(QSize(141, 21));
        strata->setMaximumSize(QSize(141, 21));

        gridLayout->addWidget(strata, 6, 0, 1, 1);

        numEmailsInStrata = new QLabel(MFS);
        numEmailsInStrata->setObjectName(QString::fromUtf8("numEmailsInStrata"));
        numEmailsInStrata->setMinimumSize(QSize(31, 21));
        numEmailsInStrata->setMaximumSize(QSize(31, 21));

        gridLayout->addWidget(numEmailsInStrata, 6, 1, 1, 1);


        retranslateUi(MFS);

        QMetaObject::connectSlotsByName(MFS);
    } // setupUi

    void retranslateUi(QWidget *MFS)
    {
        MFS->setWindowTitle(QApplication::translate("MFS", "MailFilterStatus", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Inbox->setText(QApplication::translate("MFS", "Inbox", 0, QApplication::UnicodeUTF8));
        numEmailsInInbox->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
        bnChat->setText(QApplication::translate("MFS", "bn/chat", 0, QApplication::UnicodeUTF8));
        numEmailsInBnChat->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
        infoJunk->setText(QApplication::translate("MFS", "infoJunk", 0, QApplication::UnicodeUTF8));
        numEmailsInInfojunk->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
        linuxBeagleBoard->setText(QApplication::translate("MFS", "linux/beagleboard", 0, QApplication::UnicodeUTF8));
        numEmailsInLinuxBeagleBoard->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
        linuxSlug->setText(QApplication::translate("MFS", "linux/slug", 0, QApplication::UnicodeUTF8));
        numEmailsInLinuxSlug->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
        strata->setText(QApplication::translate("MFS", "strata", 0, QApplication::UnicodeUTF8));
        numEmailsInStrata->setText(QApplication::translate("MFS", "999", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MFS: public Ui_MFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFS_H

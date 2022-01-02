/********************************************************************************
** Form generated from reading UI file 'mailfilterstatus.ui'
**
** Created: Sun Jul 24 15:45:14 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILFILTERSTATUS_H
#define UI_MAILFILTERSTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MailFilterStatus
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Inbox;
    QLabel *bnChat;
    QLabel *infoJunk;
    QLabel *linuxBeagleBoard;
    QLabel *linuxSlug;
    QLabel *strata;

    void setupUi(QWidget *MailFilterStatus)
    {
        if (MailFilterStatus->objectName().isEmpty())
            MailFilterStatus->setObjectName(QString::fromUtf8("MailFilterStatus"));
        MailFilterStatus->resize(139, 174);
        verticalLayout = new QVBoxLayout(MailFilterStatus);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Inbox = new QLabel(MailFilterStatus);
        Inbox->setObjectName(QString::fromUtf8("Inbox"));
        Inbox->setMinimumSize(QSize(121, 21));
        Inbox->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(Inbox);

        bnChat = new QLabel(MailFilterStatus);
        bnChat->setObjectName(QString::fromUtf8("bnChat"));
        bnChat->setMinimumSize(QSize(121, 21));
        bnChat->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(bnChat);

        infoJunk = new QLabel(MailFilterStatus);
        infoJunk->setObjectName(QString::fromUtf8("infoJunk"));
        infoJunk->setMinimumSize(QSize(121, 21));
        infoJunk->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(infoJunk);

        linuxBeagleBoard = new QLabel(MailFilterStatus);
        linuxBeagleBoard->setObjectName(QString::fromUtf8("linuxBeagleBoard"));
        linuxBeagleBoard->setMinimumSize(QSize(121, 21));
        linuxBeagleBoard->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(linuxBeagleBoard);

        linuxSlug = new QLabel(MailFilterStatus);
        linuxSlug->setObjectName(QString::fromUtf8("linuxSlug"));
        linuxSlug->setMinimumSize(QSize(121, 21));
        linuxSlug->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(linuxSlug);

        strata = new QLabel(MailFilterStatus);
        strata->setObjectName(QString::fromUtf8("strata"));
        strata->setMinimumSize(QSize(121, 21));
        strata->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(strata);


        retranslateUi(MailFilterStatus);

        QMetaObject::connectSlotsByName(MailFilterStatus);
    } // setupUi

    void retranslateUi(QWidget *MailFilterStatus)
    {
        MailFilterStatus->setWindowTitle(QApplication::translate("MailFilterStatus", "MailFilterStatus", 0, QApplication::UnicodeUTF8));
        Inbox->setText(QApplication::translate("MailFilterStatus", "Inbox", 0, QApplication::UnicodeUTF8));
        bnChat->setText(QApplication::translate("MailFilterStatus", "bn/chat", 0, QApplication::UnicodeUTF8));
        infoJunk->setText(QApplication::translate("MailFilterStatus", "infoJunk", 0, QApplication::UnicodeUTF8));
        linuxBeagleBoard->setText(QApplication::translate("MailFilterStatus", "linux/beagleboard", 0, QApplication::UnicodeUTF8));
        linuxSlug->setText(QApplication::translate("MailFilterStatus", "linux/slug", 0, QApplication::UnicodeUTF8));
        strata->setText(QApplication::translate("MailFilterStatus", "strata", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MailFilterStatus: public Ui_MailFilterStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILFILTERSTATUS_H

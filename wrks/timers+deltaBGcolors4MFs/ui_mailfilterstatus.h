/********************************************************************************
** Form generated from reading UI file 'mailfilterstatus.ui'
**
** Created: Sat Jul 16 22:07:22 2011
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
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *MailFilterStatus)
    {
        if (MailFilterStatus->objectName().isEmpty())
            MailFilterStatus->setObjectName(QString::fromUtf8("MailFilterStatus"));
        MailFilterStatus->resize(139, 147);
        verticalLayout = new QVBoxLayout(MailFilterStatus);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(MailFilterStatus);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(121, 21));
        label_4->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(MailFilterStatus);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(121, 21));
        label_5->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(label_5);

        label = new QLabel(MailFilterStatus);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(121, 21));
        label->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(MailFilterStatus);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(121, 21));
        label_2->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(MailFilterStatus);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(121, 21));
        label_3->setMaximumSize(QSize(121, 21));

        verticalLayout->addWidget(label_3);


        retranslateUi(MailFilterStatus);

        QMetaObject::connectSlotsByName(MailFilterStatus);
    } // setupUi

    void retranslateUi(QWidget *MailFilterStatus)
    {
        MailFilterStatus->setWindowTitle(QApplication::translate("MailFilterStatus", "MailFilterStatus", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MailFilterStatus", "bn/chat", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MailFilterStatus", "infoJunk", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MailFilterStatus", "linux/beagleBoard", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MailFilterStatus", "linux/slug", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MailFilterStatus", "strata", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MailFilterStatus: public Ui_MailFilterStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILFILTERSTATUS_H

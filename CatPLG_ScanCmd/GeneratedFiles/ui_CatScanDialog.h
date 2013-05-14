/********************************************************************************
** Form generated from reading UI file 'CatScanDialog.ui'
**
** Created: Tue May 14 20:20:47 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATSCANDIALOG_H
#define UI_CATSCANDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatScanDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *portBox;
    QToolButton *addBtn;
    QListWidget *portList;
    QToolButton *rmBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *waitBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CatScanDialog)
    {
        if (CatScanDialog->objectName().isEmpty())
            CatScanDialog->setObjectName(QString::fromUtf8("CatScanDialog"));
        CatScanDialog->resize(227, 329);
        verticalLayout = new QVBoxLayout(CatScanDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        portBox = new QSpinBox(CatScanDialog);
        portBox->setObjectName(QString::fromUtf8("portBox"));
        portBox->setMaximum(9999999);

        horizontalLayout->addWidget(portBox);

        addBtn = new QToolButton(CatScanDialog);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout->addWidget(addBtn);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        portList = new QListWidget(CatScanDialog);
        portList->setObjectName(QString::fromUtf8("portList"));

        verticalLayout->addWidget(portList);

        rmBtn = new QToolButton(CatScanDialog);
        rmBtn->setObjectName(QString::fromUtf8("rmBtn"));

        verticalLayout->addWidget(rmBtn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(CatScanDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        waitBox = new QSpinBox(CatScanDialog);
        waitBox->setObjectName(QString::fromUtf8("waitBox"));
        waitBox->setMaximum(100000);
        waitBox->setSingleStep(100);
        waitBox->setValue(3000);

        horizontalLayout_2->addWidget(waitBox);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(CatScanDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CatScanDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatScanDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatScanDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatScanDialog);
    } // setupUi

    void retranslateUi(QDialog *CatScanDialog)
    {
        CatScanDialog->setWindowTitle(QApplication::translate("CatScanDialog", "\351\205\215\347\275\256\346\211\253\346\217\217\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("CatScanDialog", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        rmBtn->setText(QApplication::translate("CatScanDialog", "\347\247\273\351\231\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatScanDialog", "\345\256\214\346\210\220\347\255\211\345\276\205\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatScanDialog: public Ui_CatScanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATSCANDIALOG_H

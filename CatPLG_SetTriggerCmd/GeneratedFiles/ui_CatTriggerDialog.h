/********************************************************************************
** Form generated from reading UI file 'CatTriggerDialog.ui'
**
** Created: Wed Mar 27 21:12:02 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATTRIGGERDIALOG_H
#define UI_CATTRIGGERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatTriggerDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *extMode;
    QRadioButton *instanceMode;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *triggerNum;
    QDialogButtonBox *buttonBox;
    QButtonGroup *modeGroup;

    void setupUi(QDialog *CatTriggerDialog)
    {
        if (CatTriggerDialog->objectName().isEmpty())
            CatTriggerDialog->setObjectName(QString::fromUtf8("CatTriggerDialog"));
        CatTriggerDialog->resize(174, 145);
        verticalLayout_2 = new QVBoxLayout(CatTriggerDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatTriggerDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        extMode = new QRadioButton(groupBox);
        modeGroup = new QButtonGroup(CatTriggerDialog);
        modeGroup->setObjectName(QString::fromUtf8("modeGroup"));
        modeGroup->addButton(extMode);
        extMode->setObjectName(QString::fromUtf8("extMode"));
        extMode->setChecked(true);

        verticalLayout->addWidget(extMode);

        instanceMode = new QRadioButton(groupBox);
        modeGroup->addButton(instanceMode);
        instanceMode->setObjectName(QString::fromUtf8("instanceMode"));

        verticalLayout->addWidget(instanceMode);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CatTriggerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        triggerNum = new QSpinBox(CatTriggerDialog);
        triggerNum->setObjectName(QString::fromUtf8("triggerNum"));
        triggerNum->setMinimum(1);

        horizontalLayout->addWidget(triggerNum);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CatTriggerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatTriggerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatTriggerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatTriggerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatTriggerDialog);
    } // setupUi

    void retranslateUi(QDialog *CatTriggerDialog)
    {
        CatTriggerDialog->setWindowTitle(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        extMode->setText(QApplication::translate("CatTriggerDialog", "\345\244\226\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        instanceMode->setText(QApplication::translate("CatTriggerDialog", "\347\253\213\345\215\263\346\211\253\346\217\217\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatTriggerDialog: public Ui_CatTriggerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATTRIGGERDIALOG_H

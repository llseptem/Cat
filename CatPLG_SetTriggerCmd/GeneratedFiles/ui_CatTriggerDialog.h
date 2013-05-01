/********************************************************************************
** Form generated from reading UI file 'CatTriggerDialog.ui'
**
** Created: Wed May 1 18:19:36 2013
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
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
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *triggerNum;
    QLabel *label_2;
    QSpinBox *sampleNum;
    QLabel *label_3;
    QDoubleSpinBox *sampleInterval;
    QDialogButtonBox *buttonBox;
    QButtonGroup *modeGroup;

    void setupUi(QDialog *CatTriggerDialog)
    {
        if (CatTriggerDialog->objectName().isEmpty())
            CatTriggerDialog->setObjectName(QString::fromUtf8("CatTriggerDialog"));
        CatTriggerDialog->resize(174, 197);
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

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(CatTriggerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        triggerNum = new QSpinBox(CatTriggerDialog);
        triggerNum->setObjectName(QString::fromUtf8("triggerNum"));
        triggerNum->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, triggerNum);

        label_2 = new QLabel(CatTriggerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sampleNum = new QSpinBox(CatTriggerDialog);
        sampleNum->setObjectName(QString::fromUtf8("sampleNum"));
        sampleNum->setMinimum(2);
        sampleNum->setMaximum(10000);
        sampleNum->setSingleStep(10);
        sampleNum->setValue(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, sampleNum);

        label_3 = new QLabel(CatTriggerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        sampleInterval = new QDoubleSpinBox(CatTriggerDialog);
        sampleInterval->setObjectName(QString::fromUtf8("sampleInterval"));
        sampleInterval->setDecimals(4);
        sampleInterval->setMinimum(0.0001);
        sampleInterval->setMaximum(1);
        sampleInterval->setSingleStep(0.001);

        formLayout->setWidget(2, QFormLayout::FieldRole, sampleInterval);


        verticalLayout_2->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(CatTriggerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatTriggerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatTriggerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatTriggerDialog, SLOT(reject()));
        QObject::connect(instanceMode, SIGNAL(toggled(bool)), triggerNum, SLOT(setDisabled(bool)));
        QObject::connect(extMode, SIGNAL(toggled(bool)), sampleInterval, SLOT(setDisabled(bool)));
        QObject::connect(extMode, SIGNAL(toggled(bool)), sampleNum, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(CatTriggerDialog);
    } // setupUi

    void retranslateUi(QDialog *CatTriggerDialog)
    {
        CatTriggerDialog->setWindowTitle(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        extMode->setText(QApplication::translate("CatTriggerDialog", "\345\244\226\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        instanceMode->setText(QApplication::translate("CatTriggerDialog", "\347\253\213\345\215\263\346\211\253\346\217\217\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatTriggerDialog", "\350\247\246\345\217\221\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CatTriggerDialog", "\351\207\207\346\240\267\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CatTriggerDialog", "\351\207\207\346\240\267\351\227\264\351\232\224\357\274\210\347\247\222\357\274\211", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatTriggerDialog: public Ui_CatTriggerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATTRIGGERDIALOG_H

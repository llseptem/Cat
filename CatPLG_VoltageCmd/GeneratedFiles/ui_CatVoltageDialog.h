/********************************************************************************
** Form generated from reading UI file 'CatVoltageDialog.ui'
**
** Created: Wed May 15 20:46:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATVOLTAGEDIALOG_H
#define UI_CATVOLTAGEDIALOG_H

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

class Ui_CatVoltageDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *dc;
    QRadioButton *ac;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *vRange;
    QDialogButtonBox *buttonBox;
    QButtonGroup *vMode;

    void setupUi(QDialog *CatVoltageDialog)
    {
        if (CatVoltageDialog->objectName().isEmpty())
            CatVoltageDialog->setObjectName(QString::fromUtf8("CatVoltageDialog"));
        CatVoltageDialog->resize(174, 145);
        verticalLayout_2 = new QVBoxLayout(CatVoltageDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatVoltageDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dc = new QRadioButton(groupBox);
        vMode = new QButtonGroup(CatVoltageDialog);
        vMode->setObjectName(QString::fromUtf8("vMode"));
        vMode->addButton(dc);
        dc->setObjectName(QString::fromUtf8("dc"));
        dc->setChecked(true);

        verticalLayout->addWidget(dc);

        ac = new QRadioButton(groupBox);
        vMode->addButton(ac);
        ac->setObjectName(QString::fromUtf8("ac"));

        verticalLayout->addWidget(ac);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CatVoltageDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        vRange = new QSpinBox(CatVoltageDialog);
        vRange->setObjectName(QString::fromUtf8("vRange"));
        vRange->setMinimum(1);
        vRange->setMaximum(99999);
        vRange->setSingleStep(10);

        horizontalLayout->addWidget(vRange);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CatVoltageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatVoltageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatVoltageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatVoltageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatVoltageDialog);
    } // setupUi

    void retranslateUi(QDialog *CatVoltageDialog)
    {
        CatVoltageDialog->setWindowTitle(QApplication::translate("CatVoltageDialog", "\347\224\265\345\216\213\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatVoltageDialog", "\347\224\265\345\216\213\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        dc->setText(QApplication::translate("CatVoltageDialog", "DC", 0, QApplication::UnicodeUTF8));
        ac->setText(QApplication::translate("CatVoltageDialog", "AC", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatVoltageDialog", "\347\224\265\345\216\213\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatVoltageDialog: public Ui_CatVoltageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATVOLTAGEDIALOG_H

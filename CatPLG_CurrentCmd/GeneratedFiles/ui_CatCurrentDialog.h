/********************************************************************************
** Form generated from reading UI file 'CatCurrentDialog.ui'
**
** Created: Mon Apr 22 20:02:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATCURRENTDIALOG_H
#define UI_CATCURRENTDIALOG_H

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

class Ui_CatCurrentDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *cDC;
    QRadioButton *cAC;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *cRange;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *CatCurrentDialog)
    {
        if (CatCurrentDialog->objectName().isEmpty())
            CatCurrentDialog->setObjectName(QString::fromUtf8("CatCurrentDialog"));
        CatCurrentDialog->resize(174, 145);
        verticalLayout_2 = new QVBoxLayout(CatCurrentDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatCurrentDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cDC = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(CatCurrentDialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(cDC);
        cDC->setObjectName(QString::fromUtf8("cDC"));
        cDC->setChecked(true);

        verticalLayout->addWidget(cDC);

        cAC = new QRadioButton(groupBox);
        buttonGroup->addButton(cAC);
        cAC->setObjectName(QString::fromUtf8("cAC"));

        verticalLayout->addWidget(cAC);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CatCurrentDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cRange = new QSpinBox(CatCurrentDialog);
        cRange->setObjectName(QString::fromUtf8("cRange"));
        cRange->setMinimum(1);
        cRange->setMaximum(999999);
        cRange->setSingleStep(10);

        horizontalLayout->addWidget(cRange);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CatCurrentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatCurrentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatCurrentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatCurrentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatCurrentDialog);
    } // setupUi

    void retranslateUi(QDialog *CatCurrentDialog)
    {
        CatCurrentDialog->setWindowTitle(QApplication::translate("CatCurrentDialog", "\347\224\265\346\265\201\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatCurrentDialog", "\347\224\265\346\265\201\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        cDC->setText(QApplication::translate("CatCurrentDialog", "DC", 0, QApplication::UnicodeUTF8));
        cAC->setText(QApplication::translate("CatCurrentDialog", "AC", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatCurrentDialog", "\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatCurrentDialog: public Ui_CatCurrentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATCURRENTDIALOG_H

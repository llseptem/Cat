/********************************************************************************
** Form generated from reading UI file 'CatCurveDialog.ui'
**
** Created: Wed May 15 20:46:04 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATCURVEDIALOG_H
#define UI_CATCURVEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatCurveDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *tagEdit;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *CatCurveDialog)
    {
        if (CatCurveDialog->objectName().isEmpty())
            CatCurveDialog->setObjectName(QString::fromUtf8("CatCurveDialog"));
        CatCurveDialog->resize(174, 197);
        verticalLayout_2 = new QVBoxLayout(CatCurveDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatCurveDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(CatCurveDialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CatCurveDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tagEdit = new QLineEdit(groupBox_2);
        tagEdit->setObjectName(QString::fromUtf8("tagEdit"));

        horizontalLayout->addWidget(tagEdit);


        verticalLayout_2->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(CatCurveDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatCurveDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatCurveDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatCurveDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatCurveDialog);
    } // setupUi

    void retranslateUi(QDialog *CatCurveDialog)
    {
        CatCurveDialog->setWindowTitle(QApplication::translate("CatCurveDialog", "CatCurveDialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatCurveDialog", "\346\265\213\351\207\217\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("CatCurveDialog", "Voltage", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("CatCurveDialog", "Resistance", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("CatCurveDialog", "Current", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CatCurveDialog", "\346\240\207\347\255\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatCurveDialog: public Ui_CatCurveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATCURVEDIALOG_H

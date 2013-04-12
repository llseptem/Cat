/********************************************************************************
** Form generated from reading UI file 'CatCheckDialog.ui'
**
** Created: Thu Apr 11 21:33:08 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATCHECKDIALOG_H
#define UI_CATCHECKDIALOG_H

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
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatCheckDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *vBtn;
    QRadioButton *rBtn;
    QRadioButton *cBtn;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *lowerBtn;
    QRadioButton *upperBtn;
    QRadioButton *rangeBtn;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *lowerBox;
    QLabel *label_2;
    QSpinBox *upperBox;
    QToolButton *addBtn;
    QListWidget *rangeList;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *CatCheckDialog)
    {
        if (CatCheckDialog->objectName().isEmpty())
            CatCheckDialog->setObjectName(QString::fromUtf8("CatCheckDialog"));
        CatCheckDialog->resize(303, 466);
        verticalLayout_2 = new QVBoxLayout(CatCheckDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(CatCheckDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vBtn = new QRadioButton(groupBox_2);
        buttonGroup = new QButtonGroup(CatCheckDialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(vBtn);
        vBtn->setObjectName(QString::fromUtf8("vBtn"));
        vBtn->setChecked(true);

        verticalLayout->addWidget(vBtn);

        rBtn = new QRadioButton(groupBox_2);
        buttonGroup->addButton(rBtn);
        rBtn->setObjectName(QString::fromUtf8("rBtn"));

        verticalLayout->addWidget(rBtn);

        cBtn = new QRadioButton(groupBox_2);
        buttonGroup->addButton(cBtn);
        cBtn->setObjectName(QString::fromUtf8("cBtn"));

        verticalLayout->addWidget(cBtn);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(CatCheckDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lowerBtn = new QRadioButton(groupBox_3);
        buttonGroup_2 = new QButtonGroup(CatCheckDialog);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(lowerBtn);
        lowerBtn->setObjectName(QString::fromUtf8("lowerBtn"));

        verticalLayout_3->addWidget(lowerBtn);

        upperBtn = new QRadioButton(groupBox_3);
        buttonGroup_2->addButton(upperBtn);
        upperBtn->setObjectName(QString::fromUtf8("upperBtn"));

        verticalLayout_3->addWidget(upperBtn);

        rangeBtn = new QRadioButton(groupBox_3);
        buttonGroup_2->addButton(rangeBtn);
        rangeBtn->setObjectName(QString::fromUtf8("rangeBtn"));
        rangeBtn->setChecked(true);

        verticalLayout_3->addWidget(rangeBtn);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox = new QGroupBox(CatCheckDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lowerBox = new QSpinBox(groupBox);
        lowerBox->setObjectName(QString::fromUtf8("lowerBox"));
        lowerBox->setMinimum(-999999999);
        lowerBox->setMaximum(999999999);
        lowerBox->setSingleStep(100);

        horizontalLayout->addWidget(lowerBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        upperBox = new QSpinBox(groupBox);
        upperBox->setObjectName(QString::fromUtf8("upperBox"));
        upperBox->setMinimum(-999999999);
        upperBox->setMaximum(999999999);
        upperBox->setSingleStep(100);

        horizontalLayout->addWidget(upperBox);

        addBtn = new QToolButton(groupBox);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout->addWidget(addBtn);


        verticalLayout_2->addWidget(groupBox);

        rangeList = new QListWidget(CatCheckDialog);
        rangeList->setObjectName(QString::fromUtf8("rangeList"));

        verticalLayout_2->addWidget(rangeList);

        buttonBox = new QDialogButtonBox(CatCheckDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatCheckDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatCheckDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatCheckDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatCheckDialog);
    } // setupUi

    void retranslateUi(QDialog *CatCheckDialog)
    {
        CatCheckDialog->setWindowTitle(QApplication::translate("CatCheckDialog", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CatCheckDialog", "\350\257\273\345\217\226\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        vBtn->setText(QApplication::translate("CatCheckDialog", "Voltage", 0, QApplication::UnicodeUTF8));
        rBtn->setText(QApplication::translate("CatCheckDialog", "Resistance", 0, QApplication::UnicodeUTF8));
        cBtn->setText(QApplication::translate("CatCheckDialog", "Current", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CatCheckDialog", "\345\210\244\346\226\255", 0, QApplication::UnicodeUTF8));
        lowerBtn->setText(QApplication::translate("CatCheckDialog", "Lower", 0, QApplication::UnicodeUTF8));
        upperBtn->setText(QApplication::translate("CatCheckDialog", "Upper", 0, QApplication::UnicodeUTF8));
        rangeBtn->setText(QApplication::translate("CatCheckDialog", "Range", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatCheckDialog", "\350\214\203\345\233\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatCheckDialog", "\344\270\213\351\231\220", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CatCheckDialog", "\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("CatCheckDialog", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatCheckDialog: public Ui_CatCheckDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATCHECKDIALOG_H

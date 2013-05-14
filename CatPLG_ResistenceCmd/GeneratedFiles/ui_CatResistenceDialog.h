/********************************************************************************
** Form generated from reading UI file 'CatResistenceDialog.ui'
**
** Created: Tue May 14 20:20:47 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATRESISTENCEDIALOG_H
#define UI_CATRESISTENCEDIALOG_H

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

class Ui_CatResistenceDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *twoWire;
    QRadioButton *fourWire;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *rRange;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *CatResistenceDialog)
    {
        if (CatResistenceDialog->objectName().isEmpty())
            CatResistenceDialog->setObjectName(QString::fromUtf8("CatResistenceDialog"));
        CatResistenceDialog->resize(174, 145);
        verticalLayout_2 = new QVBoxLayout(CatResistenceDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatResistenceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        twoWire = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(CatResistenceDialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(twoWire);
        twoWire->setObjectName(QString::fromUtf8("twoWire"));
        twoWire->setChecked(true);

        verticalLayout->addWidget(twoWire);

        fourWire = new QRadioButton(groupBox);
        buttonGroup->addButton(fourWire);
        fourWire->setObjectName(QString::fromUtf8("fourWire"));

        verticalLayout->addWidget(fourWire);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CatResistenceDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        rRange = new QSpinBox(CatResistenceDialog);
        rRange->setObjectName(QString::fromUtf8("rRange"));
        rRange->setMinimum(1);
        rRange->setMaximum(9999999);
        rRange->setSingleStep(10);

        horizontalLayout->addWidget(rRange);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CatResistenceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatResistenceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatResistenceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatResistenceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatResistenceDialog);
    } // setupUi

    void retranslateUi(QDialog *CatResistenceDialog)
    {
        CatResistenceDialog->setWindowTitle(QApplication::translate("CatResistenceDialog", "\347\224\265\351\230\273\346\265\213\351\207\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatResistenceDialog", "\347\224\265\351\230\273\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        twoWire->setText(QApplication::translate("CatResistenceDialog", "\344\270\244\347\272\277", 0, QApplication::UnicodeUTF8));
        fourWire->setText(QApplication::translate("CatResistenceDialog", "\345\233\233\347\272\277", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatResistenceDialog", "Range", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatResistenceDialog: public Ui_CatResistenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATRESISTENCEDIALOG_H

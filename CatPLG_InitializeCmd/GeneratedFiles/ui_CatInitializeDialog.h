/********************************************************************************
** Form generated from reading UI file 'CatInitializeDialog.ui'
**
** Created: Mon Apr 22 20:02:36 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATINITIALIZEDIALOG_H
#define UI_CATINITIALIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CatInitializeDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *adr34980;
    QLabel *label_2;
    QLineEdit *adr34411;
    QDialogButtonBox *buttonBox;
    QCheckBox *closeDev;

    void setupUi(QDialog *CatInitializeDialog)
    {
        if (CatInitializeDialog->objectName().isEmpty())
            CatInitializeDialog->setObjectName(QString::fromUtf8("CatInitializeDialog"));
        CatInitializeDialog->resize(410, 93);
        gridLayout = new QGridLayout(CatInitializeDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CatInitializeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        adr34980 = new QLineEdit(CatInitializeDialog);
        adr34980->setObjectName(QString::fromUtf8("adr34980"));

        gridLayout->addWidget(adr34980, 0, 1, 1, 1);

        label_2 = new QLabel(CatInitializeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        adr34411 = new QLineEdit(CatInitializeDialog);
        adr34411->setObjectName(QString::fromUtf8("adr34411"));

        gridLayout->addWidget(adr34411, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CatInitializeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        closeDev = new QCheckBox(CatInitializeDialog);
        closeDev->setObjectName(QString::fromUtf8("closeDev"));

        gridLayout->addWidget(closeDev, 2, 0, 1, 1);


        retranslateUi(CatInitializeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatInitializeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatInitializeDialog, SLOT(reject()));
        QObject::connect(closeDev, SIGNAL(clicked(bool)), adr34980, SLOT(setDisabled(bool)));
        QObject::connect(closeDev, SIGNAL(clicked(bool)), adr34411, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(CatInitializeDialog);
    } // setupUi

    void retranslateUi(QDialog *CatInitializeDialog)
    {
        CatInitializeDialog->setWindowTitle(QApplication::translate("CatInitializeDialog", "\350\276\223\345\205\245\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CatInitializeDialog", "34980\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CatInitializeDialog", "34411\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        closeDev->setText(QApplication::translate("CatInitializeDialog", "\345\205\263\351\227\255\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatInitializeDialog: public Ui_CatInitializeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATINITIALIZEDIALOG_H

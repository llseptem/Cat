/********************************************************************************
** Form generated from reading UI file 'catportselectdialog.ui'
**
** Created: Mon Mar 25 20:42:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATPORTSELECTDIALOG_H
#define UI_CATPORTSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatPortSelectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *portEdit;
    QToolButton *addBtn;
    QListWidget *portList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CatPortSelectDialog)
    {
        if (CatPortSelectDialog->objectName().isEmpty())
            CatPortSelectDialog->setObjectName(QString::fromUtf8("CatPortSelectDialog"));
        CatPortSelectDialog->resize(216, 300);
        verticalLayout = new QVBoxLayout(CatPortSelectDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        portEdit = new QLineEdit(CatPortSelectDialog);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout->addWidget(portEdit);

        addBtn = new QToolButton(CatPortSelectDialog);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout->addWidget(addBtn);


        verticalLayout->addLayout(horizontalLayout);

        portList = new QListWidget(CatPortSelectDialog);
        portList->setObjectName(QString::fromUtf8("portList"));

        verticalLayout->addWidget(portList);

        buttonBox = new QDialogButtonBox(CatPortSelectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CatPortSelectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatPortSelectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatPortSelectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatPortSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *CatPortSelectDialog)
    {
        CatPortSelectDialog->setWindowTitle(QApplication::translate("CatPortSelectDialog", "\346\267\273\345\212\240\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("CatPortSelectDialog", "\357\274\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatPortSelectDialog: public Ui_CatPortSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATPORTSELECTDIALOG_H

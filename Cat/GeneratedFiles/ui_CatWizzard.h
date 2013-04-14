/********************************************************************************
** Form generated from reading UI file 'CatWizzard.ui'
**
** Created: Sun Apr 14 14:15:16 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATWIZZARD_H
#define UI_CATWIZZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatWizzard
{
public:
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *openBtn;
    QCommandLinkButton *newBtn;

    void setupUi(QDialog *CatWizzard)
    {
        if (CatWizzard->objectName().isEmpty())
            CatWizzard->setObjectName(QString::fromUtf8("CatWizzard"));
        CatWizzard->resize(446, 145);
        verticalLayout = new QVBoxLayout(CatWizzard);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        openBtn = new QCommandLinkButton(CatWizzard);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));

        verticalLayout->addWidget(openBtn);

        newBtn = new QCommandLinkButton(CatWizzard);
        newBtn->setObjectName(QString::fromUtf8("newBtn"));

        verticalLayout->addWidget(newBtn);


        retranslateUi(CatWizzard);

        QMetaObject::connectSlotsByName(CatWizzard);
    } // setupUi

    void retranslateUi(QDialog *CatWizzard)
    {
        CatWizzard->setWindowTitle(QApplication::translate("CatWizzard", "\345\220\221\345\257\274", 0, QApplication::UnicodeUTF8));
        openBtn->setText(QApplication::translate("CatWizzard", "\346\211\223\345\274\200\345\267\262\346\234\211\346\243\200\346\265\213\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        openBtn->setDescription(QApplication::translate("CatWizzard", "\346\211\223\345\274\200\345\271\266\350\277\220\350\241\214\344\270\200\344\270\252\345\267\262\347\273\217\345\255\230\345\234\250\347\232\204\350\247\243\345\206\263\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        newBtn->setText(QApplication::translate("CatWizzard", "\346\226\260\345\273\272\346\243\200\346\265\213\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
        newBtn->setDescription(QApplication::translate("CatWizzard", "\346\226\260\345\273\272\345\271\266\344\277\235\345\255\230\344\270\200\344\270\252\346\226\260\347\232\204\350\247\243\345\206\263\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatWizzard: public Ui_CatWizzard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATWIZZARD_H

/********************************************************************************
** Form generated from reading UI file 'CatGroupSelector.ui'
**
** Created: Fri Apr 12 12:32:10 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATGROUPSELECTOR_H
#define UI_CATGROUPSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatGroupSelector
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *allBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CatGroupSelector)
    {
        if (CatGroupSelector->objectName().isEmpty())
            CatGroupSelector->setObjectName(QString::fromUtf8("CatGroupSelector"));
        CatGroupSelector->resize(174, 95);
        verticalLayout_2 = new QVBoxLayout(CatGroupSelector);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CatGroupSelector);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        allBox = new QCheckBox(groupBox);
        allBox->setObjectName(QString::fromUtf8("allBox"));

        verticalLayout->addWidget(allBox);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(CatGroupSelector);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CatGroupSelector);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatGroupSelector, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatGroupSelector, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatGroupSelector);
    } // setupUi

    void retranslateUi(QDialog *CatGroupSelector)
    {
        CatGroupSelector->setWindowTitle(QApplication::translate("CatGroupSelector", "\351\200\211\346\213\251\347\273\204", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatGroupSelector", "\351\200\211\346\213\251\350\246\201\346\211\247\350\241\214\347\232\204\347\273\204", 0, QApplication::UnicodeUTF8));
        allBox->setText(QApplication::translate("CatGroupSelector", "\345\205\250\351\200\211", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatGroupSelector: public Ui_CatGroupSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATGROUPSELECTOR_H

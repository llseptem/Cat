/********************************************************************************
** Form generated from reading UI file 'CatUserDecideCmd.ui'
**
** Created: Sun May 12 19:33:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATUSERDECIDECMD_H
#define UI_CATUSERDECIDECMD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatUserDecideCmd
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *imgLabel;
    QLabel *askLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CatUserDecideCmd)
    {
        if (CatUserDecideCmd->objectName().isEmpty())
            CatUserDecideCmd->setObjectName(QString::fromUtf8("CatUserDecideCmd"));
        CatUserDecideCmd->resize(400, 300);
        verticalLayout = new QVBoxLayout(CatUserDecideCmd);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        imgLabel = new QLabel(CatUserDecideCmd);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));

        verticalLayout->addWidget(imgLabel);

        askLabel = new QLabel(CatUserDecideCmd);
        askLabel->setObjectName(QString::fromUtf8("askLabel"));
        askLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(askLabel);

        buttonBox = new QDialogButtonBox(CatUserDecideCmd);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CatUserDecideCmd);
        QObject::connect(buttonBox, SIGNAL(accepted()), CatUserDecideCmd, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CatUserDecideCmd, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatUserDecideCmd);
    } // setupUi

    void retranslateUi(QDialog *CatUserDecideCmd)
    {
        CatUserDecideCmd->setWindowTitle(QApplication::translate("CatUserDecideCmd", "\350\257\267\347\225\231\346\204\217", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("CatUserDecideCmd", "TextLabel", 0, QApplication::UnicodeUTF8));
        askLabel->setText(QApplication::translate("CatUserDecideCmd", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatUserDecideCmd: public Ui_CatUserDecideCmd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATUSERDECIDECMD_H

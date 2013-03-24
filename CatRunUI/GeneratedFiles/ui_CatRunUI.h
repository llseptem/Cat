/********************************************************************************
** Form generated from reading UI file 'CatRunUI.ui'
**
** Created: Sun Mar 24 18:08:51 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATRUNUI_H
#define UI_CATRUNUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatRunUI
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *imgLabel;
    QLabel *textLabel;
    QVBoxLayout *verticalLayout;
    QPushButton *yesBtn;
    QPushButton *noBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *stopBtn;

    void setupUi(QDialog *CatRunUI)
    {
        if (CatRunUI->objectName().isEmpty())
            CatRunUI->setObjectName(QString::fromUtf8("CatRunUI"));
        CatRunUI->resize(806, 545);
        CatRunUI->setModal(true);
        horizontalLayout = new QHBoxLayout(CatRunUI);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        imgLabel = new QLabel(CatRunUI);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(imgLabel);

        textLabel = new QLabel(CatRunUI);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));
        textLabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(textLabel);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        yesBtn = new QPushButton(CatRunUI);
        yesBtn->setObjectName(QString::fromUtf8("yesBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yesBtn->sizePolicy().hasHeightForWidth());
        yesBtn->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        yesBtn->setIcon(icon);
        yesBtn->setIconSize(QSize(24, 24));
        yesBtn->setCheckable(true);

        verticalLayout->addWidget(yesBtn);

        noBtn = new QPushButton(CatRunUI);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));
        sizePolicy.setHeightForWidth(noBtn->sizePolicy().hasHeightForWidth());
        noBtn->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Resources/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        noBtn->setIcon(icon1);
        noBtn->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(noBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stopBtn = new QPushButton(CatRunUI);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        sizePolicy.setHeightForWidth(stopBtn->sizePolicy().hasHeightForWidth());
        stopBtn->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(stopBtn);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(CatRunUI);
        QObject::connect(stopBtn, SIGNAL(clicked()), CatRunUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatRunUI);
    } // setupUi

    void retranslateUi(QDialog *CatRunUI)
    {
        CatRunUI->setWindowTitle(QApplication::translate("CatRunUI", "\347\272\277\346\235\237\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("CatRunUI", "TextLabel", 0, QApplication::UnicodeUTF8));
        textLabel->setText(QApplication::translate("CatRunUI", "TextLabel", 0, QApplication::UnicodeUTF8));
        yesBtn->setText(QApplication::translate("CatRunUI", "\346\230\257", 0, QApplication::UnicodeUTF8));
        noBtn->setText(QApplication::translate("CatRunUI", "\345\220\246", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("CatRunUI", "\347\273\223\346\235\237\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatRunUI: public Ui_CatRunUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATRUNUI_H

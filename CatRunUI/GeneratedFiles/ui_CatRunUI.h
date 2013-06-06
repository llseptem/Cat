/********************************************************************************
** Form generated from reading UI file 'CatRunUI.ui'
**
** Created: Thu Jun 6 20:54:26 2013
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatRunUI
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *imgLabel;
    QGroupBox *resultGrp;
    QLabel *titleLabel;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *yesBtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *noBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *continueBtn;
    QPushButton *printBtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *stopBtn;

    void setupUi(QDialog *CatRunUI)
    {
        if (CatRunUI->objectName().isEmpty())
            CatRunUI->setObjectName(QString::fromUtf8("CatRunUI"));
        CatRunUI->resize(914, 638);
        CatRunUI->setModal(true);
        horizontalLayout_2 = new QHBoxLayout(CatRunUI);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imgLabel = new QLabel(CatRunUI);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setFrameShape(QFrame::StyledPanel);
        imgLabel->setScaledContents(true);
        imgLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(imgLabel);

        resultGrp = new QGroupBox(CatRunUI);
        resultGrp->setObjectName(QString::fromUtf8("resultGrp"));

        horizontalLayout->addWidget(resultGrp);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        titleLabel = new QLabel(CatRunUI);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        titleLabel->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(25);
        titleLabel->setFont(font);
        titleLabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(titleLabel);

        textEdit = new QTextEdit(CatRunUI);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 3);

        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        yesBtn = new QPushButton(CatRunUI);
        yesBtn->setObjectName(QString::fromUtf8("yesBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yesBtn->sizePolicy().hasHeightForWidth());
        yesBtn->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        yesBtn->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        yesBtn->setIcon(icon);
        yesBtn->setIconSize(QSize(32, 32));
        yesBtn->setCheckable(true);

        verticalLayout->addWidget(yesBtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        noBtn = new QPushButton(CatRunUI);
        noBtn->setObjectName(QString::fromUtf8("noBtn"));
        sizePolicy.setHeightForWidth(noBtn->sizePolicy().hasHeightForWidth());
        noBtn->setSizePolicy(sizePolicy);
        noBtn->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Resources/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        noBtn->setIcon(icon1);
        noBtn->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(noBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        continueBtn = new QPushButton(CatRunUI);
        continueBtn->setObjectName(QString::fromUtf8("continueBtn"));
        sizePolicy.setHeightForWidth(continueBtn->sizePolicy().hasHeightForWidth());
        continueBtn->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        continueBtn->setFont(font2);

        verticalLayout->addWidget(continueBtn);

        printBtn = new QPushButton(CatRunUI);
        printBtn->setObjectName(QString::fromUtf8("printBtn"));
        sizePolicy.setHeightForWidth(printBtn->sizePolicy().hasHeightForWidth());
        printBtn->setSizePolicy(sizePolicy);
        printBtn->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Resources/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        printBtn->setIcon(icon2);
        printBtn->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(printBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        stopBtn = new QPushButton(CatRunUI);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        sizePolicy.setHeightForWidth(stopBtn->sizePolicy().hasHeightForWidth());
        stopBtn->setSizePolicy(sizePolicy);
        stopBtn->setFont(font2);

        verticalLayout->addWidget(stopBtn);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(7, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);

        retranslateUi(CatRunUI);
        QObject::connect(stopBtn, SIGNAL(clicked()), CatRunUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(CatRunUI);
    } // setupUi

    void retranslateUi(QDialog *CatRunUI)
    {
        CatRunUI->setWindowTitle(QApplication::translate("CatRunUI", "\347\272\277\346\235\237\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QString());
        resultGrp->setTitle(QApplication::translate("CatRunUI", "\346\211\253\346\217\217\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("CatRunUI", "TextLabel", 0, QApplication::UnicodeUTF8));
        yesBtn->setText(QApplication::translate("CatRunUI", "\346\230\257", 0, QApplication::UnicodeUTF8));
        noBtn->setText(QApplication::translate("CatRunUI", "\345\220\246", 0, QApplication::UnicodeUTF8));
        continueBtn->setText(QApplication::translate("CatRunUI", "\347\273\247\347\273\255\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        printBtn->setText(QApplication::translate("CatRunUI", "\346\211\223\345\215\260\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("CatRunUI", "\347\273\223\346\235\237\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatRunUI: public Ui_CatRunUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATRUNUI_H

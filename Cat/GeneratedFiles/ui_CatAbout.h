/********************************************************************************
** Form generated from reading UI file 'CatAbout.ui'
**
** Created: Fri Jun 7 18:47:43 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATABOUT_H
#define UI_CATABOUT_H

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
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatAbout
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *aboutQtBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *CatAbout)
    {
        if (CatAbout->objectName().isEmpty())
            CatAbout->setObjectName(QString::fromUtf8("CatAbout"));
        CatAbout->resize(384, 346);
        verticalLayout = new QVBoxLayout(CatAbout);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(CatAbout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/CatMainWindow/Resources/hardware.png")));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(label_2);

        textBrowser = new QTextBrowser(CatAbout);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        aboutQtBtn = new QPushButton(CatAbout);
        aboutQtBtn->setObjectName(QString::fromUtf8("aboutQtBtn"));

        horizontalLayout->addWidget(aboutQtBtn);

        okBtn = new QPushButton(CatAbout);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout->addWidget(okBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CatAbout);
        QObject::connect(okBtn, SIGNAL(clicked()), CatAbout, SLOT(accept()));

        QMetaObject::connectSlotsByName(CatAbout);
    } // setupUi

    void retranslateUi(QDialog *CatAbout)
    {
        CatAbout->setWindowTitle(QApplication::translate("CatAbout", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        textBrowser->setHtml(QApplication::translate("CatAbout", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#000000;\">\347\272\277\346\235\237\346\243\200\346\265\213 1.0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        aboutQtBtn->setText(QApplication::translate("CatAbout", "\346\202\250\346\255\243\345\234\250\344\275\277\347\224\250Qt\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("CatAbout", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatAbout: public Ui_CatAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATABOUT_H

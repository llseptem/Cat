/********************************************************************************
** Form generated from reading UI file 'CatPresentation.ui'
**
** Created: Thu Jun 6 20:54:45 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATPRESENTATION_H
#define UI_CATPRESENTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatPresentation
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *imagePrev;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *imgPath;
    QToolButton *selImageBtn;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *description;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *breakOnFalse;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CatPresentation)
    {
        if (CatPresentation->objectName().isEmpty())
            CatPresentation->setObjectName(QString::fromUtf8("CatPresentation"));
        CatPresentation->resize(596, 332);
        verticalLayout_3 = new QVBoxLayout(CatPresentation);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        imagePrev = new QLabel(CatPresentation);
        imagePrev->setObjectName(QString::fromUtf8("imagePrev"));
        imagePrev->setFrameShape(QFrame::StyledPanel);
        imagePrev->setScaledContents(false);
        imagePrev->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(imagePrev);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(CatPresentation);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imgPath = new QLineEdit(groupBox_2);
        imgPath->setObjectName(QString::fromUtf8("imgPath"));
        imgPath->setReadOnly(true);

        horizontalLayout->addWidget(imgPath);

        selImageBtn = new QToolButton(groupBox_2);
        selImageBtn->setObjectName(QString::fromUtf8("selImageBtn"));

        horizontalLayout->addWidget(selImageBtn);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(CatPresentation);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        description = new QPlainTextEdit(groupBox);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);


        verticalLayout_2->addWidget(groupBox);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        breakOnFalse = new QCheckBox(CatPresentation);
        breakOnFalse->setObjectName(QString::fromUtf8("breakOnFalse"));

        horizontalLayout_2->addWidget(breakOnFalse);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(CatPresentation);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_2->addWidget(okBtn);

        cancelBtn = new QPushButton(CatPresentation);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout_2->addWidget(cancelBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(CatPresentation);

        QMetaObject::connectSlotsByName(CatPresentation);
    } // setupUi

    void retranslateUi(QDialog *CatPresentation)
    {
        CatPresentation->setWindowTitle(QApplication::translate("CatPresentation", "\347\274\226\350\276\221\347\224\250\346\210\267\346\217\220\347\244\272", 0, QApplication::UnicodeUTF8));
        imagePrev->setText(QApplication::translate("CatPresentation", "\346\262\241\346\234\211\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CatPresentation", "\351\200\211\346\213\251\347\244\272\346\204\217\345\233\276", 0, QApplication::UnicodeUTF8));
        selImageBtn->setText(QApplication::translate("CatPresentation", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CatPresentation", "\350\276\223\345\205\245\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        breakOnFalse->setText(QApplication::translate("CatPresentation", "\347\224\250\346\210\267\351\200\211\345\220\246\346\227\266\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("CatPresentation", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("CatPresentation", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatPresentation: public Ui_CatPresentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATPRESENTATION_H

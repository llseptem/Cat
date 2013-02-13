/********************************************************************************
** Form generated from reading UI file 'CatActionList.ui'
**
** Created: Wed Feb 13 11:51:25 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATACTIONLIST_H
#define UI_CATACTIONLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CatActionList
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *actionList;
    QSpacerItem *verticalSpacer;
    QLabel *actionDescription;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *CatActionList)
    {
        if (CatActionList->objectName().isEmpty())
            CatActionList->setObjectName(QString::fromUtf8("CatActionList"));
        CatActionList->resize(536, 298);
        verticalLayout_2 = new QVBoxLayout(CatActionList);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        actionList = new QComboBox(CatActionList);
        actionList->setObjectName(QString::fromUtf8("actionList"));

        verticalLayout->addWidget(actionList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        actionDescription = new QLabel(CatActionList);
        actionDescription->setObjectName(QString::fromUtf8("actionDescription"));
        actionDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        actionDescription->setWordWrap(true);

        horizontalLayout->addWidget(actionDescription);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addBtn = new QPushButton(CatActionList);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout_2->addWidget(addBtn);

        cancelBtn = new QPushButton(CatActionList);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout_2->addWidget(cancelBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CatActionList);
        QObject::connect(cancelBtn, SIGNAL(clicked()), CatActionList, SLOT(reject()));
        QObject::connect(addBtn, SIGNAL(clicked()), CatActionList, SLOT(accept()));

        QMetaObject::connectSlotsByName(CatActionList);
    } // setupUi

    void retranslateUi(QDialog *CatActionList)
    {
        CatActionList->setWindowTitle(QApplication::translate("CatActionList", "\351\200\211\346\213\251\345\221\275\344\273\244\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        actionDescription->setText(QApplication::translate("CatActionList", "\346\217\217\350\277\260\357\274\232", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("CatActionList", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("CatActionList", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatActionList: public Ui_CatActionList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATACTIONLIST_H

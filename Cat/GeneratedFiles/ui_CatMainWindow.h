/********************************************************************************
** Form generated from reading UI file 'CatMainWindow.ui'
**
** Created: Sat May 4 20:21:19 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATMAINWINDOW_H
#define UI_CATMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatMainWindow
{
public:
    QAction *actionNewSolution;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionOpen;
    QAction *actionNewAction;
    QAction *actionRemoveAction;
    QAction *actionAbout;
    QAction *actionGo;
    QAction *actionNewGroup;
    QWidget *centralWidget;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CatMainWindow)
    {
        if (CatMainWindow->objectName().isEmpty())
            CatMainWindow->setObjectName(QString::fromUtf8("CatMainWindow"));
        CatMainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CatMainWindow/Resources/hardware.png"), QSize(), QIcon::Normal, QIcon::Off);
        CatMainWindow->setWindowIcon(icon);
        actionNewSolution = new QAction(CatMainWindow);
        actionNewSolution->setObjectName(QString::fromUtf8("actionNewSolution"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/CatMainWindow/Resources/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewSolution->setIcon(icon1);
        actionSave = new QAction(CatMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/CatMainWindow/Resources/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSaveAs = new QAction(CatMainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/CatMainWindow/Resources/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon3);
        actionOpen = new QAction(CatMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/CatMainWindow/Resources/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon4);
        actionNewAction = new QAction(CatMainWindow);
        actionNewAction->setObjectName(QString::fromUtf8("actionNewAction"));
        actionNewAction->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/CatMainWindow/Resources/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewAction->setIcon(icon5);
        actionRemoveAction = new QAction(CatMainWindow);
        actionRemoveAction->setObjectName(QString::fromUtf8("actionRemoveAction"));
        actionRemoveAction->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/CatMainWindow/Resources/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemoveAction->setIcon(icon6);
        actionAbout = new QAction(CatMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/CatMainWindow/Resources/kdeprint_printer_infos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon7);
        actionGo = new QAction(CatMainWindow);
        actionGo->setObjectName(QString::fromUtf8("actionGo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/CatMainWindow/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGo->setIcon(icon8);
        actionNewGroup = new QAction(CatMainWindow);
        actionNewGroup->setObjectName(QString::fromUtf8("actionNewGroup"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/CatMainWindow/Resources/tab_new_background.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewGroup->setIcon(icon9);
        centralWidget = new QWidget(CatMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CatMainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(CatMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        CatMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(CatMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CatMainWindow->setStatusBar(statusBar);

        toolBar->addAction(actionNewSolution);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actionNewGroup);
        toolBar->addAction(actionNewAction);
        toolBar->addAction(actionRemoveAction);
        toolBar->addSeparator();
        toolBar->addAction(actionGo);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);

        retranslateUi(CatMainWindow);

        QMetaObject::connectSlotsByName(CatMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CatMainWindow)
    {
        CatMainWindow->setWindowTitle(QApplication::translate("CatMainWindow", "\346\243\200\346\265\213\346\226\271\346\241\210\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        actionNewSolution->setText(QApplication::translate("CatMainWindow", "\346\226\260\345\273\272\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewSolution->setToolTip(QApplication::translate("CatMainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252\346\243\200\346\237\245\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("CatMainWindow", "\344\277\235\345\255\230\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("CatMainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\346\243\200\346\237\245\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSaveAs->setText(QApplication::translate("CatMainWindow", "\345\217\246\345\255\230\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("CatMainWindow", "\345\217\246\345\255\230\345\275\223\345\211\215\346\243\200\346\237\245\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("CatMainWindow", "\346\211\223\345\274\200\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("CatMainWindow", "\346\211\223\345\274\200\344\270\200\344\270\252\347\216\260\346\234\211\347\232\204\346\243\200\346\237\245\346\226\271\346\241\210", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewAction->setText(QApplication::translate("CatMainWindow", "\346\226\260\345\242\236\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewAction->setToolTip(QApplication::translate("CatMainWindow", "\346\226\260\345\242\236\344\270\200\344\270\252\346\243\200\346\265\213\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRemoveAction->setText(QApplication::translate("CatMainWindow", "\347\247\273\351\231\244\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRemoveAction->setToolTip(QApplication::translate("CatMainWindow", "\347\247\273\351\231\244\351\200\211\344\270\255\347\232\204\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("CatMainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("CatMainWindow", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGo->setText(QApplication::translate("CatMainWindow", "Go", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGo->setToolTip(QApplication::translate("CatMainWindow", "\350\277\220\350\241\214\346\243\200\346\237\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewGroup->setText(QApplication::translate("CatMainWindow", "\346\226\260\345\273\272\345\221\275\344\273\244\347\273\204", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatMainWindow: public Ui_CatMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATMAINWINDOW_H

#ifndef CATUSERDECIDECMD_H
#define CATUSERDECIDECMD_H

#include <QDialog>
#include "ui_CatUserDecideCmd.h"

class CatUserDecideCmd : public QDialog
{
	Q_OBJECT

public:
	CatUserDecideCmd(QWidget *parent = 0);
	~CatUserDecideCmd();

	void setShowImage(const QString& img);
	void setQuestion(const QString& qst);
private:
	Ui::CatUserDecideCmd ui;
};

#endif // CATUSERDECIDECMD_H

#ifndef CATRUNUI_H
#define CATRUNUI_H

#include <QDialog>
#include "catrunui_global.h"

namespace Ui
{
	class CatRunUI;
}

class CATRUNUI_EXPORT CatRunUI : public QDialog
{
	Q_OBJECT

public:
	CatRunUI(QWidget *parent = 0);
	~CatRunUI();

	void setInformation(const QString& info);
	void setImage(const QImage& img);
	void setImage(const QString& pth);
	bool waitForDecition();
	bool wait(int sec);
private:
	Ui::CatRunUI* ui;
};

#endif // CATRUNUI_H

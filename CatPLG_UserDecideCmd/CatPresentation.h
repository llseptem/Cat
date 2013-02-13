#ifndef CATPRESENTATION_H
#define CATPRESENTATION_H

#include <QDialog>
#include "ui_CatPresentation.h"

class CatPresentation : public QDialog
{
	Q_OBJECT

public:
	CatPresentation(QWidget *parent = 0);
	~CatPresentation();

	QString imagePath() const;
	QString description() const;
private slots:
	void onSelectImage();
	void onAccepted();
private:
	Ui::CatPresentation ui;
	void setupConnect();
};

#endif // CATPRESENTATION_H

#pragma once
#include <QWidget>
#include <QDialog>
#include "ui_about.h"

class About : public QDialog {
	Q_OBJECT

public:
	About(QDialog * parent = nullptr);
	~About() = default;

	void setIndex(int);
private:
	Ui::About ui;
};

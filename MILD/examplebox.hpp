#pragma once
#include <QDialog>
#include "ui_examplebox.h"

class ExampleBox : public QDialog {
	Q_OBJECT

public:
	ExampleBox(QDialog * parent = nullptr);
private:
	Ui::ExampleBox ui;
};

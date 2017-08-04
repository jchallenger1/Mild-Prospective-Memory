#include <QLabel>
#include <QPixmap>
#include <QStackedWidget>
#include "about.hpp"

About::About(QDialog * parent) : QDialog(parent) {
	ui.setupUi(this);
	QPixmap img(":/Images/Resources/lucidity.png");
	img = img.scaled(100, 100);
	ui.label_5->setPixmap(img);
}

void About::setIndex(int a) {
	if (a == 0 || a == 1)
		ui.stackedWidget->setCurrentIndex(a);
	else
		throw std::out_of_range("Widget index is out of range.");
}

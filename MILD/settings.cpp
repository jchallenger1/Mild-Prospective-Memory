#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QCheckBox>
#include "settings.hpp"

Settings::Settings(QDialog * parent) : QDialog(parent) {
	ui.setupUi(this);
	example = std::make_unique<ExampleBox>();
	example->hide();
	ui.fileButton->setEnabled(false);
	connect(ui.fileButton, &QPushButton::pressed, this, &Settings::showFileDialog);
	connect(ui.questionButton, &QPushButton::pressed, this, &Settings::showExample);
	connect(ui.checkBox_3, &QCheckBox::stateChanged, this, &Settings::AllowNewEntries);
	connect(ui.okButton, &QPushButton::pressed, this, &Settings::getData);
	connect(ui.cancelButton, &QPushButton::pressed, this, &QApplication::quit);
}

void Settings::AllowNewEntries() {
	if (ui.checkBox_3->isChecked()) {
		ui.fileButton->setEnabled(true);
		ui.lineEdit_2->setReadOnly(false);
	}
	else {
		ui.fileButton->setEnabled(false);
		ui.lineEdit_2->setReadOnly(true);

	}
}

void Settings::showFileDialog() {
	QFileDialog file(this);
	file.exec();
	QStringList n = file.selectedFiles();
	if (n.size() >= 1) {
		QString url = n[0];
		if (QFile(url).exists()) {
			ui.lineEdit_2->setText(n[0]);
		}
		else {
			QMessageBox box;
			box.setText(url + " does not exist!");
			ui.lineEdit_2->setText("");
		}
		
	}
	
}

void Settings::showExample() {
	if (example->isHidden()) {
		example->show();
	}
	else {
		QMessageBox box(this);
		box.setText("Close the current example box before opening a new one");
		box.exec();
	}
}


void Settings::getData() {
	file_name = ui.lineEdit->text().toStdString();
	date = ui.checkBox->isChecked();
	number = ui.checkBox_2->isChecked();
	entry_count = ui.spinBox->value();
	if (ui.checkBox_3->isChecked()) {
		const QString path = ui.lineEdit_2->text();
		QFile file(path);
		if (!file.exists()) {
			add_new_entries = false;
			QMessageBox box(this);
			box.setText(path + "Does not exist!");
			box.exec();
		}
		else {
			add_new_entries = true;
			user_entry_path = ui.lineEdit_2->text().toStdString();
		}
	}
}



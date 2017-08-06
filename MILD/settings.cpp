#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QCheckBox>
#include "settings.hpp"

Settings::Settings(QDialog * parent) : QDialog(parent) {
	ui.setupUi(this);
	this->setWindowIcon(QIcon(":/Images/Resources/Settings icon.ico"));
	example = std::make_unique<ExampleBox>();
	example->hide();
	ui.fileButton->setEnabled(false);
	ui.pushButton->setEnabled(false);
	connect(ui.fileButton, &QPushButton::pressed, this, &Settings::showFileNewDialog);
	connect(ui.pushButton, &QPushButton::pressed, this, &Settings::showFileDiffDialog);
	connect(ui.questionButton, &QPushButton::pressed, this, &Settings::showExample);
	connect(ui.checkBox_3, &QCheckBox::stateChanged, this, &Settings::AllowNewEntries);
	connect(ui.checkBox_4, &QCheckBox::stateChanged, this, &Settings::AllowDifDir);
	connect(ui.okButton, &QPushButton::pressed, this, &Settings::getData);
	connect(ui.cancelButton, &QPushButton::pressed, this, &Settings::emitCancel);
	connect(this, &QDialog::rejected, this, &Settings::emitCancel);
}


void Settings::emitCancel() {
	emit settingsCanceled();
}

void Settings::debug() {
	QMessageBox box(this);
	box.setText("I WAS CALLED!");
	box.exec();
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

void Settings::AllowDifDir() {
	if (ui.checkBox_4->isChecked()) {
		ui.pushButton->setEnabled(true);
		ui.lineEdit_3->setReadOnly(false);
	}
	else {
		ui.pushButton->setEnabled(false);
		ui.lineEdit_3->setReadOnly(true);
	}
}

void Settings::showFileDiffDialog() {
	showFileDialog(ui.lineEdit_3);
}

void Settings::showFileNewDialog() {
	showFileDialog(ui.lineEdit_2);
}

void Settings::showFileDialog(QLineEdit* editor) {
	//QFileDialog takes a large amount of resources,
	//It is better to delete the resource instead of hiding it.
	std::unique_ptr<QFileDialog> file = std::make_unique<QFileDialog>(this);
	file->exec();
	QStringList n = file->selectedFiles();
	if (n.size() >= 1) {
		QFileInfo cur_file(n[0]);
		if (cur_file.exists()) {
			editor->setText(n[0]);
		}
		else {
			QMessageBox box;
			box.setText(cur_file.absoluteFilePath() + " does not exist!");
			editor->setText("");
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

void Settings::showData() {
	ui.lineEdit->setText(file_name);
	add_new_entries ? ui.checkBox_3->setChecked(true) : ui.checkBox_3->setChecked(false);
	ui.lineEdit_2->setText(user_entry_path);
	dif_save_dir ? ui.checkBox_4->setChecked(true) : ui.checkBox_4->setChecked(false);
	ui.lineEdit_3->setText(save_directory);
	date ? ui.checkBox->setChecked(true) : ui.checkBox->setChecked(false);
	number ? ui.checkBox_2->setChecked(true) : ui.checkBox_2->setChecked(false);
	ui.spinBox->setValue(entry_count);
}

/*If one part of the settings is incorrect, we should not accept
all of the settings unless we know they're all correct. If the settings are
invalid, then the current settings should not change. There could be
a possibility of a part of a program accepting some settings when
it isn't suppost to. */
void Settings::getData() {//TODO: THE NEW FILE DIALOG
	bool validSettings = true;
	QString temp_file_name = ui.lineEdit->text();
	bool temp_date = ui.checkBox->isChecked();
	bool temp_number = ui.checkBox_2->isChecked();
	int temp_entry_count = ui.spinBox->value();
	bool temp_add_new_entries = false, temp_dif_save_dir = false;
	QString temp_user_entry_path, temp_save_directory;
	if (ui.checkBox_3->isChecked()) {
		const QString path = ui.lineEdit_2->text();
		QFileInfo file(path);
		if (!file.exists()) {
			validSettings = false;
			QMessageBox box(this);
			box.setText(path + "Does not exist!");
			box.exec();
		}
		else {
			temp_add_new_entries = true;
			temp_user_entry_path = ui.lineEdit_2->text();
		}
	}
	if (ui.checkBox_4->isChecked()) {
		const QString path = ui.lineEdit_3->text();
		QFileInfo file(path);
		if (!file.exists()) {
			validSettings = false;
			QMessageBox box(this);
			box.setText(path + "Does not exist!");
			box.exec();
		}
		else {
			temp_dif_save_dir = true;
			temp_save_directory = path;
		}
	}
	if (validSettings) {
		file_name = temp_file_name.isEmpty() ? file_name : temp_file_name;
		date = temp_date ? temp_date : date;
		number = temp_number ? temp_number : number;
		entry_count = temp_entry_count;
		if (temp_add_new_entries) {
			add_new_entries = true;
			user_entry_path = temp_user_entry_path;
		}
		if (temp_dif_save_dir) {
			dif_save_dir = true;
			save_directory = temp_save_directory;
		}
		emit settingsAccepted();
	}
}



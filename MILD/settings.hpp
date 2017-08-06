#pragma once
#include <QWidget>
#include <QLineEdit>
#include <string>
#include <memory>
#include "ui_settings.h"
#include "examplebox.hpp"

class Settings : public QDialog {
	Q_OBJECT

public:
	Settings(QDialog * parent = nullptr);


	QString file_name = "LD.txt";
	QString user_entry_path;
	QString save_directory;
	bool date = true;
	bool number = false;
	bool add_new_entries = false;
	bool dif_save_dir = false;
	int entry_count = 4;
public slots:
	void showData();
signals:
	void settingsAccepted();
	void settingsCanceled();
private slots:
	void debug();
	void emitCancel();
	void getData();
	void showFileNewDialog();
	void showFileDiffDialog();
	void showExample();
	void AllowNewEntries();
	void AllowDifDir();
private:
	std::unique_ptr<ExampleBox> example = nullptr;
	Ui::Settings ui;
	void showFileDialog(QLineEdit*);
};

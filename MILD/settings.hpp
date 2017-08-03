#pragma once
#include <QWidget>
#include <string>
#include <memory>
#include "ui_settings.h"
#include "examplebox.hpp"

class Settings : public QDialog {
	Q_OBJECT

public:
	Settings(QDialog * parent = nullptr);


	std::string file_name = "LD.txt";
	std::string user_entry_path;
	bool date = true;
	bool number = false;
	bool add_new_entries = false;
	int entry_count = 4;
private slots:
	void getData();
	void showFileDialog();
	void showExample();
	void AllowNewEntries();
private:
	std::unique_ptr<ExampleBox> example = nullptr;
	Ui::Settings ui;
};

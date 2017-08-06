#include <QAction>
#include <QVBoxLayout>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include "window.h"
#include "entryitem.hpp"

Window::Window(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	this->setWindowIcon(QIcon(":/Images/Resources/lucidity icon.ico"));
	data = std::make_shared<DataEntries>(standard_entries);
	settings = std::make_unique<Settings>();
	settings->hide();
	entry_items = std::make_shared<MapType>();
	layout = std::make_unique<QVBoxLayout>(ui.groupBox);
	about = std::make_unique<About>();
	about->hide();
	
	setupGrid();
	
	connect(ui.pushButton_3, &QPushButton::pressed, this, &QApplication::quit);
	connect(ui.actionSettings, &QAction::triggered, this, &Window::showSettings);
	connect(ui.pushButton, &QPushButton::pressed, this, &Window::refreshGrid);
	connect(ui.pushButton_2, &QPushButton::pressed, this, &Window::outPutEntries);
	connect(settings.get(), &Settings::settingsCanceled, this, &Window::closeSettings);
	connect(settings.get(), &Settings::settingsAccepted, this, &Window::acceptSettings);
	connect(ui.actionAbout_Prospective_Memory, &QAction::triggered, this, &Window::showAboutProsp);
	connect(ui.actionAbout_Program, &QAction::triggered, this, &Window::showAboutGen);
}

void Window::setupGrid() {
	vector<string> entries = data->returnEntries(settings->entry_count);
	for (int x = 0; x < entries.size(); x++) {
		entry_items->insert(std::pair<string, std::unique_ptr<EntryItem>>(entries[x], std::make_unique<EntryItem>(entry_items,this)));
	}
	for (auto iter = entry_items->begin(); iter != entry_items->end(); iter++) {
		auto& item = iter->second;
		item->setText(iter->first);
		item->setData(data);
		layout->addWidget(item.get());
	}
	layout->addStretch(1);
	ui.groupBox->setLayout(layout.get());
}

void Window::refreshGrid() {
	vector<string> entries = data->returnEntries(settings->entry_count);
	int x = 0;
	for (auto begin = entry_items->begin(); begin != entry_items->end(); begin++) {
		begin->second->setText(entries[x]);
		x++;
	}
}

void Window::completeRefreshGrid() {
	for (auto begin = entry_items->begin(); begin != entry_items->end(); begin++) {
		layout->removeWidget(begin->second.get());
	}
	entry_items->clear();
	setupGrid();
}

void Window::showSettings() {
	settings->showData();
	settings->setModal(true);
	settings->show();
}

void Window::closeSettings() {
	settings->hide();
}

void Window::acceptSettings() {
	closeSettings();
	completeRefreshGrid();
	if (settings->add_new_entries) {
		std::ifstream ifs(settings->user_entry_path.toStdString());
		data->addEntries(ifs);
	}
}

void Window::outPutEntries() {
	vector<string> entries;
	for (auto iter = entry_items->begin(); iter != entry_items->end(); iter++) {
		entries.emplace_back(iter->second->lineText());
	}
	QString raw_path;
	if (settings->dif_save_dir) {
		QFileInfo info(settings->save_directory);
		if (info.isFile()) {
			raw_path = settings->save_directory;
		}
		else {// its a directory and we need to create the file.
			raw_path = settings->save_directory +"/"+ settings->file_name;
		}
	}
	else {
		raw_path = settings->file_name;
	}
	
	QFile file(raw_path);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QTextStream qts(&file);
		if (settings->date) {
			QDateTime date = QDateTime::currentDateTime();
			qts << "\t" << date.toString();
			endl(qts);
		}
		for (auto begin = entries.cbegin(); begin != entries.cend(); begin++) {
			int range = begin - entries.cbegin();
			if (settings->number) {
				qts << range+1 << ". ";
			}
			qts << QString::fromStdString(*begin);
			endl(qts);
		}
		QMessageBox* success_box = new QMessageBox(this);
		success_box->setText(QString::number(settings->entry_count) + " entries successfully written to |" + raw_path + "|");
		success_box->exec();
	}
	else {
		QMessageBox* error_box = new QMessageBox(this);
		error_box->setText("An error occured when writing to the file with path |" + raw_path + "|");
		error_box->exec();
	}
}

void Window::showAboutProsp() {
	about->setIndex(0);
	about->show();
}
void Window::showAboutGen() {
	about->setIndex(1);
	about->show();
}


Window::~Window() {
	entry_items->clear();
}
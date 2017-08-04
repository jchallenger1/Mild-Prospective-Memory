#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <unordered_map>
#include <QMainWindow>
#include <QVBoxLayout>
#include "ui_window.h"
#include "settings.hpp"
#include "entryitem.hpp"
#include "DataEntries.hpp"
#include "Functions.hpp"

class Window : public QMainWindow {
	Q_OBJECT
public:
	Window(QWidget *parent = 0);
	~Window();

private slots:
	void showSettings();
	void closeSettings();
	void acceptSettings();
	void refreshGrid(); //only modifies the text
	void completeRefreshGrid(); //removes the widgets
	void outPutEntries();
private:
	void setupGrid();
	std::shared_ptr<DataEntries> data = nullptr;
	std::shared_ptr<MapType> entry_items = nullptr;
	std::unique_ptr<Settings> settings = nullptr;
	std::unique_ptr<QVBoxLayout> layout = nullptr;
	
	Ui::WindowClass ui;
};

#endif // WINDOW_H

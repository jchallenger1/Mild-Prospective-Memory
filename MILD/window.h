#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <unordered_map>
#include <QMainWindow>
#include "ui_window.h"
#include "settings.hpp"
#include "entryitem.hpp"
#include "DataEntries.hpp"
using MapType = std::unordered_map<std::string, EntryItem*>; //string representing the text in the entryitem.
class Window : public QMainWindow {
	Q_OBJECT
public:
	Window(QWidget *parent = 0);
	~Window() = default;

private slots:
	void showSettings();
private:
	void setupGrid();
	DataEntries data;
	std::unique_ptr<Settings> settings = nullptr;
	std::shared_ptr<MapType> entry_items = nullptr;
	Ui::WindowClass ui;
};

#endif // WINDOW_H

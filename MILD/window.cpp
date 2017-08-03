#include <QAction>
#include <QVBoxLayout>
#include "window.h"
#include "entryitem.hpp"

Window::Window(QWidget *parent) : QMainWindow(parent), data(standard_entries) {
	settings = std::make_unique<Settings>();
	settings->hide();
	entry_items = std::make_shared<MapType>();
	ui.setupUi(this);

	setupGrid();
	
	connect(ui.actionSettings, &QAction::triggered, this, &Window::showSettings);
}

void Window::setupGrid() {
	vector<string> entries = data.returnEntries(settings->entry_count);
	QVBoxLayout* vLayout = new QVBoxLayout(ui.groupBox);
	for (int x = 0; x < entries.size(); x++) {
		EntryItem* item = new EntryItem(entry_items, this);
		item->setText(entries[x]);
		//entry_items->insert(std::pair<string, EntryItem*>(entries[x], item));
		vLayout->addWidget(item);
	}
	vLayout->addStretch(1);
	ui.groupBox->setLayout(vLayout);
}

void Window::showSettings() {
	settings->setModal(true);
	settings->show();
}
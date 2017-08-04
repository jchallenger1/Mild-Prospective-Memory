#include <memory>
#include <QIcon>
#include <QString>
#include "entryitem.hpp"
#include "Functions.hpp"

EntryItem::EntryItem(std::shared_ptr<MapType>& s,QWidget * parent) : map(s), QWidget(parent) {
	button = std::make_unique<QPushButton>(this);
	button->setIcon(QIcon(":/Images/Resources/Refresh icon.ico"));
	line = std::make_unique<QLineEdit>(this);
	line->setReadOnly(false);
	line->setText(QString::fromStdString(entry));
	QFont font;
	font.setPixelSize(14);
	line->setFont(font);
	layout = std::make_unique<QHBoxLayout>(this);
	layout->addWidget(button.get());
	layout->addWidget(line.get());
	this->setLayout(layout.get());
	connect(button.get(), &QPushButton::pressed, this, &EntryItem::refreshText);
}

void EntryItem::setData(std::shared_ptr<DataEntries>& ptr) {
	data = ptr;
}

void EntryItem::refreshText() {
	if (data == nullptr) {
		data = std::make_shared<DataEntries>(standard_entries);
	}
	string x = data->returnEntry();
	while ( x.empty() && map->find(x) != map->end() ) {
		x = data->returnEntry();
	}
	line->setText(QString::fromStdString(x));
	entry = x;
}

EntryItem& EntryItem::operator=(const std::string s) {
	entry = s;
	return *this;
}

std::string EntryItem::text() const {
	return entry;
}

void EntryItem::setText(const std::string& s) {
	entry.assign(s);
	line->setText(QString::fromStdString(entry));
}

string EntryItem::lineText() const {
	return line->text().toStdString();
}
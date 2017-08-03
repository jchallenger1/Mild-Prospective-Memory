#include <memory>
#include <QIcon>
#include <QString>
#include "entryitem.hpp"
using MapType = std::unordered_map<std::string, EntryItem*>; //string representing the text in the entryitem.
EntryItem::EntryItem(std::shared_ptr<MapType>& s,QWidget * parent) : map(s),QWidget(parent) {
	button = std::make_unique<QPushButton>(this);
	button->setIcon(QIcon(":/Images/Resources/Refresh icon.ico"));
	line = std::make_unique<QLineEdit>(this);
	line->setReadOnly(true);
	line->setText(QString::fromStdString(entry));
	QFont font;
	font.setPixelSize(14);
	line->setFont(font);
	layout = std::make_unique<QHBoxLayout>(this);
	layout->addWidget(button.get());
	layout->addWidget(line.get());
	this->setLayout(layout.get());
}

EntryItem & EntryItem::operator=(const std::string s) {
	entry = s;
	return *this;
}

std::string EntryItem::text() const {
	return entry;
}
std::string& EntryItem::rtext(){
	return entry;
}

void EntryItem::setText(const std::string& s) {
	entry.assign(s);
	line->setText(QString::fromStdString(entry));
}
#pragma once
#include <string>
#include <memory>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <unordered_map>
class EntryItem;
using MapType = std::unordered_map<std::string, EntryItem*>; //string representing the text in the entryitem.
class EntryItem : public QWidget {
	Q_OBJECT

public:
	EntryItem(std::shared_ptr<MapType>&,QWidget * parent = nullptr);
	EntryItem& operator=(const std::string s);
	std::string text() const;
	std::string& rtext();
	void setText(const std::string&);
private:
	std::shared_ptr<MapType> map = nullptr;
	std::unique_ptr<QPushButton> button = nullptr;
	std::unique_ptr<QLineEdit> line = nullptr;
	std::unique_ptr<QHBoxLayout> layout = nullptr;
	std::string entry;
};

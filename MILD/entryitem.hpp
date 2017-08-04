#pragma once
#include <string>
#include <memory>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <unordered_map>
#include "Functions.hpp"
#include "DataEntries.hpp"

class EntryItem : public QWidget {
	Q_OBJECT

public:
	EntryItem(std::shared_ptr<MapType>&,QWidget * parent = nullptr);
	EntryItem& operator=(const std::string s);
	std::string text() const;
	void setData(std::shared_ptr<DataEntries>&);
	void setText(const std::string&);
	string lineText() const;
private slots:
	void refreshText();
private:
	std::shared_ptr<DataEntries> data = nullptr;
	std::shared_ptr<MapType> map = nullptr; //associates all instances of entryItems.
	std::unique_ptr<QPushButton> button = nullptr;
	std::unique_ptr<QLineEdit> line = nullptr;
	std::unique_ptr<QHBoxLayout> layout = nullptr;
	std::string entry;
};

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "StandardEntries.hpp"
using std::string; using std::vector;

class DataEntries {
public:
	DataEntries() = delete;
	DataEntries(const std::array<const char*, sESize>& arr) : old_entries(arr) {};

	void addEntries(const std::vector<string>& vec);
	void addEntries(std::ifstream&);
	std::vector<string> returnEntries(const int& i) const;
	std::string returnEntry() const;
private:
	static std::string returnSingleEntry(const std::array<const char*, sESize>&, const std::vector<string>&);
	const std::array<const char*, sESize>& old_entries;
	std::vector<string> new_entries;
};


 
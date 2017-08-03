
#include "DataEntries.hpp"

#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
void DataEntries::addEntries(const std::vector<string>&vec) {
	new_entries.assign(vec.cbegin(), vec.cend());
}

void DataEntries::addEntries(std::ifstream& ifs) {
	std::vector<string> ent;
	std::string x;
	while (std::getline(std::cin, x)) {
		ent.push_back(x);
	}
	addEntries(ent);
}

std::string DataEntries::returnEntry() const {
	return returnSingleEntry(old_entries, new_entries);
}


std::string DataEntries::returnSingleEntry(const std::array<const char*, sESize>& olds, const std::vector<string>& news) {
	std::default_random_engine engine(time(0));
	std::uniform_int_distribution<int> roll(1, sESize + (news.empty() ? 0 : news.size()));
	std::string return_string;
	int rng = roll(engine);
	if (rng <= sESize) { //uses the old entries
		return_string = olds[rng - 1];
	}
	else { //uses the new entries
		return_string = news[rng - 1];
	}
	return return_string;
}

std::vector<string> DataEntries::returnEntries(const int& entry_count) const {
	std::vector<string> return_entry;
	while (return_entry.size() < entry_count) {
		string x = returnEntry();
		auto dup_iter = std::find(return_entry.cbegin(), return_entry.cend(), x);
		if (dup_iter == return_entry.cend()) {
			return_entry.emplace_back(x);
		}
	}
	return return_entry;
}
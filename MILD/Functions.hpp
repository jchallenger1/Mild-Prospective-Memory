
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "DataEntries.hpp"
using std::string; using std::vector; using std::cin; using std::cout; using std::endl;
#pragma once

auto yes_or_no = [](const char& c) {  return c == 'y' || c == 'n';   };
template<typename TI, typename F = std::function<bool()> >
TI check(const string& error_message, const string& message, F fx = std::function<bool()>([]()->bool {return true; })) {
	//checking inputs recieved, if the stream is good and if they match what characters were wanted.
	TI x;
	while (cin.good()) {
		cin >> x;
		if (cin.fail()) {
			if (!error_message.empty())
				cout << error_message << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else {//cin is in a good condition
			bool good = fx(x);
			if (good) {
				return x;
			}
			else {
				if (!message.empty())
					cout << message << endl;
				continue;
			}
		}

	}//while
	throw std::runtime_error("Did not recieve input from user");
	return TI();// return empty object if function fails
}

inline void outputEntries(const vector<string>& g) {
	cout << "Your Entries are : " << endl;
	std::ostream_iterator<string> os(cout, "\n");
	std::copy(g.cbegin(), g.cend(), os);
}

void runProgram() {
	vector<string> new_entries;
	DataEntries data(standard_entries);
	cout << "How many entries do you want provided? (4 is the standard)" << endl;
	int amount = check<int>("Only enter numbers", "Must be less than 20, greater than 0", [](const int& i) {
		return i > 0 && i <= 20;
	});
	cout << "Do you want to add new entries(y/n)?" << endl;
	char x = check<char>("Only enter a character", "Enter (y)es or (n)o", yes_or_no);
	if (x == 'y') {
		cout << "To add new Entries, have a text file with each entry separated by a newspace(enter key) and name it \"LDEntries.txt\" " << endl;
		do {
			std::ifstream ifs("LDEntries.txt");
			if (ifs) {
				string line;
				while (getline(ifs, line)) {
					new_entries.push_back(line);
				}
				data.addEntries(new_entries);
			}
			else {
				cout << "Error: Could not find file \"LDEntries.txt\", Try creating the file again in the same directory." << endl;
				cout << "Try again ? (y\n)" << endl;
				char again = check<char>("Only enter a character", "Enter (y)es or (n)o", yes_or_no);
				if (again == 'y')
					continue;
			}
		} while (false);

	}
	vector<string> y = data.returnEntries(amount);
	
	cout << "Make sure these entries are ok to use, (1) for good, (2) to reroll entries" << endl;
	while (true) {
		outputEntries(y);
		int n = check<int>("Only enter numbers", "Only enter 1 for good, 2 for bad", [](const int& i) {
			return i == 1 || i == 2;
		});
		if (n == 2) {
			y = data.returnEntries(amount);
		}
		else {
			break;
		}
	}
	auto g = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	char calendar[26];
	ctime_s(calendar, sizeof calendar, &g);
	std::ofstream ofs("LD.txt");
	ofs << "\t" << calendar;
	std::ostream_iterator<string> os(ofs, "\n");
	std::copy(y.cbegin(), y.cend(), os);
}


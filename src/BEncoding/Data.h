#pragma once
#include "EntryInfo.h"
#include <string>

using namespace std;

class Data : public EntryInfo {
public:
	
	Data(string str): m_str(str) {
	}

	~Data() {}

	/*
	int getAsInt() const {
		return strtol(m_str.c_str(), nullptr, 10);
	}
	*/

	string getAsString() const {
		return m_str;
	}

private:

	string m_str;

};

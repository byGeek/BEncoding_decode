#pragma once

#include "EntryInfo.h"
#include <map>
#include <string>

class Dictionary : public EntryInfo{
private:
	std::map<std::string, EntryInfo*> m_dic;

public:

	void put(std::string key, EntryInfo* info) {
		m_dic.emplace(key, info);
	}

	void remove(std::string key) {
		m_dic.erase(key);
	}
};

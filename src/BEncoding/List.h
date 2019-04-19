#pragma once

#include <vector>
#include "EntryInfo.h"
#include <string>

class List : public EntryInfo {
private:
	std::vector<EntryInfo*> m_v;

public:
	void put(EntryInfo* value) {
		m_v.push_back(value);
	}
};

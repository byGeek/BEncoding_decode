#pragma once

#include "EntryInfo.h"

class Number : public EntryInfo {
public:

	Number(int num) : m_value(num){

	}

	int getValue() const {
		return m_value;
	}

private:

	int m_value;
};

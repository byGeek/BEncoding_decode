#include <iostream>
#include <string>
#include "EntryInfo.h"
#include "Dictionary.h"
#include "List.h"
#include "Data.h"
#include "Number.h"

using namespace std;


EntryInfo* bencoding(string torrentString);
Data* parseWord(const char** pp);
EntryInfo* do_bencoding(const char** pp);
Dictionary* parseDictionary(const char** pp);
List* parseList(const char** pp);


 Dictionary* parseDictionary(const char** pp) {
	 Dictionary* dic = new Dictionary();
	 while (1) {
		 if (**pp == 'e') {
			 ++(*pp);
			 break;
		 }

		 Data* key = parseWord(pp);
		 auto entryInfo = do_bencoding(pp);
		 dic->put(key->getAsString(), entryInfo);
	 }
	 return dic;
}

List* parseList(const char** pp) {
	List* list = new List();
	while (1) {
		if (**pp == 'e') {
			++(*pp);
			break;
		}

		auto item = do_bencoding(pp);
		list->put(item);
	}


	return list;

}

Number* parseInt(const char** pp) {
	const char* ret = strchr(*pp, 'e');
	if (ret == NULL) {
		throw invalid_argument("can not find e in parseInt");
	}

	char* num = new char[ret - *pp + 1];
	memcpy_s(num, ret - *pp + 1, *pp, ret - *pp);
	num[ret - *pp] = '\0';

	int value = strtol(num, nullptr, 10);
	delete num;

	*pp = ret + 1;
	
	Number* number = new Number(value);
	return number;
}

Data* parseWord(const char** pp) {
	int ch = ':';
	const char* ret = strchr(*pp, ch);
	if (ret == NULL) {
		throw new invalid_argument("can not find : !");
	}
	char* num = new char[ret - *pp +1];
	memcpy_s(num, ret - *pp+1, *pp, ret - *pp);
	num[ret - *pp] = '\0';
	int len = strtol(num, nullptr, 10);
	delete num;
	char* str = new char[len+1];
	memcpy_s(str, len + 1, ret + 1, len);
	str[len] = '\0';
	*pp = ret + len + 1;
	
	Data* data = new Data(string(str));
	delete str;
	return data;
}

EntryInfo* bencoding(string torrentString) {
	try {
		const char* str = torrentString.c_str();
		auto entryInfo = do_bencoding(&str);
		return entryInfo;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		throw;
	}
}

EntryInfo* do_bencoding(const char** pp) {

	EntryInfo* ei = nullptr;
	switch (**pp)
	{
	case 'd':
		(*pp)++;
		ei = parseDictionary(pp);
		break;
	case 'l':
		(*pp)++;
		ei = parseList(pp);
		break;
	case 'i':
		(*pp)++;
		ei = parseInt(pp);
			break;
	default:
		ei = parseWord(pp);
		break;
	}

	return ei;
}


int main() {

	string str = "d8:announce39:http://torrent.ubuntu.com:6969/announce13:announce-listll39:http://torrent.ubuntu.com:6969/announceel44:http://ipv6.torrent.ubuntu.com:6969/announceee7:comment29:Ubuntu CD releases.ubuntu.com13:creation datei1519934077e4:infod6:lengthi1624211456e4:name32:ubuntu-16.04.4-desktop-amd64.iso12:piece lengthi524288e6:pieces20:aaaaaaaaaaaaaaaaaaaaee";
	auto data = bencoding(str);

	return 0;
}
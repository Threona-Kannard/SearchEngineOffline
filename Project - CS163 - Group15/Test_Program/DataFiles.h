#ifndef DATAFILES_H_
#define DATAFILES_H_

#include <algorithm>
#include "tst.h"

using namespace std;
class Forest : public TST
{
public:
	vector <TST> sourceTree;
	vector <pair<wstring,pair<int,bool>>> sourceName;
};
bool LoadData(const wchar_t* path, Forest& forest, locale loc);
bool LoadTXT(const wchar_t* path, Forest& forest, locale loc);
bool LoadSW(TST& sw, locale loc);
//bool SaveData(const char* path, TST& tree);
#endif
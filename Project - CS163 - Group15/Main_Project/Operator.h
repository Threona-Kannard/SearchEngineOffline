#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <sstream>
#include "DataFiles.h"
//Tan------------------------------------------------------------------------
wstring deleteSW(TST& sw, wstring& str, locale loc);
wstring prop(wstring& go);

const wchar_t* StringToWch(wstring input);

class Operator : public Forest
{
public:
//Phat-----------------------------------------------------------------------
	bool checkAnd(wstring str);
	void OperatorAnd(wstring str,vector<int>&result, locale loc);

	bool checkOr(wstring str);
	void OperatorOr(wstring str, vector<int>&result, locale loc);
	vector<int> PreSearch(wstring str, locale loc);
	void NormalSearch(wstring str, locale loc, vector<int>& result);
//Huy------------------------------------------------------------------------
	bool checkfiletype(wstring str);
	void Filetype(wstring str, locale loc, vector <int>& result);

	bool checkintitle(wstring str);
	void Intitle(wstring str, locale loc, vector <int>& result);
//Khang----------------------------------------------------------------------
	int checkRange(wstring str);
	void transver(Node* node, vector<wstring>& count, wstring& out);
	bool findranged(Node* node, pair<int, int> range);
	bool find$(Node* node, pair<int, int> range);

	void priceSearch(wstring patt, vector<int>& result);
	void priceRangedSearch(wstring patt, vector<int>& result);
	void rangedSearch(wstring patt, vector<int>& result);
//Tan-------------------------------------------------------------------------
	bool checksynomyms(wstring str);
	void synonyms(vector <int>& result, wstring str, locale loc);
	void exactmatch(vector <int>& result, wstring str, locale loc);
	void plus(vector <int>& result, wstring str, locale loc);
	bool checkexactmatch(wstring str, locale loc);
	bool checkeplus(wstring str, locale loc);
};
#endif
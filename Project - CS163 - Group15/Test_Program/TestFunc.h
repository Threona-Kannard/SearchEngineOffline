#ifndef TestFunc_H
#define TestFunc_H

#include <sstream>
#include "DataFiles.h"

wstring deleteSW(TST& sw, wstring& str, locale loc);

const wchar_t* StringToWch(wstring input);

bool checkAnd(wstring str);
void OperatorAnd(wstring str);

bool checkOr(wstring str);
void OperatorOr(wstring str);

#endif
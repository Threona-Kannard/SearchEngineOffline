#include "TestFunc.h" 

wstring deleteSW(TST& sw, wstring& str,locale loc)
{
	wstring temp = L"";
	wistringstream ss(str);
	ss.imbue(loc);
	do
	{
		wstring word;
		ss >> word;
		if (!sw.search(word)) temp = temp + word + L" ";
	} while (ss);
	return temp;
}

const wchar_t* StringToWch(wstring input)
{
	if (input.length() == 0)
		return nullptr;
	const wchar_t* ch = const_cast<wchar_t*>(input.c_str());
	return ch;
}

bool checkAnd(wstring str)
{
	wchar_t substr[6] = L" AND ";
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, substr);
	if (check)
		return true;
	else
		return false;
}

void OperatorAnd(wstring str)
{
	wstring substr = L" AND ";
	if (checkAnd(str))
	{
		size_t check = str.find(substr);
		if (check == 0)
		{
			wstring str2 = str;
			str2.erase(0, check+5);
			//Search(str2)==true return txt
		}
		else
		{ 
			if (check == str[str.length() - 1])
			{
				wstring str2 = str;
				str2.erase(check);
				//return when search(str2)==true
			}
			else
			{
				wstring str2 = str;
				str2.erase(check);
				wstring str3 = str;
				str3.erase(0, check + 5);
				//Return when search(str2)==true && search(str3)==true;
			}
		}
	}
}

bool checkOr(wstring str)
{
	wchar_t substr[5] = L" OR ";
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, substr);
	if (check)
		return true;
	else
		return false;
}

void OperatorOr(wstring str)
{
	wstring substr = L" OR ";
	if (checkOr)
	{
		size_t check = str.find(substr);
		if (check == 0)
		{
			wstring str2 = str;
			str2.erase(0, check + 4);
			//return when search(str2)==true
		}
		else
		{
			if (check == str[str.length() - 1])
			{
				wstring str2 = str;
				str2.erase(check);
				////return when search(str2)==true
			}
			else
			{
				wstring str2 = str;
				str2.erase(check);
				wstring str3 = str;
				str3.erase(0, check + 4);
				//Return when search(str2)||true && search(str3)==true;
			}
		}
	}
}



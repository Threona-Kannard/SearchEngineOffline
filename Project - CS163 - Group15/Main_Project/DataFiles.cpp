#include "DataFiles.h"

bool Forest::LoadData(const wchar_t* path, locale loc)
{
	wifstream finn;
	finn.open(path);
	if (!finn.is_open())
		return false;
	//fin.imbue(loc);
	TST tree;
	while (!finn.eof())
	{
		wstring str;
		finn >> str;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		
		if (str != L"")
		{
			while (str[0] == L'"' || str[0] == L'\'')
				str.erase(0, 1);
			int k = str.length() - 1;
			if (str != L"")
			{
				while ((str[k] == L'.'
					|| str[k] == L','
					|| str[k] == L';'
					|| str[k] == L'!'
					|| str[k] == L'?'
					|| str[k] == L':'
					|| str[k] == L'"') && k > 0)
				{
					str.erase(k);
					k--;
				}
			}
			if (str != L"") tree.insertToTree(str);
		}
	}
	sourceTree.push_back(tree);
	finn.close();
	return true;
}

bool Forest::LoadTXT(const wchar_t* path, locale loc)
{

	wifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	fin.imbue(loc);
	for (int i = 0; i < 11268; i++)
	{
		wchar_t ID[10000] = L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/";
		wchar_t* ch = new wchar_t[100];
		fin.get(ch, 100, '\n');
		wcscat_s(ID, ch);
		fin.ignore(100, '\n');
		bool ans = LoadData(ID, loc);
		if (ans)
		{
			sourceName.push_back(make_pair(ch,0));
		}
		delete[]ch;
	}
	fin.close();
	return true;
}

bool LoadSW(TST& sw, locale loc)
{
	wifstream swfin;
	swfin.open("D:/Johan/Homework/Project CS163/Project - CS163 - Group15/Main_Project/Stopword.txt");
	if (!swfin.is_open()) return false;
	swfin.imbue(loc);
	while (!swfin.eof())
	{
		wstring str;
		swfin >> str;
		sw.insertToTree(str);
	}
	swfin.close();
	return true;
}
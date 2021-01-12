#include "DataFiles.h"

bool LoadData(const wchar_t* path,Forest& forest,locale loc)
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
		/*if (str != L"")
		{
			size_t k = str.length() - 1;
			if (str[0] == L'"')
				str.erase(0, 1);
			while (str[k] == L'.'
				|| str[k] == L','
				|| str[k] == L';'
				|| str[k] == L'!'
				|| str[k] == L'?'
				|| str[k] == L':'
				|| str[k] == L'"')
			{
				str.erase(k);
				k--;
			}
		}*/
		if (str != L"") tree.insertToTree(str);
	}
	forest.sourceTree.push_back(tree);
	finn.close();
	return true;
}

bool LoadTXT(const wchar_t* path,Forest& forest, locale loc)
{
	
	wifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	fin.imbue(loc);
	for(int i=0;i<11268;i++)
	{
		wchar_t ID[10000] = L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/";
		wchar_t* ch=new wchar_t[100];
		fin.get(ch, 100, '\n');
		wcscat_s(ID, ch);
		fin.ignore(100, '\n');
		bool ans = LoadData(ID,forest, loc);
		if (ans)
		{
			forest.sourceName.push_back(make_pair(ch,make_pair(0,false)));
		}
		delete[]ch;
	}
	fin.close();
	return true;
}

bool LoadSW(TST& sw, locale loc)
{
	wifstream swfin;
	swfin.open("D:/Johan/Homework/Project CS163/Project - CS163 - Group15/Test_Program/Stopword.txt");
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
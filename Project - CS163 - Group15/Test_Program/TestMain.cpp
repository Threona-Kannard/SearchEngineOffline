#include "TestFunc.h"

using namespace std;

int main() {
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	locale loc(locale(), new codecvt_utf8<wchar_t>);
		/*TST sw;
		LoadSW(sw, loc);
		wstring str = L"Tan and Khang AND Phat act America ACT HuyLam";
		wcout << str << endl;
		str = deleteSW(sw, str, loc);
		wcout << str << endl;*/
		Forest forest;
		LoadTXT(L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/___index.txt",forest,loc);
		std::wstring searchtest = L"GALÁPAGOS";
		int result = forest.sourceName.size();
		wcout << result << endl;
		int answer = forest.sourceTree.size();
		wcout << answer << endl;
		/*for (auto i=forest.sourceTree.begin();i!=forest.sourceTree.end();++i)
		{
			tree = *i;
			if (tree.search(searchtest))
				std::wcout << L"YES" << endl;
		}*/
		system("pause");
		return 0;
	}
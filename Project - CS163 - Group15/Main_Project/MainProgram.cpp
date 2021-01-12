#include "Display.h"

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
	/*Forest forest;
	forest.LoadTXT(L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/___index.txt", loc);
	std::wstring searchtest = L"GALÁPAGOS";
	int result = forest.sourceName.size();
	wcout << result << endl;
	int answer = forest.sourceTree.size();
	wcout << answer << endl;*/
	Operator MAIN;
	TextColorSet(15);
	Intialize(MAIN, loc);
	system("cls");
	int a;
	do
	{
		gotoxy(15, 12);
		PrintLogo1(15,12);
		gotoxy(26, 19);
		wstring str;
		wcin >> str;
		vector<int>result = MAIN.PreSearch(str, loc);
		PrintResult(MAIN, result, loc);
		wcout << "Press any key to continue and Backspace to stop.";
		a = _getch();
		system("cls");
	} while (a!=8);
	/*for (auto i=forest.sourceTree.begin();i!=forest.sourceTree.end();++i)
	{
		tree = *i;
		if (tree.search(searchtest))
			std::wcout << L"YES" << endl;
	}*/
	system("pause");
	return 0;
}
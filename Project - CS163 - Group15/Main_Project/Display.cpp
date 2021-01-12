#include "Display.h"

void PrintLogo1(int x, int y)
{
  /*string str = "    _   ____                      ____             ___   ___             "
		         "   / | / / /_  __  ______  ____ _/ __ \____ _____ |__ \ /   |   __    __ "
		         "  /  |/ / __ \/ / / / __ \/ __ `/ / / / __ `/ __ \__/ // /| |__/ /___/ /_"
		         " / /|  / / / / /_/ / / / / /_/ / /_/ / /_/ / /_/ / __// ___ /_  __/_  __/"
		         "/_/ |_/_/ /_/\__,_/_/ /_/\__, /_____/\__,_/\____/____/_/  |_|/_/   /_/   "
	             "                        /____/                                           ";*/
	TextColorSet(12);
	wcout << L"    _   ____                     ";
	TextColorSet(13);
	wcout << L" ____            ";
	TextColorSet(14);
	wcout << L" ___   ___             ";
	wcout << endl;
	y++;
	gotoxy(x, y);
	TextColorSet(12);
	wcout << L"   / | / / /_  __  ______  ____ _";
	TextColorSet(13);
	wcout << L"/ __ \\____ _____ ";
	TextColorSet(14);
	wcout << L"|__ \\ /   |   __    __ ";
	wcout << endl;
	y++;
	gotoxy(x, y);
	TextColorSet(12);
	wcout << L"  /  |/ / __ \\/ / / / __ \\/ __ `";
	TextColorSet(13);
	wcout << L"/ / / / __ `/ __ \\";
	TextColorSet(14);
	wcout << L"__/ // /| |__/ /___/ /_";
	wcout << endl;
	y++;
	gotoxy(x, y);
	TextColorSet(12);
	wcout << L" / /|  / / / / /_/ / / / / /_/ ";
	TextColorSet(13);
	wcout << L"/ /_/ / /_/ / /_/ /";
	TextColorSet(14);
	wcout << L" __// ___ /_  __/_  __/";
	wcout << endl;
	y++;
	gotoxy(x, y);
	TextColorSet(12);
	wcout << L"/_/ |_/_/ /_/\\__,_/_/ /_/\\__, ";
	TextColorSet(13);
	wcout << L"/_____/\\__,_/\\____/";
	TextColorSet(14);
	wcout << L"____/_/  |_|/_/   /_/   ";
	wcout << endl;
	TextColorSet(12);
	y++;
	gotoxy(x, y);
	wcout << L"                        /____/                                           ";
	wcout << endl;
	y++;
	gotoxy(x+10, y);
	TextColorSet(15);
	SearchBoard(x+10, y);
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}

void TextColorSet(int x)
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void SearchBoard(int x, int y)
{
	wcout << L"˹";
	for (int i = 0; i < 50; i++)
	{
		wcout << L"̅";
	}
	wcout << L"˺"; 
	wcout << endl;
	y++;
	gotoxy(x, y);
	wcout << L"|";
	for (int i = 0; i < 50; i++)
	{
		wcout << L" ";
	}
	wcout << L"|";
	wcout << endl;
	y++;
	gotoxy(x, y);
	wcout << L"˻";
	for (int i = 0; i < 50; i++)
	{
		wcout << L"̲";
	}
	wcout << L"˼" << endl;
}

void Intialize(Operator &MAIN, locale loc)
{
	wstring mess = L"                                           Loading...........\n";
	wcout << mess << flush;
	time_t start = time(&start);
	while (difftime(time(NULL), start) < 60/*seconds*/)
	{
		MAIN.LoadTXT(L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/___index.txt", loc);
	}
	wcout << "\r" << wstring(mess.length(), ' ') << "\r" << flush;
}

void PrintResult(Operator MAIN, vector<int> result, locale loc)
{
	system("cls");
	if (result.size() == 0 || result.size()==11268)
	{
		TextColorSet(240);
		wcout << L"                                             Cannot find." << endl;
	}
	int i = result.size();
	if (i > 5)
		i = 5;
	int j = 0;
	while(j<i)
	{
		const wchar_t* ch = StringToWch(MAIN.sourceName[result[i]].first);
		TextColorSet(240);
		wcout << j + 1<< L". " << MAIN.sourceName[result[j]].first << endl;
		TextColorSet(15);
		j++;
	}
	wcout << L"Select your choice(0 to out): "; 
	int a;
	gotoxy(31, 4);
	cin >> a;
	while (a > 5 && a!=0)
	{
			wcout << L"Please choose again: ";
			cin >> a ;
	}
	
	wifstream tan;
	wchar_t ID[10000] = L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/";
	const wchar_t* ch = StringToWch(MAIN.sourceName[result[a]].first);
	wcscat_s(ID, ch);
	tan.open(ID);
	tan.imbue(loc);
	while (!tan.eof())
	{
		wstring strsec;
		getline(tan, strsec);
		wcout << strsec << endl;
	}
	tan.close();
	wcout << "Press any key to go back to start screen.";
	_getch();
	system("cls");
	return;
}

//void ControlCursor(int x, int y)
//{
//	HANDLE hConsoleOutput;
//	COORD Cursor_an_Pos;
//	
//	Cursor_an_Pos.X = x;
//	Cursor_an_Pos.Y = y;
//
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
//	while (true)
//	{
//
//	}
//}
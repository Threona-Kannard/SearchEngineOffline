#include "Operator.h" 

wstring deleteSW(TST& sw, wstring& str, locale loc)
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

bool Operator::checkAnd(wstring str)
{
	wchar_t substr[6] = L" AND ";
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, substr);
	if (check)
		return true;
	else
		return false;
}

void Operator::OperatorAnd(wstring str,vector <int>&result, locale loc)
{
	wstring substr = L" AND ";
		size_t check = str.find(substr);
		if (check == 0)
		{
			wstring str2 = str;
			str2.erase(0, check + 5);
			//Search(str2)==true return txt
			wistringstream ss(str2);
			ss.imbue(loc);
			do
			{
				wstring word;
				ss >> word;
				if (word != L"")
				{
					int i = 0;
					while (i < result.size())
					{
						if (!sourceTree[result[i]].search(word))
						{
							result.erase(result.begin() + i);
							i--;
							break;
						}
						i++;
					}
				}
			} while (ss);
		}
		else
		{
			if (check == str[str.length() - 1])
			{
				wstring str2 = str;
				str2.erase(check);
				//return when search(str2)==true
				wistringstream ss(str2);
				ss.imbue(loc);
				do
				{
					wstring word;
					ss >> word;
					if (word != L"")
					{
						int i = 0;
						while (i < result.size())
						{
							if (!sourceTree[result[i]].search(word))
							{
								result.erase(result.begin() + i);
								i--;
								break;
							}
							i++;
						}
					}
				} while (ss);
			}
			else
			{
				wstring str2 = str;
				str2.erase(check);
				wstring str3 = str;
				str3.erase(0, check + 5);
				//Return when search(str2)==true && search(str3)==true;
				wistringstream ss(str2);
				ss.imbue(loc);
				do
				{
					wstring word;
					ss >> word;
					if (word != L"")
					{
						int i = 0;
						while (i < result.size())
						{
							if (!sourceTree[result[i]].search(word))
							{
								result.erase(result.begin() + i);
								i--;
								break;
							}
							i++;
						}
					}
				} while (ss);
				wistringstream st(str3);
				st.imbue(loc);
				do
				{
					wstring word;
					st >> word;
					if (word != L"")
					{
						int i = 0;
						while (i < result.size())
						{
							if (!sourceTree[result[i]].search(word))
							{
								result.erase(result.begin() + i);
								i--;
								break;
							}
							i++;
						}
					}
				} while (st);
			}
		}
}

bool Operator::checkOr(wstring str)
{
	wchar_t substr[5] = L" OR ";
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, substr);
	if (check)
		return true;
	else
		return false;
}

void Operator::OperatorOr(wstring str, vector<int>&result, locale loc)
{
	wstring substr = L" OR ";
		size_t check = str.find(substr);
		if (check == 0)
		{
			wstring str2 = str;
			str2.erase(0, check + 4);
			//return when search(str2)==true
			wistringstream ss(str2);
			ss.imbue(loc);
			do
			{
				wstring word;
				ss >> word;
				if (word != L"")
				{
					int i = 0;
					while (i < result.size())
					{
						if (!sourceTree[result[i]].search(word))
						{
							result.erase(result.begin() + i);
							i--;
							break;
						}
						i++;
					}
				}
			} while (ss);
		}
		else
		{
			if (check == str[str.length() - 1])
			{
				wstring str2 = str;
				str2.erase(check);
				////return when search(str2)==true
				wistringstream ss(str2);
				ss.imbue(loc);
				do
				{
					wstring word;
					ss >> word;
					if (word != L"")
					{
						int i = 0;
						while (i < result.size())
						{
							if (!sourceTree[result[i]].search(word))
							{
								result.erase(result.begin() + i);
								i--;
								break;
							}
							i++;
						}
					}
				} while (ss);
			}
			else
			{
				wstring str2 = str;
				str2.erase(check);
				wstring str3 = str;
				str3.erase(0, check + 4);
				//Return when search(str2)||true && search(str3)==true;
				int i = 0;
				while (i < result.size())
				{
					wistringstream ss(str2);
					ss.imbue(loc);
					bool check1 = true;
					bool check2 = true;
					do
					{
						wstring word;
						ss >> word;
						if (word != L"")
						{
							bool ans = sourceTree[result[i]].search(word);
							if (!ans)
								check1 = false;
						}
					} while (ss);
					wistringstream st(str3);
					st.imbue(loc);
					do
					{
						wstring word;
						st >> word;
						if (word != L"")
						{
							bool ans = sourceTree[result[i]].search(word);
							if (!ans)
								check2 = false;
						}
					} while (st);
					if (!check1 && !check2)
					{
						result.erase(result.begin() + i);
						i--;
					}
					i++;
				}
			}
		}
}

vector<int> Operator::PreSearch(wstring str, locale loc)
{
	vector<int>result;
	for (int i = 0; i < 11268; i++)
	{
		result.push_back(i);
	}
	if (checkintitle(str))
	{
		Intitle(str, loc, result);
		return result;
	}
	else
	{
		if (checkfiletype(str))
		{
			Filetype(str, loc, result);
			return result;
		}
		else
		{
			if (checksynomyms(str))
			{
				synonyms(result, str, loc);
				return result;
			}
			else
			{
				if (checkexactmatch(str,loc))
				{
					exactmatch(result, str, loc);
					return result;
				}
				else
				{
					if (checkAnd(str))
					{
						OperatorAnd(str, result, loc);
					}
					else
					{
						if (checkOr(str))
							OperatorOr(str, result, loc);
						else
						{
							if (checkeplus(str,loc))
								plus(result, str, loc);
							else
							{
								NormalSearch(str, loc, result);
							}
						}
					}
				}
			}
		}
	}
	return result;
}
void Operator::NormalSearch(wstring str, locale loc, vector<int>&result)
{
	
	wistringstream ss(str);
	ss.imbue(loc);
	do
	{
		wstring word;
		ss >> word;
		if (word != L"")
		{
			int i = 0;
			while (i < result.size())
			{
				if (!sourceTree[result[i]].search(word))
				{
					result.erase(result.begin() + i);
					i--;
					break;
				}
				i++;
			}
		}
	} while (ss);
}

bool Operator::checkintitle(wstring str)
{
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, L"intitle:");
	if (check)
		return true;
	else
		return false;
}

void Operator::Intitle(wstring str, locale loc, vector <int>& result)
{

		size_t start = str.find(L"intitle:");
		if (start != 0 && str[start + 9] == L' ')
			return;
		else
		{
			wstring struse;
			int j = 0;
			for (int i = start + 9; str[i] != L' '; i++)
			{
				struse[j] = str[i];
				j++;
			}
			int i = 0;
			while (i < result.size())
			{
				if (!sourceTree[result[i]].search(struse))
				{
					result.erase(result.begin() + i);
					i--;
					break;
				}
				i++;
			}
			//access tree find struse
			//vector ans

			i = 0;
			while (i < result.size())
			{
				wifstream finn;
				wchar_t ID[10000] = L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/";
				const wchar_t* chr = StringToWch(sourceName[result[i]].first);
				wcscat_s(ID, chr);
				finn.open(ID);
				finn.imbue(loc);
				wchar_t* placeholder = new wchar_t[1000];
				finn.get(placeholder, 1000, '\n');
				const wchar_t* check = wcsstr(placeholder, StringToWch(struse));
				if (!check)
				{
					result.erase(result.begin() + i);
					break;
				}
				else i++;
				finn.close();
			}
		}	
}

bool Operator::checkfiletype(wstring str)
{
	const wchar_t* ch = StringToWch(str);
	const wchar_t* check = wcsstr(ch, L"filetype:");
	if (check)
		return true;
	else
		return false;
}

void Operator::Filetype(wstring str, locale loc, vector <int>& result)
{
		size_t start = str.find(L"filetype:");
		if (str[start + 10] == L' ')
			return;
		else
		{
			wstring struse;
			int j = 0;
			for (int i = start + 10; str[i] != L' '; i++)
			{
				struse[j] = str[i];
				j++;
			}

			//find type in sourname
			int i = 0;
			while (i < result.size())
			{
				wstring tree = sourceName[result[i]].first;
				if (!wcsstr(StringToWch(tree), StringToWch(struse)))
					result.erase(result.begin() + i);
				else i++;
			}
		}
}

int Operator::checkRange(wstring str)
{
	const wchar_t* pos$ = wcsstr(StringToWch(str), L"$");
	const wchar_t* posDotDot = wcsstr(StringToWch(str), L"..");
	if (pos$ && posDotDot)
		return 0;
	else if (pos$)
		return 1;
	else if (posDotDot)
		return 2;
	return -1;
}

//help to get the string after $------
void Operator::transver(Node* node, vector<wstring>& count, wstring& out) {
	if (node) {
		transver(node->left, count, out);
		out.push_back(node->data);
		if (node->bEOS)
			count.push_back(out);
		transver(node->eq, count, out);
		out.pop_back();
		transver(node->right, count, out);
	}
}

bool Operator::findranged(Node* node, pair<int, int> range) {
	//note int range in wchar_t is 48->57
	vector<wstring> count;
	wstring tmp;
	transver(node, count, tmp);
	for (int i = 0; i < count.size(); i++) {
		tmp = count[i];
		for (int j = 0; j < tmp.size(); j++)
			if (tmp[j] < '0' || tmp[j] >'9')
				continue;
		if (stoi(tmp) >= range.first && stoi(tmp) <= range.second)
			return true;
	}
	return false;
}

bool Operator::find$(Node* node, pair<int, int> range) {
	while (node->data != '$' && node != nullptr) {
		if ('$' < node->data)
			node = node->left;
		else if ('$' > node->data)
			node = node->right;
		else
			node = node->eq;
	}
	if (node == nullptr)
		return false;
	vector<wstring> count;
	for (int i = 0; i < 2; i++) {
		wstring tmp;
		if (i == 0)
			transver(node->left, count, tmp);
		if (i == 1)
			transver(node->right, count, tmp);
		if (i == 2)
			transver(node->eq, count, tmp);
	}
	bool ans = false;
	for (int i = 0; i < count.size(); i++) {
		int value = stoi(count[i]);
		if (value >= range.first && value <= range.second)
			ans = true;
	}
	return ans;
}
//--------------------------------------------------------

void Operator::priceSearch(wstring patt, vector<int>& result) {
	if (patt.length()==0)
		return;
	wstring price = to_wstring(stoi(patt));
	for (int i = 0; i < result.size(); i++) {
		if (sourceTree[result[i]].search(patt)
			|| (sourceTree[result[i]].search(price)
				&& (sourceTree[result[i]].search(L"price")
					|| sourceTree[result[i]].search(L"prices")
					|| sourceTree[result[i]].search(L"dollar")
					|| sourceTree[result[i]].search(L"dollars")
					)
				)
			)
			continue;
		result.erase(result.begin() + i);
		i--;
	}
}

void Operator::priceRangedSearch(wstring patt, vector<int>& result) {
	if (patt.length()==0)
		return;
	int pos = patt.find_first_of('..');
	int tpos = pos - 1;
	wstring str1 = patt.substr(1, tpos);
	tpos = pos + 3;
	wstring str2 = patt.substr(tpos);
	for (int i = 0; i < result.size(); i++) {
		if (find$(sourceTree[result[i]].getTree(), make_pair(stoi(str1), stoi(str2))))
			continue;
		result.erase(result.begin() + i);
		i--;
	}
}

void Operator::rangedSearch(wstring patt, vector<int>& result) {
	if (patt.length()==0)
		return;
	int pos = patt.find_first_of('..');
	int tpos = pos;
	wstring str1 = patt.substr(1, tpos);
	tpos = pos + 2;
	wstring str2 = patt.substr(tpos);
	int lowBound = stoi(str1);
	int upBound = stoi(str2);
	for (int i = 0; i < result.size(); i++) {
		if (findranged(sourceTree[result[i]].getTree(), make_pair(lowBound, upBound)))
			continue;
		result.erase(result.begin() + i);
		i--;
	}
}

bool Operator::checksynomyms(wstring str)
{
	const wchar_t* check=wcsstr(StringToWch(str), L"~");
	if (check)
		return true;
	else
		return false;
}

void Operator::synonyms(vector <int>& result, wstring str, locale loc)
{
	size_t k = str.find(L"~");
	if (k != 0)
		return;
	str.erase(0, 1);
	size_t l = str.find_first_of(L" ");
	str.erase(str.begin()+l, str.end());
	vector <wstring> syms;
	syms.push_back(str);

	wifstream dic;
	dic.open("D:/Johan/Homework/Project CS163/Project - CS163 - Group15/Main_Project/Dictionary.txt");
	if (!dic.is_open()) return;
	dic.imbue(loc);
	while (!dic.eof())
	{
		wstring go;
		dic >> go;
		if (go[0] == L'-')
		{
			go.erase(0, 1);
			if (go == syms[0])
			{
				while (go != L".")
				{
					dic >> go;
					if (go != L".") syms.push_back(go);
				}
				break;
			}
		}
	}
	if (syms.size() == 1) return;
	dic.close();

	int i = 0;
	while (i < result.size())
	{
		int count = 0;
		for (int j = 0; j < syms.size(); j++)
		{
			if (sourceTree[result[i]].search(syms[j])) break;
			else count++;
		}
		if (count == syms.size()) result.erase(result.begin() + i);
		else i++;
	}
}

wstring prop(wstring& go)
{
	std::transform(go.begin(), go.end(), go.begin(), ::tolower);
	if (go != L"")
	{
		while (go[0] == L'"' || go[0] == L'\'')
			go.erase(0, 1);
		int k = go.length() - 1;
		if (go != L"")
		{
			while ((go[k] == L'.'
				|| go[k] == L','
				|| go[k] == L';'
				|| go[k] == L'!'
				|| go[k] == L'?'
				|| go[k] == L':'
				|| go[k] == L'"') && k > 0)
			{
				go.erase(k);
				k--;
			}
		}
	}
	return go;
}

void Operator::exactmatch(vector <int>& result, wstring str, locale loc)
{
	vector <wstring> ex;
	wistringstream sss(str);
	sss.imbue(loc);
	do
	{
		wstring word;
		sss >> word;
		if (word[0] == L'"' && word[word.length() - 1] == L'"')
		{
			word.erase(0, 1);
			word.pop_back();
			ex.push_back(word);
			break;
		}
		else if (word[0] == L'"')
		{
			word.erase(0, 1);
			ex.push_back(word);
			while (1)
			{
				sss >> word;
				if (word[word.length() - 1] == L'"')
				{
					word.pop_back();
					ex.push_back(word);
					break;
				}
				else ex.push_back(word);
			}
			break;
		}
	} while (sss);

	int i = 0;
	while (i < result.size())
	{
		for (int j = 0; j < ex.size(); j++)
		{
			if (!sourceTree[result[i]].search(ex[j]))
			{
				result.erase(result.begin() + i);
				i--;
				break;
			}
		}
		i++;
	}

	i = 0;
	while (i < result.size())
	{
		wchar_t ID[10000] = L"D:/Johan/Homework/Project CS163/Data files/Search Engine-Data/Search Engine-Data/";
		const wchar_t* ch = StringToWch(sourceName[result[i]].first);
		wcscat_s(ID, ch);
		wifstream fin;
		fin.open(ID);
		if (!fin.is_open()) return;
		fin.imbue(loc);
		bool check = false;
		while (!fin.eof())
		{
			wstring go;
			fin >> go;
			go = prop(go);
			if (go == ex[0])
			{
				int count = 1;
				for (int j = 1; j < ex.size(); j++)
				{
					fin >> go;
					go = prop(go);
					if (go != L"" && go != ex[j]) break;
					else count++;
				}
				if (count == ex.size())
				{
					check = true;
					break;
				}
			}
		}
		if (!check)
		{
			result.erase(result.begin() + i);
			i--;
		}
		fin.close();
		i++;
	}
}

void Operator::plus(vector <int>& result, wstring str, locale loc)
{
	size_t start = str.find(L'+');
	if (str[start + 1] == L' ')
		return;
	else
	{
		wstring use;
		for (int i = start + 1; i < str.length(); i++)
		{
			if (i == str.length() - 1 || str[i] == L' ')
				use = str.substr(0, i + 1);
		}
		use.erase(start, 1);
		use = L'"' + use;
		use.push_back('"');
		exactmatch(result, use, loc);
	}
}

bool Operator::checkexactmatch(wstring str, locale loc)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '"') ++count;
	if (count == 2) return true;
}

bool Operator::checkeplus(wstring str, locale loc)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '+') return true;
}


#ifndef TST_H
#define TST_H

#include <vector>
#include <iostream>
#include <fcntl.h>
#include <iomanip>
#include <fstream>
#include <io.h>
#include <locale>
#include <codecvt>
#include <string>
#include <Windows.h>
#include <wchar.h>
#include <utility>

typedef struct TSTNode {
	wchar_t data;
	bool bEOS; //boolean End Of String
	TSTNode* left;
	TSTNode* eq;
	TSTNode* right;
}Node;

Node* insert(Node*& root, const wchar_t* data);

class TST {
protected:
	Node* node;
	const wchar_t* data;
public:
	TST();
	~TST();
	const wchar_t* StrtoChar(std::wstring& input); //convert wstring to wchar
	void printAll(); //print all nodes
	bool search(std::wstring pattern);
	int MaxLen();
	void insertToTree(std::wstring goin);
	Node* getTree();
};
#endif

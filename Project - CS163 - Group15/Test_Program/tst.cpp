#include"tst.h"

TST::TST() {
	this->data = new wchar_t;
	this->node = nullptr;
}

TST::~TST() {
}

const wchar_t* TST::StrtoChar(std::wstring &input) {
	if(input.length() == 0)
		return nullptr;
	const wchar_t* ch = const_cast<wchar_t*>(input.c_str());
	return ch;
}
//create a new Tree Node
Node* newNode(wchar_t data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->bEOS = false;
	temp->left = temp->eq = temp->right = nullptr;
	return temp;
}

Node* insert(Node*& root, const wchar_t* data) {
	if (data == nullptr)
		return nullptr;
	if (!root) {
		root = newNode(*data);
	}
	if (*data < root->data)
		root->left = insert(root->left, data);
	else if (*data == root->data) {
		if (*(data + 1)) //check if the next character is not null, if null this is end of word, if not, it is eq.
			root->eq = insert(root->eq, data + 1);
		else
			root->bEOS = true;
	}
	else
		root->right = insert(root->right, data);
	return root;
}

bool TST::search(std::wstring pattern) {
	const wchar_t* patt = StrtoChar(pattern);
	if (patt == nullptr) return false;
	Node* root = this->node;
	while (root) {
		if (*patt < root->data)
			root = root->left;
		else if (*patt == root->data) {
			if (root->bEOS
				&& *(patt + 1) == '\0')
				return true;
			patt++;
			root = root->eq;
		}
		else
			root = root->right;
	}
	return false;
}

void TST::insertToTree(std::wstring goin) {
		this->node = insert(this->node, StrtoChar(goin));
}

Node* TST::getTree()
{
	return this->node;
}

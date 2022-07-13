#include <iostream>
#include "BinTree.h"
using namespace std;

typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;


Menu SelectMenu(void)
{
	int ch;
	do {
		printf("[1]ADD [2]DELETE [3]SEARCH [4]PRINT [0]EXIT => ");
		cin >> ch;
	} while (ch <TERMINATE || ch >PRINT);
	return (Menu)ch;
}


int main(void)
{
	Menu menu;
	BinNode* root = NULL;
	cout << "\n===================================================\n\n";

	do {

		Member x;
		BinNode* temp;
		switch (menu = SelectMenu()) {
		case ADD:
			cout << "\n/------- ADD -------/\n";
			cout << "\n이름 : ";
			cin >> x.name;
			cout << "\n번호 : ";
			cin >> x.num;
			root = Add(root, &x);
			cout << "\n===================================================\n\n";
			break;

		case REMOVE:
			cout << "\n/------- REMOVE -------/\n";
			cout << "\n이름 : ";
			cin >> x.name;
			cout << "\n번호 : ";
			cin >> x.num;
			Remove(&root, &x);
			cout << "\n===================================================\n\n";
			break;

		case SEARCH:
			cout << "\n/------- SEARCH -------/\n";
			cout << "\n이름 : ";
			cin >> x.name;
			cout << "\n번호 : ";
			cin >> x.num;
			if ((temp = Search(root, &x)) != NULL)
			{
				cout << "검색결과 : 존재!  " << temp->data.name << "  " << temp->data.num;
			}
			cout << "\n===================================================\n\n";
			break;

		case PRINT:
			cout << "\n/------- PRINT -------/\n";
			PrintTree(root);
			cout << "===================================================\n\n";
			break;

		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}
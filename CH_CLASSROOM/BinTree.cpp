#include "BinTree.h"
#include <iostream>
using namespace std;


static BinNode* AllocBinNode(void)
{
	BinNode* temp = new BinNode;
	return temp;
}

static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x;
	n->left = (__bnode*) left;
	n->right = (__bnode*) right;
}

BinNode* Search(BinNode* p, const Member* x)
{
	if (p == NULL)
		return NULL;
	else if (*p->data.name == *x->name && p->data.num == x->num) 
		return p;
	else if (x->num < p->data.num)
		Search(p->left, x);
	else
		Search(p->right, x);
}

BinNode* Add(BinNode* p, const Member* x)
{
	if (p == NULL)
	{
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if (p->data.name == x->name && p->data.num == x->num)
		cout << "이미 등록되어 있는 정보입니다.\n";
	else if (x->num < p->data.num)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);

	return p;
}

int Remove(BinNode** root, const Member* x) 
{
	BinNode* next;
	BinNode* temp;
	BinNode** left;
	BinNode** p = root;
	
	while (1)
	{
		if (*p == NULL)
		{
			cout << "등록되어 있지 않은 정보입니다.\n";
			return -1;
		}
		else if (*(*p)->data.name == *x->name && (*p)->data.num == x->num) 
			break;
		else if (x->num < (*p)->data.num)
			p = &((*p)->left);
		else
			p = &((*p)->right);
	}

	if ((*p)->left == NULL)
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL)
			left = &(*left)->right;
		next = *left;
		*left = (*left)->right;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return 0;

}


void PrintTree(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTree(p->left);
		cout << "이름 : " << p->data.name << "\n";
		cout << "번호 : " << p->data.num << "\n\n";
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p)
{
	if (p != NULL)
	{
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}


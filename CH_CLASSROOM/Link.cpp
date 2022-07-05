#include "Link.h"
#include <cstdio>

Link::Link()
{
	head == NULL;
}

Link::~Link()
{
}

void Link::Add_Student(string name, int number)
{
	Student* temp = new Student;

	if (temp == NULL)
	{
		printf("메모리 부족");
		exit(1);
	}
	
	temp->strName = name;
	temp->iNumber = number;

	if (head == NULL) // First input
	{
		head = temp;
		head->next = NULL;
		rewind(stdin);
		cout << "\n메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n";
		getchar();
		return;
	}

	Student* pre = NULL;
	Student* cur = head;
	while (cur != NULL) // cur이 NULL이 아닐동안 반복
	{
		if (cur->iNumber < temp->iNumber) // temp가 더 큰 경우
		{
			if (pre != NULL) // pre -> temp -> cur
				pre->next = temp;
			else // pre가 NULL 이라면 새로운 학생이 head
				head = temp;
			temp->next = cur;
			return; // return
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = temp; // 위 비교에서 하나도 걸리지 않을 경우, 저장된 모든 성적보다 성적이 저조한 경우 즉 맨 마지막!
	rewind(stdin);
	cout << "\n메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n";
	getchar();
	return;

}

void Link::Delete_Student(string name)
{
	system("cls");

	int flag = 0;
	temp = head;

	Student* pre = NULL;
	Student* cur = head;

	while (cur != NULL)
	{
		if (name == cur->strName)
		{
			pre->next = cur->next;
			break;
		}
		pre = cur;
		cur = cur->next;

	}
	rewind(stdin);
	cout << "\n삭제를 완료하였습니다. 메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n";
	getchar();
	if (flag == 0)
		cout << name << "라는 이름을 가진 학생을 찾지 못하였습니다.\n";
}

void Link::Print_Student()
{
	system("cls");
	cout << "출력 시스템을 실행합니다.\n\n";
	temp = head; 
	while (temp != NULL)
	{
		cout << temp->iNumber << "번   " << temp->strName << "\n";
		temp = temp->next; 
	}
	cout << "\n메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n";
	getchar();
}

void Link::Search_Student(string name)
{
	system("cls");

	int flag = 0;
	temp = head;
	while (temp != NULL)
	{
		if (name == temp->strName)
		{
			cout << temp->iNumber << "번   " << temp->strName << "\n";
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	rewind(stdin);
	cout<<"메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n";
	getchar();
	if (flag == 0)
		cout << name << "라는 이름을 가진 학생을 찾지 못하였습니다.\n";
}

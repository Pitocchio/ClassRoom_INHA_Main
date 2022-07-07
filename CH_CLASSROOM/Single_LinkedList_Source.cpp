#include "Single_LinkedList.h"

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
		printf("�޸� ����");
		exit(1);
	}
	
	temp->strName = name;
	temp->iNumber = number;
	temp->next = NULL;

	if (head == NULL) // First input
	{
		head = temp;
		head->next = NULL;
		rewind(stdin);
		cout << "\n�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
		getchar();
		return;
	}

	Student* pre = NULL;
	Student* cur = head;
	/*
	while (cur != NULL) // cur�� NULL�� �ƴҵ��� �ݺ�
	{
		if (cur->iNumber < temp->iNumber) // temp�� �� ū ���
		{
			if (pre != NULL) // pre -> temp -> cur
				pre->next = temp;
			else // pre�� NULL �̶�� ���ο� �л��� head
				head = temp;
			temp->next = cur;
			return; // return
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = temp; // �� �񱳿��� �ϳ��� �ɸ��� ���� ���, ����� ��� �������� ������ ������ ��� �� �� ������!
	*/
	while (cur != NULL) // cur�� NULL�� �ƴҵ��� �ݺ�
	{
		if (cur->iNumber > temp->iNumber) // cur���� new�� �� �۴�
		{
			if (pre != NULL) // cur���� new�� ���� �۴�, �ٵ� cur�� �߰��� ��ġ�ϰ� �ִ�
				pre->next = temp;
			else // cur���� new�� ���� �۴�, �ٵ� cur�� ����
				head = temp;
			temp->next = cur;
			rewind(stdin);
			cout << "\n�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
			getchar();
			return; 
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = temp; // �� �񱳿��� �ϳ��� �ɸ��� ���� ���, ���� ���� ���� �� ����������

	rewind(stdin);
	cout << "\n�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
	getchar();
	return;

}

void Link::Delete_Student(string name)
{
	system("cls");

	bool bIsfind = false;
	temp = head;

	Student* pre = NULL;
	Student* cur = head;

	while (cur != NULL)
	{
		if (name == cur->strName)
		{
			if (cur == head)
			{
				head = cur->next;
				break;
			}
			pre->next = cur->next;
			bIsfind = true;
			break;
		}
		pre = cur;
		cur = cur->next;

	}
	rewind(stdin);
	cout << "\n������ �Ϸ��Ͽ����ϴ�. �޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
	getchar();
	if (!bIsfind)
		cout << name << "��� �̸��� ���� �л��� ã�� ���Ͽ����ϴ�.\n";
}

void Link::Print_Student()
{
	system("cls");
	cout << "��� �ý����� �����մϴ�.\n\n";
	temp = head; 
	if (head == NULL)
	{
		cout << "\n���� ����Ʈ�� ��ϵ� �л��� �����ϴ�.\n\n";
		cout << "\n�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
		getchar();
		return;
	}
	while (temp != NULL)
	{
		cout << temp->iNumber << "��   " << temp->strName << "\n";
		temp = temp->next; 
	}
	cout << "\n�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
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
			cout << temp->iNumber << "��   " << temp->strName << "\n";
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	rewind(stdin);
	cout<<"�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n";
	getchar();
	if (flag == 0)
		cout << name << "��� �̸��� ���� �л��� ã�� ���Ͽ����ϴ�.\n";
}


void Link::Free_Data()
{

	for (Student* cur = head; cur != NULL;)
	{
		Student* temp = cur->next;
		delete cur;
		cur = temp;
	}
}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>

typedef struct Score
{
	int kor, eng, mat;
	float avg;
}Score;

typedef struct Student
{
	int num;
	char name[20];
	struct Score score;
	struct Student* next;
}Student;

Student* head, * temp;

void Input_student();
void Print_student();
void Find_student();
void Delete_student();
void free_data(Student* temp);

int main(void)
{
	int index;
	head = NULL;

	
	while (1)
	{
		system("cls");
		printf("1. �Է�\t\t2.���\t\t3.�˻�\t\t4.����\t\t5.����\n\n");
		printf("���Ͻô� �޴��� ��ȣ�� �Է����ּ��� : _\b");
		scanf("%d", &index);
		rewind(stdin);
		switch (index)
		{
		case (1): Input_student();
			break;
		case (2): Print_student();
			break;
		case (3): Find_student();
			break;
		case (4): Delete_student();
			break;
		case (5): printf("�ý����� �����ϰڽ��ϴ�.\n");
			temp = head;
			free_data(temp);
			exit(1);
		}
	}
	return 0;
}

void Input_student()
{
	temp = (struct Student*)malloc(sizeof(struct Student)); // �ӽ� temp ���� 
	if (temp == NULL)
	{
		printf("�޸� ����");
		exit(1);
	}
	system("cls");
	printf("�й�, �̸�, �����, �����, ���м����� ������� �Է����ּ��� : ");
	scanf("%d%s%d%d%d",
		&(temp->num), temp->name, &(temp->score.kor), &(temp->score.eng), &(temp->score.mat));
	temp->score.avg = ((temp->score.kor + temp->score.eng + temp->score.mat) / 3.0);
	if (head == NULL) // First input
	{
		head = temp;
		head->next = NULL;
		return;
	}
	Student* pre = NULL;
	Student* cur = head;
	while (cur != NULL) // cur�� NULL�� �ƴҵ��� �ݺ�
	{
		if (cur->score.avg < temp->score.avg) // temp�� �� ū ���
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
	rewind(stdin);
	printf("�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n");
	getchar();
}

void Print_student()
{
	system("cls");
	printf("��� �ý����� �����մϴ�.\n\n");
	temp = head; // ������ ��ĵ�� �����ϴ�
	while (temp != NULL)
	{
		printf("�̸� : %s\t�й� : %d\t����� : %d\t����� : %d\t���м��� : %d\t\n\n",
			temp->name, temp->num, temp->score.kor, temp->score.eng, temp->score.mat);
		temp = temp->next; // ���� ���ʷ� ����
	}
	printf("�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n");
	getchar(); // Ű �Է� ��ٸ�
}

void Find_student()
{
	system("cls");
	char temp_name[20];
	printf("�˻� �ý����� �����մϴ�.\n\n");
	printf("ã���� �л��� �̸��� �Է����ּ��� : ");
	scanf("%s", temp_name);
	int flag = 0;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp_name, temp->name) == 0)
		{
			printf("\n�̸� : %s\t�й� : %d\t����� : %d\t����� : %d\t���м��� : %d\t\n\n",
				temp->name, temp->num, temp->score.kor, temp->score.eng, temp->score.mat);
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	rewind(stdin);
	printf("�޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n");
	getchar();
	if (flag == 0)
		printf("%s��� �̸��� ���� �л��� ã�� ���Ͽ����ϴ�.\n", temp_name);
}

void Delete_student()
{
	system("cls");
	char temp_name[20];
	printf("���� �ý����� �����մϴ�.\n\n");
	printf("������ �л��� �̸��� �Է����ּ��� : ");
	scanf("%s", temp_name);
	int flag = 0;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp_name, temp->next->name) == 0)
		{
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;

	}
	rewind(stdin);
	printf("\n������ �Ϸ��Ͽ����ϴ�. �޴��� ���ư��� ���Ѵٸ� ���͸� �����ּ���.\n\n");
	getchar();
	if (flag == 0)
		printf("%s��� �̸��� ���� �л��� ã�� ���Ͽ����ϴ�.\n", temp_name);
}

void free_data(Student* temp)
{
	if (temp == NULL)
		return;
	free_data(temp->next);

	free(temp);
	return;
}
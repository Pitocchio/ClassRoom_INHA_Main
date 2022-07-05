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
		printf("1. 입력\t\t2.출력\t\t3.검색\t\t4.삭제\t\t5.종료\n\n");
		printf("원하시는 메뉴를 번호로 입력해주세요 : _\b");
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
		case (5): printf("시스템을 종료하겠습니다.\n");
			temp = head;
			free_data(temp);
			exit(1);
		}
	}
	return 0;
}

void Input_student()
{
	temp = (struct Student*)malloc(sizeof(struct Student)); // 임시 temp 생성 
	if (temp == NULL)
	{
		printf("메모리 부족");
		exit(1);
	}
	system("cls");
	printf("학번, 이름, 국어성적, 영어성적, 수학성적을 순서대로 입력해주세요 : ");
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
	while (cur != NULL) // cur이 NULL이 아닐동안 반복
	{
		if (cur->score.avg < temp->score.avg) // temp가 더 큰 경우
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
	printf("메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n");
	getchar();
}

void Print_student()
{
	system("cls");
	printf("출력 시스템을 실행합니다.\n\n");
	temp = head; // 헤드부터 스캔을 시작하다
	while (temp != NULL)
	{
		printf("이름 : %s\t학번 : %d\t국어성적 : %d\t영어성적 : %d\t수학성적 : %d\t\n\n",
			temp->name, temp->num, temp->score.kor, temp->score.eng, temp->score.mat);
		temp = temp->next; // 다음 차례로 연결
	}
	printf("메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n");
	getchar(); // 키 입력 기다림
}

void Find_student()
{
	system("cls");
	char temp_name[20];
	printf("검색 시스템을 실행합니다.\n\n");
	printf("찾으실 학생의 이름을 입력해주세요 : ");
	scanf("%s", temp_name);
	int flag = 0;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp_name, temp->name) == 0)
		{
			printf("\n이름 : %s\t학번 : %d\t국어성적 : %d\t영어성적 : %d\t수학성적 : %d\t\n\n",
				temp->name, temp->num, temp->score.kor, temp->score.eng, temp->score.mat);
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	rewind(stdin);
	printf("메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n");
	getchar();
	if (flag == 0)
		printf("%s라는 이름을 가진 학생을 찾지 못하였습니다.\n", temp_name);
}

void Delete_student()
{
	system("cls");
	char temp_name[20];
	printf("삭제 시스템을 실행합니다.\n\n");
	printf("삭제할 학생의 이름을 입력해주세요 : ");
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
	printf("\n삭제를 완료하였습니다. 메뉴로 돌아가기 원한다면 엔터를 눌러주세요.\n\n");
	getchar();
	if (flag == 0)
		printf("%s라는 이름을 가진 학생을 찾지 못하였습니다.\n", temp_name);
}

void free_data(Student* temp)
{
	if (temp == NULL)
		return;
	free_data(temp->next);

	free(temp);
	return;
}
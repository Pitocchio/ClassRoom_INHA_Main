#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct Student
{
	string strName;
	int iNumber;
	
	struct Student* prev; // 앞 노드를 가리키는 포인터
	struct Student* next; // 뒤 노드를 가리키는 포인터

}Student;


class Link
{

public:
	Link();
	~Link();

public:
	void Add_Student(string name, int number);
	void Delete_Student(string name);
	void Print_Student();
	void Search_Student(string name);
	void Free_Data();

private:
	Student* head, * temp, *tail;
};


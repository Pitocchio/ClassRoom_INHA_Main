#include "Queue.h"
#include <iostream>
#include <cstdlib>


int Initialize(IntQueue* q, int max)
{
	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == NULL)
		return -1;
	q->front = q->rear = q->num = 0;
	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x)
{
	if (IsFull(q))
		return -1;
	q->que[q->rear++] = x;
	q->num++;
	return 0;
}

int Deque(IntQueue* q, int* x)
{
	if (IsEmpty(q))
		return -1;
	*x = q->que[q->front++];
	q->num--;

	return 0;
}

int Peek(IntQueue* q, int* x) // 맨 앞에 데이터
{
	if (IsEmpty(q))
		return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(IntQueue* q)
{
	q->front = q->rear = q->num = 0;
}

int Capacity(const IntQueue* q)
{
	return q->max;
}

int Size(const IntQueue* q)
{
	return q->num;
}

int IsEmpty(const IntQueue* q)
{
	if (q->num <= 0)
		return 1;
	else
		return 0;
}

int IsFull(const IntQueue* q)
{
	if (q->num >= q->max)
		return 1;
	else
		return 0;
}

int Search(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; ++i)
	{
		if (q->que[(i+q->front)%q->max] == x)
			return i;
	}

	return -1;
}

void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; ++i)
	{
		printf("%d ", q->que[(i + q->front) % q->max]);
	}
	printf("\n");
}

void Terminate(IntQueue* q)
{
	free(q->que);
	q->front = q->rear = q->max = q->num = 0;
}
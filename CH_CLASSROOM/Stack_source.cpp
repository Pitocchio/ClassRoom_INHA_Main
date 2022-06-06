#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <iostream>
#include <cstdlib>


int Initialize(IntStack* s, int max)
{
	s->stk = (int*)calloc(max, sizeof(int));
	if (s->stk == NULL)
		return -1;

	s->ptr = 0;
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)
		return -1;

	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	s->ptr--;
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

int IsEmpty(const IntStack* s)
{
	if (s->ptr <= 0)
		return 1;
	else
		return 0;
}

int IsFull(const IntStack* s)
{
	if (s->ptr >= s->max)
		return 1;
	else
		return 0;
}

int Search(const IntStack* s, int x)
{
	for (int i = s->ptr - 1; i >= 0; --i)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const IntStack* s)
{
	for (int i = 0; i < s->ptr; ++i)
	{
		printf("%d\n", s->stk[i]);
	}

}

void Terminate(IntStack* s)
{
	free(s->stk);
	s->max = s->ptr = 0;
}


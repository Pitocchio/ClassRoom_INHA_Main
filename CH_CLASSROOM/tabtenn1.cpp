#include "tabtenn1.h"
#include <iostream>


// TableTennisPlayer Class Method
TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) // C++ ��Ÿ�� �ʱ�ȭ �Լ�
	: firstname(fn), lastname(ln), hasTable(ht) {}	

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}


// RatedTableTennisPlayer Class Method
// ��� Ŭ���� �ʱ�ȭ��, ��� �ʱ��� ����Ʈ �ʿ�
RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
	const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht) // ��� �ʱ��� ����Ʈ (TableTennisPlayer ������ ȣ��)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	: TableTennisPlayer(tp), rating(r) {}
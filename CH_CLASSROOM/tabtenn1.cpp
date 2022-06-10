#include "tabtenn1.h"
#include <iostream>


// TableTennisPlayer Class Method
TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) // C++ 스타일 초기화 함수
	: firstname(fn), lastname(ln), hasTable(ht) {}	

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}


// RatedTableTennisPlayer Class Method
// 상속 클래스 초기화시, 멤버 초기자 리스트 필요
RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
	const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht) // 멤버 초기자 리스트 (TableTennisPlayer 생성자 호출)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	: TableTennisPlayer(tp), rating(r) {}
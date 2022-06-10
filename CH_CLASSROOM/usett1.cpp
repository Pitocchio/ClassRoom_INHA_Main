#include "tabtenn1.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;

	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true); 
	
	rplayer1.Name();			// 파생 객체가 기초 메서드를 사용한다
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";

	player1.Name();				// 기초 객체가 기초 메서드를 사용한다
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";

	cout << "이름 :";
	rplayer1.Name();
	cout << ". 랭킹 : " << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1); // TableTennisPLayer 객체를 사용하여 RatedPlayer를 초기화한다
	cout << "이름 : ";
	rplayer2.Name();
	cout << "; 랭킹 : " << rplayer2.Rating() << endl;

	return 0;

}
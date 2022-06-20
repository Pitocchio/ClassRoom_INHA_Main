#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// FileTemp.txt

int main(void)
{

	int iNumOfFiles(0);
	string strTemp, strTargetFileName;
	vector <string> vecFiles;

	cout << "Enter the FileNumber : ";
	cin >> iNumOfFiles;

	for (int i = 0; i < iNumOfFiles; ++i)
	{
		cout << "Enter the SourceFile : ";
		cin >> strTemp;
		vecFiles.push_back(strTemp);
	}

	cout << "Enter the TargetFile : ";
	cin >> strTargetFileName;


	ofstream fout; // 출력을 위한 파일 객체 생성 
	fout.open(strTargetFileName.c_str(), ios_base::out | ios_base::binary);
	if (!fout.is_open())
	{
		cout << "쓰기 위한 파일을 여는 데 실패했습니다. \n시스템을 종료합니다.\n";
		exit(1);
	}




	for (int i = 0; i < iNumOfFiles; ++i)
	{
		char ch;

		ifstream fin; // 입력을 위한 파일 객체 생성
		fin.open(vecFiles[i].c_str(), ios_base::in | ios_base::binary); // 파일 객체를 읽기모드 + 바이너리 형태로 오픈
		if (!fin.is_open())
		{
			cout << "읽기 위한 파일을 여는 데 실패했습니다. \n시스템을 종료합니다.\n";
			exit(1);
		}
		

		while (!fin.eof())
		{

			fin.get(ch);
			fout << ch;
		}

		fin.close();
	}

	cout << "Combine Done.\n";

	fout.close();

	return 0;
}
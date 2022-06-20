#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// File_Origin.txt

int main(void)
{
	string strOrigin_FileName, strDivided_FileName;
	int iDivided_FileSize(0), iOrigin_FileSize(0), iNumOfFiles(1), iCount(0);

	cout << "Enter the FileName : ";
	cin >> strOrigin_FileName;
	cout << "Enter the FileSize : ";
	cin >> iDivided_FileSize;

	ifstream fin; // 입력을 위한 파일 객체 생성
	fin.open(strOrigin_FileName.c_str(), ios_base::in | ios_base::binary); // 파일 객체를 읽기모드 + 바이너리 형태로 오픈
	if (!fin.is_open())
	{
		cout << "읽기 위한 파일을 여는 데 실패했습니다. \n시스템을 종료합니다.\n";
		exit(1);
	}
	fin.seekg(0, ios::end); // 입력 포인터를 끝으로 보냄
	iOrigin_FileSize = (int)fin.tellg();// 마지막 위치 값을 인트형으로 받음
	fin.seekg(0); // 입력 포인터를 다시 처음 위치로

	ofstream fout; // 출력을 위한 파일 객체 생성 
	strDivided_FileName = strOrigin_FileName + "." + to_string(iNumOfFiles) + ".jpg";
	fout.open(strDivided_FileName.c_str(), ios_base::out | ios_base::binary); 
	if (!fout.is_open())
	{
		cout << "쓰기 위한 파일을 여는 데 실패했습니다. \n시스템을 종료합니다.\n";
		exit(1);
	}

	while (!fin.eof())
	{
		char ch;

		if (iCount == iDivided_FileSize)
		{
			cout << " => " << strDivided_FileName << "\n";
			fout.close();
			iNumOfFiles++;
			iCount = 0;
			strDivided_FileName = strOrigin_FileName + "." + to_string(iNumOfFiles) + ".jpg";
			fout.open(strDivided_FileName.c_str(), ios_base::out | ios_base::binary);
			if (!fout.is_open())
			{
				cout << "쓰기 위한 파일을 여는 데 실패했습니다.\n시스템을 종료합니다.\n";
				exit(1);
			}
		}

		fin.get(ch);
		fout << ch;
		iCount++;

	}

	cout << "Split Done.\n";

	fin.close();
	fout.close();

	return 0;
}
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


	ofstream fout; // ����� ���� ���� ��ü ���� 
	fout.open(strTargetFileName.c_str(), ios_base::out | ios_base::binary);
	if (!fout.is_open())
	{
		cout << "���� ���� ������ ���� �� �����߽��ϴ�. \n�ý����� �����մϴ�.\n";
		exit(1);
	}




	for (int i = 0; i < iNumOfFiles; ++i)
	{
		char ch;

		ifstream fin; // �Է��� ���� ���� ��ü ����
		fin.open(vecFiles[i].c_str(), ios_base::in | ios_base::binary); // ���� ��ü�� �б��� + ���̳ʸ� ���·� ����
		if (!fin.is_open())
		{
			cout << "�б� ���� ������ ���� �� �����߽��ϴ�. \n�ý����� �����մϴ�.\n";
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
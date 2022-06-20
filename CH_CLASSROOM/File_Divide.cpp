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

	ifstream fin; // �Է��� ���� ���� ��ü ����
	fin.open(strOrigin_FileName.c_str(), ios_base::in | ios_base::binary); // ���� ��ü�� �б��� + ���̳ʸ� ���·� ����
	if (!fin.is_open())
	{
		cout << "�б� ���� ������ ���� �� �����߽��ϴ�. \n�ý����� �����մϴ�.\n";
		exit(1);
	}
	fin.seekg(0, ios::end); // �Է� �����͸� ������ ����
	iOrigin_FileSize = (int)fin.tellg();// ������ ��ġ ���� ��Ʈ������ ����
	fin.seekg(0); // �Է� �����͸� �ٽ� ó�� ��ġ��

	ofstream fout; // ����� ���� ���� ��ü ���� 
	strDivided_FileName = strOrigin_FileName + "." + to_string(iNumOfFiles) + ".jpg";
	fout.open(strDivided_FileName.c_str(), ios_base::out | ios_base::binary); 
	if (!fout.is_open())
	{
		cout << "���� ���� ������ ���� �� �����߽��ϴ�. \n�ý����� �����մϴ�.\n";
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
				cout << "���� ���� ������ ���� �� �����߽��ϴ�.\n�ý����� �����մϴ�.\n";
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
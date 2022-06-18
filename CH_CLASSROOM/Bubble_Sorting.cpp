#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int iSize(0), iTemp(0), iPass(0), iChangeCount(0), iComCount(0);
	vector <int> vData;
	bool bCheck(0), bPrintCheck(0);


	// Get_Data()
	cout << "사용할 데이터의 갯수를 입력해주세요 => ";
	cin >> iSize;

	cout << "\n데이터를 갯수만큼 입력해주세요 => ";
	for (int i = 0; i < iSize; ++i)
	{
		cin >> iTemp;
		vData.push_back(iTemp);
	}


	// Sorting_Data()
	cout << "\n\n=============================\n\n\n";

	while(1)
	{
		cout << "<PASS " << iPass << ">\n";

		int k = 0;
		for (int j = 0; j < vData.size(); ++j)
		{
			// 출력부
			for (int i = 0; i < vData.size()+1; ++i) // 한줄 출력
			{
				if (k == 6 && i == 6)
				{
					cout << vData[i] << "   ";
					break;
				}
				cout << vData[i] << "   ";
				
	
				if (i == k && vData[i] > vData[i+1] && !bPrintCheck)
				{
					cout << "+   ";
					bPrintCheck = 1;
				}
				else if (i == k && vData[i] <= vData[i+1] && !bPrintCheck)
				{
					cout << "-   ";
					bPrintCheck = 1;
				}

				if (i == vData.size() - 1)
				{
					bPrintCheck = 0;
					k++;
					break;
				}
			}
			cout << "\n";
			
			iComCount++;
			if (vData[j] > vData[j + 1])
			{
				iTemp = vData[j];
				vData[j] = vData[j + 1];
				vData[j + 1] = iTemp;

				bCheck = 1;
				iChangeCount++;
			}
		}

		if (!bCheck)
		{
			cout << "\n\n";
			break;
		}
		else
		{
			bCheck = 0;
			iPass++;
			cout << "\n\n";
		}

	}
	cout << "\n=============================\n\n\n";


	// Print_Data()
	cout << "정렬된 데이터 : ";
	for (int i = 0; i < vData.size(); ++i)
	{
		cout << vData[i] << " ";
	}
	cout << "\n\n비교 횟수 : " << iComCount << "\n\n";
	cout << "교환 횟수 : " << iChangeCount << "\n\n";
	

	return 0;
}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	int iSize(0), iTemp(0), iPass(0), iChangeCount(0), iComCount(0);
//	vector <int> vData;
//	bool bCheck(0), bPrintCheck(0);
//
//
//	// Get_Data()
//	cout << "사용할 데이터의 갯수를 입력해주세요 => ";
//	cin >> iSize;
//
//	cout << "\n데이터를 갯수만큼 입력해주세요 => ";
//	for (int i = 0; i < iSize; ++i)
//	{
//		cin >> iTemp;
//		vData.push_back(iTemp);
//	}
//
//
//	// Sorting_Data()
//	cout << "\n\n=============================\n\n\n";
//
//	while (1)
//	{
//		cout << "<PASS " << iPass << ">\n";
//
//		int k = 0;
//		for (int j = 0; j < vData.size() - 1; ++j)
//		{
//			// 출력부
//			for (int i = 1; i < vData.size(); ++i) // 한줄 출력
//			{
//				cout << vData[i - 1] << " ";
//
//				if ((i - 1) == k && vData[i - 1] > vData[i] && !bPrintCheck)
//				{
//					cout << "+";
//					bPrintCheck = 1;
//				}
//				else if ((i - 1) == k && vData[i - 1] <= vData[i] && !bPrintCheck)
//				{
//					cout << "-";
//					bPrintCheck = 1;
//				}
//
//				if (i == vData.size() - 1)
//				{
//					bPrintCheck = 0;
//					k++;
//				}
//			}
//			cout << "\n";
//
//			iComCount++;
//			if (vData[j] > vData[j + 1])
//			{
//				iTemp = vData[j];
//				vData[j] = vData[j + 1];
//				vData[j + 1] = iTemp;
//
//				bCheck = 1;
//				iChangeCount++;
//			}
//		}
//
//		if (!bCheck)
//		{
//			cout << "\n\n";
//			break;
//		}
//		else
//		{
//			bCheck = 0;
//			iPass++;
//			cout << "\n\n";
//		}
//
//	}
//	cout << "\n=============================\n\n\n";
//
//
//	// Print_Data()
//	cout << "정렬된 데이터 : ";
//	for (int i = 0; i < vData.size(); ++i)
//	{
//		cout << vData[i] << " ";
//	}
//	cout << "\n\n비교 횟수 : " << iComCount << "\n\n";
//	cout << "교환 횟수 : " << iChangeCount << "\n\n";
//
//
//	return 0;
//}
//


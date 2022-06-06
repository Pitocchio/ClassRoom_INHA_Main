#include <iostream>
using namespace std;

#define Max 2100000000

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[3];
	int iVolume(1), iProfit(0);

	// Get_Datas
	for (int i = 0; i < 3; ++i)
	{
		do
		{
			cin >> arr[i];
		} while ((arr[i] < 1) || (Max < arr[i]));
	}

	// Calculate_BREAK-EVEN-POINT
	if (arr[1] > arr[2]) // 개당가격보다 가변비용이 높은 경우, 손익분기점은 존재하지 않는다
	{
		cout << -1;
	}
	else
	{
		while (1)
		{
			iProfit = (((arr[2] - arr[1]) * iVolume) - arr[0]);

			if (iProfit > 0)
				break;
		
			iVolume++;
		}
		cout << iVolume;
	}

	return 0;
}
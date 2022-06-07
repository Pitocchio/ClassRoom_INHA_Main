#include <iostream>
#include <string>
using namespace std;

void Permutation(string str, string prefix);

int main(void)
{
	string str;
	cout << "���ڿ��� �Է����ּ��� => ";
	cin >> str;
    cout << "\n============================\n\n";

    Permutation(str, "");

	return 0;
}

void Permutation(string str, string prefix)
{
    if (str.length() == 0)
        cout << prefix << "\n\n";
    else
    {
        for (int i = 0; i < str.length(); ++i)
        {
            string Temp = str.substr(0, i) + str.substr(i + 1);

            Permutation(Temp, prefix + str[i]);
        }
    }
}
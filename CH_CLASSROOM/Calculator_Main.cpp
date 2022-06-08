#include <iostream>
#include <string>
#include <vector>
using namespace std;


void Set_Fomular(string& strFormula, vector <int>& OPERATOR_STACK, vector <int>& POSTFIX_QUEUE);

void Calculate_Fomular(vector <int>& POSTFIX_QUEUE, vector <int>& OPERAND_STACK);

int main(void)
{
	string strFormula;
	vector <int> OPERATOR_STACK, POSTFIX_QUEUE, OPERAND_STACK;

	
	cout << "������ �Է����ּ��� => ";
	cin >> strFormula;

	Set_Fomular(strFormula, OPERATOR_STACK, POSTFIX_QUEUE);

	Calculate_Fomular(POSTFIX_QUEUE, OPERAND_STACK);

	cout << OPERAND_STACK[0];

	return 0;
}

void Set_Fomular(string& strFormula, vector <int>& OPERATOR_STACK, vector <int>& POSTFIX_QUEUE)
{
	string temp="";
	bool bCanMinusFlag(0);
	bool bMinusFlag (0);

	strFormula.insert(0, "(");
	strFormula.insert(strFormula.size(), ")");


	for (int i = 0; i < strFormula.size(); ++i)
	{
		if (isdigit(strFormula[i])) // �ǿ����� -> POSTFIX_QUEUE
		{
			temp += strFormula[i];
		}
		else // ������ -> OPERATOR_STACK
		{

			// ���� ó�� �κ�
			if (strFormula[i] == '(' || strFormula[i] == '+' || strFormula[i] == '-' || strFormula[i] == '*' || strFormula[i] == '/')
			{
				bCanMinusFlag = 1;
			}

			if (bCanMinusFlag && strFormula[i] == '-')
			{
				bMinusFlag = 1;
				bCanMinusFlag = 0;
			}
			/*else if (bCanMinusFlag && (strFormula[i] == '(' || strFormula[i] == '+' || strFormula[i] == '-' || strFormula[i] == '*' || strFormula[i] == '/'))
			{
				bCanMinusFlag = 1;
			}*/
			else 
				bCanMinusFlag = 0;


			if (temp.size())
			{
				if (bCanMinusFlag) // ���� ó�� �κ�
				{
					POSTFIX_QUEUE.push_back(stoi(temp) * -1);
					temp = "";
					bCanMinusFlag = 0;
					bMinusFlag = 0;
					continue;
				}
				else
				{
					POSTFIX_QUEUE.push_back(stoi(temp));
					temp = "";
				}
				
			}

			// ���͸�1 (������ �켱����)
			if (((strFormula[i] == '+') || (strFormula[i] == '-')) 
				&& ((OPERATOR_STACK[OPERATOR_STACK.size()-1] == '*') || (OPERATOR_STACK[OPERATOR_STACK.size()-1] == '/')))
			{
				POSTFIX_QUEUE.push_back(OPERATOR_STACK.back());
				OPERATOR_STACK[OPERATOR_STACK.size()-1] = strFormula[i];
				continue;
			}

			// ���͸�2 (�ݴ� ��ȣ�� ��)
			if (strFormula[i] == ')') 
			{
				for (int j = OPERATOR_STACK.size()-1; j>=0; --j)
				{
					if (OPERATOR_STACK[j] == '(')
					{
						OPERATOR_STACK.pop_back();
						break;
					}
					else
					{
						POSTFIX_QUEUE.push_back(OPERATOR_STACK[j]);
						OPERATOR_STACK.pop_back();
					}
				}
			}
			else
			{	if (!bMinusFlag)
					OPERATOR_STACK.push_back(strFormula[i]);
			}
		}
	}
}


void Calculate_Fomular(vector <int>& POSTFIX_QUEUE, vector <int>& OPERAND_STACK)
{
	int iTemp(0);

	for (int i = 0; i < POSTFIX_QUEUE.size(); ++i) 
	{
		if (POSTFIX_QUEUE[i] == 42 || POSTFIX_QUEUE[i] == 43 || POSTFIX_QUEUE[i] == 45 || POSTFIX_QUEUE[i] == 47)  // ������
		{
			switch (POSTFIX_QUEUE[i])
			{
				case 42: //������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 1] * OPERAND_STACK[OPERAND_STACK.size() - 2];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();

					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 43: // ������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 1] + OPERAND_STACK[OPERAND_STACK.size() - 2];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();

					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;
				
				case 45: // ������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 1] - OPERAND_STACK[OPERAND_STACK.size() - 2];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();

					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 47: // ��������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 1] / OPERAND_STACK[OPERAND_STACK.size() - 2];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();

					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;
			}
		}
		else // �ǿ����� 
		{
			OPERAND_STACK.push_back(POSTFIX_QUEUE[i]);
		}
	}
}
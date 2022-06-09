#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ��ȯ �Լ�(����ǥ�� -> ����ǥ��)
void Convert_Formula(string& strFormula, vector <double>& OPERATOR_STACK, vector <double>& POSTFIX_QUEUE); 

// ��� �Լ�
void Calculate_Fomular(vector <double>& POSTFIX_QUEUE, vector <double>& OPERAND_STACK); 

int main(void)
{
	while (1)
	{
		string strFormula;
		vector <double> OPERATOR_STACK, POSTFIX_QUEUE, OPERAND_STACK;

		cout << "������ �Է����ּ��� => ";
		getline(cin, strFormula);

		Convert_Formula(strFormula, OPERATOR_STACK, POSTFIX_QUEUE);

		Calculate_Fomular(POSTFIX_QUEUE, OPERAND_STACK);

		cout << "��� ��� : " << OPERAND_STACK[0] << "\n\n";
	}

	return 0;
}

void Convert_Formula(string& strFormula, vector <double>& OPERATOR_STACK, vector <double>& POSTFIX_QUEUE)
{
	string temp = "";
	bool isMinus(0);
	bool isGetNum(0);
	
	// ���� ��ȣ �߰� ����
	strFormula.insert(0, "(");
	strFormula.insert(strFormula.size(), ")");

	for (int i = 0; i < strFormula.size(); ++i)
	{
		if (strFormula[i] == ' ') // ����ó�� (��ĭ�� ���)
			continue;

		if (strFormula[i] == '(')
		{
			isGetNum = true;
		}
		else if (strFormula[i] == ')')
		{
			isGetNum = false;
		}

		if ((isGetNum && isdigit(strFormula[i])) || (isGetNum && strFormula[i] == 46)) // ���� -> TEMP (for �� �ڸ��� �̻�, �Ҽ� ó��) -> STACK
		{
			temp += strFormula[i];
		}
		else // ������
		{
			if (isGetNum && strFormula[i] == '-')
			{
				isMinus = true;
			}

			if (temp.size()) // ���� -> TEMP (for �� �ڸ��� �̻� ó��) -> STACK
			{
				if (isMinus) // ���� �ݿ�(O)
				{
					POSTFIX_QUEUE.push_back(stod(temp) * -1);
					temp = "";
					isMinus = 0;
					OPERATOR_STACK.push_back(strFormula[i]);
					continue;

				}
				else // ���� �ݿ�(X)
				{
					POSTFIX_QUEUE.push_back(stod(temp));
					temp = "";
				}
			}

			// Filter_1 (������ �켱���� ó�� : �켱������ �ٸ� ��, �켱������ ���� ��)
			if ((((strFormula[i] == '+') || (strFormula[i] == '-'))
				&& ((OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '*') || (OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '/')))
				|| (strFormula[i] == '*') && (OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '/') 
				|| (strFormula[i] == '/') && (OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '*')
				|| (strFormula[i] == '+') && (OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '-')
				|| (strFormula[i] == '-') && (OPERATOR_STACK[OPERATOR_STACK.size() - 1] == '+'))
			{
				POSTFIX_QUEUE.push_back(OPERATOR_STACK.back());
				OPERATOR_STACK[OPERATOR_STACK.size() - 1] = strFormula[i];
				continue;
			}

			// Filter_2 (�ݴ� ��ȣ�� �� ó��)
			if (strFormula[i] == ')')
			{
				for (int j = OPERATOR_STACK.size() - 1; j >= 0; --j)
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
			{
				if (!isMinus || isdigit(strFormula[i]))
				{
					OPERATOR_STACK.push_back(strFormula[i]);
					isGetNum = true;
				}
			}
			
		}
	}
}

void Calculate_Fomular(vector <double>& POSTFIX_QUEUE, vector <double>& OPERAND_STACK)
{
	double iTemp(0);

	for (int i = 0; i < POSTFIX_QUEUE.size(); ++i)
	{
		if (POSTFIX_QUEUE[i] == 42 || POSTFIX_QUEUE[i] == 43 || POSTFIX_QUEUE[i] == 45 || POSTFIX_QUEUE[i] == 47)  // ������
		{
			switch (int(POSTFIX_QUEUE[i]))
			{
				case 42: // ������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] * OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 43: // ������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] + OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 45: // ������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] - OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 47: // ��������ȣ(�ƽ�Ű)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] / OPERAND_STACK[OPERAND_STACK.size() - 1];

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
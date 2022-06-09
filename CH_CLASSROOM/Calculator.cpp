#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 전환 함수(중위표기 -> 후위표기)
void Convert_Formula(string& strFormula, vector <double>& OPERATOR_STACK, vector <double>& POSTFIX_QUEUE); 

// 계산 함수
void Calculate_Fomular(vector <double>& POSTFIX_QUEUE, vector <double>& OPERAND_STACK); 

int main(void)
{
	while (1)
	{
		string strFormula;
		vector <double> OPERATOR_STACK, POSTFIX_QUEUE, OPERAND_STACK;

		cout << "수식을 입력해주세요 => ";
		getline(cin, strFormula);

		Convert_Formula(strFormula, OPERATOR_STACK, POSTFIX_QUEUE);

		Calculate_Fomular(POSTFIX_QUEUE, OPERAND_STACK);

		cout << "계산 결과 : " << OPERAND_STACK[0] << "\n\n";
	}

	return 0;
}

void Convert_Formula(string& strFormula, vector <double>& OPERATOR_STACK, vector <double>& POSTFIX_QUEUE)
{
	string temp = "";
	bool isMinus(0);
	bool isGetNum(0);
	
	// 양쪽 괄호 추가 세팅
	strFormula.insert(0, "(");
	strFormula.insert(strFormula.size(), ")");

	for (int i = 0; i < strFormula.size(); ++i)
	{
		if (strFormula[i] == ' ') // 예외처리 (빈칸일 경우)
			continue;

		if (strFormula[i] == '(')
		{
			isGetNum = true;
		}
		else if (strFormula[i] == ')')
		{
			isGetNum = false;
		}

		if ((isGetNum && isdigit(strFormula[i])) || (isGetNum && strFormula[i] == 46)) // 숫자 -> TEMP (for 두 자릿수 이상, 소수 처리) -> STACK
		{
			temp += strFormula[i];
		}
		else // 연산자
		{
			if (isGetNum && strFormula[i] == '-')
			{
				isMinus = true;
			}

			if (temp.size()) // 숫자 -> TEMP (for 두 자릿수 이상 처리) -> STACK
			{
				if (isMinus) // 음수 반영(O)
				{
					POSTFIX_QUEUE.push_back(stod(temp) * -1);
					temp = "";
					isMinus = 0;
					OPERATOR_STACK.push_back(strFormula[i]);
					continue;

				}
				else // 음수 반영(X)
				{
					POSTFIX_QUEUE.push_back(stod(temp));
					temp = "";
				}
			}

			// Filter_1 (연산자 우선순위 처리 : 우선순위가 다를 때, 우선순위가 같을 때)
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

			// Filter_2 (닫는 괄호일 때 처리)
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
		if (POSTFIX_QUEUE[i] == 42 || POSTFIX_QUEUE[i] == 43 || POSTFIX_QUEUE[i] == 45 || POSTFIX_QUEUE[i] == 47)  // 연산자
		{
			switch (int(POSTFIX_QUEUE[i]))
			{
				case 42: // 곱셈기호(아스키)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] * OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 43: // 덧셈기호(아스키)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] + OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 45: // 뺄셈기호(아스키)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] - OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;

				case 47: // 나눗셈기호(아스키)
					iTemp = OPERAND_STACK[OPERAND_STACK.size() - 2] / OPERAND_STACK[OPERAND_STACK.size() - 1];

					OPERAND_STACK.pop_back();
					OPERAND_STACK.pop_back();
					OPERAND_STACK.push_back(iTemp);
					iTemp = 0;
					break;
			}
		}
		else // 피연산자 
		{
			OPERAND_STACK.push_back(POSTFIX_QUEUE[i]);
		}
	}
}
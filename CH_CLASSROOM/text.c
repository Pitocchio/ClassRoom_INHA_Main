

/*



if (temp.score > tail.score) ���� ���� �����, ���� ��պ��� ���� ���

else

	head = temp; // head�� ����ִ�, �� ó�� ��ǲ�� ���� ��Ȳ : head�� ���� ������ temp�� ����Ŵ
	else
	{
		tail->next = temp; // ���� �ƴ϶�� ���� tail�� next�� �������� (��ũ��) ������ ���� ����
		printf("�Է� �ý����� �����մϴ�.\n\n");
		printf("�й�, �̸�, ���� ����, ���� ����, ���� ������ ������� �Է����ּ��� : ");
		scanf("%d%s%d%d%d",
			&(temp->num), temp->name, &(temp->score.kor), &(temp->score.eng), &(temp->score.mat));

		if (((temp->score.kor + temp->score.eng + temp->score.mat) / 3.0) > ((tail->score.kor + tail->score.eng + tail->score.mat) / 3.0))
		{
			temp->next = tail;
		}
		else
		{

		}
		temp->next = NULL;
		tail = temp;  // ������ ����
	}
*/

//void Input_student()
//{
//	system("cls");
//	temp = (struct Student*)malloc(sizeof(struct Student)); // �ӽ� temp ���� 
//
//	if (temp == NULL)
//	{
//		printf("�޸𸮰� �����Ͽ� �ý����� �����մϴ�");
//		exit(1);
//	}
//
//
//	if (head == NULL)
//		head = temp; // head�� ����ִ�, �� ó�� ��ǲ�� ���� ��Ȳ : head�� ���� ������ temp�� ����Ŵ
//	else
//		tail->next = temp; // ���� �ƴ϶�� ���� tail�� next�� �������� (��ũ��) ������ ���� ���� 
//	printf("�Է� �ý����� �����մϴ�.\n\n");
//	printf("�й�, �̸�, ���� ����, ���� ����, ���� ������ ������� �Է����ּ��� : ");
//	scanf("%d%s%d%d%d",
//		&(temp->num), temp->name, &(temp->score.kor), &(temp->score.eng), &(temp->score.mat));
//
//	temp->next = NULL;
//	tail = temp;  // ������ ����
//
//}

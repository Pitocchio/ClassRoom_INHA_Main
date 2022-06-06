

/*



if (temp.score > tail.score) 새로 들어온 평균이, 꼬리 평균보다 높은 경우

else

	head = temp; // head가 비어있다, 즉 처음 인풋이 들어온 상황 : head가 위에 생성된 temp을 가리킴
	else
	{
		tail->next = temp; // 위가 아니라면 현재 tail의 next에 연결해줌 (링크됨) 꼬리를 새로 생성
		printf("입력 시스템을 실행합니다.\n\n");
		printf("학번, 이름, 국어 성적, 영어 성적, 수학 성적을 순서대로 입력해주세요 : ");
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
		tail = temp;  // 꼬리로 지정
	}
*/

//void Input_student()
//{
//	system("cls");
//	temp = (struct Student*)malloc(sizeof(struct Student)); // 임시 temp 생성 
//
//	if (temp == NULL)
//	{
//		printf("메모리가 부족하여 시스템을 종료합니다");
//		exit(1);
//	}
//
//
//	if (head == NULL)
//		head = temp; // head가 비어있다, 즉 처음 인풋이 들어온 상황 : head가 위에 생성된 temp을 가리킴
//	else
//		tail->next = temp; // 위가 아니라면 현재 tail의 next에 연결해줌 (링크됨) 꼬리를 새로 생성 
//	printf("입력 시스템을 실행합니다.\n\n");
//	printf("학번, 이름, 국어 성적, 영어 성적, 수학 성적을 순서대로 입력해주세요 : ");
//	scanf("%d%s%d%d%d",
//		&(temp->num), temp->name, &(temp->score.kor), &(temp->score.eng), &(temp->score.mat));
//
//	temp->next = NULL;
//	tail = temp;  // 꼬리로 지정
//
//}

//#include"��������head.h"
//int a[256] = { 0 };
//que_ front, rear;
//T root;
//table_ head, tail;
//bool is_empty()
//{
//	if (rear == front)return true;
//	else return false;
//}
//
//void exchange(que_ *min,que_ *move1)
//{
//	int a;
//	char b;
//	T c;
//
//	a = (*min)->num;
//	b = (*min)->ch;
//	c = (*min)->totree;
//
//	(*min)->num = (*move1)->num;
//	(*min)->ch = (*move1)->ch;
//	(*min)->totree=(*move1)->totree;
//
//	(*move1)->num = a;
//	(*move1)->ch = b;
//	(*move1)->totree = c;
//}
//
//void numTable()
//{
//	char str[MAX];
//	int i;
//
//	printf("\n�����ַ���\n");
//	scanf_s("%s", str, MAX);
//	str[MAX - 1] = '\0';
//	while (getchar() != '\n');
//
//	for (i = 0; i < strlen(str); i++)
//	{
//		a[(int)str[i]]++;
//	}
//}
//
//void initQue()//��ʼ�����нڵ�
//{
//	front = (que_)malloc(sizeof(struct que));
//	rear = front;
//}
//
//void addQue()
//{
//	for (int i = 0; i < 256; i++)
//	{
//		if (a[i] != 0)
//		{
//			que_ p = rear;//�����½ڵ���ԭ�Ƚڵ�����
//			rear = (que_)malloc(sizeof(struct que));
//			p->next = rear;
//			rear->next = NULL;
//
//			rear->ch = (char)i;//���ַ��ͳ��ִ���������нڵ�
//			rear->num = a[i];
//
//			rear->totree = (T)malloc(sizeof(T_));
//			rear->totree->ch = (char)i;//���ַ��ͳ��ִ����������ڵ�
//			rear->totree->num = a[i];
//			rear->totree->left = NULL;
//			rear->totree->right = NULL;
//		}
//	}
//}
//
//void sortQue()
//{
//	que_ move1=front->next;
//	que_ move2 = front->next;
//	que_ min;
//	if (!is_empty())
//	{
//		for (;move1->next;move1=move1->next)
//		{
//			for (move2=move1,min=move1; move2; move2 = move2->next)
//			{
//				min = (min->num < move2->num ? min : move2);
//			}
//			exchange(&min,&move1);
//		}
//	}
//	return;
//}
//
//T getQue()
//{
//	que_ now=front->next;
//	while (1)
//	{
//		T newTn = (T)malloc(sizeof(T_));//�������ڵ�
//
//		newTn->left = now->totree;//������������
//		newTn->right = now->next->totree;
//
//		newTn->num = now->num + now->next->num;//�����ڵ�����������Ȩֵ֮��
//
//		if (now->next->next)
//		{
//			que_ latter = now->next;//ָ���ƶ�λ��
//			now = now->next->next;
//
//			que_ newque = (que_)malloc(sizeof(que));
//			newque->num = newTn->num;
//			newque->totree = newTn;
//			if (newTn->num > now->num)//���Ȩֵ֮�ͽϴ󣬲����ұ�
//			{
//				newque->next = now->next;//���Ӷ��нڵ�
//				now->next = newque;
//			}
//			else//���Ȩֵ֮�ͽ�С���������
//			{
//				latter->next = newque;
//				newque->next = now;
//				now = newque;
//			}
//		}
//		else return newTn;
//	}
//}
//
//void creatHT()
//{
//	numTable();
//	initQue();
//	addQue();
//	sortQue();
//	if (front->next->next)
//	{
//		root = getQue();
//	}
//	else if (is_empty())
//	{
//		printf("\n������\n"); root = NULL;
//	}
//	else root = front->next->totree;
//	return;
//}
//
//void initcT()
//{
//	head = (table_)malloc(sizeof(struct table));
//	tail = head;
//	head->next == NULL;
//}
//
//void travel(T p,char C[256],int i,char n)
//{
//	C[i] = n;
//	if (p == NULL)return;
//	if (p->left == NULL && p->right == NULL)
//	{
//		C[i+1] = '\0';
//		table_ q = tail;
//
//		tail= (table_)malloc(sizeof(struct table));
//		tail->code = (char*)malloc(sizeof(char) * (strlen(C) + 1));
//		tail->ch = p->ch;
//		strcpy_s(tail->code, strlen(C) + 1,C);
//
//		q->next = tail;
//		tail->next = NULL;
//
//		return;
//	}
//	travel(p->left, C, i + 1,'0');
//	travel(p->right, C, i + 1,'1');
//	return;
//}
//
//void creatTable()
//{
//	initcT();
//	if (root->left == NULL && root->right == NULL)
//	{
//		table_ q = tail;
//		tail = (table_)malloc(sizeof(struct table));
//		q->next = tail;
//		tail->next = NULL;
//
//		tail->code = (char*)malloc(sizeof(char) * 2);
//		char C[2]; C[0] = '0'; C[1] = '\0';
//		strcpy_s(tail->code, 2, C);
//
//		tail->ch = root->ch;
//	}
//	else
//	{
//		char C[256];
//		int i = 0;
//		travel(root->left, C, i, '0');
//		char B[256];
//		travel(root->right, B, i, '1');
//	}
//	return;
//}
//
//void encode()
//{
//    if (head->next == NULL)
//    {
//		printf("\n������\n"); return;
//	}
//	for (table_ move = head->next; move; move = move->next)
//	{
//		printf("\n%c  %s\n", move->ch, move->code);
//	}
//	return;
//}
//
//void decode()
//{
//	printf("\n������\n");
//	char str[MAX_DECODE], str_[MAX_DECODE];
//	scanf_s("%s", str, MAX_DECODE);
//	str[MAX_DECODE-1] = 0;
//	str_[MAX_DECODE - 1] = '\0';
//	while (getchar() != '\n');
//	if (root == NULL||str==NULL)
//	{
//		printf("\n������\n\n"); return;
//	}
//	T p = root;
//	for (int i = 0,j=0; str[i]; i++)
//	{
//		if (p->left == NULL && p->right == NULL)
//		{
//			printf(" %c ", p->ch);
//			p = root;
//			for(int i=0;i< MAX_DECODE;i++)str_[i] = '\0';
//			j = 0;
//		}
//		if (str[i]=='0')
//		{
//			p = p->left;
//			str_[j++] = str[i];
//		}
//		if (str[i]=='1')
//		{
//			p = p->right;
//			str_[j++] = str[i];
//		}
//		if (str[i] != '0' && str[i] != '1')
//		{
//			printf("\n�����\n"); return;
//		}
//	}
//	int a = strlen(str_);
//	str_[a] = '\0';
//	
//	printf("\n%s\n", str_);
//	return;
//}
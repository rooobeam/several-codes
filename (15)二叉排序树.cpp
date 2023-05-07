//#include"tool.h"
//
//typedef struct tree {
//	int data;
//	struct tree* L;
//	struct tree* R;
//}*T;
//T head = (T)malloc(sizeof(struct tree));
//
//char ch;
//
//void init()
//{
//	printf("\n����a b c d ��� ���� ɾ�� �˳�\n");
//	ch = getchar();
//	getchar();
//	if (ch == 'b' || ch == 'c')printf("\n��\n");
//	if (ch == 'd')exit(0);
//	head->L = NULL;
//	head->R = NULL;
//	printf("\n����\n");
//	int n;
//	scanf_s("%d", &(head->data));
//	getchar();
//}
//
//void add()//��С�Ƚϵ���
//{
//	int n;
//	while (1)
//	{
//		printf("\n��������\n");
//		scanf_s("%d", &n);
//		while (getchar() != '\n');
//
//		if (n == 0)return;
//		T e = head;
//		while (1)
//		{
//			if (n > e->data)
//			{
//				if (e->R != NULL)e = e->R;
//				else
//				{
//					T p = (T)malloc(sizeof(struct tree));
//					p->data = n;
//					p->L = NULL;
//					p->R = NULL;
//					e->R = p;
//					break;
//				}
//			}
//
//			else
//			{
//				if (e->L != NULL)e = e->L;
//				else
//				{
//					T p = (T)malloc(sizeof(struct tree));
//					p->data = n;
//					p->L = NULL;
//					p->R = NULL;
//					e->L = p;
//					break;
//				}
//			}
//		}
//	}
//}
//
//void search(T *now,T *latter)//��С�Ƚϵ���
//{
//	//ѯ������
//	int n;
//	printf("\n��������\n");
//	scanf_s("%d", &n);
//	getchar();
//
//	//����������� head �ͷ���Ŀ������
//	if (head->data == n)
//	{
//		printf("\n%p", head);
//		*now = head;
//		*latter = head;
//		return;
//	}
//
//	//now Ϊ p ������Ϊ e
//	T p = head;
//	T e=p;
//
//
//	while (1)
//	{
//
//		if (n == p->data)
//		{
//			printf("\n%p", p);
//			*now = p;
//			*latter = e;
//			return;
//		}
//
//		if (n > p->data)
//		{
//			if (p->R != NULL)
//			{
//				e = p;
//				p = p->R;
//			}
//			else
//			{
//				printf("\n��");
//				*now=NULL;
//				*latter = NULL;
//				return;
//			}
//			continue;
//		}
//
//		if(n<p->data)
//		{
//			if (p->L != NULL) 
//			{
//				e = p;
//				p = p->L;
//			}
//			else
//			{
//				if (p->L != NULL)p = p->L;
//				else
//				{
//					printf("\n��");
//					*now = NULL;
//					*latter = NULL;
//					return ;
//				}
//			}
//		}
//	}
//}
//
//void delet()//����������Ȼ��һֱ�� (���� ����Ȼ��һֱ��) ����������
//{
//	T p, e, stay;
//
//	//��λ
//	search(&p,&e);
//	stay = p;
//
//	//��¼Ҫɾdata λ�� p λ��������� һ�������� �� ��һ���� �� ������ �� NULL
//	stay = p;
//
//	//���� null
//	if (p == NULL)return;
//
//	//����������� ������
//	if (p->L == NULL && p->R == NULL)
//	{
//		if (e->L == p)e->L = NULL;
//		else e->R = NULL;
//		free(p);
//		return;
//	}
//
//	//��ʱ���Ϊ������ �ȿ���������û�� �ٿ���������û��
//	if (p->L != NULL)
//	{
//
//		//����������������� ֱ�Ӱ�������
//		if (p->L->R == NULL) 
//		{
//			e = p;
//			p = p->L;
//			e->data = p->data;
//			e->L = p->L;
//			free(p);
//		}
//
//		//����������������� �鵽�����ҵ�����
//		else 
//		{
//			e = p;
//			p = p->L;
//			for (e = p, p = p->R; p->R != NULL; e = p, p = p->R);
//
//			//���� ָ��p ��ָ��Ϊnull
//			stay->data = p->data;
//	        e->R = NULL;
//			free(p);
//		}
//
//	}
//
//	//����������һ������
//	else
//	{
//
//		//����������������� ֱ�Ӱ�������
//		if (p->R->L == NULL)
//		{
//			e = p;
//			p = p->R;
//			e->data = p->data;
//			e->R = p->R;
//			free(p);
//		}
//
//		//����������������� �鵽�����������
//		else
//		{
//			e = p;
//			p = p->R;
//			for (e = p, p = p->L; p->L != NULL; e = p, p = p->L);
//
//			//���� ָ��p ��ָ��Ϊnull
//			stay->data = p->data;
//			e->L = NULL;
//			free(p);
//		}
//	}
//}
//
//int main()
//{	
//	init();
//	if(ch=='d')	return 0;
//	T p, e;
//	while (1)
//	{
//		printf("\n����a b c d ��� ���� ɾ�� �˳�\n");
//		ch = getchar();
//		getchar();
//		if (ch == 'd')break;
//		switch (ch)
//		{
//		case 'a':add(); break;
//		case 'b':search(&p, &e); break;
//		case 'c':delet(); break;
//		default:break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//������ ���Ϊ0�ĵ�  Ȼ���߳����� ͬʱ���µ�
//�����ڽӾ������ڽӱ�

//#include"tool.h"
//#define MAX 20
//
//int vnum, bnum;
//
//typedef struct edgenode {
//	int v;
//	struct edgenode* next;
//}*L;
//
//struct vex{
//	int in;
//	char data;
//	L to_L;
//}vex[MAX];
//
//typedef struct queue {
//	struct queue* next;
//	int v;
//}*Q;
//
//Q front, rear;
//
//void init()
//{
//	front = (Q)malloc(sizeof(struct queue));
//	rear = front;
//	rear->next = NULL;
//	for (int i = 0; i < MAX; i++)
//	{
//		vex[i].in = 0;
//		vex[i].to_L = NULL;
//	}
//}
//
//bool is_repeat(int v1, int v2)
//{
//	for (L e = vex[v1].to_L; e; e = e->next)
//		if (e->v == v2)return true;
//	return false;
//}
//
//void createg()
//{
//	while (1)
//	{
//		printf("\n���붥����������(x/x)��");
//		scanf_s("%d/%d", &vnum, &bnum);
//		while (getchar() != '\n');
//		if (vnum > 20) { printf("\n̫����"); continue; }
//		if (vnum == 1) { printf("\n��������"); continue; }
//		if (vnum >= 2 && (vnum * (vnum - 1) / 2 < bnum))
//		{
//			printf("\n��������"); continue;
//		}
//		break;
//	}
//	/*for (int i = 0; i < vnum; i++)
//	{
//		printf("\n�����%d�����������", i);
//		a[i] = getchar();
//		while (getchar() != '\n');
//	}*/
//	for (int i = 0; i < bnum; i++)
//	{
//		int b1, b2;
//		printf("\n�����%d����������˵Ķ������(x->x)", i + 1);
//		scanf_s("%d->%d", &b1, &b2);
//		while (getchar() != '\n');
//
//		b1--; b2--;
//		if (b1 >= MAX || b2 >= MAX)
//		{
//			printf("\n�������"); i--; continue;
//		}
//		//�жϱ��Ƿ��Ѿ�����
//		if (is_repeat(b1, b2))
//		{
//			printf("\n�ñ��Ѿ�������������");
//			i--;
//		}
//		else//����addL
//		{
//			vex[b2].in++;
//			L p = (L)malloc(sizeof(struct edgenode));
//			p->v = b2;
//			p->next = vex[b1].to_L;
//			vex[b1].to_L = p;
//		}
//	}
//}
//
//void sort()
//{
//	int cnt = 0;
//	
//	for (int i = 0; i < vnum; i++)
//	{
//		if (vex[i].in == 0)
//		{
//			Q p = (Q)malloc(sizeof(struct queue));
//			p->next = rear->next;
//			p->v = i;
//			rear->next = p;
//			rear = p;
//		}
//	}
//	printf("\n");
//	while (front!=rear)//������ջ���׵�����������ǰ��ҪŪ��ջer
//	{
//		int k = front->next->v;//frontǰ��,�޳�һ����
//		printf(" %d",k);
//		Q p = front;
//		front = front->next;
//		free(p);
//
//		for (L e = vex[k].to_L; e; e = e->next)
//		{
//			if(--vex[e->v].in==0)
//			{
//				Q p = (Q)malloc(sizeof(struct queue));
//				p->next = rear->next;
//				p->v = e->v;
//				rear->next = p;
//				rear = p;
//			}
//		}
//	}
//}
//
//int main()
//{
//	init();
//	createg();
//	sort();
//	return 0;
//}
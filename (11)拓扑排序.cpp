//队列入 入度为0的点  然后踢出更新 同时进新点
//不用邻接矩阵，用邻接表

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
//		printf("\n输入顶点数，边数(x/x)：");
//		scanf_s("%d/%d", &vnum, &bnum);
//		while (getchar() != '\n');
//		if (vnum > 20) { printf("\n太多了"); continue; }
//		if (vnum == 1) { printf("\n重新输入"); continue; }
//		if (vnum >= 2 && (vnum * (vnum - 1) / 2 < bnum))
//		{
//			printf("\n重新输入"); continue;
//		}
//		break;
//	}
//	/*for (int i = 0; i < vnum; i++)
//	{
//		printf("\n输入第%d个顶点的数据", i);
//		a[i] = getchar();
//		while (getchar() != '\n');
//	}*/
//	for (int i = 0; i < bnum; i++)
//	{
//		int b1, b2;
//		printf("\n输入第%d条有向边两端的顶点序号(x->x)", i + 1);
//		scanf_s("%d->%d", &b1, &b2);
//		while (getchar() != '\n');
//
//		b1--; b2--;
//		if (b1 >= MAX || b2 >= MAX)
//		{
//			printf("\n输入错误"); i--; continue;
//		}
//		//判断边是否已经存在
//		if (is_repeat(b1, b2))
//		{
//			printf("\n该边已经存在重新输入");
//			i--;
//		}
//		else//否则addL
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
//	while (front!=rear)//这里用栈到底的条件，所以前面要弄个栈er
//	{
//		int k = front->next->v;//front前进,剔除一个点
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
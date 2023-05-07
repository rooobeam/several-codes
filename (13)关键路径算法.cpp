//#include"tool.h"
//#define MAX 20
//
//int vnum, bnum;
//
//typedef struct edgenode {
//	int v;
//	int weight;
//	struct edgenode* next;
//}*L,*R_L;
//
//struct vex{
//	int in;
//	L to_L;
//	L to_R_L;
//}vex[MAX];
//
//typedef struct zhan {
//	int v;
//	struct zhan* back;
//	struct zhan* next;
//}*stack;
//
//stack base, top;
//
//int etv[MAX], ltv[MAX], ete[MAX], lte[MAX];
//
//void init()
//{
//	top = (stack)malloc(sizeof(struct zhan));
//	base = (stack)malloc(sizeof(struct zhan));
//	base->next = top;
//	base->back = NULL;
//	top->next = NULL;
//	top->back = base;
//
//
//	for (int i = 0; i < MAX; i++)
//	{
//		vex[i].in = 0;
//		vex[i].to_L = NULL;
//		vex[i].to_R_L = NULL;
//		etv[i] = 0;
//		ltv[i] = 0;
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
//		int b1, b2, n;
//		printf("\n�����%d����������˵Ķ������(x x)", i + 1);
//		scanf_s("%d %d", &b1, &b2);
//		while (getchar() != '\n');
//		printf("\n������Ȩֵ", i + 1);
//		scanf_s("%d", &n);
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
//			R_L q= (R_L)malloc(sizeof(struct edgenode));
//			q->v = b1;
//			q->weight = n;
//			q->next = vex[b2].to_R_L;
//			vex[b2].to_R_L = q;
//
//
//			L p = (L)malloc(sizeof(struct edgenode));
//			p->v = b2;
//			p->weight = n;
//			p->next = vex[b1].to_L;
//			vex[b1].to_L = p;
//		}
//	}
//}
//
//void createz()//����˫����ջ
//{
//	int cnt = 0;
//	
//	for (int i = 0; i < vnum; i++)//��Դ�����
//	{
//		if (vex[i].in == 0)
//		{
//			top->v = i;
//			stack p = (stack)malloc(sizeof(struct zhan));
//			p->next = NULL;
//			p->back = top;
//			top->next = p;
//			top = p;
//		}
//	}
//	printf("\n");
//	stack now = base->next;
//	while (now !=top)
//	{
//		int k =now->v;
//
//		for (L e = vex[k].to_L; e; e = e->next)
//		{
//			if(--vex[e->v].in==0)
//			{
//				top->v = e->v;
//				stack p = (stack)malloc(sizeof(struct zhan));
//				p->next = NULL;
//				p->back = top;
//				top->next = p;
//				top = p;
//			}
//		}
//		now = now->next;
//	}
//}
//
//void create_table()
//{
//	stack now = base->next;
//	while (now != top)//�������
//	{
//		int k = now->v;
//
//		for (L e = vex[k].to_L; e; e = e->next)
//		{
//			if (etv[e->v] < (e->weight + etv[k]))
//				etv[e->v] = (e->weight + etv[k]);
//		}
//		now = now->next;
//	}
//
//	now =top->back;//�������
//	while (now != base)
//	{
//		int k = now->v;
//
//		for (L e = vex[k].to_R_L; e; e = e->next)
//		{
//			ltv[e->v] = etv[k] - e->weight;
//		}
//		now = now->back;
//	}
//
//
//	printf("\n");//��ӡ����
//	now = base->next;
//	while (now != top)
//	{
//		if (etv[now->v] == ltv[now->v])
//			printf("\t%d", now->v+1);
//		if (vex[now->v].to_L == NULL)
//		{
//			printf("\t%d", now->v+1);
//			ltv[now->v] = etv[now->v];
//		}
//		now = now->next;
//	}
//
//	printf("\n");
//	for (int i = 0; i < vnum; i++)
//		printf("%d etv=%d\t",i+1,etv[i]);
//	printf("\n");
//	for (int i = 0; i < vnum; i++)
//		printf("%d ltv=%d\t", i + 1, ltv[i]);
//}
//
//int main()
//{
//	init();
//	createg();
//	createz();
//	create_table();
//	system("pause");
//	return 0;
//}
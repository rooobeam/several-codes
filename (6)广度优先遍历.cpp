////�ȷ������Ȿ������������еķ��������ߡ�˼·ȥǶ��
////���ݷ����ó��Ĵ���������߼���ʽȥ�����������з��������ߡ�˼·��û�еĻ����õײ�Ķ���ȥ�����Ȼ�����Ż���
////��ȱ����ö���ʵ�֡���¼����һ��һ���ߣ���ȱ����õݹ飬һͷ�����ס�
//#include"tool.h"
//#define MAX 20
//typedef struct bian {
//	int lv;
//	struct bian* lnext;
//	int rv;
//	struct bian* rnext;
//}*B;
//
//struct vertex {
//	char data;
//	B to_list;
//	bool sta;
//}a[MAX];
//
//typedef struct queue {
//	struct queue* next;
//	int no;
//}*Q;
//
//Q front, rear;
//int vnum, bnum;
//
//void init()
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		a[i].to_list = NULL;
//		a[i].sta = false;
//	}
//	front = (Q)malloc(sizeof(struct queue));
//	rear = front;
//	front->next = NULL;
//}
//
//int is_repeat(int v1,int v2)
//{
//	B p = a[v1].to_list;
//	while (1)
//	{
//		if (p == NULL)return 0;
//		if ((p->lv == v1 && p->rv == v2) || (p->lv == v2 && p->rv == v1))return 1;
//		else
//		{
//			if (p->lv == v1)p = p->lnext;
//			else p = p->rnext;
//		}
//	}
//}
//
//void addL(int lv, int rv)
//{
//	B p=(B)malloc(sizeof(struct bian));
//	p->lnext = a[lv].to_list;
//	p->rnext = a[rv].to_list;
//	p->lv = lv;
//	p->rv = rv;
//	a[lv].to_list = p;
//	a[rv].to_list = p;
//	return;
//}
//
//void createg()
//{
//	while (1)
//	{
//		printf("\n���붥����������(x/x)��");
//		scanf_s("%d/%d", &vnum, &bnum);
//		while (getchar() != '\n');
//		if (vnum == 1) { printf("\n��������"); continue; }
//		if (vnum >= 2) { if (vnum * (vnum - 1) / 2 < bnum)printf("\n��������"); continue; }
//		break;
//	}
//	for (int i = 0; i < vnum; i++)
//	{
//		printf("\n�����%d�����������", i + 1);
//		a[i].data = getchar();
//		while (getchar() != '\n');
//	}
//	for (int i = 0; i < bnum; i++)
//	{
//		printf("\n�����%d�������˵Ķ������(x/x)", i + 1);
//		int b1, b2;
//		scanf_s("%d/%d", &b1, &b2);
//		b1--; b2--;
//		if (b1 >= MAX || b2 >= MAX)
//		{
//			printf("\n�������");
//		}
//		while (getchar() != '\n');
//		//����һ�������list�жϱ��Ƿ��Ѿ�����
//		if (is_repeat(b1, b2))
//		{
//			printf("\n�ñ��Ѿ�������������");
//			i--;
//		}
//		else//����ͷ�巨Ϊ���������list���� ��
//		{
//			addL(b1, b2);
//		}
//	}
//}
//
//void addq(int n)
//{
//	Q p = (Q)malloc(sizeof(struct queue));
//	p->next = NULL;
//	p->no = n;
//	rear->next = p;
//	rear = p;
//}
//
//void sw_about(B p,int no)
//{
//	while (1)
//	{
//		if (p->lv != no && a[p->lv].sta != true) {
//			printf(" %c ", a[p->lv].data); a[p->lv].sta = true; addq(p->lv);
//		}
//		if (p->rv != no && a[p->rv].sta != true) {
//			printf(" %c ", a[p->rv].data); a[p->rv].sta = true; addq(p->rv);
//		}
//		if (p->lv == no)p = p->lnext;
//		else p = p->rnext;
//		if (p == NULL)break;
//	}
//}
//
//void gothrough(int no)
//{
//	//�����ǰ��s
//	printf(" %c ", a[no].data);
//	a[no].sta = true;
//	//����ǰ��������
//	addq(no);
//	//�ö��д����������ŵĵ�
//	Q p = front->next;
//	while (p)
//	{
//		//ȡ�׸���ɨ����Χ��������rearָ��һ��
//		sw_about(a[p->no].to_list, p->no);
//		Q u = p;
//		p = p->next;
//		free(u);
//	}
//	return;
//}
//
//int main()
//{
//	init();
//	createg();
//	gothrough(0);
//	system("pause");
//	return 0;
//}

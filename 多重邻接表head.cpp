//#include"�����ڽӱ�head.h"
//
//void print1()
//{
//	printf("\n�����ַ�������ո��ʾ�˳�\n");
//	return;
//}
//void print2(int j, struct vertex v[])
//{
//	printf("\n�Ƿ����%d��������Ϊ%c�Ķ����б�,����1������������\n",j+1,v[j].data);
//	return;
//}
//
//void init(struct vertex v[])
//{
//	for (int i = 0; i < MAX; i++) 
//	{
//		v[i].p = NULL; 
//		v[i].sta = wei;
//	}
//}
//
//void absort()
//{
//	while (getchar() != '\n');
//}
//
//void addl(int i,int j, struct vertex v[])
//{
//	b newb = (b)malloc(sizeof(struct bian));
//	newb->lv = i;
//	newb->rv = j;
//	newb->lnext = v[newb->lv].p;
//	v[newb->lv].p = newb;
//	newb->rnext = v[newb->rv].p;
//	v[newb->rv].p = newb;
//}
//
//void createg(struct vertex v[])
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		print1();
//		char ch = getchar();
//        absort();
//		if (ch == ' ')return;
//		v[i].data = ch;
//		if (i == 0)continue;
//
//		for (int j = 0; j < i; j++)//����
//		{
//			print2(j,v);
//			char ch_ = getchar();
//			absort();
//			if (ch_ == '1')addl(i,j,v);
//		}
//	}
//}
//
//void locate(int k,b now,char aim, struct vertex v[],int n,int a[])
//{
//	if (now == NULL)return;
//	else 
//	{
//		if (v[k].sta == yi)return;
//		if (v[k].data == aim && v[k].sta == wei)a[n++] = k;
//        v[k].sta=yi;
//
//		if (now->lv != k)
//		{
//			locate(now->lv, v[now->lv].p, aim, v, n, a); locate(now->rv, now->rnext, aim, v, n, a);
//		}
//		else
//		{
//			locate(now->rv, v[now->rv].p, aim, v, n, a); locate(now->lv, now->lnext, aim, v, n, a);
//		}
//		return;
//	}
//}
//
//void search(struct vertex v[])
//{
//	printf("\n����������ҵ�����\n");
//	char aim = getchar();
//	absort();
//	int a[MAX];
//	for (int i = 0; i < MAX; i++)a[i] = MAX;
//	locate(0,v[0].p, aim,v,0,a);
//	for (int i = 0; i < MAX; i++)if (a[i] != MAX)printf("\n\t%d\n", a[i]);
//}
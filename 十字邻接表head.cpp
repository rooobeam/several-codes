//#include"十字邻接表head.h"
//
//void print1()
//{
//	printf("\n输入字符，输入空格表示退出\n");
//	return;
//}
//
//
//void init(struct bian b[][MAX], struct vertex v[])
//{
//	int i,j;
//	for (i = 0; i < MAX; i++)
//	{
//		v[i].hlink = NULL;
//		v[i].tlink = NULL;
//		for (j = 0; j < MAX; j++)b[i][j].n = wu;
//	}
//}
//
//void printform(struct bian b[][MAX],int i)
//{
//	for (int x = 0; x < i; x++)
//	{
//		printf("\n");
//		for (int y = 0; y < i; y++)
//		{
//			printf("\t%d", b[x][y].n);
//		}
//	}
//}
//
//void createL(int i, int j, L*T,L*H)
//{
//	L p;
//	if ((*T) == NULL)
//	{
//		p = (L)malloc(sizeof(struct list));
//		p->hlink = NULL;
//		p->tlink = NULL;
//		p->tail = i;
//		p->head = j;
//		(*T) = p;
//		p;
//	}
//	else
//	{
//		for (p = (*T); p->tlink; p = p->tlink);
//		L next = (L)malloc(sizeof(struct list));
//		next->hlink = NULL;
//		next->tlink = NULL;
//		next->tail = i;
//		next->head = j;
//		p->tlink = next;
//		p = next;
//	}
//	
//	if ((*H) == NULL)
//	{
//		(*H) = p;
//	}
//	else
//	{
//		L u;
//		for (u = (*H); u->hlink; u = u->hlink);
//		u->hlink = p;
//	}
//}
//
//void createg(struct bian b[][MAX], int* i, struct vertex v[])
//{
//	int j;
//	char ch;
//	for (*i = 0; (*i) < MAX; (*i)++)
//	{
//		print1();
//		ch = getchar();
//		while (getchar() != '\n');
//
//		if (ch == ' ')
//		{
//			if (*i == 0) break;
//			else return;
//		}
//		v[*i].data = ch;
//		for (j = 0; j < *i; j++)
//		{
//			printf("\n第%d个，数据为%c的顶点指向它吗？,是输1，不是输其它\n", j + 1, v[j].data);
//			char ch_ = getchar();
//			while (getchar() != '\n');
//			if (ch_ == '1')
//			{
//				b[j][*i].n = you;
//				createL(j, *i, &v[j].tlink, &v[*i].hlink);
//			}
//
//			
//			printf("\n第%d个，数据为%c的顶点被它指向吗？,是输1，不是输其它\n", j + 1, v[j].data);
//			ch_ = getchar();
//			while (getchar() != '\n');
//			if (ch_ == '1')
//			{
//				b[*i][j].n = you;
//				createL(*i, j, &v[*i].tlink, &v[j].hlink);
//			}
//		}
//	}
//	return;
//}
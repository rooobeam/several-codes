//#include"tool.h"
//#define MAX 20
//#define INF 32767
//
//int vnum, bnum, edge[MAX][MAX];
//
//struct vertex {
//	bool sta;
//	int weight;
//	char ch[MAX];
//}v[MAX];
//void init()
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		sprintf_s(v[i].ch, "%d", i);
//		v[i].sta = false;
//		for (int j = 0; j < MAX; j++)
//		{
//			edge[i][j] = INF;
//			edge[j][i] = edge[i][j];
//		}
//	}
//}
//
//int is_repeat(int v1, int v2)
//{
//	if (edge[v1][v2] == INF)return 0;
//	else return 1;
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
//		int b1, b2, weight;
//		printf("\n�����%d�������˵Ķ������(x/x)", i + 1);
//		scanf_s("%d/%d", &b1, &b2);
//		while (getchar() != '\n');
//		printf("\n����ñߵ�Ȩֵ");
//		scanf_s("%d", &weight);
//		while (getchar() != '\n');
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
//		else//������ӵ�������
//		{
//			edge[b1][b2] = weight;
//			edge[b2][b1] = weight;
//		}
//	}
//}
//
//void creater()
//{
//	int start,end;
//	printf("\n������㡢�յ�(x/x)\n");
//	scanf_s("%d/%d", &start,&end);
//	if (start > vnum)
//	{
//		printf("\n�������\n");
//		return;
//	}
//	--start; --end;
//	while (getchar() != '\n');
//	for (int i = 0; i < vnum; i++)
//	{
//		v[i].weight = edge[start][i];
//		if (edge[start][i] != INF)
//		{
//			strcat_s(v[i].ch, 20, v[start].ch);
//		}
//	}
//	v[start].weight = 0;
//	v[start].sta = true;
//
//
//	for (int i = 0; i < vnum - 1; i++)
//	{
//		int index = -1;
//		int min = INF;
//		for (int j = 0; j < vnum; j++)//����С
//		{
//			if (v[j].weight < min&&v[j].sta!=true)
//			{
//				min = v[j].weight;
//				index = j;
//			}
//		}
//		if (index == -1)continue;
//		v[index].sta = true;//���
//
//		for (int j = 0; j < vnum; j++)//������Χδ��ǵ�
//		{
//			if (edge[index][j] != INF && v[j].sta != true&& edge[index][j]+v[index].weight<v[j].weight)
//			{
//				v[j].weight = edge[index][j] + v[index].weight;
//				sprintf_s(v[j].ch, "%d", j);
//				strcat_s(v[j].ch, 20, v[index].ch);
//			}
//		}
//	}
//	printf("\n");
//	for (int i = vnum - 1; i >= 0; --i)
//		printf("%c ", v[end].ch[i]);
//}
//
//
//int main()
//{
//	init();
//	createg();
//	creater();
//	system("pause");
//	return 0;
//}
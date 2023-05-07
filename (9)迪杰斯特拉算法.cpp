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
//		int b1, b2, weight;
//		printf("\n输入第%d条边两端的顶点序号(x/x)", i + 1);
//		scanf_s("%d/%d", &b1, &b2);
//		while (getchar() != '\n');
//		printf("\n输入该边的权值");
//		scanf_s("%d", &weight);
//		while (getchar() != '\n');
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
//		else//否则添加到矩阵中
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
//	printf("\n输入起点、终点(x/x)\n");
//	scanf_s("%d/%d", &start,&end);
//	if (start > vnum)
//	{
//		printf("\n输入错误\n");
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
//		for (int j = 0; j < vnum; j++)//找最小
//		{
//			if (v[j].weight < min&&v[j].sta!=true)
//			{
//				min = v[j].weight;
//				index = j;
//			}
//		}
//		if (index == -1)continue;
//		v[index].sta = true;//标记
//
//		for (int j = 0; j < vnum; j++)//更新周围未标记点
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
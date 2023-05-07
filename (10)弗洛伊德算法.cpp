//#include"tool.h"
//#define MAX 20
//#define INF 32767
//char a[MAX];//这个没有初始化也没有用上
//
//int vnum, bnum, vex[MAX], edge[MAX][MAX], path[MAX][MAX];
//
//void init()
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		vex[i] = -1;
//		for (int j = 0; j < MAX; j++)
//		{
//			edge[i][j] = INF;
//			edge[j][i] = edge[i][j];
//			path[j][i] = i;
//			path[i][j] = path[j][i];
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
//	for (int i = 0; i < vnum; i++)
//	{
//		for (int j = 0; j < vnum; j++)//起点
//		{
//			for (int k = 0; k < vnum; k++)//终点
//			{
//				if (edge[j][k] > edge[i][j] + edge[i][k])
//				{
//					edge[j][k] = edge[i][j] + edge[i][k];
//					edge[k][j] = edge[j][k];
//					path[j][k] = path[j][i];
//					path[k][j] = path[j][k];
//				}
//			}
//		}
//	}
//	int v1, v2;
//	printf("\n输入起点和终点(x/x)\n");
//	scanf_s("%d/%d", &v1, &v2);
//	printf("\n距离为%d", edge[--v1][--v2]);
//}
//
//int main()
//{
//	init();
//	createg();
//	creater();
//	return 0;
//}
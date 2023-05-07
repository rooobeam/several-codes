//#include"tool.h"
//#define MAX 20
//#define IMP 32767
//char a[MAX];
//
//int vnum, bnum, NO;
//
////   邻近边权值   邻近点    集合点     邻接矩阵，各边权值
//int lowcost[MAX],adjvex[MAX],vex[MAX],edge[MAX][MAX];
//
//struct {
//	int lv, rv;
//}b[MAX];
//
//void init()
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		vex[i] = -1;//集合内点初始为-1
//		adjvex[i] = -1;//邻近点初始为-1
//		lowcost[i] = IMP;//邻近边权值无穷
//		for (int j = 0; j < MAX; j++)//各边权值初始为IMP
//		{
//			edge[i][j] = IMP;
//			edge[j][i] = edge[i][j];
//		}
//	}
//	edge[0][0] = IMP;
//}
//
//int is_repeat(int v1,int v2)
//{
//	if (edge[v1][v2] == IMP)return 0;
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
//		if (vnum >= 2&&(vnum * (vnum - 1) / 2 < bnum))
//		{
//				printf("\n重新输入"); continue;
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
//		int b1, b2,weight;
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
//int MIN()
//{
//	int mini = lowcost[0]; NO = 0;
//	for (int i = 1; lowcost[i] != IMP; i++)
//	{
//		if (lowcost[i] < mini)NO = i;
//	}
//	return b[NO].rv;
//}
//
//void creater()
//{
//	int birth;
//	printf("\n输入起始点序号：");
//	scanf_s("%d", &birth);
//	--birth;
//	printf("\n");
//	vex[0] = birth;
//
//	for (int i = 0; i < vnum-1; ++i)
//	{
//
//		for (int j = 0; vex[j] != -1; ++j)//筛选邻近点
//		{
//			for (int k = 0, m=0; k < vnum; k++)
//			{
//				if (edge[ vex[j] ][k] != IMP && edge[ vex[j] ][k] != 0)
//				{
//					lowcost[m] = edge[vex[j]][k];
//					b[m].lv = vex[j];
//					b[m].rv = k;
//					++m;
//				}
//			}
//		}
//	
//		vex[i + 1] = MIN();
//		printf("  %d  %d", b[NO].lv, b[NO].rv);
//		for (int j = 0; j < i + 1; ++j)
//		{
//			edge[ vex[j] ][vex[i + 1]] = 0;
//			edge[vex[i + 1]][ vex[j] ] = edge[ vex[j] ][vex[i + 1]];
//		}
//
//		for (int i = 0; i < MAX; i++)
//		{
//			lowcost[i] = IMP;
//		}
//	}
//	return;
//}
//
//int main()
//{
//	init();
//	createg();
//	creater();
//	system("pause");
//	return 0;
//}

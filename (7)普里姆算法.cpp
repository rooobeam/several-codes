//#include"tool.h"
//#define MAX 20
//#define IMP 32767
//char a[MAX];
//
//int vnum, bnum, NO;
//
////   �ڽ���Ȩֵ   �ڽ���    ���ϵ�     �ڽӾ��󣬸���Ȩֵ
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
//		vex[i] = -1;//�����ڵ��ʼΪ-1
//		adjvex[i] = -1;//�ڽ����ʼΪ-1
//		lowcost[i] = IMP;//�ڽ���Ȩֵ����
//		for (int j = 0; j < MAX; j++)//����Ȩֵ��ʼΪIMP
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
//		printf("\n���붥����������(x/x)��");
//		scanf_s("%d/%d", &vnum, &bnum);
//		while (getchar() != '\n');
//		if (vnum > 20) { printf("\n̫����"); continue; }
//		if (vnum == 1) { printf("\n��������"); continue; }
//		if (vnum >= 2&&(vnum * (vnum - 1) / 2 < bnum))
//		{
//				printf("\n��������"); continue;
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
//		int b1, b2,weight;
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
//	printf("\n������ʼ����ţ�");
//	scanf_s("%d", &birth);
//	--birth;
//	printf("\n");
//	vex[0] = birth;
//
//	for (int i = 0; i < vnum-1; ++i)
//	{
//
//		for (int j = 0; vex[j] != -1; ++j)//ɸѡ�ڽ���
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

/*#include"tool.h"
#define MAX 8//8时输入0/0很快出图

struct chess {
	int cnt;
	bool sta;
}a[MAX][MAX];
int num=1;

void init()
{
	int i, j;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)a[i][j].sta = false;
}

void print()
{
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		printf("\n");
		for (j = 0; j < MAX; j++)printf("\t%d", a[i][j].cnt);
	}
}

int nextxy(int*x,int*y,int no)
{
	int x1 = (*x), y1 = (*y);
	switch (no)
	{
	case 1:if (x1 - 2 >= 0 && y1 + 1 < MAX && a[x1 - 2][y1 + 1].sta != true) {
		(*x) = x1 - 2; (*y) = y1 + 1; return 1;
	} break;
	case 2:if (x1 - 1 >= 0 && y1 + 2 < MAX && a[x1 - 1][y1 + 2].sta != true) {
		(*x) = x1 - 1; (*y) = y1 + 2; return 1;
	}break;
	case 3:if (x1 + 1 < MAX && y1 + 2 < MAX && a[x1 + 1][y1 + 2].sta != true) {
		(*x) = x1 + 1; (*y) = y1 + 2; return 1;
	}break;
	case 4:if (x1 + 2 < MAX && y1 + 1 < MAX && a[x1 + 2][y1 + 1].sta != true) {
		(*x) = x1 + 2; (*y) = y1 + 1; return 1;
	}break;
	case 5:if (y1 - 1 >= 0 && x1 + 2 < MAX && a[x1 + 2][y1 - 1].sta != true) {
		(*x) = x1 + 2; (*y) = y1 - 1; return 1;
	}break;
	case 6:if (y1 - 2 >= 0 && x1 + 1 < MAX && a[x1 + 1][y1 - 2].sta != true) {
		(*x) = x1 + 1; (*y) = y1 - 2; return 1;
	}break;
	case 7:if (y1 - 2 >= 0 && x1 - 1 >= 0 && a[x1 - 1][y1 - 2].sta != true) {
		(*x) = x1 - 1; (*y) = y1 - 2; return 1;
	}break;
	case 8:if (y1 - 1 >= 0 && x1 - 2 >= 0 && a[x1 - 2][y1 - 1].sta != true) {
		(*x) = x1 - 2; (*y) = y1 - 1; return 1;
	}break;
	default:return 0;
	}
	return 0;
}

void travel(int* x, int* y)
{
		a[*x][*y].cnt = num++;//没读过的点记录并标记为读过
		a[*x][*y].sta = true;
		int k = 1;
		
		
		while (k <= 8)//历遍各个可能的点
		{
			int x1 = (*x), y1 = (*y);
			if (nextxy(&x1, &y1, k)) { travel(&x1, &y1);}
			k++;
		}

		if (num == MAX * MAX+1)return;
		else
		{
			a[*x][*y].cnt = 0;
			num--;
			a[*x][*y].sta = false;
			return;
		}
}

int main()
{
	init();
	int x, y;
	while (1)//确保首坐标合理
	{
		printf("\n输入起始位置(x/y)\n");
		scanf_s("%d/%d", &x, &y);
		while (getchar() != '\n');
		if (x >= 0 && x < MAX && y >= 0 && y < MAX)break;
	}
	travel(&x, &y);
	if(num==MAX*MAX+1);
	else
	{
		int i, j;
		for (i=0; i < MAX; i++)
			for (j=0; j < MAX; j++)a[i][j].cnt = 0;
	}
	print();
}*/
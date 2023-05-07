//#include<stdio.h>
//#include<string.h>
//#define MAX 20
//void search(int str[MAX],int n,int length)
//{
//	int low, mid, high, cnt;
//	low = 0; high = length; cnt = 0;
//	
//	while (low != high)
//	{
//		cnt++;
//
//		mid = (low+high)/2;
//
//		if (str[mid] == n)
//		{
//			printf("\n%d %d 次数%d\n", mid, n, cnt);
//			return;
//		}
//
//		if (str[mid] < n)//查后半段
//		{
//			low = mid + 1;
//		}
//
//		if (str[mid] > n)//查前半段
//		{
//			high = mid - 1;
//			if (str[high] == n)
//			{
//				printf("\n%d %d 次数%d\n", high, n, ++cnt);
//				return;
//			}
//		}
//	}
//	printf("\n无此数据\n");
//}
//
//int main()
//{
//	int str[MAX], i, length = 0, n;
//	for ( i = 0; i < MAX; i++)
//	{
//		printf("\n输入数据：\n");
//		scanf_s("%d", str+i);
//		getchar();
//		if (str[i] != 0)length++;
//		else break;
//	}
//
//	printf("\n输入要查找的数据\n");
//	scanf_s("%d", &n);
//	getchar();
//	search(str, n, length);
//
//
//
//	return 0;
//}
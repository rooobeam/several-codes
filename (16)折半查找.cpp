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
//			printf("\n%d %d ����%d\n", mid, n, cnt);
//			return;
//		}
//
//		if (str[mid] < n)//�����
//		{
//			low = mid + 1;
//		}
//
//		if (str[mid] > n)//��ǰ���
//		{
//			high = mid - 1;
//			if (str[high] == n)
//			{
//				printf("\n%d %d ����%d\n", high, n, ++cnt);
//				return;
//			}
//		}
//	}
//	printf("\n�޴�����\n");
//}
//
//int main()
//{
//	int str[MAX], i, length = 0, n;
//	for ( i = 0; i < MAX; i++)
//	{
//		printf("\n�������ݣ�\n");
//		scanf_s("%d", str+i);
//		getchar();
//		if (str[i] != 0)length++;
//		else break;
//	}
//
//	printf("\n����Ҫ���ҵ�����\n");
//	scanf_s("%d", &n);
//	getchar();
//	search(str, n, length);
//
//
//
//	return 0;
//}
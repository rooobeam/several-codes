//#include"tool.h"
//#define MAX 20
//
//
//
//void print1()
//{
//	printf("\n�����ַ�������ո��ʾ�˳�\n");
//	return;
//}
//
//
//
//int main()
//{
//	int i, j, n=0;
//	char ch;
//	typedef enum { wu, you }ex;
//
//	struct vertex
//	{
//		char data;
//		struct vertex* p;
//	}v[MAX];
//	struct bian
//	{
//		ex n;
//	}b[MAX][MAX];
//
//	for (i = 0; i < MAX; i++)
//		for (j = 0; j < MAX; j++)b[i][j].n = wu;
//
//	for (i = 0; i < MAX; i++)
//	{
//		print1();
//		ch = getchar();
//		while (getchar() != '\n');
//		if (ch == ' ')
//		{
//			n = i; break;
//		}
//		v[i].data = ch;
//		for (j = 0; j < i; j++)
//		{
//			printf("\n�Ƿ����%d��������Ϊ%c�Ķ����б�,����1������������\n", j+1, v[j].data);
//			char ch_ = getchar();
//			while (getchar() != '\n');
//			if (ch_ == '1')
//			{
//				b[i][j].n = you;
//				b[j][i].n = you;
//				v[i].p = &v[j];
//				v[j].p = &v[i];
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("\n");
//		for (j = 0; j < n; j++)
//		{
//			printf("\t%d", b[i][j].n);
//		}
//	}
//
//	system("pause");
//	return 0;
//}
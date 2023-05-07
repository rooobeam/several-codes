//#include"tool.h"
//#define MAX 20
//int* next;
//char ch[MAX], CH[MAX];
//void init()
//{
//	//获取模式串
//	printf("输入模式串:");
//	scanf_s("%s", ch,MAX);
//	getchar();
//
//	// next 数组获取内存
//	int n = strlen(ch);
//	next = (int*)malloc(n * sizeof(int));
//	next[0] = -1;
//
//	//获取目标串
//	printf("输入目标串:");
//	scanf_s("%s", CH, MAX);
//	getchar();
//}
//
//void cre_arry()
//{
//	//int cnt ,j=-1;
//	//for (int i = 0; ch[i]; i++)
//	//{
//	//	cnt = i;
//	//
//	//	for (int j , k = 1,m; k <= i; k++)//找出最大cnt
//	//	{
//	//		j = 0; m = k;
//	//		for (; m <= i;m++,j++)
//	//		{
//	//			if (ch[j] != ch[m])
//	//			{
//	//				cnt--; break;
//	//			}
//	//		}
//	//		if (m==i+1)break;
//	//	}
//	//	next[i] = cnt;//给next[i]
//	//}
//
//	int j, k;
//	j = 0; k = -1;
//	next[0] = -1;//第一个字符前无字符串，给值-1
//	while (ch[j])
//	{
//		if (k == -1 || ch[j] == ch[k]) 	//k为-1或比较的字符相等时
//		{
//			j++; k++;
//			next[j] = k;
//			//对应字符匹配情况下，s与t指向同步后移
//			//通过字符串"aaaaab"求next的意义
//			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,数组过程想一下这一步k);
//		}
//		else
//		{
//			k = next[k];/*****************/
//			//我们现在知道next[k]的值代表的是下标为k的字符前面的字符串最长相等前后缀的长度
//			//也表示该处字符不匹配时应该回溯到的字符的下标
//			//这个值给k后又进行while循环判断，此时t.data[k]即指最长相等前缀后一个字符**
//			//为什么要回退此处进行比较，我们往下接着看。其实原理和上面介绍的KMP原理差不多
//			//printf("(2) k=%d\n",k);
//		}
//	}
//}
//
//int main()
//{
//	init();
//	cre_arry();
//	system("pause");
//	return 0;
//}
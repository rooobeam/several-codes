//#include"tool.h"
//#define MAX 20
//int* next;
//char ch[MAX], CH[MAX];
//void init()
//{
//	//��ȡģʽ��
//	printf("����ģʽ��:");
//	scanf_s("%s", ch,MAX);
//	getchar();
//
//	// next �����ȡ�ڴ�
//	int n = strlen(ch);
//	next = (int*)malloc(n * sizeof(int));
//	next[0] = -1;
//
//	//��ȡĿ�괮
//	printf("����Ŀ�괮:");
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
//	//	for (int j , k = 1,m; k <= i; k++)//�ҳ����cnt
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
//	//	next[i] = cnt;//��next[i]
//	//}
//
//	int j, k;
//	j = 0; k = -1;
//	next[0] = -1;//��һ���ַ�ǰ���ַ�������ֵ-1
//	while (ch[j])
//	{
//		if (k == -1 || ch[j] == ch[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
//		{
//			j++; k++;
//			next[j] = k;
//			//��Ӧ�ַ�ƥ������£�s��tָ��ͬ������
//			//ͨ���ַ���"aaaaab"��next������
//			//printf("(1) j=%d,k=%d,next[%d]=%d\n",j,k,j,���������һ����һ��k);
//		}
//		else
//		{
//			k = next[k];/*****************/
//			//��������֪��next[k]��ֵ��������±�Ϊk���ַ�ǰ����ַ�������ǰ��׺�ĳ���
//			//Ҳ��ʾ�ô��ַ���ƥ��ʱӦ�û��ݵ����ַ����±�
//			//���ֵ��k���ֽ���whileѭ���жϣ���ʱt.data[k]��ָ����ǰ׺��һ���ַ�**
//			//ΪʲôҪ���˴˴����бȽϣ��������½��ſ�����ʵԭ���������ܵ�KMPԭ����
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
//#include"tool.h"
//#define MAX 20
//#define INF 32767
//char a[MAX];//���û�г�ʼ��Ҳû������
//
//int vnum, bnum, vex[MAX], edge[MAX][MAX], ends[MAX], maxi=-1;
//
//enum {A,B,C}v_sta[MAX];
//
//struct {
//	int lv, rv, weight;
//}b[MAX],prepare;
//
//void init()
//{
//	for (int i = 0; i < MAX; i++)
//	{
//		v_sta[i] = A;
//		ends[i] = -1;
//		vex[i] = -1;
//		for (int j = 0; j < MAX; j++)
//		{
//			edge[i][j] = INF;
//			edge[j][i] = edge[i][j];
//		}
//		b[i].lv = -1;
//		b[i].rv = -1;
//		b[i].weight = INF;
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
//		printf("\n���붥����������(x/x)��");
//		scanf_s("%d/%d", &vnum, &bnum);
//		while (getchar() != '\n');
//		if (vnum > 20) { printf("\n̫����"); continue; }
//		if (vnum == 1) { printf("\n��������"); continue; }
//		if (vnum >= 2 && (vnum * (vnum - 1) / 2 < bnum))
//		{
//			printf("\n��������"); continue;
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
//		int b1, b2, weight;
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
//			b[i].lv = b1;//ע����������������˳���
//			b[i].rv = b2;
//			b[i].weight = weight;
//			edge[b1][b2] = weight;
//			edge[b2][b1] = weight;
//		}
//	}
//}
//
//void sort()
//{
//	for (int i = 0; b[i].weight != INF; i++)
//	{
//		int min = b[i].weight, NO = i;
//		for (int j = i; b[j].weight != INF; j++)
//		{
//			if (b[j].weight < min)
//			{
//				min = b[j].weight; NO = j;
//			}
//		}
//		prepare = b[NO];
//		b[NO] = b[i];
//		b[i] = prepare;
//	}
//}
//
//bool is_fin()
//{
//	for (int i = 0; i < vnum - 1; i++)
//		if (ends[i] != ends[i+1])return false;
//	if (ends[0] != -1)return true;
//	else return false;
//}
//
//bool is_cir(int v1,int v2)
//{
//	if (ends[v1] == ends[v2] && ends[v1] != -1)return true;
//	else return false;
//}
////bool check(int x,int y){
////     if(father(x)==father(y)){
////        return true;
////      }
////      return false;
////}     
//void find(int v)
//{
//	
//	if (v_sta[v] == B) return;
//	else
//	{
//		v_sta[v] = B;
//		if (v > maxi)maxi = v;
//		for (int j = 0; j < vnum; j++)
//		{
//			if (edge[v][j] == 0)
//			{
//				find(j);
//			}
//		}
//	}
//	return;
//}
//
//bool is_exist(int v)
//{
//	for (int i = 0; vex[i] != -1; i++)
//	{
//		if (v == vex[i])return true;
//	}
//	return false;
//}
//
//void update(int v1,int v2,int NO)       //���ֲ���  ͬһ����ֻ��fatherԪ�� x=n[x]  �ϲ���������ʱ�������һ�����ϵ� x[n]�ı�   ��������Ԫ�ص�father��ݹ�ָ��x=x[n]�ļһ� 
//{                                       //int father(int x){
//	printf("  %d����%d", v1, v2);       //    if(x==n[x])return x;
//	if (!is_exist(v1))	vex[NO++] = v1; //    n[x]=father(n[x]);//(�˴�ѹ��·��)
//	if (!is_exist(v2))	vex[NO++] = v2; //    return father(n[x]); 
//	edge[v1][v2] = 0;                   //}
//	edge[v2][v1] = edge[v1][v2];        
//	                                    
//	for (int i = 0; vex[i] != -1; i++)  
//	{                                   
//		if (v_sta[vex[i]] == C)continue;
//		maxi = vex[i];                  
//		find(vex[i]);//��v[i]���ӵĵ���ΪB�����ҵõ���ͨ��������maxi//�˴�����д��һ����
//		for (int j = 0; j < vnum; j++)//���ղ���ͨ�ĵ�ends���²����ΪC
//		{                               
//			if (v_sta[j] == B)           //void merge(int x,int y){
//			{                            //     n(father(x))=father(y);
//				ends[j] = maxi;          //}
//				v_sta[j] = C;            
//			}                            
//		}                                
//	}                                    
//	
//}
//
//void creater()
//{
//	int NO = 0;
//	sort();
//	printf("\n");
//	for (int i = 0; i < vnum; i++)
//	{
//		int v1 = b[i].lv, v2 = b[i].rv;
//
//		if (is_fin())return;//��vex[MAX]��ĵ���յ��ж�
////�������vex��ĵ���յ�
//		if (is_cir(v1,v2))continue;
//		else update(v1,v2,NO);//���³��ֵı���Զ��ʱ ���update ends[]
//	}
//}
//
//int main()
//{
//	init();
//	createg();
//	creater();
//	return 0;
//}
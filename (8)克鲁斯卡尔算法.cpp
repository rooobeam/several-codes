//#include"tool.h"
//#define MAX 20
//#define INF 32767
//char a[MAX];//这个没有初始化也没有用上
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
//			b[i].lv = b1;//注意这里两个点是有顺序的
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
//void update(int v1,int v2,int NO)       //高手操作  同一集合只有father元素 x=n[x]  合并两个集合时会把其中一个集合的 x[n]改变   所有其它元素的father会递归指向x=x[n]的家伙 
//{                                       //int father(int x){
//	printf("  %d——%d", v1, v2);       //    if(x==n[x])return x;
//	if (!is_exist(v1))	vex[NO++] = v1; //    n[x]=father(n[x]);//(此处压缩路径)
//	if (!is_exist(v2))	vex[NO++] = v2; //    return father(n[x]); 
//	edge[v1][v2] = 0;                   //}
//	edge[v2][v1] = edge[v1][v2];        
//	                                    
//	for (int i = 0; vex[i] != -1; i++)  
//	{                                   
//		if (v_sta[vex[i]] == C)continue;
//		maxi = vex[i];                  
//		find(vex[i]);//将v[i]连接的点标记为B，并且得到联通过的最大点maxi//此处并集写得一坨答辩
//		for (int j = 0; j < vnum; j++)//将刚才联通的点ends更新并标记为C
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
//		if (is_fin())return;//从vex[MAX]里的点的终点判断
////否则更新vex里的点的终点
//		if (is_cir(v1,v2))continue;
//		else update(v1,v2,NO);//当新出现的边在远处时 如何update ends[]
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
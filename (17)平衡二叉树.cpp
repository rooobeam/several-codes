//#include"tool.h"
//
//typedef struct tree {
//	struct tree* P;
//	struct tree* L;
//	struct tree* R;
//	int data;
//	int height;
//}*T;
//T always_root;
//int calcha(T root)//计算左右高度差
//{
//	if (root->L == NULL && root->R == NULL)return 0;
//	if (root->L == NULL && root->R != NULL)return -(root->R->height);
//	if (root->L != NULL && root->R == NULL)return (root->L->height);
//	return root->L->height-root->R->height ;
//}
//
//int calheight(T root)//更新/计算当前节点高度
//{
//	if (root->L == NULL && root->R == NULL)return 1;
//	if (root->L == NULL && root->R != NULL)return (root->R->height + 1);
//	if (root->L != NULL && root->R == NULL)return (root->L->height + 1);
//	return root->R->height > root->L->height ? root->R->height + 1 : (root->L->height + 1);
//}
//
//void turnl(T root)//注意把旋下的点height 变为1
//{
//	T newroot = root->R;
//
//	//处理旧root 的 parent
//	if (root->P != NULL) {
//		if (root->P->L == root)root->P->L = newroot;
//		else root->P->R = newroot;
//	}
//	else always_root = newroot;
//	newroot->P = root->P;
//
//	//处理新root的左子树
//	root->R = newroot->L;
//	if (newroot->L != NULL)
//		newroot->L->P = root;
//
//	//处理新root 和旧 root
//	root->P = newroot;
//	newroot->L = root;
//}
//
//void turnr(T root)
//{
//	T newroot = root->L;
//
//	//处理旧root 的 parent
//	if (root->P != NULL) {
//		if (root->P->R == root)root->P->R = newroot;
//		else root->P->L = newroot;
//	}
//	else always_root = newroot;
//	newroot->P = root->P;
//
//	//处理新root的左子树
//	root->L = newroot->R;
//	if (newroot->R != NULL)
//		newroot->R->P = root;
//
//	//处理新root 和旧 root
//	root->P = newroot;
//	newroot->R = root;
//}
//
//void addT(T root,int n)
//{
//	//添加
//	if (n <= root->data){
//		if (root->L == NULL){
//			T newnode = (T)malloc(sizeof(struct tree));
//			newnode->P = root;
//			newnode->L = NULL;
//			newnode->R = NULL;
//			newnode->data = n;
//			newnode->height = 1;
//			root->L = newnode;
//		}
//		else addT(root->L, n);
//	}
//	else{
//		if (root->R == NULL) {
//			T newnode = (T)malloc(sizeof(struct tree));
//			newnode->P = root;
//			newnode->L = NULL;
//			newnode->R = NULL;
//			newnode->data = n;
//			newnode->height = 1;
//			root->R = newnode;
//		}
//		else addT(root->R, n);
//	}
//
//	//更新高度
//	root->height = calheight(root);
//
//	//左旋
//
//	if (calcha(root) == 2)
//	{
//		if (calcha(root->L) == -1)//LR型 否则为LL
//		{
//			turnl(root->L);
//		}
//
//		turnr(root);
//		root->height = calheight(root);
//	}
//
//	if (calcha(root) == -2)
//	{
//		if (calcha(root->R) == 1)//LR型 否则为LL
//		{
//			turnr(root->R);
//		}
//
//		turnl(root);
//		root->height = calheight(root);
//	}
//
//	
//
//}
//
//int init(T root)
//{
//	root->L = NULL;
//	root->R = NULL;
//	root->P = NULL;
//	printf("\n输入数据");
//	int n;
//	scanf_s("%d", &n);
//	while (getchar() != '\n');
//	if (n == 0)return 0;
//	root->data = n;
//	return 1;
//}
//
//int main()
//{
//	T root = (T)malloc(sizeof(struct tree));
//	always_root = root;
//	if(!init(root))exit(0);
//	while (1)
//	{
//		printf("\n输入数据");
//		int n;
//		scanf_s("%d", &n);
//		while (getchar() != '\n');
//		if (n == 0)break;
//		addT(always_root, n);
//	}
//
//
//
//
//
//	system("pause");
//	return 0;
//}
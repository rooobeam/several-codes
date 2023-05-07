//#include"tool.h"
//#define FINISH 0
//
//typedef struct tree {
//	int sta;
//	int n1, n2;
//	struct tree* fir;
//	struct tree* sec;
//	struct tree* thd;
//	struct tree* pare;
//}*T;
//T root;
//
//void init() {
//	int n;
//	printf("\n输入数据\n");
//	scanf_s("%d", &n);
//	while (getchar() != '\n');
//	if (n == 0)exit(0);
//	else {
//		root = (T)malloc(sizeof(struct tree));
//		root->fir = NULL;
//		root->sec = NULL;
//		root->thd = NULL;
//		root->pare = NULL;
//		root->n1 = n;
//		root->sta = 2;
//	}
//	return;
//}
//
//void newroot(T old, int middle) {
//	root = (T)malloc(sizeof(struct tree));
//	root->pare = NULL;
//	root->fir = old;
//	T p = (T)malloc(sizeof(struct tree));
//}
//
//
//int addT(T pos, int n) {
//	//到底
//	int middle;
//	if (pos->fir == NULL) {
//		//为二 到底返回FINISH
//		if (pos->sta == 2) {
//			if (n > pos->n1) {
//				pos->n2 = n;
//			}
//			else {
//				pos->n2 = pos->n1;
//				pos->n1 = n;
//			}
//			pos->sta = 3;
//			return FINISH;
//		}
//
//		//为三  改变三节点 返回middle 下面a 不为FINISH则要对节点拆分（不管你是不是底）
//		
//		else {
//			if (n > pos->n2) {
//				middle = pos->n2;
//				pos->n2 = n;
//				return middle;
//			}
//			else if (n < pos->n1) {
//				middle = pos->n1;
//				pos->n1 = n;
//				return middle;
//			}
//			else return n;
//		}
//
//	}
//	//没到底
//	else {
//		//为2没到 再进入addT 可能会返回一个值加入pos节点
//		int a;
//		if (pos->sta == 2) {
//			if (n > pos->n1) {
//				a = addT(pos->sec, n);
//				//return FINISH 则说明问题解决
//				if (a == FINISH)return FINISH;//return FINISH 写一个可节约空间
//				
//				//否则下面一定是三节点传来middle
//				else {
//					//添加到此处
//
//					pos->n2 = a;
//					pos->sta = 3;
//					//拆分
//					pos->sec->sta = 2;
//					pos->thd = (T)malloc(sizeof(struct tree));
//					pos->thd->fir = NULL;
//					pos->thd->sec = NULL;
//					pos->thd->thd = NULL;
//					pos->thd->pare = pos;
//					pos->thd->sta = 2;
//					pos->thd->n1 = pos->sec->n2;
//					return FINISH;
//				}
//			}
//
//			//n较小 到左边 a一定是较pos小的
//			else {
//				a = addT(pos->fir, n);
//				if (a == FINISH)return FINISH;
//				
//				else {
//
//					//添加到此处
//					pos->n2 = pos->n1;
//					pos->n1 = a;
//					pos->sta = 3;
//
//					pos->thd = pos->sec;
//					pos->fir->sta = 2;
//
//					pos->sec = (T)malloc(sizeof(struct tree));
//					pos->sec->n1 = pos->fir->n2;
//					pos->sec->fir = NULL;
//					pos->sec->sec = NULL;
//					pos->sec->thd = NULL;
//					pos->sec->sta = 2;
//					pos->sec->pare = pos;
//
//					return FINISH;
//				}
//			}
//		}
//
//		//否则为三节点没到底
//		else {
//			//最小
//			int middle;
//			if (n < pos->n1) {
//				a = addT(pos->fir, n);
//				if (a == FINISH)return FINISH;
//
//				else {//此处少了拆分
//					middle = pos->n1;
//					pos->n1 = a;
//					
//				}
//			}
//			//最大
//			else if (n > pos->n2) {
//				a = addT(pos->thd, n);
//				if (a == FINISH)return FINISH;
//				else {
//
//
//
//
//					middle = pos->n2;
//					pos->n2 = a;
//				}
//			}
//			//中间
//			else {
//				a = addT(pos->sec, n);
//				if (a == FINISH)return FINISH;
//				else {
//					middle = a;
//				}
//			}
//			return middle;
//
//
//		}
//
//	}
//
//
//}
//
//int main()
//{
//	init();
//	while (1)
//	{
//		int n;
//		printf("\n输入数据\n");
//		scanf_s("%d", &n);
//		while (getchar() != '\n');
//		//addT 不为FINISH 进行根节点拆分
//		if (n == 0)break;
//		int a=addT(root, n);
//		if ( a!= FINISH) {
//			newroot(root, a);
//		}
//	}
//
//
//	system("pause");
//	return 0;
//}
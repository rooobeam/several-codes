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
//	printf("\n��������\n");
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
//	//����
//	int middle;
//	if (pos->fir == NULL) {
//		//Ϊ�� ���׷���FINISH
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
//		//Ϊ��  �ı����ڵ� ����middle ����a ��ΪFINISH��Ҫ�Խڵ��֣��������ǲ��ǵף�
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
//	//û����
//	else {
//		//Ϊ2û�� �ٽ���addT ���ܻ᷵��һ��ֵ����pos�ڵ�
//		int a;
//		if (pos->sta == 2) {
//			if (n > pos->n1) {
//				a = addT(pos->sec, n);
//				//return FINISH ��˵��������
//				if (a == FINISH)return FINISH;//return FINISH дһ���ɽ�Լ�ռ�
//				
//				//��������һ�������ڵ㴫��middle
//				else {
//					//��ӵ��˴�
//
//					pos->n2 = a;
//					pos->sta = 3;
//					//���
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
//			//n��С ����� aһ���ǽ�posС��
//			else {
//				a = addT(pos->fir, n);
//				if (a == FINISH)return FINISH;
//				
//				else {
//
//					//��ӵ��˴�
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
//		//����Ϊ���ڵ�û����
//		else {
//			//��С
//			int middle;
//			if (n < pos->n1) {
//				a = addT(pos->fir, n);
//				if (a == FINISH)return FINISH;
//
//				else {//�˴����˲��
//					middle = pos->n1;
//					pos->n1 = a;
//					
//				}
//			}
//			//���
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
//			//�м�
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
//		printf("\n��������\n");
//		scanf_s("%d", &n);
//		while (getchar() != '\n');
//		//addT ��ΪFINISH ���и��ڵ���
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
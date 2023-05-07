//#include"tool.h"
//
//typedef struct tree {
//	int data;
//	struct tree* L;
//	struct tree* R;
//}*T;
//T head = (T)malloc(sizeof(struct tree));
//
//char ch;
//
//void init()
//{
//	printf("\n输入a b c d 添加 查找 删除 退出\n");
//	ch = getchar();
//	getchar();
//	if (ch == 'b' || ch == 'c')printf("\n无\n");
//	if (ch == 'd')exit(0);
//	head->L = NULL;
//	head->R = NULL;
//	printf("\n输入\n");
//	int n;
//	scanf_s("%d", &(head->data));
//	getchar();
//}
//
//void add()//大小比较到达
//{
//	int n;
//	while (1)
//	{
//		printf("\n输入数据\n");
//		scanf_s("%d", &n);
//		while (getchar() != '\n');
//
//		if (n == 0)return;
//		T e = head;
//		while (1)
//		{
//			if (n > e->data)
//			{
//				if (e->R != NULL)e = e->R;
//				else
//				{
//					T p = (T)malloc(sizeof(struct tree));
//					p->data = n;
//					p->L = NULL;
//					p->R = NULL;
//					e->R = p;
//					break;
//				}
//			}
//
//			else
//			{
//				if (e->L != NULL)e = e->L;
//				else
//				{
//					T p = (T)malloc(sizeof(struct tree));
//					p->data = n;
//					p->L = NULL;
//					p->R = NULL;
//					e->L = p;
//					break;
//				}
//			}
//		}
//	}
//}
//
//void search(T *now,T *latter)//大小比较到达
//{
//	//询问数据
//	int n;
//	printf("\n输入数据\n");
//	scanf_s("%d", &n);
//	getchar();
//
//	//处理特殊情况 head 就发现目标数据
//	if (head->data == n)
//	{
//		printf("\n%p", head);
//		*now = head;
//		*latter = head;
//		return;
//	}
//
//	//now 为 p ，后置为 e
//	T p = head;
//	T e=p;
//
//
//	while (1)
//	{
//
//		if (n == p->data)
//		{
//			printf("\n%p", p);
//			*now = p;
//			*latter = e;
//			return;
//		}
//
//		if (n > p->data)
//		{
//			if (p->R != NULL)
//			{
//				e = p;
//				p = p->R;
//			}
//			else
//			{
//				printf("\n无");
//				*now=NULL;
//				*latter = NULL;
//				return;
//			}
//			continue;
//		}
//
//		if(n<p->data)
//		{
//			if (p->L != NULL) 
//			{
//				e = p;
//				p = p->L;
//			}
//			else
//			{
//				if (p->L != NULL)p = p->L;
//				else
//				{
//					printf("\n无");
//					*now = NULL;
//					*latter = NULL;
//					return ;
//				}
//			}
//		}
//	}
//}
//
//void delet()//倒排序，先右然后一直左 (或者 先左然后一直右) 这下面搞错了
//{
//	T p, e, stay;
//
//	//定位
//	search(&p,&e);
//	stay = p;
//
//	//记录要删data 位置 p 位置四种情况 一有俩子树 二 有一子树 三 无子树 四 NULL
//	stay = p;
//
//	//处理 null
//	if (p == NULL)return;
//
//	//处理特殊情况 无子树
//	if (p->L == NULL && p->R == NULL)
//	{
//		if (e->L == p)e->L = NULL;
//		else e->R = NULL;
//		free(p);
//		return;
//	}
//
//	//此时情况为有子树 先看左子树有没有 再看右子树有没有
//	if (p->L != NULL)
//	{
//
//		//如果左子树无右子树 直接把它换上
//		if (p->L->R == NULL) 
//		{
//			e = p;
//			p = p->L;
//			e->data = p->data;
//			e->L = p->L;
//			free(p);
//		}
//
//		//如果左子树有右子树 查到它最右的子树
//		else 
//		{
//			e = p;
//			p = p->L;
//			for (e = p, p = p->R; p->R != NULL; e = p, p = p->R);
//
//			//交换 指向p 的指针为null
//			stay->data = p->data;
//	        e->R = NULL;
//			free(p);
//		}
//
//	}
//
//	//否则右子树一定存在
//	else
//	{
//
//		//如果右子树无左子树 直接把它换上
//		if (p->R->L == NULL)
//		{
//			e = p;
//			p = p->R;
//			e->data = p->data;
//			e->R = p->R;
//			free(p);
//		}
//
//		//如果右子树有左子树 查到它最左的子树
//		else
//		{
//			e = p;
//			p = p->R;
//			for (e = p, p = p->L; p->L != NULL; e = p, p = p->L);
//
//			//交换 指向p 的指针为null
//			stay->data = p->data;
//			e->L = NULL;
//			free(p);
//		}
//	}
//}
//
//int main()
//{	
//	init();
//	if(ch=='d')	return 0;
//	T p, e;
//	while (1)
//	{
//		printf("\n输入a b c d 添加 查找 删除 退出\n");
//		ch = getchar();
//		getchar();
//		if (ch == 'd')break;
//		switch (ch)
//		{
//		case 'a':add(); break;
//		case 'b':search(&p, &e); break;
//		case 'c':delet(); break;
//		default:break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}
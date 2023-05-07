//检查重定义
//传参不能传未malloc的指针
//分清楚位序还是关键字本身  mid key[mid]

#include"tool.h"
#define m 3//阶数

typedef struct BT {
	int key[m];//留多一个区域给多出的
	struct BT* child[m + 1];
	struct BT* parent;
	int num;
}*T;

typedef struct  RZ{
	int n;//key
	int no;//位序
	T p;//新节点指针
}result;
result FINISH = {-1};
result NEED ;
result NO_NEED{ -2};
//确定key 在节点中的位置
int locate(T p,int key) {
	int pos = 0;
	while (key > p->key[pos] && pos < p->num)pos++;
	return pos;
}

//查找
//result search(){
//
//}



//分裂有两个任务 将它裂开 存双亲节点里去（双亲存在的情况进入，否则裂开return result 回去）
void split(T p) {
	int mid=p->num/2;
	
	int pos = locate(p->parent, p->key[mid]);

	//裂开
	T newnode = (T)malloc(sizeof(struct BT));

	for (int i = 0; i < m; i++)newnode->child[i] = NULL;

	newnode->parent = p->parent;
	  //移过去
	int i;
	for (newnode->num=0,i = mid + 1; i <p->num; i++, newnode->num++) {
		newnode->key[i - mid - 1] = p->key[i];
		newnode->child[i - mid - 1] = p->child[i];
	}
	newnode->child[p->num - mid - 1] = p->child[p->num];//最后一个要额外移一下
	p->num = mid;

	if (pos == p->parent->num) {
		p->parent->child[pos+1] = newnode;
		p->parent->key[pos] = p->key[mid];
		p->parent->num++;
	}
	else {
		//双亲节点中腾位置存入
		i = p->parent->num;
		p->parent->child[i + 1] = p->parent->child[i];
		for (i--; i >= pos; i--) {
			p->parent->child[i + 1] = p->parent->child[i];
			p->parent->key[i + 1] = p->parent->key[i];
		}

		p->parent->child[pos] = newnode;
		p->parent->key[pos] = p->key[mid];
		p->parent->num++;
	}
}

void split2(T p,result* k) {
	int mid = p->num / 2,i;
	T newnode = (T)malloc(sizeof(struct BT));

	for ( i = 0; i < m; i++)newnode->child[i] = NULL;

	for (newnode->num = 0, i = mid + 1; i < p->num; i++, newnode->num++) {
		newnode->key[i - mid - 1] = p->key[i];
		newnode->child[i - mid - 1] = p->child[i];
	}
	newnode->child[p->num - mid - 1] = p->child[p->num];//最后一个要额外移一下
	p->num = mid;

	(*k).n = p->key[mid];
	(*k).p = newnode;

	return ;
}

result addT(int key,T p) {
	int pos = locate(p, key), i = p->num;

	//是叶子
	if (p->child[0] == NULL) {

		//先加入 再看是否要裂开
		if (pos != p->num) {
			for (i--; i >= pos; i--) {
				p->key[i + 1] = p->key[i];
			}
		}			
		p->key[pos] = key;
		p->num++;
		
		//满了且双亲节点存在
		if (p->num == m && p->parent != NULL) {
			split(p);
			return NO_NEED;
		}
		//满了且双亲节点不存在
		else if (p->num == m && p->parent == NULL){ 
			split2(p,&NEED);
			return NEED;
		}
		//没满
		else return FINISH;


	}
	//不是叶子
	else {
		result k = addT(key, p->child[pos]);
		//如果是完成就返回完成
		if (k.n == FINISH.n)return FINISH;
		//如果不是完成 就说明p改变了有人晋升上来 要看是否满位
		else if (p->num < m)return FINISH;
		//满位时要分有无双亲
		else {
			if (p->parent != NULL) {
				split(p);
				return NO_NEED;
			}
			else {
				split2(p,&NEED);
				return NEED;
			}

		}
	}

}

void Addnewroot(T* oldroot, result k) {

	T newroot = (T)malloc(sizeof(struct BT));

	//新旧建立关系
	newroot->child[0] = *oldroot;
	(*oldroot)->parent = newroot;
	newroot->child[1] = k.p;
	k.p->parent = newroot;

	//更新根节点
	newroot->key[0] = k.n;
	newroot->num = 1;
	newroot->parent = NULL;
	(*oldroot) = newroot;

	return;
}

void init(T root) {
	int n;
	printf("\n输入数据\n");
	scanf_s("%d", &n);
	while (getchar() != '\n');
	if (n == 0)exit(0);
	else {
		root->parent = NULL;
		root->num = 1;
		root->key[0] = n;
		for (int i = 0; i < m; i++)root->child[i] = NULL;
	}
	return;
}

int main() {
	T root = (T)malloc(sizeof(struct BT));
	init(root);
	while (1) {
		int n;
		result a;
		printf("\n输入数据\n");
		scanf_s("%d", &n);
		while (getchar() != '\n');
		if (n == 0)break;
		else {
			a=addT(n, root);
		}
		if (a.n !=FINISH.n&&a.n!=NO_NEED.n )Addnewroot(&root,a);
	}
	printf("\n");
}
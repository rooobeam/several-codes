//����ض���
//���β��ܴ�δmalloc��ָ��
//�����λ���ǹؼ��ֱ���  mid key[mid]

#include"tool.h"
#define m 3//����

typedef struct BT {
	int key[m];//����һ������������
	struct BT* child[m + 1];
	struct BT* parent;
	int num;
}*T;

typedef struct  RZ{
	int n;//key
	int no;//λ��
	T p;//�½ڵ�ָ��
}result;
result FINISH = {-1};
result NEED ;
result NO_NEED{ -2};
//ȷ��key �ڽڵ��е�λ��
int locate(T p,int key) {
	int pos = 0;
	while (key > p->key[pos] && pos < p->num)pos++;
	return pos;
}

//����
//result search(){
//
//}



//�������������� �����ѿ� ��˫�׽ڵ���ȥ��˫�״��ڵ�������룬�����ѿ�return result ��ȥ��
void split(T p) {
	int mid=p->num/2;
	
	int pos = locate(p->parent, p->key[mid]);

	//�ѿ�
	T newnode = (T)malloc(sizeof(struct BT));

	for (int i = 0; i < m; i++)newnode->child[i] = NULL;

	newnode->parent = p->parent;
	  //�ƹ�ȥ
	int i;
	for (newnode->num=0,i = mid + 1; i <p->num; i++, newnode->num++) {
		newnode->key[i - mid - 1] = p->key[i];
		newnode->child[i - mid - 1] = p->child[i];
	}
	newnode->child[p->num - mid - 1] = p->child[p->num];//���һ��Ҫ������һ��
	p->num = mid;

	if (pos == p->parent->num) {
		p->parent->child[pos+1] = newnode;
		p->parent->key[pos] = p->key[mid];
		p->parent->num++;
	}
	else {
		//˫�׽ڵ�����λ�ô���
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
	newnode->child[p->num - mid - 1] = p->child[p->num];//���һ��Ҫ������һ��
	p->num = mid;

	(*k).n = p->key[mid];
	(*k).p = newnode;

	return ;
}

result addT(int key,T p) {
	int pos = locate(p, key), i = p->num;

	//��Ҷ��
	if (p->child[0] == NULL) {

		//�ȼ��� �ٿ��Ƿ�Ҫ�ѿ�
		if (pos != p->num) {
			for (i--; i >= pos; i--) {
				p->key[i + 1] = p->key[i];
			}
		}			
		p->key[pos] = key;
		p->num++;
		
		//������˫�׽ڵ����
		if (p->num == m && p->parent != NULL) {
			split(p);
			return NO_NEED;
		}
		//������˫�׽ڵ㲻����
		else if (p->num == m && p->parent == NULL){ 
			split2(p,&NEED);
			return NEED;
		}
		//û��
		else return FINISH;


	}
	//����Ҷ��
	else {
		result k = addT(key, p->child[pos]);
		//�������ɾͷ������
		if (k.n == FINISH.n)return FINISH;
		//���������� ��˵��p�ı������˽������� Ҫ���Ƿ���λ
		else if (p->num < m)return FINISH;
		//��λʱҪ������˫��
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

	//�¾ɽ�����ϵ
	newroot->child[0] = *oldroot;
	(*oldroot)->parent = newroot;
	newroot->child[1] = k.p;
	k.p->parent = newroot;

	//���¸��ڵ�
	newroot->key[0] = k.n;
	newroot->num = 1;
	newroot->parent = NULL;
	(*oldroot) = newroot;

	return;
}

void init(T root) {
	int n;
	printf("\n��������\n");
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
		printf("\n��������\n");
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
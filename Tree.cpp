#include <stdio.h>
#include <stdlib.h>
//#define MaxSize 

typedef struct BiTNode{
	char data;
	struct BiTNode * lchild;
	struct BiTNode * rchild; //���Һ���ָ��
	
}BiTNode,*BiTree;

void visit(BiTNode *t);//��ӡ�����data 
void CreateBiTree(BiTree &root);//������
//���� 
void preorder(BiTree t);//����
void InOrder(BiTree T);//����
void PostOrder(BiTree T);//����
 

//typedef BiNode* bintree;
void visit(BiTNode *t){
	printf("%c",t->data);
} 

//������� �ȸ�   ǰ׺  ��׺ ��׺  
void preorder(BiTree t){
	if(t!=NULL){
		visit(t); //�� 
		preorder(t->lchild);//�� 
		preorder(t->rchild);//�� 
	}

}
//������� �и�
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);//�ݹ���������� 
		visit(T);		   //���ʸ���� 
		InOrder(T->rchild);//�ݹ���������� 
		 
	}
} 
//���� ��� 
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);//�ݹ���������� 
		PostOrder(T->rchild);//�ݹ���������� 
		visit(T);		   //���ʸ����  
	}
} 


int treeDepth(BiTree T){
	if(T==NULL){
		return 0;
	}
	else{
		int l=treeDepth(T->lchild );
		int r=treeDepth(T->rchild );
		//�������=Max(��������ȣ����������)+1
		return l>r? l+1:r+1; 
	}
}

//������������
void ChangLR(BiTree &T){
	if(T==NULL){
		return ;
	}
	else{
		BiTree temp=(BiTree)malloc(sizeof(BiTree));
		temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=temp;
	
//		BiTree L= T->lchild;
//		BiTree R= T->rchild;
//		BiTree temp=(BiTree)malloc(sizeof(BiTree));
//		temp=L;
//		L=R;
//		R=temp;
	
		ChangLR(T->lchild);
		ChangLR(T->rchild);
	}
} 

//������������ 
void ExChangeTree(BiTree &T){
	BiTree temp =  (BiTree)malloc(sizeof(BiTree));
    if (T)
    {
        temp = T->rchild;
        T->rchild = T->lchild;
        T->lchild = temp;
        ExChangeTree(T->lchild);
        ExChangeTree(T->rchild);
    }
    else
    {
        return;
    }
} 
 
/*
void Tree::ExChangeTree(BiTree *T) {
 
    BiTree *temp = new BiTree;
    if (T)
    {
        temp = T->rchild;
        T->rchild = T->lchild;
        T->lchild = temp;
        ExChangeTree(T->lchild);
        ExChangeTree(T->rchild);
    }
    else
    {
        return;
    }
}
*/

//���򴴽�������  ����ʱһ����������� ���磺ABD###CE##F## 
BiTree PreCreateBiTree(){
	BiTree T=(BiTNode *)malloc(sizeof(BiTNode)); 

	char ch;
	scanf("%c",&ch);

	if(ch=='#'){
		return NULL;
	}

	T->data=ch;
//	T->lchild=T->rchild=NULL; //���Բ�Ҫ 
	T->lchild=PreCreateBiTree();
	T->rchild=PreCreateBiTree();
	
	return T;
}

//n�����Ķ������� �� n+1������ 
int main(){
	BiTree root=NULL;
	printf("������������Ľ��:");
	root=PreCreateBiTree();
//	root=(BiTree)malloc(sizeof(BiTNode));
//	root->data ='1';
//	root->lchild=NULL;
//	root->rchild=NULL;
//	BiTNode*p=(BiTNode*)malloc(sizeof(BiTNode));
//	p->data='2';
//	p->lchild=NULL;
//	p->rchild=NULL; 
//	root->lchild=p;
	 	printf("\nǰ������Ϊ��");
		preorder(root);//���� 
		printf("\n");
		
	 	printf("��������Ϊ��");
		InOrder(root); //���� 
		printf("\n");
	
	 	printf("��������Ϊ��");
		PostOrder(root);// ���� 
		printf("\n");

		int x= treeDepth(root);
		printf("\n���Ϊ%d",x);
	
		ChangLR(root);		//������������
	 	printf("\n��������������:\n");
 	
 		printf("\nǰ������Ϊ��");
		preorder(root);//���� 
		printf("\n");
	 	
		printf("��������Ϊ��");
		InOrder(root); //���� 
		printf("\n");
	 	
		printf("��������Ϊ��");
		PostOrder(root);// ���� 
		printf("\n");


	return 0;

}






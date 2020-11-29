#include <stdio.h>
#include <stdlib.h>
//#define MaxSize 

typedef struct BiTNode{
	char data;
	struct BiTNode * lchild;
	struct BiTNode * rchild; //左右孩子指针
	
}BiTNode,*BiTree;

void visit(BiTNode *t);//打印树结点data 
void CreateBiTree(BiTree &root);//创建树
//遍历 
void preorder(BiTree t);//先序
void InOrder(BiTree T);//中序
void PostOrder(BiTree T);//后序
 

//typedef BiNode* bintree;
void visit(BiTNode *t){
	printf("%c",t->data);
} 

//先序遍历 先根   前缀  中缀 后缀  
void preorder(BiTree t){
	if(t!=NULL){
		visit(t); //根 
		preorder(t->lchild);//左 
		preorder(t->rchild);//右 
	}

}
//中序遍历 中根
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);//递归遍历左子树 
		visit(T);		   //访问根结点 
		InOrder(T->rchild);//递归遍历右子树 
		 
	}
} 
//后序 后根 
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);//递归遍历左子树 
		PostOrder(T->rchild);//递归遍历右子树 
		visit(T);		   //访问根结点  
	}
} 


int treeDepth(BiTree T){
	if(T==NULL){
		return 0;
	}
	else{
		int l=treeDepth(T->lchild );
		int r=treeDepth(T->rchild );
		//树的深度=Max(左子树深度，右子树深度)+1
		return l>r? l+1:r+1; 
	}
}

//交换左右子树
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

//交换左右子树 
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

//先序创建二叉树  输入时一次性输入完毕 例如：ABD###CE##F## 
BiTree PreCreateBiTree(){
	BiTree T=(BiTNode *)malloc(sizeof(BiTNode)); 

	char ch;
	scanf("%c",&ch);

	if(ch=='#'){
		return NULL;
	}

	T->data=ch;
//	T->lchild=T->rchild=NULL; //可以不要 
	T->lchild=PreCreateBiTree();
	T->rchild=PreCreateBiTree();
	
	return T;
}

//n个结点的二叉链表 又 n+1个空链 
int main(){
	BiTree root=NULL;
	printf("请输入二叉树的结点:");
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
	 	printf("\n前序排序为：");
		preorder(root);//先序 
		printf("\n");
		
	 	printf("中序排序为：");
		InOrder(root); //中序 
		printf("\n");
	
	 	printf("后序排序为：");
		PostOrder(root);// 后序 
		printf("\n");

		int x= treeDepth(root);
		printf("\n深度为%d",x);
	
		ChangLR(root);		//交换左右子树
	 	printf("\n交换左右子树后:\n");
 	
 		printf("\n前序排序为：");
		preorder(root);//先序 
		printf("\n");
	 	
		printf("中序排序为：");
		InOrder(root); //中序 
		printf("\n");
	 	
		printf("后序排序为：");
		PostOrder(root);// 后序 
		printf("\n");


	return 0;

}






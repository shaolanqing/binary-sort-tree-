 //�����������Ĳ����㷨
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int flag;
struct btree
{
	int date;
    btree *left, *right;
};
 
void creathead(btree *&root)
{
	root=new btree;
	cin>>root->date;
	root->left=root->right=NULL;
}
 
void creatbtree(btree *& root, int insert)
{
	if (root==NULL)
	{
		root=new btree;
		root->date=insert;
		root->left=root->right=NULL;
		return;
	}
	if (root->date<insert)
	{
		creatbtree(root->right, insert);
	}
	else if (root->date>insert)
	{
		creatbtree(root->left,insert);
	}
}
 
void find(btree *root, int tar, int cnt)
{
	if (root==NULL)
	{
		return;
	}
	if (tar==root->date)
	{
		cout<<cnt + 1;
		flag=1;
		return;
	}
	else if (tar<root->date)
	{
		find(root->left, tar, cnt  + 1);
	}
	else if (tar>root->date)
	{
		find(root->right, tar, cnt  + 1);
	}
}
 
int main()
{
	int n;
	printf("����ؼ��ָ���n:\n");
	cin>>n;
	btree *root;
	int k;
	flag=0;
	int num;
	printf("����ͷ���:\n");
    creathead(root); //ͷ���
    printf("����ؼ��֣�\n");
	for (int i=0; i<n; i++)
	{	
		cin>>num;
		creatbtree(root, num);
	}
    printf("����Ҫ���ҵĹؼ���:\n");
	cin>>k;
	printf("����ɹ����ұȽϵĴ���:\n");
	find(root,k,0);
	cout<<endl;
	if (!flag)
		cout<< "-1"<<endl;
	return 0;
}


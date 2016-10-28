/*
题目概述：给定前序遍历和后序遍历的顺序，要求出总共有多少棵不同形态的二叉树满足这样的遍历顺序。
 
方法：树的不唯一性是由于只有一个儿子节点的父亲节点的存在造成的，因为前序遍历和后续遍历都无法知道这样的父亲节点拥有左儿子还是右儿子，而左右在二叉树中不是等价的，这也是二叉树与普通树的一个主要区别。
下面用递归找出只有一个儿子节点的父亲节点有多少个，每找到一个，树的种数就要乘以2，而且当只有一棵子树时，默认为左子树。
先序序列a1[0,1,2...len],后序序列a2[0,1,2...len],（len>0）
易知a1[1]是左子树的根（默认为左子树）,且左子树的根在后续遍历中位于左右子树的交接处
故int i=len-1;while(a2[i]!=a1[1])i--;便能确定左右子树的先后序遍历在哪个位置。
然后用cpy将子树遍历序列复制到l,r数组中，进行递归。
当右子树长度为0时（根只有一棵子树），种数乘以2
*/
#include <iostream>
#include <string.h>
using namespace std;

int n=1;

void copy(char dest[],char source[],int begin,int end){
	int i;
	for(i = begin; i <= end; i++)
		dest[i-begin]=source[i];
	dest[i-begin] = 0;
}

void find(char a1[],char a2[],int len){
	if (len==1)
		return;
	char l1[50],r1[50];
	char l2[50],r2[50];
 
	int i=0;
	while(a2[i]!=a1[1])		//找到先序遍历根左结点在后序遍历的区分位置
		i++;
   
	copy(l1,a1,1,i+1);
	copy(r1,a1,i+2,len-1);
   
	copy(l2,a2,0,i);
	copy(r2,a2,i+1,len-2);
   
	find(l1,l2,strlen(l1));
   
	if(strlen(r1)==0)
		n <<= 1;
	else
		find(r1,r2,strlen(r1));
}
	
int main() {
	char a1[50],a2[50];
	scanf("%s",a1);
	scanf("%s",a2);
	find(a1,a2,strlen(a1));
	printf("%d",n);
	return 0;
}
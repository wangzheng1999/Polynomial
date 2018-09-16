#include<stdio.h>
#include<string.h>
typedef struct node
{
	int coe;
	int exp;
}Node;
Node *creat(Node *a,int n)
{
	Node t;
	int i,j;
	char p,q,r;
	scanf("%d%c",&n,&p);
	for(i=0;i<n;i++)
	{
	scanf("%c%d%c%d%c",&p,&a[i].coe,&r,&a[i].exp,&q);
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[i].exp>a[i+1].exp)
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	return a;
}
void print(Node *a,int n)
{
	char x='X';
	int i;
	if(a[0].coe!=0)
	{
	if(a[0].exp>2)
	printf("%d%c^%d",a[0].coe*a[0].exp,x,a[0].exp-1);
	if(a[0].exp==2)
	printf("%d%c",a[0].coe*a[0].exp,x);
	 if(a[0].exp==1)
	printf("%d",a[0].coe);
}
	for(i=1;i<n;i++)
	{
		if(a[i].coe!=0)
		{
		if(a[i].exp*a[i].coe>0&&a[i-1].exp!=0)
		printf("+");
	   if(a[i].exp>2)
	   printf("%d%c^%d",a[i].coe*a[i].exp,x,a[i].exp-1);
	   if(a[i].exp==2)
	   printf("%d%c",a[i].coe*a[i].exp,x);
	   if(a[i].exp==1)
	   printf("%d",a[i].coe);
   }
	}
}
int main(void)
{
	Node a[10],*p;
	int n;
	scanf("%d",&n);
	p=creat(a,n);
	print(p,n);
}

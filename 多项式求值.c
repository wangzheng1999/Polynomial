#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct node
{
	int coe;
	int exp;
}Node;
void creat(Node *a,int n)
{
	Node t;
	int i,j;
	char x,p,q,r;
	x='X';
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
}
int calu(Node *a,int n, int x)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i].coe*pow(x,a[i].exp);
	}
	return sum;
}
int main(void)
{
	Node a[20];
	int n,x,valu;
	scanf("%d",&n);
	creat(a,n);
	scanf("%d",&x);
	valu=calu(a,n,x);
	printf("%d",valu);
}

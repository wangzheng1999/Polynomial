#include<stdio.h>
#include<string.h>
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
void print(Node *a,int n)
{
	char x='X';
	int i=1;
	if(a[0].exp>=2)
	printf("%d%c^%d",a[0].coe,x,a[0].exp);
	else if(a[0].exp==1)
	{
	printf("%d",a[0].coe);
	putchar(x);
    }
	else
	printf("%d",a[0].coe);
	while(i<n)
	{
		if(a[i].coe>0)
		printf("+");
	   if(a[i].exp>=2)
	   printf("%d%c^%d",a[i].coe,x,a[i].exp);
	    if(a[i].exp==1)
	   {
	   printf("%d",a[i].coe);
	   putchar(x);
       }
	   if(a[i].exp==0)
	   printf("%d",a[i].coe);
	   i++;
    }
}
int subtract(Node *a,int n,Node *b,int m,Node *c)
{
	int i=0,j=0,k=0;
	while(i<n&&j<m)
	{
		if(a[i].exp<b[j].exp)
		{
			if(a[i].coe!=0)
			{
		     c[k].coe=a[i].coe;
		     c[k].exp=a[i].exp;
		     i++;
		     k++;
		    }
		    else
		    {
		    	i++;
			}
	    }
		else if(a[i].exp>b[j].exp)
		{
			if(b[j].coe!=0)
			{
			c[k].coe=-b[j].coe;
			c[k].exp=b[j].exp;
			j++;
			k++;
		    }
		    else
		    {
		    	j++;
			}
		}
		else
		{
			c[k].coe=a[i].coe-b[j].coe;
			c[k].exp=a[i].exp;
			if(c[k].coe!=0)
			{
			i++;
			j++;
			k++;
		    }
		    else
		    {
		    	i++;
		    	j++;
			}
		}
	}
		while(j<m)
		{
			c[k].coe=-b[j].coe;
			c[k].exp=b[j].exp;
			if(c[k].coe!=0)
			{
			k++;
			j++;
		    }
		    else
		    {
		    	j++;
			}
		}
		while(i<n)
		{
			c[k].coe=a[i].coe;
			c[k].exp=a[i].exp;
			if(c[k].coe!=0)
			{
			k++;
			i++;
		    }
		    else
		    {
		    	i++;
			}
		}
	return k;
}
int main(void)
{
	int n,m,r;
	Node a[10],b[10],c[20];
	scanf("%d",&n);
	creat(a,n);
	scanf("%d",&m);
	creat(b,m);
	r=subtract(a,n,b,m,c);
	if(r!=0)
	print(c,r);
	else
	printf("0");
}

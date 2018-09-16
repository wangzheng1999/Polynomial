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
	char x='X',y='-';
	int i=1;
	if(a[0].coe==1||a[0].coe==-1)
	{
		if(a[0].exp>=2)
		{
		if(a[0].coe==-1)
	    printf("%c%c^%d",y,x,a[0].exp);
	    else
	    printf("%c^%d",x,a[0].exp);
       }
	 if(a[0].exp==1)
	{
	if(a[0].coe==-1)
	printf("%c",y);
	putchar(x);
    }
	if(a[0].exp==0)
	printf("%d",a[0].coe);
	}
	else
	{
	if(a[0].exp>=2)
	printf("%d%c^%d",a[0].coe,x,a[0].exp);
	 if(a[0].exp==1)
	{
	printf("%d",a[0].coe);
	putchar(x);
    }
	if(a[0].exp==0)
	printf("%d",a[0].coe);
    }
	while(i<n)
	{
		if(a[i].coe>0)
		printf("+");
		if(a[i].coe==1||a[i].coe==-1)
		{
	     if(a[i].exp>=2)
	     {
	   	 if(a[i].coe==-1)
	     printf("%c%c^%d",y,x,a[i].exp);
	     else
	     printf("%c^%d",x,a[i].exp);
         }
	     if(a[i].exp==1)
	     {
	      if(a[i].coe==-1)
	      printf("%c",y);
	      putchar(x);
        }
	     if(a[i].exp==0)
	     printf("%d",a[i].coe);
	     i++;
       }
      else
      {
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
}
int multi(Node *a,int n,Node *b,int m,Node *c)
{
	int i,j,l,k=0;
	Node t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;
			c[k].exp=a[i].exp+b[j].exp;
			if(c[k].coe!=0)
			k++;
		}
	}
	i=0;
	while(i<k-1)
	{
		j=i+1;
		while(j<k)
		{
			if(c[i].exp==c[j].exp)
			{
		    c[i].coe=c[i].coe+c[j].coe;
		    l=j;
		    while(l<k-1)
		    {
		    	c[l].coe=c[l+1].coe;
		    	c[l].exp=c[l+1].exp;
		    	l++;
			}
			k--;
		    }
		    else
		    j++;
		}
		if(c[i].coe==0)
		{
			l=i;
			while(l<k-1)
			{
			c[l]=c[l+1];
			l++;
		    }
		    k--;
		}
		else
		i++;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-i-1;j++)
		if(c[i].exp>c[i+1].exp)
		{
			t=c[i];
			c[i]=c[i+1];
			c[i+1]=t;
		}
	}
	return k;
}
int main(void)
{
	Node a[10],b[10],c[100];
	int n,m,r;
	scanf("%d",&n);
	creat(a,n);
	scanf("%d",&m);
	creat(b,m);
	r=multi(a,n,b,m,c);
	if(r!=0)
	print(c,r);
	else
	printf("0");
}

#include<bits/stdc++.h>
using namespace std;
void merge(int x[],int l,int m,int u)
{
	int a,b,i,y[230];
	a=l;
	b=m+1;
	for(i=l;i<=u;i++)
	{
		if(a>m)
		{
			y[i]=x[b];
			b++;
		}
		else if(b>u)
		{
			y[i]=x[a];
			a++;
		}
		else if(x[a]>x[b])
		{
			y[i]=x[b];
			b++;
		}
		else
		{
			y[i]=x[a];
			a++;
		}
	}
	for(i=l;i<=u;i++)
	{
		x[i]=y[i];
	}
}
void mergesort(int x[],int l,int u)
{
	int m;
	if(l>=u)
	{
		return;
	}
	m=(l+u)/2;
	mergesort(x,l,m);
	mergesort(x,m+1,u);
	merge(x,l,m,u);
}
int main()
{
	int n,i,m,se;
	cin>>n;
  int x[n];
	for(i=0;i<n;i++)
	{
		cin>>x[i];
	}
	mergesort(x,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<"  ";
	}
}

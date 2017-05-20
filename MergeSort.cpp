#include <bits/stdc++.h>
using namespace std;
void merge(long int a[] ,long int l, long int m,long int r);
void mergesort(long int a[], long int l, long int r)
{
	if(l<r)
	{
		long int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);

		merge(a,l,m,r);
	}
}
void merge(long int a[],long int l, long int m, long int r)
{
	long int n1,n2,i,j,k,flag=0;
	n1=m-l+1;
	n2=r-m;
	long int l1[n1],r1[n2];
	for(int i=0;i<n1;i++)
		l1[i]=a[l+i];
	for(int j=0;j<n2;j++)
		r1[j]=a[m+1+j];
	i=0;j=0;k=l;
	while(i<n1&&j<n2)
	{
		if(l1[i]<=r1[j])
		{
			a[k]=l1[i];
			flag++;
			i++;
		}
		else
		{
			a[k]=r1[j];
			flag++;
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=l1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=r1[j];
		j++;
		k++;
	}
}
int main()
{
	long int n,t,l,r;
	cin>>t;
	while(t--)
	{
		l=0;
		r=n-1;
  	    cin>>n;
  	    long int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		mergesort(a,l,r);
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
	}
	return 0;
}
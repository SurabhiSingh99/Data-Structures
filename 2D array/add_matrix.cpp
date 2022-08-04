#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	clock_t s,e;
	int a[50][50],b[50][50],add[50][50],r,c,i,j;
	cout<<"enter number of rows and columns respectively\n";
	cin>>r>>c;
	cout<<"enter the first array\n";
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>a[i][j];
	cout<<"enter the second array\n";
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>b[i][j];
	cout<<"the final array after addition is:\n";
	s=clock();
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			add[i][j]=a[i][j]+b[i][j];
	e=clock()-s;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<add[i][j]<<"  ";
		cout<<"\n";
	}
	cout<<"execution time of algorithm : "<<((double)e)/CLOCKS_PER_SEC;
			
	
}

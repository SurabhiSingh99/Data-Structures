#include<iostream>
using namespace std;
int main()
{
	int a[50][50],b[50][50],mul[50][50],r1,c1,r2,c2,r3,c3,i,j,k;
	for(i=0;i<50;i++)
		for(j=0;j<50;j++)
			mul[i][j]=0;
	cout<<"enter number of rows and columns of first matrix respectively\n";
	cin>>r1>>c1;
	cout<<"enter number of rows and columns of second matrix respectively\n";
	cin>>r2>>c2;
	if(c1!=r1)
	{
		cout<<"cannot multiply matrices\n";
		return 0;
	}
	r3=r1;
	c3=c2;
	cout<<"enter the first array\n";
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			cin>>a[i][j];
	cout<<"enter the second array\n";
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
			cin>>b[i][j];
	cout<<"the final array after multiplication is:\n";
	for(k=0;k<r1;k++)
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
				mul[k][i]+=a[i][j]*b[j][i];
		}
			
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
			cout<<mul[i][j]<<"  ";
		cout<<"\n";
	}
		
}

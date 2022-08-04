#include<iostream>
using namespace std;
int main()
{
	int a[50][50],i,j,r,c,f=0;
	cout<<"enter number of rows and columns respectively\n";
	cin>>r>>c;
	cout<<"enter the matrix\n";
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>a[i][j];
	for(i=0;i<r;i++)
	{
		for(j=i;j<c;j++)
		{
			if(i!=j)
			{
				if(a[i][j]!=0&&a[j][i]==0)
					continue;
				else
				{
					f=1;
					break;
				}
			}
			else
			{
				if(a[i][j]==0)
				{
					f=1;
					break;
				}
			}
			
			
		}
	}
	if(f==0)
		cout<<"upper triangle\n";
	else
		cout<<"not upper triangle";
}

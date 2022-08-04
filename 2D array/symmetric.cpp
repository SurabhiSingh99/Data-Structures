#include<iostream>
using namespace std;
int main()
{
	int a[50][50],i,j,r,f=0;
	cout<<"enter the value of number of rows and columns\n";
	cin>>r;
	cout<<"enter the matrix\n";
	for(i=0;i<r;i++)
		for(j=0;j<r;j++)
			cin>>a[i][j];
	for(i=0;i<r;i++)
	{
		for(j=i;j<r;j++)
		{
			if(a[i][j]==a[j][i])
				continue;
			else
			{
				f=1;
				break;
			}
			
		}
	}
	if(f==0)
		cout<<"symmetric\n";
	else
		cout<<"not symmetric";
}

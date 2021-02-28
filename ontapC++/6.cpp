#include<iostream>
using namespace std;

void xuat(long long a[][100],long long n,long long T)
{
	cout<<"Test "<<T<<":\n";
	for(long long i = 0 ; i < n ; i++)
	{
		for(long long j = 0 ; j < n ; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;		
	}		
}

int main()
{
	long long T;
	cin>>T;
	for(long long k = 1 ; k <= T ; k++)
	{
		long long n,value,row = 0,column = 0,a[100][100],m;
		cin>>n;
		m = n;
		value = n*n;
		for(long long j = 1 ; j <= m/2+1 ; j++)
		{
			// tu trai sang phai
			for(long long i = column  ; i < n ; i++)
				a[row][i] = value--;
			// tu tren xuong duoi
			for(long long i = row+1 ; i < n ; i++)		
				a[i][n-1] = value--;
			// tu phai sang trai
			for(long long i = n-1-1 ; i >= column ; i--)
				a[n-1][i] = value--;
			// tu duoi len tren
			for(long long i = n-1-1 ; i > row ; i--)
				a[i][column] = value--;
			row++;
			column++;
			n--;	
		}
		xuat(a,m,k);	
	}
	return 0;
}

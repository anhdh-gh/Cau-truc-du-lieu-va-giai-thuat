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

// Tim k so fibonacci dau tien
long long FB[100];
long long fb(long long n)
{
	FB[0] = 1;
	FB[1] = 1;
	for(long long i = 2 ; i < n ; i++)
		FB[i] = FB[i-1] + FB[i-2];
}

int main()
{
	long long T;
	cin>>T;
	for(long long k = 1 ; k <= T ; k++)
	{
		long long n,row = 0,column = 0,a[100][100],m,count = 0;
		cin>>n;
		m = n;
		fb(n*n);
		for(long long j = 1 ; j <= m/2+1 ; j++)
		{
			// tu trai sang phai
			for(long long i = column  ; i < n ; i++)
				a[row][i] = FB[count++];
			// tu tren xuong duoi
			for(long long i = row+1 ; i < n ; i++)		
				a[i][n-1] = FB[count++];
			// tu phai sang trai
			for(long long i = n-1-1 ; i >= column ; i--)
				a[n-1][i] = FB[count++];
			// tu duoi len tren
			for(long long i = n-1-1 ; i > row ; i--)
				a[i][column] = FB[count++];
			row++;
			column++;
			n--;	
		}
		xuat(a,m,k);	
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;

long long n,a[100][100],chuaxet[100][100] = {0};

vector<string>result;
string temp;
void TRY(long long i,long long j)
{
	if(a[1][1] == 0 || a[n][n] == 0) return;
	if(i == n && j == n) result.push_back(temp);
	if(a[i+1][j] == 1 && i != n && chuaxet[i+1][j] == 0)
	{
		temp.push_back('D');
		chuaxet[i][j] = 1;
		TRY(i+1,j);
		temp.erase(temp.size()-1);
		chuaxet[i][j] = 0;
	}
	if(a[i][j-1] == 1 && j != 1 && chuaxet[i][j-1] == 0)
	{
		temp.push_back('L');
		chuaxet[i][j] = 1;
		TRY(i,j-1);
		temp.erase(temp.size()-1);
		chuaxet[i][j] = 0;		
	}
	if(a[i][j+1] == 1 && j != n && chuaxet[i][j+1] == 0)
	{
		temp.push_back('R');
		chuaxet[i][j] = 1;
		TRY(i,j+1);
		temp.erase(temp.size()-1);
		chuaxet[i][j] = 0;		
	}
	if(a[i-1][j] == 1 && i != 1 && chuaxet[i-1][j] == 0)
	{
		temp.push_back('U');
		chuaxet[i][j] = 1;
		TRY(i-1,j);
		temp.erase(temp.size()-1);
		chuaxet[i][j] = 0;
	}
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		// input
		cin>>n;
		for(long long i =1 ; i <= n; i++)
			for(long long j = 1 ; j <= n ; j++)
				cin>>a[i][j];
		// output
		temp.clear();
		result.clear();
		TRY(1,1);
		if(result.empty()==1) cout<<-1;
		else
			for(long long i = 0 ; i < result.size() ; i++)
				cout<<result[i]<<" ";
		cout<<endl;
	}
}

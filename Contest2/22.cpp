#include<iostream>
#include<vector>
using namespace std;

long long n,a[100][100];

vector<string>result;
string b;
void TRY(long long i,long long j)
{
	if(n < 2 || a[1][1] == 0 || a[n][n] == 0) return;
	if(i == n && j == n) result.push_back(b);
	if(i+1 <= n && a[i+1][j] == 1)
	{
		b.push_back('D');
		TRY(i+1,j);
		b.erase(b.size()-1);
	}
	if(j+1 <= n && a[i][j+1] == 1)
	{
		b.push_back('R');
		TRY(i,j+1);
		b.erase(b.size()-1);		
	}
}

main ()
{
  long long T;
  cin>>T;
  while(T--)
  {
  	// input
    cin>>n;
    for(long long i = 1 ; i <= n ; i++)
    	for(long long j = 1 ; j <= n ; j++)
    		cin>>a[i][j];
    // output
    b.clear();
    result.clear();
    TRY(1,1);
    if(result.empty()==1) cout<<-1;
    else
    	for(long long i = 0 ; i < result.size() ; i++)
    		cout<<result[i]<<" ";
    cout<<endl;
  }
}

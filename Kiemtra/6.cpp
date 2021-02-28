#include <bits/stdc++.h> 
using namespace std; 

int dp[1005][1005];
int Min(string str) { 
	memset(dp,0,sizeof(dp));
    int n = str.size();

    for (int i = 0; i < n; i++) 
        dp[i][i] = 1; 
  
    for (int c=2; c<=n; c++) { 
        for (int i=0; i<n-c+1; i++) { 
            int j=i+c-1; 
            if (str[i]==str[j] && c==2) 
                dp[i][j]=2; 
            else if (str[i]==str[j]) 
                dp[i][j]=dp[i+1][j-1] + 2; 
            else
                dp[i][j]=max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 
  
    return dp[0][n-1]; 
} 
  
int solve(string str) { 
    int n=str.size(); 
    int len=Min(str); 
    return (n - len); 
} 
  
main(){  
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<solve(s)<<endl;
	}
}

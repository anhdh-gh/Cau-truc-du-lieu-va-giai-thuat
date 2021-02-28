#include<iostream>
using namespace std;
string s;
int a[1000][1000],n;
int QHD(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i]==s[j]&&i!=j){
				a[i][j]=(i-1>=0&&j-1>=0)?a[i-1][j-1]+1:1;
			} 
			else{
				a[i][j]=max( (i-1>=0)?a[i-1][j]:0,(j-1>=0)?a[i][j-1]:0 );
			}
		}
	}
	return a[n-1][n-1];
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n>>s;
		cout<<QHD()<<endl;
	}
	
	return 0 ;
}

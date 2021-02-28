#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int v,e,n;
int a[111][111];
int main(){
	cin>>v>>e;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++) a[i][j]=1111;
	}
	for(int i=1;i<=v;i++) a[i][i]=0;
	for(int i=1;i<=e;i++){
		int x,y,z;cin>>x>>y>>z;
		a[x][y]=z;a[y][x]=z;
	}
	for (int k=1;k<=v;k++){
		for (int i=1;i<=v;i++){
        	for (int j=1;j<=v;j++){
            	if(a[i][j]>a[i][k]+a[k][j]){
            		a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		cout<<a[x][y]<<endl;
	}
	return 0;
}
//5 6
//1 2 6
//1 3 7
//2 4 8
//3 4 9
//3 5 1
//4 5 2
//3
//1 5
//2 5
//4 3


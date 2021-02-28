#include<iostream>
using namespace std;
int n,a[10],b[5],x[10],d[10],danhdau;
void PhepTinh( int i){
	if(danhdau==1) return;
	for( int j=1;j<=3;j++){
		b[i]=j;
		if(i==4){
			int tong=d[a[1]];
			for(int t=1;t<=4;t++){
				if(b[t]==1) tong=tong+d[a[t+1]];
				else if(b[t]==2) tong=tong-d[a[t+1]];
				else if(b[t]==3) tong=tong*d[a[t+1]];
			}
			if(tong==23){
				danhdau=1;
				return;
			}
		}
		else PhepTinh(i+1);
	}
}
void HoanViSo( int i){
	if(danhdau==1) return;
	for( int j=1;j<=n;j++){
		if(x[j]==0){
			x[j]=1 ;a[i]=j ;
			if(i==n){
				PhepTinh(1);
				if(danhdau==1) return;
			}
			else HoanViSo(i+1) ;
			x[j]=0 ;
		}
	}
}
int main(){
	int T;cin>>T;
	while(T--){
		n=5;
		for(int i=1;i<=5;i++){a[i]=i;cin>>d[i];x[i]=0;};
		danhdau=0;
		HoanViSo(1);
		if(danhdau==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	
	return 0 ;
}


#include<iostream>
using namespace std;
long long n,a[1001],tang[1001],giam[1001];
void DayTang(){
	for(long long i=1;i<=n;i++){
		tang[i]=a[i];
		for(long long j=0;j<i;j++){
			if(a[j]<a[i]){
				tang[i]=max(tang[i],tang[j]+a[i]);
			}
		}
	}
}
void DayGiam(){
	for(long long i=n;i>=1;i--){
		giam[i]=a[i];
		for(long long j=n;j>i;j--){
			if(a[j]<a[i]){
				giam[i]=max(giam[i],giam[j]+a[i]);
			}
		}
	}
}
int GiaiQuyet(){
	long long MAX=0;
	DayTang();
	DayGiam();
	for(long long i=1;i<=n;i++){
		MAX=max(MAX,tang[i]+giam[i]-a[i]);
	}
	return MAX;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i];
		cout<<GiaiQuyet()<<endl;
	}
	return 0 ;
}


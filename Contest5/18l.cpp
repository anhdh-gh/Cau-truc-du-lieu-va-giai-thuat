#include<iostream>
#include<algorithm>
using namespace std;
struct CapSo{
	long long x;
	long long y;
};
CapSo a[10000];
long long n,b[10000];
bool cmp(CapSo a,CapSo b){
	if(a.x<b.x) return true;
	return false;
}
long long QHD(){
	long long KetQua=0;
	b[0]=0;
	for(long long i=1;i<=n;i++){
		b[i]=0;
		for(long long j=0;j<i;j++){
			if(a[j].y<a[i].x){
				b[i]=max(b[i],b[j]+1);
			}
		}
		KetQua=max(KetQua,b[i]);
	}
	return KetQua;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+n,cmp);
		cout<<QHD()<<endl;
	}
	return 0 ;
}

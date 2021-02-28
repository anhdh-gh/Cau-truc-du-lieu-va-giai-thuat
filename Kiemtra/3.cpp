#include <iostream>
#include <string>

using namespace std;


int F[100001];

int solve(int n)
{
    F[1]=0;
    for(int i=2; i<=n; i++)
    {
        int c1=1e6,c2=1e6,c3=1e6;

        if(i%3==0)
            c2=F[i/3];
        if(i%2==0)
            c1=F[i/2];
        if(i>1)
            c3=F[i-1];

        F[i] = 1+min(min(c1,c2),c3);
    }
    return F[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}

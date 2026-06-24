#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n;
    double t; cin>>n>>t;
    vector<long long> A(n);
    double temp = 0;
    for(int i=0; i<n; i++){
        double x;
        cin>>x;
        A[i] = (long long)x;
        temp+= (1/x);
    }
    long long ans = (long long)((t+n)/temp);
    long long l=(long long)(max((long long)0,((long long)t-n))/temp);
    long long r = ans;
    while(l<r){
        if(r-l==1){
            long long sum=0;
            for(int i=0; i<n; i++){
                sum+=(long long) (l/A[i]);
            }
            if(sum!=t) l = r;
            break;
        }
        long long m = (r+l)/2;
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=(long long) (m/A[i]);
        }
        // cout<<l<<' '<<r<<' '<<m<<'\n';
        if(sum>=t){
            r = m;
        }else{
            l = m;
        }
    }
    cout<<l;
}
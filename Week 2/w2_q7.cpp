#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n, k; cin>>n>>k;
        // vector<long long> A(n);
        long long ans = 0, count = 1;
        long long prev; cin>>prev;
        for(int i=1; i<n; i++){
            long long x; cin>>x;
            if(2*x>prev){
                count+=1;
            }else{
                ans += max((long long)0, count-k);
                count = 1;
            }
            prev = x;
        }
        ans += max((long long)0, count-k);
        cout<<ans<<'\n';
    }
}
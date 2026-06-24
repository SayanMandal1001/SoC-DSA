#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> A(n);
        for(int i=0; i<n; i++){
            int x; cin>>x;
            A[x-1] = i;
        }
        int x, y, count = 0;
        if(n%2==0){
            x = n/2; y = x+1;
            if(A[x-1]>A[y-1]){
                cout<<n/2<<'\n';
                continue;
            }
            count = 2;
        }else{
            x = (n+1)/2; y = x;
            count = 1;
        }
        int left = 0, right = 0;
        for(int i=x-1; i>0; i--){
            if(A[i-1]<A[i]) left+=1;
            else break;
        }
        for(int i=y+1; i<=n; i++){
            if(A[i-1]>A[i-2]) right+=1;
            else break;
        }
        count += 2*min(left, right);
        cout<<(n-count)/2<<'\n';
    }
}
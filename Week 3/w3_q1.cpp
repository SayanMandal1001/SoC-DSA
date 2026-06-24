#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> A(n);
    long long ans = 0;
    for(int i=0; i<n; i++){
        long long a, d;
        cin>>a>>d;
        ans+=d;
        A[i] = a;
    }
    sort(A.begin(), A.end());
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum+=A[i];
        ans-=sum;
    }
    cout<<ans;

}
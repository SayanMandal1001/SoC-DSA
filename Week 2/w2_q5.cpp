#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    long long mid = n%2==0? (A[n/2] + A[(n/2)-1])/2 : A[(n-1)/2];
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(mid - A[i]);
    }
    cout<<ans;
}
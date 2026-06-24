#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> A(6);
    A[1] = 1;
    A[2] = 2;
    A[3] = 4;
    A[4] = 8;
    A[5] = 16;
    A[0] = 32;
    for(int i=7; i<=n; i++){
        long long sum = 0;
        for(auto x: A) { sum+=x; sum%=(1000000007);}
        A[i%6] = sum;
    }
    cout<<A[n%6];
}
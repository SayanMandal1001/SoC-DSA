#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    long long n, x; cin>>n>>x;
    vector<long long> A(n);
    for(int i=0; i<n; i++){
        long long a; cin>>a;
        A[i] = a;
    }
    map<long long, vector<pair<long long, long long>>> m1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            m1[A[i]+A[j]].push_back(make_pair(i+1, j+1));
        }
    }
    bool found = false;
    for(int i=0; i<n; i++){
        if(found) break;
        long long a = A[i];
        if(m1.count(x-a)==0) continue;
        vector<pair<long long, long long>> v = m1[x-a];
        for(auto v1 : v){
            if(v1.first != i+1 && v1.second != i+1){
                cout<<i+1<<' '<<v1.first<<' '<<v1.second;
                found = true;
                break;
            }
        }
    }
    if(!found) {
        cout<<"IMPOSSIBLE";
    }
}
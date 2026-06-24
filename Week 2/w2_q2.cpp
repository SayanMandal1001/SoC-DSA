#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    long long n, x; cin>>n>>x;
    map<long long, vector<long long>> m;
    for(int i=0; i<n; i++){
        long long a; cin>>a;
        m[a].push_back(i+1);
    }
    bool found = false;
    for(auto p: m){
        long long a = p.first;
        if(2*a==x){
            if(p.second.size()>=2) {cout<<p.second[0]<<' '<<p.second[1]; found = true; break;}
        }else{
            if(m.count(x-a)!=0) {cout<<m[x-a][0]<<' '<<p.second[0]; found = true; break;}
        }
    }
    if(!found) {
        cout<<"IMPOSSIBLE";
    }
}
#include <iostream>
#include <map>
using namespace std;

int main(){
    long long n; cin>>n;
    map<long long, long long> m;
    long long count=0, maxCount=0;
    for(int i=0; i<n; i++){
        long long x; cin>>x;
        if(m.count(x)==0 || m[x] == -1){
            m[x] = i;
            count++;
        }else{
            count = i - m[x];
            m[x] = i;
        }
        maxCount = max(maxCount, count);
    }    
    cout<<maxCount;
}
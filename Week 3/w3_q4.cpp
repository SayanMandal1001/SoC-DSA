#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long edit(vector<vector<long long>>& memo, string a, string b, long long i, long long j){
    if(j >= b.length()) return a.length() - i;
    if(i >= a.length()) return b.length() - j;
    if(memo[i][j]!=-1) return memo[i][j];
    
    long long temp = edit(memo, a, b, i+1, j+1);
    long long res = min(temp, min(edit(memo, a, b, i, j+1), edit(memo, a, b, i+1, j))) + 1;
    if(a[i]==b[j]) res = min(res, edit(memo, a, b, i+1, j+1));
    memo[i][j] = res;
    return res;
}

int main(){
    string a, b;
    cin>>a>>b;
    vector<vector<long long>> memo(a.length(), vector<long long>(b.length(), -1));
    cout<<edit(memo, a, b, 0, 0);
}
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  string s;cin>>s;
  int n=s.size();

  vector<int> memo(n,0);
  
  bool hasL=false;
  int cnt=0,odd=0,even=0,bias,lid,rid;
  for(int i=0;i<=n;++i){
    if (i==n || hasL && s[i]=='R'){
      if ((cnt+bias)%2==0) {
        memo[rid] = even;
        memo[lid] = odd;
      }else{
        memo[rid] = odd;
        memo[lid] = even;
      }
     
      odd=even=cnt=0;
      hasL=false;
    }
    if (!hasL && s[i]=='L'){
      bias = cnt;
      lid=i-1;
      rid=i;
      hasL=true;
    }
    if (cnt%2==0)
      ++odd;
    else
      ++even;
    
    ++cnt;
  }

  for(int i=0;i<n;++i){
    if (i>0) cout<<" ";
    cout<<memo[i];
  }
  cout<<endl;
  
  return 0;
}

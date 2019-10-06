#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

signed main() {
  INIT;
  string s;cin>>s;
  int k;cin>>k;

  int ans = 0;
  int a=1,b=1,t=s.size()-2;
  while(a<s.size() && s[a]==s[a-1]) ++a;
  while(t>a && s[t]==s[t+1]) ++b,--t;

  int tmp = 1;
  for(int i=0;i<s.size();++i){
    if(i<s.size()-1 && s[i]==s[i+1]) ++tmp;
    else {
      ans += tmp/2 * k;
      tmp = 1;
    }
  }
  debug(ans);
  if(s.front() == s.back()) ans += ((a+b)/2-a/2-b/2) * (k-1);
  cout<<ans<<endl;

  debug(a);
  debug(b);
  
  return 0;
}

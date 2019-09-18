#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<(x)<<endl;

signed main() {
  int n;cin>>n;
  string s; cin>>s;
  int x=0,y=0;
  for(int i=0;i<s.size();++i){
    if ('a' <= s[i] && s[i] <= 'm') ++x;
    if ('n' <= s[i] && s[i] <= 'z') --x;
    if ('A' <= s[i] && s[i] <= 'M') ++y;
    if ('N' <= s[i] && s[i] <= 'Z') --y;
  }

  string ans = "";
  
  if (x<0) ans += string(abs(x),'n');
  else if(x>0) ans += string(x, 'a');
  if (y<0) ans += string(abs(y),'N');
  else if(y>0) ans += string(y, 'A');
  
  cout<<ans.size()<<endl;
  cout<<ans<<endl;
  return 0;
}

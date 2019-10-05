#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);
int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main() {
  INIT;
  string s;cin>>s;
  int k;cin>>k;

  if(s.size()==1){
    cout<<k/2<<endl;
    return 0;
  }

  int ans = 0;
  string t = s;
  int last = 0;
  for(int i=0;i<t.size()-1;++i){
    if(t[i]==t[i+1]) {
      t[i+1] = '?';
      if(i+2<t.size() && t[i] != t[i+2]) t[i] = '?';
      ans += k;
      if(s[i]!=s[i+2] || i==t.size()-2){
        for(int j=i;j>=1;--j){
          if(s[j+1]==s[j-1] && s[j] == s[j-1]) {
            t[j+1] = t[j-1] = '?';
          }
        }
      }
      ++i;
    }
  }
  if(t.front()==t.back() && t.front()!='?' && t.back()!='?') ans += k-1;
  cout<<ans<<endl;
  debug(t);
  return 0;
}

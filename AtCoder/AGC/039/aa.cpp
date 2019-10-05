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

  string t = "";
  for(int i=0;i<k;++i) t+=s;
  int ans = 0;

  for(int i=0;i<t.size()-1;++i){
    if(t[i]==t[i+1]) {
      ++ans;++i;
    }
  }
  cout<<ans<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<(x)<<endl;

// oxoxx
// xoxox

// 

signed main() {
  string s; cin>>s;
  int n = s.size();

  int d = 0;
  for(int i=n-1; i>=0; --i){
    if(s[i]=='o') d += 1<<i;
  }

  int ans = 0;

  int ddd = 0;
  while (true) {
    for(int i=0;i<n;++i){
      int tmp = 0;
      for(int j=0;j<n;++j){
        if(s[(i+j)%n] == 'o') {
          tmp += 1<<((i+j)%n);
        }
      }
      ddd = max(ddd, d ^ tmp);
    }
    ++ans;
    if (ddd == (1<<n)-1) break;
  }
  cout<<ans<<endl;
  
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  char c;cin>>c;
  string s; cin>>s;
  for(auto &&si: s){
    if(si==c) continue;
    cout<<si;
  }
  cout<<endl;
  return 0;
}

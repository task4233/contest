#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  string s;cin>>s;
  bool ok = true;
  for(int i=0;i<s.size();++i){
    if (i%2==0){
      string t = "RUD";
      bool ok2 = false;
      for(int j=0;j<3;++j){
        ok2 |= s[i] == t[j];
      }
      ok &= ok2;
    }else{
      string t = "LUD";
      bool ok2 = false;
      for(int j=0;j<3;++j){
        ok2 |= s[i] == t[j];
      }
      ok &= ok2;      
    }

  }
  cout<<(ok?"Yes":"No")<<endl;
  return 0;
}

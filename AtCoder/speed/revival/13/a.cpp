#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  string s;cin>>s;
  string t[3] = {"Sunny", "Cloudy", "Rainy"};
  for(int i=0;i<3;++i){
    if(s==t[i]){
      cout<<t[(i+1)%3]<<endl;
      return 0;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

signed main() {
  int n,l;cin>>n>>l;

  string y;getline(cin,y);
  vector<string> s(l);
  for(int i=0;i<l;++i){
    getline(cin, s[i]);
  }
  
  getline(cin,y);
  int ans;
  for(int i=0;i<n;++i){
    int j = 2*i;
    if (y[j]=='o')
      ans = j;
  }
  
  for(int i=l-1;i>=0;--i){
    if(ans>0 && s[i][ans-1] == '-') ans -= 2;
    else if(ans<2*n-1 && s[i][ans+1] == '-') ans += 2;
   
  }

  cout << (ans+1)/2+1 << endl;
  return 0;
}

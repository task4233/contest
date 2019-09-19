#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int t1,t2,r1,r2;cin>>t1>>t2>>r1>>r2;
  if (r1==r2) cout << "Draw" <<endl;
  else if (r1<0 || r2<0) {
    if (t1==t2) cout << "Draw" << endl;
    else if(t1<t2) cout << "Alice" <<endl;
    else cout << "Bob" << endl;
  } else {
    if (r1<r2) cout << "Bob" << endl;
    else cout << "Alice" << endl;
  }
  return 0;
}

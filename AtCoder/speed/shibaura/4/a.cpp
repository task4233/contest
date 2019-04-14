#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int a,b;
  cin>>a>>b;
  bool ok = (a%2 && b%2);
  cout<<(ok?"Yes":"No")<<endl;
  return 0;
}

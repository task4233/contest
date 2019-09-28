#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

signed main() {
  INIT;
  long double n;cin>>n;
  long double d = ((int)n+1)/2;
  cout<<fixed<<setprecision(10)<<d/n<<endl;
  return 0;
}

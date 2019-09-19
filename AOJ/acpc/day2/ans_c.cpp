#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

using Pos = pair<int,int>;

long double getLen(Pos a, Pos b) {
  return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second,2));
}

signed main() {
  int n;cin>>n;
  vector<long double> x(n),y(n);
  for(int i=0;i<n;++i){
    cin>>x[i]>>y[i];
  }

  long double ans = 1e9+1;
  
  vector<int> par(n);
  iota(par.begin(), par.end(), 0);
  do {
    vector<long double> angles(n);
    
    long double bx=0.0, by=0.0;
    for(int i=0;i<=n;++i){
      long double nx, ny;
      if (i==n) nx=0.0, ny=0.0;
      else nx = x[par[i]], ny = y[par[i]];
      // get angle A
      long double x = nx - bx;
      long double y = ny - by;
      long double angle;

      if(x==0 && y==0) {
        if (angles.empty()) angle = 0.0;
        else angle = angles.back();
      } else if(x==0) {
        if(y>0) angle = 90.0;
        else angle = 270.0;
      } else if(y==0) {
        if(x>0) angle = 0.0;
        else angle = 180.0;
      } else {
        angle = 180.0 * atan(y/x) / (atan(1.0)*4.0);
      }

      while(angle<0) angle += 360.0;
      angles.emplace_back(angle);

      bx = nx;
      by = ny;
    }
    
    long double tmp = 0.0;
    for(int i=0;i<angles.size()-1;++i){
      long double diff = angles[i+1]-angles[i];
      while(diff<0) diff += 360.0;
      while(diff>180) diff = 360.0 - diff;
      tmp += diff;
    }
    //debug(tmp);
    ans = min(ans, tmp);
  } while(next_permutation(par.begin(), par.end()));

  cout<<fixed<<setprecision(5)<<ans<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<fixed<<setprecision(10)<<x<<endl;

using Pos = vector< pair<long double,long double> >;

void cal(Pos four) {
  sort(four.begin(), four.end(), [](auto&& p1, auto&& p2){
                                   return p1.second/p1.first > p2.second/p2.first;
                                 });
  long double a = -1.0*four.front().first;
  long double b = -1.0*four.front().second;
  long double c = sqrt(pow(a, 2) + pow(b, 2));
  long double hoge = (pow(c,2) + pow(a,2) - pow(b,2));
  long double fuga = (2.0 * a * c);
  long double ans = 180.0*acos(hoge/fuga)/(atan(1.0)*4.0);
  // debug(ans);
  if (a==1.0 && b==0.0) ans = -360.0;
  
  if (isnan(ans)) {
    if (hoge>0)
      ans = -90.0;
    else
      ans = 90.0;
  }
  cout<<fixed<<setprecision(10)<<(ans+360.0)<<endl;

  // debug(a);
  // debug(b);
  // debug(c);
}

signed main() {
  int n;cin>>n;
  Pos pos(n);
  for(int i=0;i<n;++i){
    long double a,b;cin>>a>>b;
    pos[i] = make_pair(a,b);
  }

  Pos one, two, three, four;
  
  for(int i=0;i<n;++i){
    long double x,y;
    tie(x,y) = pos[i];
    if (x>=0 && y<0) four.emplace_back(pos[i]);
    else if(x>=0 && y>=0) one.emplace_back(pos[i]);
    else if(x<0 && y>=0) two.emplace_back(pos[i]);
    else three.emplace_back(pos[i]);
  }

  if (four.size()>0)cal(four);
  else if(three.size()>0) cal(three);
  else if(two.size()>0) cal(two);
  else cal(one);
  
  return 0;
}

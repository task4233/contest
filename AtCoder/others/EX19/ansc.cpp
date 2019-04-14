#include <bits/stdc++.h>
using namespace std;
using int64 = long long int;
#define int int64
#define debug(x) cerr<<#x<<" "<<x<<endl;

signed main() {
  int n,q;cin>>n>>q;
  string s;cin>>s;
  vector<char> t(q),d(q);
  for(int i=0;i<q;++i){
    cin>>t[i]>>d[i];
  }
  auto check = [=](int id){
                 for(int i=0;i<q;++i){
                   if(s[id] != t[i]) continue;
                   if(d[i] == 'L'){
                     --id;
                   }else{
                     ++id;
                   }
                   if(id < 0) return -1;
                   if(id > n-1) return 1;
                 }
                 return 0;
               };
    
  int lb_ng = 0,lb_ok = n;
  while(lb_ok-lb_ng > 1){
    int mid = (lb_ok+lb_ng)>>1;
    (check(mid)<0 ? lb_ng : lb_ok) = mid;
  }

  int ub_ng = n,ub_ok = 0;
  while(ub_ng-ub_ok > 1){
    int mid = (ub_ok+ub_ng)>>1;
    (check(mid)>0 ? ub_ng : ub_ok) = mid;
  }
 
  int ans = ub_ok-lb_ok+1;
  cout<<ans<<endl;
  
  return 0;
}

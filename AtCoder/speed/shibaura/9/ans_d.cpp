#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
constexpr int INF = 1LL<<60;

signed main() {
  int n,k;cin>>n>>k;
  vector<int> a(k);
  for(int i=0;i<k;++i) cin>>a[i];
  vector<string> s(n);
  for(int i=0;i<n;++i) cin>>s[i];

  // 空文字確定演出
  if(n==k) {
    cout<<""<<endl;
    return 0;
  }

  int mn_ok=INF, mn_ng=INF;
  vector<string> ok,ng;
  for(int i=0;i<k;++i){
    ok.emplace_back(s[a[i]-1]);
    mn_ok = min(mn_ok, (int)s[a[i]-1].size());
    s[a[i]-1] = "-1";
  }
  for(int i=0;i<n;++i){
    if(s[i]=="-1") continue;
    ng.emplace_back(s[i]);
    mn_ng = min(mn_ng, (int)s[i].size());
  }

  // 含んで欲しい部分の最小値を求める
  int mn = 0;
  for(int i=1;i<=mn_ok;++i) {
    bool isOK = true;
    for(int j=0;j<k-1;++j){
      isOK &= ok[j].substr(0,i) == ok[j+1].substr(0,i);
    }
    if(!isOK) break;
    mn = i;
  }

  // 含まないで欲しい部分の最大値を求める
  int mx = 0;
  for(int i=mn_ng;i>=1;--i){
    bool isOK = true;
    for(int j=0;j<ng.size()-1;++j){
      isOK &= ng[j].substr(0,i) == ng[j+1].substr(0,i);
    }
    if(isOK) {
      mx = i;
      break;
    }
  }

  // 条件が正しいかを判定
  if(mn<mx){
    // 問題がある
    cout<<(-1)<<endl;
  }else{
    // 問題ない
    cout<<(ok[0].substr(0,mx+1))<<endl;
  }
  
  return 0;
}

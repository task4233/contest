#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
constexpr int INF = 1e9 +1;

#define debug(x) cerr<<#x<<":"<<x<<endl;

template< class Abel > class RMQQ {
public:
  RMQQ(int _n) {
    init(_n);
  }

  void init(int _n) {
    N = 1;
    while (N < _n) {
      // 頂点数を2のべき乗にする
      N <<= 1;
    }
    d.resize(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; ++i) {
      d[i] = 0;
    }
  }

  void update(int k, Abel a) {
    // kの位置を葉まで移動
    k += N - 1;
    d[k] = a;
    // 頂点まで値を更新する
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = max(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // 呼び出しは[a, b)の!!!半開区間!!!
  Abel _query(int _a, int _b) {
    return query(_a, _b, 0, 0, N);
  }
  
  
private:
  int N;
  vector< Abel > d;

  // 呼び出しでミスをする可能性があるので、privateにしておく
  Abel query(int a, int b, int k, int l, int r) {
    // [a, b)に対して、[l, r)が範囲として成立していない
    if (!(a < r && l < b)) return 0;
    
    // [a, b)が[l, r)を完全にカバーしている(queryを再帰的に呼び出しても範囲は狭まるだけ)
    if (a <= l && r <= b) return d[k];
    
    // それ以外の時、葉の2つの子の最小値を再帰的に求める
    Abel vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Abel vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
  
};

template< class Abel > class RMQ {
public:
  RMQ(int _n) {
    init(_n);
  }

  void init(int _n) {
    N = 1;
    while (N < _n) {
      // 頂点数を2のべき乗にする
      N <<= 1;
    }
    d.resize(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; ++i) {
      d[i] = INF;
    }
  }

  void update(int k, Abel a) {
    // kの位置を葉まで移動
    k += N - 1;
    d[k] = a;
    // 頂点まで値を更新する
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // 呼び出しは[a, b)の!!!半開区間!!!
  Abel _query(int _a, int _b) {
    return query(_a, _b, 0, 0, N);
  }
  
  
private:
  int N;
  vector< Abel > d;

  // 呼び出しでミスをする可能性があるので、privateにしておく
  Abel query(int a, int b, int k, int l, int r) {
    // [a, b)に対して、[l, r)が範囲として成立していない
    if (!(a < r && l < b)) return INF;
    
    // [a, b)が[l, r)を完全にカバーしている(queryを再帰的に呼び出しても範囲は狭まるだけ)
    if (a <= l && r <= b) return d[k];
    
    // それ以外の時、葉の2つの子の最小値を再帰的に求める
    Abel vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Abel vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
  
};

signed main() {
  int n,k;cin>>n>>k;
  vector<int> p(n);
  
  RMQ<int> rmq(n);
  RMQQ<int> rmqq(n);
  for(int i=0;i<n;++i){
    cin>>p[i];
    rmq.update(i,p[i]);
    rmqq.update(i,p[i]);
  }

  int ans = n-k+1;

  // 0/ 1\ //
  vector<int> updown(n,0);
  for(int i=0;i<n-1;++i){
    if(p[i]>p[i+1]) updown[i] = 0;
    else updown[i] = 1;
  }

  // id, / or \\//
  vector< int > change;
  for(int i=0;i<n-2;++i){
    if(updown[i]!=updown[i+1]){
      change.emplace_back(i+1);
    }
  }
  
  // iは左端
  for(int i=0;i<n-k;++i){
    int lb=i,ub=i+k-1;
    if(p[lb]==rmq._query(lb,ub+2) && p[ub+1]==rmqq._query(lb,ub+2)){
      --ans;
    }else{
      auto lbi = lower_bound(change.begin(), change.end(), lb);
      auto ubi = lower_bound(change.begin(), change.end(), ub);
      if(*lbi<=lb && *ubi>=ub){
        //debug(*lbi);
        //debug(*ubi);
        if(lbi==ubi) {
          if(ubi!=change.end()) --ans;
        }else if (ubi!=change.end()) {
          lbi++;
          if(lbi==ubi) --ans;
        }
        if(lbi==
      }
    }
    /*
    debug(p[lb]);
    debug(p[ub+1]);
    debug(rmq._query(lb,ub+2));
    debug(rmqq._query(lb,ub+2));
    */
  }
  ans = max(ans,1LL);
  cout<<ans<<endl;
  
 
  return 0;
}

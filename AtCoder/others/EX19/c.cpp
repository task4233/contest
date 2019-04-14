#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

vector<int> order[30];
vector<int> action[30];

signed main() {
  INIT;
  VAR(int,n,q);
  VAR(string,s);
  REP(si,s.size()){
    int id = s[si] - 'A';
    order[id].push_back(si);
  }
  vector<int> diff(30,0);
  vector<int> less(30,0);
  vector<int> more(30,0);
  
  vector<map<int,int>> order_less(30);
  vector<map<int,int>> order_more(30);
  
  REP(i,30){
    REP(j,30){
      if(i==j) continue;
      REP(k,order[i].size()){
        auto itr = lower_bound(ALL(order[j]), order[i][k]);
        int _less = *itr;
        order_less[i][j] = _less;
        if(itr != order[j].begin()) itr--;
        int _more = *itr;
        order_more[i][j] = _more;
      }
    }
  }
  
  REP(i,q){
    VAR(char,t,d);
    int id = t-'A';
    int dist = (d=='L'?1:-1);
    //action[id].push_back(dist);

    
    // {id, num_from_begin}
    // あったら追加

    
    REP(i,30){
      if(i==id) continue;
      if(lower_bound(ALL(order_more[id]), diff[i]+diff[id]) != upper_bound(ALL(order_more[id]), diff[i]+diff[id])) {
        int _id = lower_bound(ALL(order_more[id]), diff[i]+diff[id]) - order_more[id].begin();
        order[i].push_back(order[id][_id] + dist);
        order[id].erase(lower_boun);
      }
    }
    
    
    // 該当するidを動かす
    diff[id] += dist;
    int _less = (lower_bound(ALL(order[id]), diff[id]) - order[id].begin());
    less[id] = max(less[id], _less);
    int _more = ((order[id].size()) - (lower_bound(ALL(order[id]), (n+diff[id])) - order[id].begin()));
    more[id] = max(more[id], _more);
    
    
    // 全てのidを動かす
    // どれを動かせば良いのかがわからない
  }

  // 最後に, 全てのindextについてminとmaxを計算
  
  int ans = n;
  REP(i,30){
    ans -= less[i] + more[i];
  }
  /*  
  REP(i,30){
    int diff = 0, less=0, more=0;
    REP(j,action[i].size()){
      diff += action[i][j];
      int _less = (lower_bound(ALL(order[i]), diff) - order[i].begin());
      less = max(less, _less);
      int _more = ((order[i].size()) - (lower_bound(ALL(order[i]), (n+diff)) - order[i].begin()));
      more = max(more, _more);
    }
    if(order[i].size()>0){
      debug(i);
      debug(less);
      debug(more);
    }
    ans -= less + more;
  }
  */
  OUT(ans)BR;
  
  
  return 0;
}

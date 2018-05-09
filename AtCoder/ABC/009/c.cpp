// ------------------------------------
// Date:2018/ 3/21
// Problem:C - 辞書式順序ふたたび c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int N, K;
string S, ans;

typedef pair< char, int > P;

bool dfs(int cnt, int n, priority_queue< char, vector< char >, greater< char > > f, priority_queue< P, vector< P >, greater< P > > q) {
  // if (cnt > K) return false;
  if (q.empty()) return false;
  if (n > N) return false;
  
  P tmp = q.top(); q.pop();
  char ch = (f.empty() ? '_' : f.top());
  /*
  debug(cnt);
  debug(tmp.first);
  debug(tmp.second);
  debug(ch);
  debug(S);
  */

  if (cnt >= K) {
    if (S[n] == '?') {
      ans[n] = ch;
      f.pop();
    }
  } else {
    if (tmp.first != S[n]) { 
      if (tmp.first == ch) {
	// OK(true);
	if (S[tmp.second] != S[n]) {
	  f.pop();
	}
	if (S[tmp.second] != '?') {
	  bool ok = true;
	  REP(i, n) {
	    if (ans[i] == ans[n]) ok = false;
	  }
	  if (ok)
	  {
	    f.push(ans[n]);
	  }
	}
      ans[n] = tmp.first;
      cnt++;
      } else {
	//OK(false);
	if (S[n] != '?') {
	  f.push(ans[n]);
	  cnt++;
	}
	if (tmp.second >= n) {
	  S[tmp.second] = '?';
	}
	ans[n] = tmp.first;
	cnt++;
      }
    }
  }
  // debug(ans);
  // cout << endl;
  
  dfs(cnt, n + 1, f, q);
  
  return true;
}

int main()
{
  cin >> N >> K;
  cin >> S;
  ans = S;
  
  priority_queue< P, vector< P >, greater< P > > q;
  REP(si, S.size()) {
    P tmp = make_pair(S[si], si);
    q.push(tmp);
  }

  priority_queue< char, vector< char >, greater< char > > f;
  dfs(0, 0, f, q);

  cout << ans << endl;
  

  return 0;
}


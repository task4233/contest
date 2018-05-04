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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

vector< int > e[MAX_N];
int N, M;
bool state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    e[a[i]].emplace_back(b[i]);
    e[b[i]].emplace_back(a[i]);
  }

  // OK(true);

  /*
  vector< int > s;
  int mn = INF;
  REP(i, N) {
    if (e[i].size() < mn) {
      mn = e[i].size();
      s.clear();
      s.emplace_back(i);
    } else if(e[i].size() == mn) {
      s.emplace_back(i);
    }
    // mn = min(mn, e[i].size());
  }
  */

  // int last;
  vector< int > after_path;
  //REP(si, s.size())
  {
    // memset(state, false, sizeof(state));
    state[0] = true;
    
    int from = 0;
    after_path.emplace_back(from);
    bool ok = false;
    // debug(from);
    
    // OK(false);
    REP(i, N - 1) {
      EACH(to, e[from]) {
	if (state[to]) continue;
	from = to;
	state[from] = true;
	after_path.emplace_back(from);
	// debug(from);
	
	
	bool check = true;
	EACH(ti, e[from]) {
	  if (!state[ti]) {
	    check = false;
	    break;
	  }
	}
	if (check) ok = true;
	// last = from;
	break;
      }
      if (ok) break;
    }
  }

  vector< int > before_path;
  {
    // memset(state, false, sizeof(state));
    // state[0] = true;
    
    int from = 0;
    before_path.emplace_back(from);
    bool ok = false;
    // debug(from);
    
    // OK(false);
    REP(i, N - 1) {
      EACH(to, e[from]) {
	if (state[to]) continue;
	from = to;
	state[from] = true;
	before_path.emplace_back(from);
	// debug(from);
	
	
	bool check = true;
	EACH(ti, e[from]) {
	  if (!state[ti]) {
	    check = false;
	    break;
	  }
	}
	if (check) ok = true;
	// last = from;
	break;
      }
      if (ok) break;
    }
  }
  
  reverse(ALL(before_path));
  
  cout << after_path.size() + before_path.size() - 1 << endl;
  REP(pi, before_path.size() - 1) {
    cout << before_path[pi] + 1 << " ";
  }
  REP(pi, after_path.size()) {
    cout << after_path[pi] + 1;
    if (pi < after_path.size() - 1) cout << " ";
    else cout << endl;
  }
  
  /*
  REP(i, N) {
    cout << i + 1 << endl;
    EACH(si, e[i]) {
      debug(si+1);
    }

    cout << endl;
  }
  */

  return 0;
}


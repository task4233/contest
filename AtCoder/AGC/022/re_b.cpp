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
const int MAX_N = 3e4 + 1;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  
  int s = 0;
  int t = 0;

  int sum;
  vector< int > lis;
  REP(i, MAX_N) {
    /*
    REP(j, lis.size()) {
      cout << lis[i];
      if (i < N - 1) cout << " ";
      else cout << endl;
    }
    */
    
    if (i % 6 == 0) continue;
    else if (i % 2 == 0) {
      lis.emplace_back(i);
      s++;
    } else if (i % 3 == 0) {
      lis.emplace_back(i);
      t++;
    } else {
      continue;
    }
    if (s + t == N) {
      if (i % 2 == 0) {
	if (t % 2 == 0) break;
	REP(j, lis.size()) {
	  if (lis[j] % 2 == 0) {
	    lis.erase(lis.begin() + j);
	    break;
	  }
	}
	FOR(j, i + 1, MAX_N) {
	    if (j % 3 == 0) {
	      lis.emplace_back(j);
	      break;
	    }
	}
	break;
      } else {
	if (i % 3 == 0) {
	  if (s % 3 == 0) break;

	  if (s % 3 == 1) {
	    REP(j, lis.size()) {
	      if (lis[j] % 2 == 0) {
		lis.erase(lis.begin() + j);
		break;
	      }
	    }
	    FOR(j, i + 1, MAX_N) {
	      if (j % 6 == 0) continue;
	      if (j % 3 == 0) {
		lis.emplace_back(j);
		break;
	      }
	    }
	  } else {
	    REP(j, lis.size()) {
	      if (lis[j] % 3 == 0) {
		lis.erase(lis.begin() + j);
		break;
	      }
	    }
	    FOR(j, i + 1, MAX_N) {
	      if (j % 6 == 0) continue;
	      if (j % 2 == 0) {
		lis.emplace_back(j);
		break;
	      }
	    }
	  }
	  break;
	}
      }
    }
  }

  REP(i, lis.size()) {
    cout << lis[i];
    if (i < lis.size() - 1) cout << " ";
    else cout << endl;
  }
  
  return 0;
}


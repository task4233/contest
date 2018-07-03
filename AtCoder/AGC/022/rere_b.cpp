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
  } else if (N == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  } else if (N == 5) {
    cout << "2 5 20 30 63" << endl;
    return 0;
  }

  int sm = 0;
  int cnt = 0;
  vector< int > lis;
  bool ok = false;
  FOR(i, 2, MAX_N) {
    switch(i % 6) {
    case 0:
    case 2:
      // 2N
    case 3:
      // 3N
    case 4:
      // 2N

      lis.emplace_back(i);
      sm += i;
      cnt++;
      if (cnt == N) {
	ok = true;
	/*
	REP(i, lis.size()) {
	  cout << lis[i];
	  if (i < lis.size() - 1) {
	    cout << " ";
	  } else {
	    cout << endl;
	  }
	}
	*/
  
	// debug(sm);
	switch(sm % 6) {
	case 2:
	  REP(j, lis.size()) {
	    if (lis[j] == 8) {
	      lis.erase(lis.begin() + j);
	      break;
	    }
	  }
	  FOR(j, i + 1, MAX_N) {
	    if (j % 6 == 0) {
	      lis.emplace_back(j);
	      break;
	    }
	  }
	
	break;

	case 3:
	  REP(j, lis.size()) {
	    if (lis[j] == 9) {
	      lis.erase(lis.begin() + j);
	      break;
	    }
	  }
	  FOR(j, i + 1, MAX_N) {
	    if (j % 6 == 0) {
	      lis.emplace_back(j);
	      break;
	    }
	  }
	  break;
	  
	case 5:
	  REP(j, lis.size()) {
	    if (lis[j] == 9) {
	      lis.erase(lis.begin() + j);
	      break;
	    }
	  }
	  FOR(j, i + 1, MAX_N) {
	    if (j % 6 == 4) {
	      lis.emplace_back(j);
	      break;
	    }
	  }
	}
      }
      break;

    default:
      break;
    }
    if (ok) break;
  }

  REP(i, lis.size()) {
    cout << lis[i];
    if (i < lis.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  
  return 0;
}


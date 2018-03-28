// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ d.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int a, b;

char g[100][100];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> a >> b;

  int sum = a + b;
  int tmp = 0;

  int loopNum = sum / 100 + (sum % 100 == 0 ? 0 : 1);
  int subloop = (abs(a - b) > 1) ? ((max(a, b) * 2) % 100 == 0 ? 100 : (max(a, b) * 2)) : a + b;
  
  REP(i, loopNum) {
    if (sum < 100) {
      if (abs(a - b) <= 1) {
	// abs(a - b) <= 1
	if(i % 2 == 0) {
	  REP(j, sum) {
	    if (j % 2 == 0) {
	      g[i][j] = '#';
	      
	  } else {
	      g[i][j] = '.';
	    }
	  }
	} else {
	  REP(j, sum) {
	    if (j % 2 == 1) {
	      g[i][j] = '#';
	    } else {
	      g[i][j] = '.';
	    }
	  }
	}
	if (i > 0) {
	  RFOR(j, sum + 2, 100) {
	    if (g[i - 1][j] == '.') {
	      g[i][j] = '.';
	    } else {
	      g[i][j] = '#';
	    }
	  }
	  g[i][sum] = g[i][sum + 1] = g[i - 1][sum + 1];
	}
      } else {
	// abs(a - b) > 1
	if (abs(a - b) < 50) {
	  if(i % 2 == 0) {
	    REP(j, max(a, b) * 2) {
	      if (j % 2 == 0) {
		g[i][j] = '#';
		
	      } else {
		g[i][j] = '.';
	      }
	    }
	  } else {
	    REP(j, max(a, b) * 2) {
	      if (j % 2 == 1) {
		g[i][j] = '#';
	      } else {
		g[i][j] = '.';
	      }
	    }
	  }
	  if (i > 0) {
	    RFOR(j, max(a, b) * 2 + 2, 100) {
	      if (g[i - 1][j] == '.') {
		g[i][j] = '.';
	      } else {
		g[i][j] = '#';
	      }
	    }
	    g[i][max(a, b) * 2] = g[i][max(a, b) * 2 + 1] = g[i - 1][max(a, b) * 2 + 1];
	  }
	  
	  RFOR(j, min(a, b) * 2, subloop) {
	    if (a < b) {
	      g[i + 1][j] = '.';
	    } else {
	      g[i + 1][j] = '#';
	    }
	    
	  }
	  REP(j, min(a, b) * 2) {
	    
	    if (g[i][j] == '.') {
	      g[i + 1][j] = '.';
	    } else {
	      g[i + 1][j] = '#';
	    }
	  }
	} else {
	  tmp = abs(a - b) / 50 + (abs(a - b) % 50 == 0 ? 0 : 1);
	  if (a < b) {
	    // .
	    REP(j, tmp) {
	      g[i + j][98] = g[i + j][99] = '.';
	    }
	  } else {
	    REP(j, tmp) {
	      g[i + j][98] = g[i + j][99] = '#';
	    }
	  }

	  FOR(k, i, tmp + i) {

	    // 48で割る
	    if(k % 2 == 0) {
	      REP(j, max(a, b) * 2) {
		if (j % 2 == 0) {
		  g[k][j] = '#';
		  
		} else {
		  g[k][j] = '.';
		}
	      }
	    } else {
	      REP(j, max(a, b) * 2) {
		if (j % 2 == 1) {
		  g[k][j] = '#';
		} else {
		  g[k][j] = '.';
		}
	      }
	    }
	    if (k > 0) {
	      RFOR(j, max(a, b) * 2 + 2, 98) {
		if (g[k - 1][j] == '.') {
		  g[k][j] = '.';
		} else {
		  g[k][j] = '#';
		}
	      }
	      g[k][max(a, b) * 2] = g[i][max(a, b) * 2 + 1] = g[i - 1][max(a, b) * 2 + 1];
	    }
	    
	    RFOR(j, min(a, b) * 2, subloop) {
	      if (a < b) {
		g[k + 1][j] = '.';
	      } else {
		g[k + 1][j] = '#';
	      }
	      
	    }
	    REP(j, min(a, b) * 2) {
	      
	      if (g[k][j] == '.') {
		g[k + 1][j] = '.';
	      } else {
		g[k + 1][j] = '#';
	      }
	    }
	  }
	}
	break;
      }
    } else {
      
      // 普通
      if(i % 2 == 0) {
	REP(j, 100) {
	  if (j % 2 == 0) {
	    g[i][j] = '#';
	  } else {
	    g[i][j] = '.';
	  }
	}
      } else {
	REP(j, 100) {
	  if (j % 2 == 1) {
	    g[i][j] = '#';
	  } else {
	    g[i][j] = '.';
	  }
	}
      }
    }
    sum -= 100;
  }

  cout << loopNum + tmp  + (abs(a - b) > 1 ? 1 : 0) << " " << min(subloop, 100) << endl;
  REP(i, loopNum + (abs(a - b) > 1 ? 1 : 0) + tmp ) {
    REP(j, min(subloop, 100)) {
      cout << g[i][j];
    }
    cout << endl;
  }

  
  return 0;
}


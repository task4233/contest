// ------------------------------------
// Date:2018/ 5/ 5
// Problem:/ / / d.cpp
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
const int MAX_N = 55556;
const int MAX_M = 1e5 + 1;
struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  void init(int n) {
    prime.resize(n + 1);
    REP(i, prime.size()) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i < sqrt(n); i++) {
      if (prime[i]) {
        for (int j = 0; i * (j + 2) < n; j++) {
	  prime[i * (j + 2)] = false;
	}
      }
    }
  }
};

int N;

int sum[MAX_M];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  Eratosthenes e(MAX_M);

 
  cin >> N;


   FOR(h, 1, 56)
  {
    bool fag = false;
    N = h;
  vector< int > list;
  vector< int > ans;
  int cnt = 0;
  REP(i, MAX_N) {
    if (e.prime[i]) {
      list.emplace_back(i);
      if (cnt < 1) {
	sum[cnt] = i;
	ans.emplace_back(i);
	// debug(i);
      } else {
	sum[cnt] = sum[cnt - 1] + i;
	if (cnt < N - 1) {
	  ans.emplace_back(i);
	}
      }
      cnt++;
    }
  }

  int ub;
 


  /*
  REP(i, 10) {
    printf("list[%d]:%d\n", i, list[i]);
    printf("sum[%d]:%d\n", i, sum[i]);
    // debug(sum[i]);
  }
  */
  
  REP(lb, list.size()) {
    bool ok = false;
    ub = lb + N - 1;

    int tmp = sum[ub - 1];
    if (lb > 0) {
      // if (lb > 1)
      {
	tmp -= sum[lb - 1];
      }
      ans.erase(ans.begin());
      ans.emplace_back(list[ub - 1]);
    }
    // debug(tmp);
    // debug(ub);

    ll p;
    while(ub < list.size()) {
      if (e.prime[tmp + list[ub]]) {
	debug(tmp + list[ub]);
	 debug(list[ub]);
	 p = tmp + list[ub];
	// debug(sum[lb + N]);
	// debug(sum[lb + N] + list[ub]);
	ans.emplace_back(list[ub]);
	ok = true;
      }
      if (ok) {
	
	ll dl = 0ll;
	REP(i, N) {
	  dl += ans[i];
	}

	if (dl == p) cout << h  << " ";
	fag = true;
	// debug(dl);
	
	//if (e.prime[dl])
	/*
	{ 
	  REP(i, N) {
	    cout << ans[i];
	    if (i < N - 1) cout << " ";
	    else cout << endl;
	  }
	  //return 0;
	  //fag = true;
	   break;
	  return 0;
	}
	*/
      }
      if (fag) break;
      ub++;
    }
    if (fag) break;
  }
  }

  

  return 0;
}


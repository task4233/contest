#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
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
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sm=0;
				debug(A.size());
        for(int i=0;i<A.size();++i){
            sm += A[i];
            int tmp=0,cnt=0,zcnt=0;
						debug("reset");
						debug(i);
						debug(sm);
            for(int j=i+1;j<A.size();++j){
                tmp += A[j];
								if(A[j] == 0) {
									zcnt++;
									continue;
								}
								debug(A[j]);
                if(tmp == sm) {
									debug(sm);
									tmp = 0;
									++cnt;
                }
            }
						if(tmp==0) {
							debug(cnt);
							debug(zcnt);
							if(cnt > 2) continue;
							if(cnt + zcnt < 2) continue; 
							return true;
						}
        }
        return false;
    }
};

signed main() {
  INIT;
	VAR(int,n);
	VEC(int,a,n);
	Solution s;
	OUT(s.canThreePartsEqualSum(a)?"ok":"ng")BR;
	
  
  return 0;
}

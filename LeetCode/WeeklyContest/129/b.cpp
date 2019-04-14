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
    int smallestRepunitDivByK(int K) {
        // even -> ng
        // 3 -> ok
        // 5 -> ng(0/5)
        // 7 -> ok?(7/4/1/8/5/2/9/6/3/0)
        auto getNum = [&](string str){
            int64_t res = 0,rate=1;
            for(int i=0;i<str.size();++i){
                res += (str[i] - '0') * rate;
                rate *= 10;
            }
            return res;
        };
        
        if(K%2==0) return -1;
				        string res = "";
        while(true){
            res += "1";
            int64_t tmp = getNum(res);
            if(tmp % K == 0) return res.size();
        }
				return -1;
    }
};

signed main() {
  INIT;
	VAR(int,k);
	Solution s;
	OUT(s.smallestRepunitDivByK(k))BR;
  
  return 0;
}

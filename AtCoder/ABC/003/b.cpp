// ------------------------------------
// Date:2018/ 2/14
// Problem:ABC 003 AtCoderトランプ b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

// -------------------------------------------------
string solve(const string S, const string T)
{
    REP(wordNum, S.size()) {
        if (S[wordNum] == T[wordNum]) continue;
        if (S[wordNum] == '@') {
            switch (T[wordNum]) {
                case 'a':
                case 't':
                case 'c':
                case 'o':
                case 'd':
                case 'e':
                case 'r':
                    break;
                default:
                    return "You will lose";
            }
            continue;
        }
        if (T[wordNum] == '@') {
            switch (S[wordNum]) {
                case 'a':
                case 't':
                case 'c':
                case 'o':
                case 'd':
                case 'e':
                case 'r':
                    break;
                default:
                    return "You will lose";
            }
            continue;
        }
        return "You will lose";
    }
    return "You can win";
}
// -------------------------------------------------

int main()
{
    string S,T;
    cin >> S >> T;
    cout << solve(S,T) << endl;
    return 0;
}


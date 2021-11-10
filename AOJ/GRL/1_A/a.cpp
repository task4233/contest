#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int V, E, r;
vector<pair<int, int>> d[101010];

void input() {
    cin >> V >> E >> r;

    for (uint idx=0; idx<E; ++idx) {
        int s, t, dd;
        cin >> s >> t >> dd;
        d[s].push_back(make_pair(t, dd));
    }
}


void solve() {
    for (uint idx=0; idx<V; ++idx) {
        cout << getAns(idx) << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}

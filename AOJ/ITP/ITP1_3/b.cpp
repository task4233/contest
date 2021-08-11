#include <iostream>
using namespace std;

int main() {
    int a, cnt = 1;
    while (1) {
        cin >> a;
        if (a == 0) break;
        printf("Case %d: %d\n", cnt++, a);
    }
    return 0;
}

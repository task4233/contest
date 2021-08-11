#include <iostream>
using namespace std;

int main() {
    int sec;
    cin >> sec;
    int min = sec / 60;
    int hr = min / 60;
    min %= 60;
    sec %= 60;

    printf("%d:%d:%d\n", hr, min, sec);
    return 0;
}

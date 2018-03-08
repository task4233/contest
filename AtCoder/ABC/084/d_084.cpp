#include <iostream>
int Q, l, r;
bool p[100001];
int c[100002];
int main()
{
    for (int i = 0; i <= 100000; ++i) if (!p[i]) for (int j = i+i; j <= 100000; j += i) p[i] = true;
    for (int i = 3; i <= 100000; i += 2) if (!p[i]&&!p[(i+1)/2])c[i]++;
    for (int i = 3; i <= 100000; ++i) c[i] += c[i-1];
    std::cin >> Q;
    while(Q--) {
        std::cin >> l >> r;
        std::cout << c[r]-c[l-1] << std::endl;
    }
    return 0;
}

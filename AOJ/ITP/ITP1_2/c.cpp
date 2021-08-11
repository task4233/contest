#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> in(3, 0);
    for (int &val : in)
    {
        cin >> val;
    }

    sort(in.begin(), in.end());

    bool isFirst = true;
    for (const int &val : in)
    {
        if (!isFirst) cout << " ";
        cout << val;
        isFirst = false;
    }
    cout << endl;
    return 0;
}

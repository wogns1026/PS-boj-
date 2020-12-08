#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, num, a, b, p[1000001];

int find(int x) {
    if (p[x] < 0) {
        return x;
    }
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; i++) {
        cin >> num >> a >> b;
        if (num == 0) {
            merge(a, b);
        }
        else {
            if (find(a) == find(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
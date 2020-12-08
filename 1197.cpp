#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, pair<int, int>> PII;
int n, m, a, b, c, p[10001], cnt, ans;
priority_queue<PII, vector<PII>, greater<PII>> pq;

int find(int x) {
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    p[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({ c, {a, b} });
    }
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; i++) {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if (merge(u, v)) {
            ans += w;
            cnt++;
            if (cnt == n - 1)
                break;            
        }
    }
    
    cout << ans << '\n';

    return 0;
}
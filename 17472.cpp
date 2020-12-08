#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXVAL 100001

using namespace std;

typedef pair<int, pair<int, int>> PII;
int n, m, arr[11][11], visit[11][11], p[10], cnt, ans;
priority_queue<PII, vector<PII>, greater<PII>> pq;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int dist[10][10];

void dfs(int x, int y, int num) {
    visit[x][y] = 1;
    arr[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int rx = x + dr[i];
        int ry = y + dc[i];
        if (rx < 0 || rx >= n || ry < 0 || ry >= m)
            continue;
        if (!visit[rx][ry] && arr[rx][ry] == 1) {
            dfs(rx, ry, num);
        }
    }
}

void func(int x, int y, int num, int islandNum) {
    int cnt = 0;
    while (1) {
        x += dr[num];
        y += dc[num];
        if (x < 0 || x >= n || y < 0 || y >= m)
            return;
        if (arr[x][y] == islandNum)
            return;
        if (arr[x][y] != 0) {
            if (cnt <= 1)
                return;
            else {
                dist[islandNum][arr[x][y]] = min(cnt, dist[islandNum][arr[x][y]]);
                return;
            }
        }
        cnt++;
    }
}

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // ¼¶ ¶óº§¸µ
    int islandNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                dfs(i, j, islandNum);
                islandNum++;
            }
        }
    }

    // ¼¶³¢¸® ÃÖ´Ü°Å¸®
    for (int i = 1; i < islandNum; i++) {
        for (int j = 1; j < islandNum; j++) {
            dist[i][j] = MAXVAL;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                for (int h = 0; h < 4; h++) {
                    func(i, j, h, arr[i][j]);
                }
            }
        }
    }

    // MST ±¸ÇÏ±â
    for (int i = 1; i < islandNum; i++) {
        for (int j = 1; j < islandNum; j++) {
            if (i != j && dist[i][j] != MAXVAL) {
                pq.push({ dist[i][j], {i, j} });
            }
        }
    }

    memset(p, -1, sizeof(p));
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if (merge(u, v)) {
            ans += w;
            cnt++;
            if (cnt == islandNum - 2) {
                break;
            }
                
        }
    }

    if (cnt != islandNum - 2)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXVAL 100000;

using namespace std;

typedef pair<int, pair<int, int>> PII;
int n, dist[51][51];
char arr[51][51];
bool visit[51][51];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
priority_queue<PII, vector<PII>, greater<PII>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dist[i][j] = MAXVAL;
        }
    }
    dist[0][0] = 0;
    pq.push({ 0, {0, 0} });
    while (!pq.empty()) {
        int curx, cury;
        do {
            curx = pq.top().second.first;
            cury = pq.top().second.second;
            pq.pop();
        } while (visit[curx][cury] && !pq.empty());
        if (visit[curx][cury])
            break;
        visit[curx][cury] = 1;
        for (int i = 0; i < 4; i++) {
            int rx = curx + dr[i];
            int ry = cury + dc[i];
            if (rx < 0 || rx >= n || ry < 0 || ry >= n)
                continue;
            int val = 0;
            if (arr[rx][ry] == '0')
                val = 1;
            if (dist[rx][ry] > dist[curx][cury] + val) {
                dist[rx][ry] = dist[curx][cury] + val;
                pq.push({ dist[rx][ry], {rx, ry} });
            }
        }
    }

    cout << dist[n - 1][n - 1] << '\n';

    return 0;
}
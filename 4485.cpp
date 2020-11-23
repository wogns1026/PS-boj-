#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXVAL 2000000

using namespace std;

typedef pair<int, pair<int, int>> PII;
int n, arr[126][126], idx = 1, dist[126][126];
bool visit[126][126];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                dist[i][j] = MAXVAL;
            }
        }
        memset(visit, 0, sizeof(visit));
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        dist[0][0] = arr[0][0];
        pq.push({ arr[0][0], {0, 0} });
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
                if (dist[rx][ry] > dist[curx][cury] + arr[rx][ry]) {
                    dist[rx][ry] = dist[curx][cury] + arr[rx][ry];
                    pq.push({ dist[rx][ry], {rx, ry} });
                }
            }
        }
        ans = dist[n - 1][n - 1];

        cout << "Problem " << idx << ": " << ans << '\n';
        idx++;
    }

    return 0;
}
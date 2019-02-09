#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#define MAXVAL 1000001

using namespace std;

typedef pair<int, pair<int, int>> p;
int n, m;
char arr[101][101];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int dist[101][101], visit[101][101];
priority_queue<p, vector<p>, greater<p>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + 1 + m, MAXVAL);
	}
	dist[1][1] = 0;
	pq.push({ 0, {1, 1} });
	while (!pq.empty()) {
		int curx, cury;
		do {
			curx = pq.top().second.first;
			cury = pq.top().second.second;
			pq.pop();
		} while (!pq.empty() && visit[curx][cury]);
		if (visit[curx][cury])
			break;
		visit[curx][cury] = 1;
		for (int i = 0; i < 4; i++) {
			int rx = curx + dr[i];
			int ry = cury + dc[i];
			if (rx < 1 || rx > n || ry < 1 || ry > m)
				continue;
			if (arr[rx][ry] == '1') {
				if (dist[rx][ry] > dist[curx][cury] + 1) {
					dist[rx][ry] = dist[curx][cury] + 1;
					pq.push({ dist[rx][ry], {rx, ry} });
				}
			}
			else {
				if (dist[rx][ry] > dist[curx][cury]){
					dist[rx][ry] = dist[curx][cury];
					pq.push({ dist[rx][ry], {rx, ry} });
				}
			}
		}
	}
	cout << dist[n][m] << '\n';

	return 0;
}
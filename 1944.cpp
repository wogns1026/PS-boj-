#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<pair<int, int>, pair<int, int>>> piii;
int n, m, visit[51][51];
pii p[51][51];
char arr[51][51];
vector<pii> candi;
int dr[4] = { 1, 0 ,-1, 0 };
int dc[4] = { 0, 1, 0, -1 };
priority_queue<piii, vector<piii>, greater<piii>> pq;

pii find(pii x) {
	if (p[x.first][x.second].first == 0 && p[x.first][x.second].second == 0)
		return { x.first, x.second };
	return p[x.first][x.second] = find(p[x.first][x.second]);
}
bool merge(pii x, pii y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	p[y.first][y.second] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K' || arr[i][j] == 'S') candi.push_back({ i, j });
		}
	}
	int candi_size = candi.size();
	for (int ca = 0; ca < candi_size; ca++) {
		queue<pii> q;
		memset(visit, 0, sizeof(visit));
		int x = candi[ca].first, y = candi[ca].second;
		q.push({ x, y });
		visit[x][y] = 1;
		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int rx = curx + dr[i];
				int ry = cury + dc[i];
				if (rx <= 0 || rx > n || ry <= 0 || ry > n)
					continue;
				if (!visit[rx][ry] && arr[rx][ry] != '1') {
					if (arr[rx][ry] == 'S' || arr[rx][ry] == 'K') {
						pq.push({ visit[curx][cury], {{x, y}, {rx, ry}} });
						q.push({ rx, ry });
						visit[rx][ry] = visit[curx][cury] + 1;
					}
					else if (arr[rx][ry] == '0') {
						visit[rx][ry] = visit[curx][cury] + 1;
						q.push({ rx, ry });
					}
				}
			}
		}
	}
	int pqsize = pq.size();
	int ans = 0, cnt = 0;
	for (int i = 0; i < pqsize; i++) {
		pii u = pq.top().second.first;
		pii v = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();
		if (merge(u, v)) {
			ans += w;
			cnt++;
		}
		if (cnt == m)
			break;
	}
	if (cnt != m)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
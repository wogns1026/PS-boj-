#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
int n, arr[21][21], visit[21][21], x, y;
queue<p> q;
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };
vector<pair<int, pair<int, int>>> v;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				x = i, y = j;
			}
		}
	}
	
	int ans = 0, shark = 2, cnt = 0;
	while (1) {
		memset(visit, 0, sizeof(visit));
		while (!q.empty())
			q.pop();
		v.clear();
		q.push({ x, y });
		visit[x][y] = 1;
		arr[x][y] = 0;
		if (cnt == shark) {
			shark++;
			cnt = 0;
		}

		while (!q.empty()) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int rx = curx + dr[i];
				int ry = cury + dc[i];
				if (rx < 0 || rx >= n || ry < 0 || ry >= n)
					continue;
				if (!visit[rx][ry] && (arr[rx][ry] == 0 || arr[rx][ry] <= shark)) {
					if (arr[rx][ry] == 0 || arr[rx][ry] == shark) {
						visit[rx][ry] = visit[curx][cury] + 1;
						q.push({ rx, ry });
					}
					else {
						visit[rx][ry] = visit[curx][cury] + 1;
						v.push_back({ visit[curx][cury], { rx, ry } });
						q.push({ rx, ry });
					}
				}
			}
		}
		if (v.size() == 0)
			break;
		else {
			sort(v.begin(), v.end());
			x = v[0].second.first, y = v[0].second.second;
			ans += v[0].first;
			cnt++;
		}
	}
	
	cout << ans << '\n';

	return 0;
}
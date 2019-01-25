#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
int n, m, k, arr[1001][1001], visit[1001][1001], cnt;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
vector<p> v;
queue<p> copy_q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	int minval = 1000001, maxval = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (i == 1 || j == 1 || j == m) {
				v.push_back({ i, j });
			}
			minval = min(minval, arr[i][j]);
			maxval = max(maxval, arr[i][j]);
		}
	}

	int l = 0, r = 1000000;
	int mid = 0;
	while (l <= r) {
		cnt = 0;
		mid = (l + r) / 2;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < v.size(); i++) {
			if (arr[v[i].first][v[i].second] <= mid) {
				copy_q.push(v[i]);
				visit[v[i].first][v[i].second] = 1;
			}
		}

		while (!copy_q.empty()) {
			int curx = copy_q.front().first;
			int cury = copy_q.front().second;
			copy_q.pop();
			if (arr[curx][cury] <= mid) {
				cnt++;
				for (int i = 0; i < 4; i++) {
					int rx = curx + dr[i];
					int ry = cury + dc[i];
					if (rx >= 1 && rx <= n && ry >= 1 && ry <= m) {
						if (!visit[rx][ry] && arr[rx][ry] <= mid) {
							visit[rx][ry] = 1;
							copy_q.push({ rx, ry });
						}
					}
				}
			}
		}

		if (cnt >= k)
			r = mid - 1;
		else
			l = mid + 1;

	}

	cout << l << '\n';

	return 0;
}
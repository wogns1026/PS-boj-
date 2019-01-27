#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

typedef pair<int, int> p;
int n, arr[101][101], visit[101][101];
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
queue<p> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ans = 0, cnt = 0;
	for (int i = 0; i <= 100; i++) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (arr[a][b] > i && !visit[a][b]) {
					cnt++;
					q.push({ a, b });
					while (!q.empty()) {
						int curx = q.front().first;
						int cury = q.front().second;
						q.pop();
						for (int h = 0; h < 4; h++) {
							int rx = curx + dr[h];
							int ry = cury + dc[h];
							if (rx >= 0 && rx < n && ry >= 0 && ry < n) {
								if (arr[rx][ry] > i && !visit[rx][ry]) {
									visit[rx][ry] = 1;
									q.push({ rx, ry });
								}
							}
						}
					}
				}
			}
		}
		ans = max(ans, cnt);
	}	

	cout << ans << '\n';

	return 0;
}
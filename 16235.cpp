#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <deque>

using namespace std;

int n, m, k, a, b, c;
int arr[11][11]; // 양분의 양
int _add[11][11];
deque<int> pq[11][11];
vector<int> die[11][11];
int dr[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dc[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> _add[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq[a][b].push_back(c);
	}
	while (k--) {
		// 봄
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!pq[i][j].empty()) {
					sort(pq[i][j].begin(), pq[i][j].end());
					int hsize = pq[i][j].size();
					for (int h = 0; h < hsize; h++) {
						int cur = pq[i][j].front();
						pq[i][j].pop_front();
						if (cur <= arr[i][j]) {
							arr[i][j] -= cur;
							cur++;
							pq[i][j].push_back(cur);
						}
						else {
							die[i][j].push_back(cur);
						}
					}
				}
			}
		}
		// 여름
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int h = 0; h < die[i][j].size(); h++) {
					arr[i][j] += (die[i][j][h] / 2);
				}
				die[i][j].clear();
			}
		}
		// 가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!pq[i][j].empty()) {
					for (int h = 0; h < pq[i][j].size(); h++) {
						if (pq[i][j][h] % 5 == 0) {
							for (int a = 0; a < 8; a++) {
								int rx = i + dr[a];
								int ry = j + dc[a];
								if (rx >= 1 && rx <= n && ry >= 1 && ry <= n) {
									pq[rx][ry].push_back(1);
								}
							}
						}
					}
				}
			}
		}
		// 겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] += _add[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += pq[i][j].size();
		}
	}
	cout << ans << '\n';

	return 0;
}
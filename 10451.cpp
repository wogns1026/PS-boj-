#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int t, n, num, visit[1001];
vector<vector<int>> adj;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		adj.clear();
		adj.resize(n + 1);
		memset(visit, 0, sizeof(visit));

		for (int i = 1; i <= n; i++) {
			cin >> num;
			adj[i].push_back(num);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				ans++;
				q.push(i);
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (auto next : adj[cur]) {
						if (!visit[next]) {
							visit[next] = 1;
							q.push(next);
						}
					}
				}
			}
		}
		cout << ans << '\n';

	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int t, n, k, a, b, fin;
int build_time[1001], ind[1001], ans[1001];
vector<vector<int>> adj;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		adj.clear();
		adj.resize(n + 1);
		memset(ind, 0, sizeof(ind));
		memset(ans, 0, sizeof(ans));

		for (int i = 1; i <= n; i++) {
			cin >> build_time[i];
			ans[i] = build_time[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			ind[b]++;
		}
		cin >> fin;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0)
				q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto i : adj[cur]) {
				ind[i]--;
				ans[i] = max(ans[i], ans[cur] + build_time[i]);
				if (ind[i] == 0)
					q.push(i);
			}
		}
		
		cout << ans[fin] << '\n';

	}

	return 0;
}
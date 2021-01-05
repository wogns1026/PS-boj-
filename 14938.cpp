#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define MAXVAL 1501

using namespace std;

typedef pair<int, int> PI;
int n, m, r;
int item[101], dist[101];
vector<PI> adj[101];
bool visit[101];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	int a, b, c;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		fill(dist, dist + n + 1, MAXVAL);
		priority_queue<PI, vector<PI>, greater<PI>> pq;

		dist[i] = 0;
		pq.push({ 0, i });
		while (!pq.empty()) {
			int cur;
			do {
				cur = pq.top().second;
				pq.pop();
			} while (!pq.empty() && visit[cur]);
			if (visit[cur])
				break;
			visit[cur] = 1;
			for (auto next : adj[cur]) {
				if (dist[next.first] > dist[cur] + next.second) {
					dist[next.first] = dist[cur] + next.second;
					pq.push({ dist[next.first], next.first });
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] <= m) {
				res += item[i];
			}
		}
		ans = max(ans, res);
	}

	cout << ans << '\n';

	return 0;
}
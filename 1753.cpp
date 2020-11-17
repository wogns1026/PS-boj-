#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> PI;
int n, m, k, u, v, w;
vector<vector<PI>> adj;
bool visit[20001];
int dist[20001];
priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	} 
	memset(visit, 0, sizeof(visit));
	fill(dist, dist + n + 1, 30000000);
	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (visit[cur] && !pq.empty());
		if (visit[cur])
			break;
		for (auto next : adj[cur]) {
			if (dist[next.first] > dist[cur] + next.second) {
				dist[next.first] = dist[cur] + next.second;
				pq.push({ dist[next.first], next.first });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 30000000)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}


	return 0;
}
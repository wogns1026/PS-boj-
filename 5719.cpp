#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#define MAXVAL 10000001

using namespace std;

typedef pair<int, int> p;
int n, m, s, d, u, v, w;
vector<vector<p>> adj;
int dist[501];
int visit[501];
priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra(int s) {
	while (!pq.empty())
		pq.pop();
	memset(visit, 0, sizeof(visit));
	fill(dist, dist + n, MAXVAL);
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur])
			break;
		visit[cur] = 1;
		for (auto i : adj[cur]) {
			if (i.second != MAXVAL) {
				if (dist[i.first] > dist[cur] + i.second) {
					dist[i.first] = dist[cur] + i.second;
					pq.push({ dist[i.first], i.first });
				}
			}
		}
	}
}
void delroad(int cost, int dest) {
	if (cost == 0 || dest == s)
		return;
	for (int i = 0; i < n; i++) {
		int adjsize = adj[i].size();
		for (int j = 0; j < adjsize; j++) {
			if (adj[i][j].first == dest) {
				if (cost - adj[i][j].second == dist[i]) {
					adj[i][j].second = MAXVAL;
					delroad(dist[i], i);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> s >> d;
		adj.clear(); adj.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[u].push_back({ v, w });
		}
		dijkstra(s);
		int mincost = dist[d];
		if (dist[d] == MAXVAL) {
			cout << -1 << '\n';
		}
		else {
			delroad(mincost, d);
			dijkstra(s);
			if (dist[d] == MAXVAL)
				cout << -1 << '\n';
			else
				cout << dist[d] << '\n';
		}
		
	}
	
	return 0;
}
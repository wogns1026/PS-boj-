#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#define MAXVAL 200000001

using namespace std;

typedef pair<int, int> p;
int n, m, a, b, c, mid1, mid2;
vector<vector<p>> adj;
int visit[801], dist[801];
priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra(int start) {
	while (!pq.empty()) {
		pq.pop();
	}
	fill(dist + 1, dist + 1 + n, MAXVAL);
	memset(visit, 0, sizeof(visit));
	pq.push({ 0, start });
	dist[start] = 0;
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
			if (dist[i.first] > dist[cur] + i.second) {
				dist[i.first] = dist[cur] + i.second;
				pq.push({ dist[i.first], i.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> mid1 >> mid2;
	
	int ans1 = 0, ans2 = 0;
	dijkstra(1);
	ans1 += dist[mid1], ans2 += dist[mid2];
	dijkstra(mid1);
	ans1 += dist[mid2], ans2 += dist[n];
	dijkstra(mid2);
	ans1 += dist[n], ans2 += dist[mid1];

	int ans = min(ans1, ans2);
	if (ans >= MAXVAL)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PI;
int n, m, a, b, c, s, d;
long long dist[1001];
bool visit[1001];
vector<vector<PI>> adj;
priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	cin >> s >> d;
	fill(dist, dist + n + 1, 10000000001);
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (visit[cur] && !pq.empty());
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
	cout << dist[d] << '\n';


	return 0;
}
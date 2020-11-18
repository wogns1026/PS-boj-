#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXVAL 200000001

using namespace std;

typedef pair<int, int> PI;
int n, m, a, b, c, u, v, dist[801], answer, tmp1, tmp2;
bool visit[801];
vector<vector<PI>> adj;

void dijkstra(int s) {
    memset(visit, 0, sizeof(visit));
    fill(dist, dist + n + 1, MAXVAL);
    priority_queue<PI, vector<PI>, greater<PI>> pq;
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
        for (auto next : adj[cur]) {
            if (dist[next.first] > dist[cur] + next.second) {
                dist[next.first] = dist[cur] + next.second;
                pq.push({ dist[next.first], next.first });
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
    cin >> u >> v;
    dijkstra(1);
    tmp1 += dist[u];
    tmp2 += dist[v];
    dijkstra(u);
    tmp1 += dist[v];
    tmp2 += dist[n];
    dijkstra(v);
    tmp1 += dist[n];
    tmp2 += dist[u];
    answer = min(tmp1, tmp2);
    if (answer >= MAXVAL)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}
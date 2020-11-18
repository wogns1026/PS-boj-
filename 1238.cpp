#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> PI;
int n, m, x, a, b, c, dist[1001], rdist[1001];
bool visit[1001], rvisit[1001];
vector<vector<PI>> adj, radj;
priority_queue<PI, vector<PI>, greater<PI>> pq;
priority_queue<PI, vector<PI>, greater<PI>> rpq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    adj.resize(n + 1);
    radj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        radj[b].push_back({ a, c });
    }
    fill(dist, dist + n + 1, 10000001);
    fill(rdist, rdist + n + 1, 10000001);
    dist[x] = 0;
    rdist[x] = 0;
    pq.push({ 0, x });
    rpq.push({ 0, x });
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
                pq.push({dist[next.first], next.first});
            }
        }
    }

    while (!rpq.empty()) {
        int cur;
        do {
            cur = rpq.top().second;
            rpq.pop();
        } while (rvisit[cur] && !rpq.empty());
        if (rvisit[cur])
            break;
        for (auto next : radj[cur]) {
            if (rdist[next.first] > rdist[cur] + next.second) {
                rdist[next.first] = rdist[cur] + next.second;
                rpq.push({ rdist[next.first], next.first });
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dist[i] + rdist[i]);
    }
    cout << answer << '\n';

    return 0;
}
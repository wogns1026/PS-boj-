#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
#define MAXVAL 10000000001

using namespace std;

typedef pair<int, int> PI;
typedef long long ll;
int n, m, a, b, c, s, d;
ll dist[1001];
int visit[1001], route[1001];
vector<vector<PI>> adj;
priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }
    cin >> s >> d;
    fill(dist, dist + n + 1, MAXVAL);
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
                route[next.first] = cur;
            }
        }
    }

    int cnt = 0;
    stack<int> ans;
    int node = d;
    while (node != 0) {
        cnt++;
        ans.push(node);
        node = route[node];
    }
    cout << dist[d] << '\n';
    cout << cnt << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';

    return 0;
}
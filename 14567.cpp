#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, indegree[1001], level[1001];
vector<int> adj[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        indegree[b]++;
        adj[a].push_back(b);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            level[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
                level[next] = level[cur] + 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << level[i] << ' ';
    }

    return 0;
}
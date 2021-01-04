#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXVAL 32001

using namespace std;

int n, m, indegree[MAXVAL];
vector<vector<int>> adj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (auto next : adj[cur]) {
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
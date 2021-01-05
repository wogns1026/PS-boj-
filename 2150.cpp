#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>

using namespace std;

int n, m, visit[10001], cnt;
vector<int> adj[10001], radj[10001], ans[10001];
stack<int> st;

void dfs(int node, bool flag) {
    visit[node] = 1;
    if (!flag) { // 정방향 그래프에서 더이상 방문할 곳이 없는 정점들을 stack에 넣어줌
        for (int next : adj[node]) {
            if (!visit[next]) {
                dfs(next, flag);
            }
        }
        st.push(node);
    }
        
    else { // 역방향 그래프에서 dfs 돌면서 탐색하는 정점들을 하나의 scc로 묶어줌
        ans[cnt].push_back(node);
        for (int next : radj[node]) {
            if (!visit[next]) {
                dfs(next, flag);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i, 0);
        }
    }
    memset(visit, 0, sizeof(visit));
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (!visit[cur]) {
            dfs(cur, 1);
            cnt++;
        }
    }
    vector<pair<int, int>> cmp;
    for (int i = 0; i < cnt; i++) {
        sort(ans[i].begin(), ans[i].end());
        cmp.push_back({ ans[i].front(), i });
    }
    sort(cmp.begin(), cmp.end());
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < ans[cmp[i].second].size(); j++) {
            cout << ans[cmp[i].second][j] << ' ';
        }
        cout << -1 << '\n';
    }

    return 0;
}
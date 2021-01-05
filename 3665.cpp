#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int t, n, m, indegree[501], arr[501];
bool chk[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        vector<int> adj[501];
        memset(indegree, 0, sizeof(indegree));
        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            chk[a][b] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (chk[arr[i]][arr[j]] == 1 || chk[arr[j]][arr[i]] == 1) {
                    adj[arr[j]].push_back(arr[i]);
                    indegree[arr[i]]++;
                }
                else {
                    adj[arr[i]].push_back(arr[j]);
                    indegree[arr[j]]++;
                }
            }
        }
        
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        bool flag = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                cout << "IMPOSSIBLE" << '\n';
                flag = true;
                break;
            }
            
            if (q.size() > 1) {
                cout << "?" << '\n';
                flag = true;
                break;
            }
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (int next : adj[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
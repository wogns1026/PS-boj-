#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, cost[101], cnt;
bool visit[101];
vector<int> adj[101], radj[101], scc[101];
stack<int> st;

void dfs(int cur, bool flag) {
	visit[cur] = 1;
	if (!flag) {
		for (int next : adj[cur]) {
			if (!visit[next]) {
				dfs(next, flag);
			}
		}
		st.push(cur);
	}
	else {
		scc[cnt].push_back(cur);
		for (int next : radj[cur]) {
			if (!visit[next]) {
				dfs(next, flag);
			}
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '1') {
				adj[i].push_back(j + 1);
				radj[j + 1].push_back(i);
			}
		}
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

	int ans = 0;
	for (int i = 0; i < cnt; i++) {
		int res = 1000001;
		for (int j = 0; j < scc[i].size(); j++) {
			res = min(res, cost[scc[i][j]]);
		}
		ans += res;
	}

	cout << ans << '\n';

	return 0;
}
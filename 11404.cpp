#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#define MAX_VAL 10000001

using namespace std;

typedef pair<int, int> p;
int n, m, a, b, c;
vector<vector<p>> adj;
int ans[101];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	for (int i = 1; i <= n; i++) {
		queue<p> q;
		fill(ans + 1, ans + 1 + n, MAX_VAL);
		ans[i] = 0;
		for (auto next : adj[i]) {
			q.push({ next.first, next.second });
			if(ans[next.first] > next.second)
				ans[next.first] = next.second;
		}
		while (!q.empty()) {
			int cur = q.front().first;
			q.pop();
			for (auto next : adj[cur]) {
				if (ans[next.first] > ans[cur] + next.second){
					q.push({ next.first, next.second });
					ans[next.first] = ans[cur] + next.second;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (ans[j] == MAX_VAL)
				cout << 0 << ' ';
			else
				cout << ans[j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}
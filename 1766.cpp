#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n, m, a, b, ind[32001];
vector<vector<int>> adj;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		ind[b]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cout << cur << ' ';
		for (auto i : adj[cur]) {
			ind[i]--;
			if (ind[i] == 0)
				q.push(i);
		}
	}

	return 0;
}
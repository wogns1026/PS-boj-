#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, pair<int, int>> pii;
int n, m, p[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	p[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int a, b, c;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ c, {a, b} });
	}
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();
		if (merge(u, v)) {
			ans += w;
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}
	cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> p;
int l, r, c;
int visit[31][31][31];
char arr[31][31][31];
int dr[6] = { 1, 0 ,-1, 0, 0, 0 };
int dc[6] = { 0, 1, 0, -1, 0, 0 };
int dl[6] = { 0, 0, 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		queue<p> q;
		memset(visit, 0, sizeof(visit));
		bool flag = false;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int h = 0; h < c; h++) {
					cin >> arr[i][j][h];
					if (arr[i][j][h] == 'S')
						q.push({ i, {j, h} }), visit[i][j][h] = 1;
				}
			}
		}
		int ans = 0;
		while (!q.empty()) {
			int curl = q.front().first;
			int curr = q.front().second.first;
			int curc = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int rl = curl + dl[i];
				int rr = curr + dr[i];
				int rc = curc + dc[i];
				if (rl < 0 || rl >= l || rr < 0 || rr >= r || rc < 0 || rc >= c)
					continue;
				if (!visit[rl][rr][rc] && arr[rl][rr][rc] != '#') {
					if (arr[rl][rr][rc] == 'E') {
						flag = true;
						ans = visit[curl][curr][curc];
					}
					else {
						q.push({ rl,{ rr, rc } });
						visit[rl][rr][rc] = visit[curl][curr][curc] + 1;
					}
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << "Escaped in " << ans << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}

	return 0;
}
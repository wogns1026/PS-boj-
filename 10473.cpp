#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#define MAXVAL 1000000000

using namespace std;

typedef pair<double, double> p;
typedef pair<double, int> pi;
double dist[111], destx, desty;
int n, visit[111];
p arr[111];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> arr[0].first >> arr[0].second >> destx >> desty >> n;
	arr[n + 1].first = destx, arr[n + 1].second = desty;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	fill(dist, dist + n + 2, MAXVAL);
	dist[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur])
			break;
		visit[cur] = 1;
		if (cur == 0) {
			for (int i = 1; i <= n + 1; i++) {
				double num = sqrt((arr[cur].first - arr[i].first)*(arr[cur].first - arr[i].first) + (arr[cur].second - arr[i].second)*(arr[cur].second - arr[i].second));
				num = num / 5;
				if (dist[i] > dist[cur] + num) {
					dist[i] = dist[cur] + num;
					pq.push({ dist[i], i });
				}
			}
		}
		else {
			for (int i = 1; i <= n + 1; i++) {
				if (cur == i)
					continue;
				double num = sqrt((arr[cur].first - arr[i].first)*(arr[cur].first - arr[i].first) + (arr[cur].second - arr[i].second)*(arr[cur].second - arr[i].second));
				if (num < 50) {
					if (num / 5 < 2 + ((50 - num) / 5))
						num = num / 5;
					else
						num = 2 + ((50 - num) / 5);
				}
				else {
					if (num / 5 < 2 + ((num - 50) / 5))
						num = num / 5;
					else
						num = 2 + ((num - 50) / 5);
				}
				
				if (dist[i] > dist[cur] + num) {
					dist[i] = dist[cur] + num;
					pq.push({ dist[i], i });
				}
			}
		}
	}

	cout << dist[n + 1] << '\n';

	return 0;
}
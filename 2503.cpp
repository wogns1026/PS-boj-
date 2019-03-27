#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, arr[101], a, b, c, aa, bb, cc;
pair<int, int> p[101];
queue<int> q;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i] >> p[i].first >> p[i].second;
	}
	for (int i = 100; i < 1000; i++) {
		a = i / 100;
		b = (i % 100) / 10;
		c = i % 10;
		if (a == b || b == c || c == a || a == 0 || b == 0 || c == 0)
			continue;
		q.push(i);
	}
	for (int i = 0; i < n; i++) {
		int qsize = q.size();
		while (qsize--) {
			int cur = q.front();
			q.pop();
			a = cur / 100;
			b = (cur % 100) / 10;
			c = cur % 10;
			int strike = 0, ball = 0;
			aa = arr[i] / 100;
			bb = (arr[i] % 100) / 10;
			cc = arr[i] % 10;
			if (a == aa)
				strike++;
			if (b == bb)
				strike++;
			if (c == cc)
				strike++;
			if (a == bb || a == cc)
				ball++;
			if (b == aa || b == cc)
				ball++;
			if (c == aa || c == bb)
				ball++;
			if (strike == p[i].first && ball == p[i].second)
				q.push(cur);
		}
	}
	cout << q.size() << '\n';


	return 0;
}
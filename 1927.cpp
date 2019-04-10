#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, num;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}
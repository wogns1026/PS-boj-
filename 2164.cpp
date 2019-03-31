#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int qsize = q.size();
	while (qsize != 1) {
		q.pop();
		
		int num = q.front();
		q.pop();
		q.push(num);
		qsize--;
	}
	cout << q.front() << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, a[51], b[51];
int p[51], visit[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i] == a[j] && !visit[j]) {
				visit[j] = 1;
				p[j] = idx;
				idx++;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	cout << '\n';

	return 0;
}
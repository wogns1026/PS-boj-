#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	a--, b--;
	int idx = 2, ans = 1;
	while (1) {
		if (a / idx == b / idx) {
			break;
		}
		else {
			idx *= 2;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, a, b;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans += b % a;
	}
	cout << ans << '\n';

	return 0;
}
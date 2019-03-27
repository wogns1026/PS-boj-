/*

�ð����⵵ ����� ����ִ� ����
�ð����⵵ = n * (1 + 1/2 + 1/3 + ... + 1/n)

(1 + 1/2 + 1/3 + ... + 1/n) �̷��� ���� ��ȭ�޼��� ��
= log(n + 1) ������� �� �� �ִٰ� �Ѵ�.
���� �� �˰����� �ð����⵵ = O(nlogn)

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, c, num, arr[2000001];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> num;
		int idx = 1;
		while (1) {
			if (num * idx > c)
				break;
			arr[num * idx] = 1;
			idx++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= c; i++) {
		if (arr[i])
			ans++;
	}
	cout << ans << '\n';
	
	return 0;
}
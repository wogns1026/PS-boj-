#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

string s;
string res[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string ans;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	int slen = s.length();
	if (s == "0") {
		cout << 0 << '\n';
		return 0;
	}

	if (s[0] == '1') {
		cout << "1";
	}
	else if (s[0] == '2') {
		cout << "10";
	}
	else if (s[0] == '3') {
		cout << "11";
	}
	else if (s[0] == '4') {
		cout << res[4];
	}
	else if (s[0] == '5') {
		cout << res[5];
	}
	else if (s[0] == '6') {
		cout << res[6];
	}
	else if (s[0] == '7'){
		cout << res[7];
	}
	
	for (int i = 1; i < slen; i++) {
		if (s[i] == '0') {
			cout << res[0];
		}
		else if (s[i] == '1') {
			cout << res[1];
		}
		else if (s[i] == '2') {
			cout << res[2];
		}
		else if (s[i] == '3') {
			cout << res[3];
		}
		else if (s[i] == '4') {
			cout << res[4];
		}
		else if (s[i] == '5') {
			cout << res[5];
		}
		else if (s[i] == '6') {
			cout << res[6];
		}
		else if (s[i] == '7'){
			cout << res[7];
		}
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, l;
		cin >> n >> l;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// determine the binary form of each element
		vector<vector<int>> bits(n, vector<int>(32));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 32; j++) {
				bits[i][j] = (a[i] & (1 << j) ? 1 : 0);
			}
		}
		// set the i-th bit to zero if the numbers in 
		// the array contain more zeroes than the ones
		// in the i-th bit, otherwise, set it to one
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int set = 0;
			for (int j = 0; j < n; j++) {
				set += bits[j][i];
			}
			int unset = n - set;
			if (set > unset) {
				ans += (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

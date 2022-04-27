#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

constexpr auto mod = int{ 1'000'000'007 };

vi memo;
int solve(int l) {
	if (memo[l] < 0) {
		for (int i = 2; i <= l; ++i) {
			if (memo[i] < 0) {
				memo[i] = (solve(i - 1) + solve(i - 2)) % mod;
			}
		}
	}

	return memo[l];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	memo = vi(16, -1);
	memo[0] = 1;
	memo[1] = 1;

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int c, v, l;
		cin >> c >> v >> l;

		cout << "Case #" << i + 1 << ": " << solve(l) << '\n';
	}

	return 0;
}
	#include <iostream>
	#include <vector>

	using namespace std;

	const int mod = 1000000007;

	uint64_t type1(int x, int y) {
	// TODO(maria.marinescu1501) Compute the number of type 1 signals.
	vector<vector<uint64_t>> dp(x + 1, vector<uint64_t> (y + 1, 0));

	// cazurile de baza
	if (x == 0 && y == 0)
		return 0;

	if ((x == 0 && y == 1) || (x == 1 && y == 0))
		return 1;

	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[0][1] = 1;
	dp[1][1] = 2;

	// se observa anumite "reguli" pentru construirea semnalelor de 1, 2, 3 cifre
	// astfel, pe langa relatia de recurenta se regasesc si alte conditii
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if ((i == 0 && j > 1) || (i == 1 && j > 2)) {
				dp[i][j] = 0;
			} else if (i > 0 && j == 0) {
				dp[i][j] = 1;
			} else if ((i == 0 && j == 0) || (i == 1 && j == 0) ||
				(i == 0 && j == 1) || (i == 1 && j == 1)) {
				continue;
			} else {
				// relatia de recurenta
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
			}
		}
	}

	return dp[x][y];
	}

	int type2(int x, int y) {
	// TODO(maria.marinescu1501) Compute the number of type 2 signals.
	vector<vector<int>> dp(x + 1, vector<int> (y + 1, 0));

	if (x == 0 && y == 0)
		return 0;

	if ((x == 0 && y == 1) || (x == 1 && y == 0))
		return 1;

	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[0][1] = 1;
	dp[1][1] = 2;

	// se observa anumite "reguli" pentru construirea semnalelor de 1, 2, 3, cifre
	// astfel, pe langa relatia de recurenta se regasesc si alte conditii in plus
	// fata de task-ul anterior
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if ((i == 0 && j > 2))  {
				dp[i][j] = 0;
			} else if ((i > 0 && j == 0) || (i == 0 && j <= 2)) {
				dp[i][j] = 1;
			} else if ((i == 0 && j == 0) || (i == 1 && j == 0) ||
				(i == 0 && j == 1) || (i == 1 && j == 1)) {
				continue;
			} else if (i == 2 && j <= 1) {
				dp[i][j] = dp[i - 1][j] + 1;
			} else if (i == 1 && j <= 2) {
				dp[i][j] = dp[i][j - 1] + 1;
			} else {
				// relatia de recurenta
				dp[i][j] = ((dp[i - 1][j - 2] + dp[i - 1][j - 1]) %
					mod + dp[i - 1][j]) % mod;
			}
		}
	}

	return dp[x][y];
	}

	int main() {
	freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

	switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
		}

	return 0;
	}

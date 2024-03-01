#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	// TODO(maria.marinescu1501) solve task 1
	vector<vector<int>> dp(m + 1, vector<int> ((n * x + 1), 0));
	int max_x = n * x;

	for (int i = 1; i <= m; i++) {
		for (int price = 0; price <= max_x; price++) {
			// caz de baza
			dp[0][price] = 0;

			// daca nu adaugam un platou atunci la pasul curent vom
			// avea platoul precedent
			dp[i][price] = dp[i - 1][price];

			if (p[i - 1] <= price) {
				// daca adaugam platoul atunci se scade din pretul maxim
				// pretul platoului curent pentru a stii cat mai putem cumpara
				int sol_aux = dp[i - 1][price - p[i - 1]];

				// adunam notele corespunzatoare
				for (int j = 0; j < n; j++)
					sol_aux += g[j][i - 1];

				dp[i][price] = max(dp[i][price], sol_aux);
			}
		}
	}

	return dp[m][max_x];
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// TODO(maria.marinescu1501) solve task 2
	vector<vector<int>> dp(m + 1, vector<int> ((n * x + 1), 0));
	int max_x = n * x;

	for (int i = 1; i <= m; i++) {
		for (int price = 0; price <= max_x; price++) {
			// caz de baza
			dp[0][price] = 0;

			// daca nu adaugam un platou atunci la pasul curent vom
			// avea platoul precedent
			dp[i][price] = dp[i - 1][price];

			int plates = 1;

			// se va adauga un platou sau 2 cat timp se respecta
			// restrictia de a adauga cel mult 2 platouri
			while ((plates * p[i - 1] <= price) && (plates <= 2)) {
				int sol_aux = dp[i - 1][price - plates * p[i - 1]];
				for (int j = 0; j < n; j++)
					sol_aux += plates * g[j][i - 1];

				dp[i][price] = max(dp[i][price], sol_aux);
				plates++;
			}
		}
	}

	return dp[m][max_x];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// TODO(maria.marinescu1501) solve task 3
	vector<vector<vector <int>>> dp(m + 1, vector<vector<int>> ((n * x + 1),
		vector<int> (n + 1, 0)));
	int max_x = n * x;
	for (int i = 1; i <= m; i++) {
		for (int price = 0; price <= max_x; price++) {
			// a treia dimensiune reprezinta numarul maxim de platouri
			for (int k = 0; k <= n; k++) {
				// caz de baza
				dp[0][price][k] = 0;

				dp[i][price][k] = dp[i - 1][price][k];
				int plates = 1, nr = 1;

				// la fiecare pas numaram cate platouri avem pentru a nu depasi
				// limita impusa de platouri, iar daca aceasta nu este depasita
				// continuam sa adaugam
				while ((plates * p[i - 1] <= price) && (plates <= 2) && (nr <= k)) {
					int sol_aux = dp[i - 1][price - plates * p[i - 1]][k - nr];
					for (int j = 0; j < n; j++)
						sol_aux += plates * g[j][i - 1];

					dp[i][price][k] = max(dp[i][price][k], sol_aux);
					nr += plates;
					plates++;
				}
			}
		}
	}

	return dp[m][max_x][n];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}

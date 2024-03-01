#include <cstdint>
#include <fstream>
#include <vector>
using namespace std;

int64_t Result(const vector<uint64_t>& w, int n, int k) {
	uint64_t left = 0, right, middle;
	// gasim intervalul in care se va afla solutia noastra
	for (int i = 0; i < n; i++) {
		// capatul inferior va fi maximul din vector
		if (w[i] > left) {
			left = w[i];
		}
		// capatul superior va fi suma tuturor elementelor
		right += w[i];
	}

	while (left <= right) {
		// mijlocul intervalului de cautare
		middle = (right + left) / 2;

		int feriboturi = 0;
		uint64_t cost = 0;
		// iteram prin vectorul de greutati si vedem daca pentru
		// (restrictia maxima impusa - middle)
		// umplem toate feriboturile
		for (int i = 0; i < n; i++) {
			cost += w[i];

			// se intra pe if cand am umplut un feribot
			if (cost > middle) {
				// numaram cate feriboturi se umplu pentru restrictia impusa
				feriboturi++;

				// incepe un nou feribot
				cost = w[i];
			}
		}

		if (feriboturi < k) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}

	return left;
}

vector<uint64_t> ReadVector(istream& is, int size) {
    vector<uint64_t> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int n, k;
    fin >> n >> k;
    auto weights = ReadVector(fin, n);

    auto res = Result(weights, n, k);
    fout << res << "\n";

    return 0;
}


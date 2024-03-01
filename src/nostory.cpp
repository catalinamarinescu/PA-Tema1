/*
 * Acest schelet citește datele de intrare și scrie răspunsul generat de voi,
 * astfel că e suficient să completați cele două funcții.
 *
 * Scheletul este doar un punct de plecare, îl puteți modifica oricum doriți:
 * puteți schimba parametrii, reordona funcțiile etc.
 */

#include <cstdint>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare {
	inline bool operator() (int64_t obj1, int64_t obj2) {
		return obj1 > obj2;
	}
};

struct compare2 {
	inline bool operator() (int64_t obj1, int64_t obj2) {
		return obj1 < obj2;
	}
};

int64_t SolveTask1(vector<int64_t>& a, vector<int64_t>& b) {
	int n = a.size();

	// sortam cei doi vectori crescator
	sort(a.begin(), a.end(), compare());
	sort(b.begin(), b.end(), compare2());
	int64_t max_score = 0;

	// comparam cate doua elemente aflate pe aceeasi
	// pozitie in cei doi vectori, iar pe cel mai mare
	// dintre ei il adaugam la scor-ul maxim
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			max_score += a[i];
		} else {
			max_score += b[i];
		}
	}
	return max_score;
}

int64_t SolveTask2(vector<int64_t>& a, vector<int64_t>& b, int moves) {
	int n = a.size();
	uint64_t score = 0;

	// interschimbam elementele din cei doi vectori,
	// astfel incat in a sa avem maximele si in b minimele
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
	}

	// sortam minimele descrescator si maximele crescator
	sort(b.rbegin(), b.rend());
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		// daca un minim este mai mare decat cel mai mic maxim,
		// adunam minimul la scor si avem grija sa nu depasim
		// numarul de mutari alocate
		if ((b[i] > a[i]) && (moves > 0)) {
			score += b[i];
			moves--;
		} else {
			// altfel, adaugam pur si simplu maximul
			score += a[i];
		}
	}

	return score;
}

vector<int64_t> ReadVector(istream& is, int size) {
	vector<int64_t> vec(size);
	for (auto& num : vec) {
		is >> num;
	}
	return vec;
}

int main() {
	ifstream fin("nostory.in");
	ofstream fout("nostory.out");

	int task;
	fin >> task;

	int n, moves;
	if (task == 1) {
		fin >> n;
	} else {
		fin >> n >> moves;
	}

	auto a = ReadVector(fin, n);
	auto b = ReadVector(fin, n);

	auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
	fout << res << "\n";

	return 0;
}

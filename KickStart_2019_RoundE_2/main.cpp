#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int D, S;
		cin >> D >> S;

		vector<pair<int, int>> CE(S);

		for (int i = 0; i < S; i++) {
			int C, E;
			cin >> C >> E;
			CE.push_back(make_pair(C, E));
		}

		for (int i = 0; i < D; i++) {
			int A, B;
			cin >> A >> B;


		}



		cout << "Case #" << tc << ": " << "\n";
	}

	return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int const MAX = 100001;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N, M, Q;
		cin >> N >> M >> Q;

		int arrQ[MAX];
		bool torn[MAX];

		memset(torn, false, sizeof(torn));

		for (int i = 0; i < M; i++) {
			int m;
			cin >> m;
			torn[m] = true;
		}

		for (int i = 0; i < Q; i++) {
			cin >> arrQ[i];
		}

		int total = 0;

		for (int i = 0; i < Q; i++) {
			for (int j = arrQ[i]; j <= N; j += arrQ[i]) {
				if (!torn[j]) total += 1;
			}
		}

		cout << "Case #" << tc << ": " << total << "\n";
	}

	return 0;
}
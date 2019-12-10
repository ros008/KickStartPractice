#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

int root[MAX];

int find(int x) {
	if (root[x] == x) return x;
	return find(root[x]);
};

void unionGraph(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) root[y] = x;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N, M;
		cin >> N >> M;

		vector<pair<int, int>> edge;

		for (int i = 0; i <= N; i++) {
			root[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int C, D;
			cin >> C >> D;

			edge.push_back(make_pair(C, D));

			unionGraph(C, D);
		}

		int result = 0;
		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			if (root[i] == i) cnt++;
		}

		result = (N - cnt) + (cnt - 1) * 2;

		cout << "Case #" << tc << ": " << result << "\n";
	}

	return 0;
}
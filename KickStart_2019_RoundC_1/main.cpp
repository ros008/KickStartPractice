#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N, R, C, SR, SC;
		string str;

		cin >> N >> R >> C >> SR >> SC;
		cin >> str;

		vector<vector<bool>> visited(R, vector<bool>(C));

		SR -= 1;
		SC -= 1;

		visited[SR][SC] = 1;

		for (int i = 0; i < N; i++) {
			if (str.at(i) == 'E') {
				while (1) {
					SC++;
					if (visited[SR][SC] == 0) {
						visited[SR][SC] = 1;
						break;
					}
				}
			}
			else if (str.at(i) == 'W') {
				while (1) {
					SC--;
					if (visited[SR][SC] == 0) {
						visited[SR][SC] = 1;
						break;
					}
				}
			}
			else if (str.at(i) == 'S') {
				while (1) {
					SR++;
					if (visited[SR][SC] == 0) {
						visited[SR][SC] = 1;
						break;
					}
				}
			}
			else if (str.at(i) == 'N') {
				while (1) {
					SR--;
					if (visited[SR][SC] == 0) {
						visited[SR][SC] = 1;
						break;
					}
				}
			}
		}

		cout << "Case #" << tc << ": " << SR + 1 << " " << SC + 1 << "\n";
	}

	return 0;
}
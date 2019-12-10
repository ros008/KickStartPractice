#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case_num;
	cin >> test_case_num;

	for (int tc = 1; tc <= test_case_num; tc++) {
		int beauty_score_len;
		cin >> beauty_score_len;

		string beauty_score;
		cin >> beauty_score;

		int mid = (beauty_score_len + 1) / 2;

		int max_score = 0;
		int score = 0;

		for (int i = 0; i < mid; i++) {
			score += beauty_score[i] - '0';
		}

		max_score = score;

		for (int i = mid; i < beauty_score_len; i++) {
			score += (beauty_score[i] - '0') - (beauty_score[i - mid] - '0');
			
			if (max_score < score) {
				max_score = score;
			}
		}

		cout << "Case #" << tc << ": " << max_score << "\n";

	}

	return 0;
}
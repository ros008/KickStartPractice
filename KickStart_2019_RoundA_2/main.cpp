#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int R, C;
		cin >> R >> C;

		int delivery_office[251][251];

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cin >> delivery_office[i][j];
			}
		}



		cout << "Case #" << tc << ": " << "\n";
	}


	return 0;
}
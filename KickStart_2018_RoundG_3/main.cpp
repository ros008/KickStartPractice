#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll A[21], B[21];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {

		int N, H;
		cin >> N >> H;
		
		for(int i=0; i<N; i++){
			cin>>A[i];
		}
		for(int i=0; i<N; i++){
			cin>>B[i];
		}
		
		ll cnt = 0;
		ll n2 = pow(2, N);
		
		for (int Abit = 0; Abit < n2; Abit++) {
			for (int Bbit = 0; Bbit < n2; Bbit++) {
				if ((Abit | Bbit) == (n2 - 1)) {
					ll AH = 0;
					ll BH = 0;

					int tmpA = Abit;
					int tmpB = Bbit;

					int bit = 0;
					while (tmpA != 0) {
						if (tmpA % 2 == 1) {
							AH += A[bit];
						}
						bit++;
						tmpA /= 2;
					}
					if (AH < H) continue;

					bit = 0;
					while (tmpB != 0) {
						if (tmpB % 2 == 1) {
							BH += B[bit];
						}
						bit++;
						tmpB /= 2;
					}
					if (BH < H) continue;
					
					cnt++;
				}
			}
		}

		cout << "Case #" << tc << ": " << cnt << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, x = 0;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			x ^= a[i];
		}
		if (x == 0)cout << "DRAW\n";
		else {
			for (int i = 30; i >= 0; --i) {
				x = 0;
				for (int j = 0; j < n; ++j) {
					if (a[j] & (1 << i))x++;
				}
				if (x % 2 == 0)continue;
				else {
					if (x % 4 == 3 && (n - x) % 2 == 0)cout << "LOSE\n";
					else cout << "WIN\n";
					break;
				}
			}
		}




	}


	return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <climits>

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
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		int one = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i])one++;
		}
		if (one > ((n+1) / 2)) {
			one = (one / 2) * 2;
			cout << one << '\n';
			for (int i = 0; i < one; i++) {
				cout << "1 ";
			}
			cout << '\n';
		}
		else {
			int zero = n - one;
			cout << zero << '\n';
			for (int i = 0; i < zero; i++) {
				cout << "0 ";
			}
			cout << '\n';
		}
		
	}

	return 0;

}
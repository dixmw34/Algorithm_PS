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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q, l, r;
		string s;
		cin >> n >> q >> s;
		while (q--) {
			bool ans = false;
			cin >> l >> r;
			l--; r--;
			for (int i = 0; i < l; ++i) {
				if (s[i] == s[l]) {
					ans = true;
					break;
				}
			}
			for (int i = r+1; i < n; ++i) {
				if (s[i] == s[r]) {
					ans = true;
					break;
				}
			}
			if (ans)cout << "YES\n";
			else cout << "NO\n";
		}

	}

	

	return 0;
}
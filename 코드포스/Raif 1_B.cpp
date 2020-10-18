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
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0, left = 0, right = 0;
		string s;
		cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			int l = (i + n - 1) % n, r = i;
			if (s[r] == '>')right++;
			else if (s[r] == '<')left++;
			else {
				right++; left++;
			}

			if (s[l] == '-' || s[r] == '-')ans++;
		}
		if (left == n || right == n)cout << n << '\n';
		else cout << ans << '\n';
	}

	return 0;

}
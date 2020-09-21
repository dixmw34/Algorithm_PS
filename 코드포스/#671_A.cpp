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
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;

		int odd = 0, even = 0;
		for (int i = 1; i <= n; ++i) {
			if ((i % 2) && (s[i-1] - '0') % 2)odd++;
			else if((i%2 == 0) && ((s[i-1] - '0') % 2 == 0)) even++;
		}
		//cout << "ans : ";

		if (n % 2 == 1) {
			if (odd)cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else {
			if (even)cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}

	return 0;

}
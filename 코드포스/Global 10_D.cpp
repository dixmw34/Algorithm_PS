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
		int n;
		string s;
		cin >> n >> s;
		int cnt = 0, ans = 0;
		while (!s.empty() && s[0] == s.back()) {
			s.pop_back();
			cnt++;
		}
		if (s.empty()) {
			if (n <= 2)cout << 0 << '\n';
			else cout << (n + 2) / 3 << '\n';
			continue;
		}
		s.push_back('!');
		for (int i = 0; i < s.size()-1; ++i) {
			cnt++;
			if (s[i] != s[i + 1])
			{
				ans += cnt / 3;
				cnt = 0;
			}
		}
		cout << ans << '\n';

	}


	return 0;

}
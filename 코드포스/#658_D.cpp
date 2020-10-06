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
		int pre = 0, n, p, num = 0;
		vector<int>a;

		cin >> n;
		for (int i = 0; i < 2 * n; ++i) {
			cin >> p;
			if (p > pre) {
				if(num)a.push_back(num);
				pre = p, num = 1;
			}
			else ++num;
		}
		a.push_back(num);

		sort(a.begin(), a.end());
		vector<bool>ans(n + 1, false);
		ans[0] = true;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = n; j - a[i] >= 0; --j) {
				if (!ans[j] && ans[j - a[i]])ans[j] = true;
			}
		}
		if (ans[n])cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;

}
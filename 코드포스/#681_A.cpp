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
		int n, cnt = 0;
		cin >> n;
		int start = 4;
		while (1) {
			vector<bool>a(4 * n + 1, true);
			vector<int>ans;
			for (int i = start; i <= 4 * n; i += 2) {
				if (a[i]) {
					ans.push_back(i);
					if (++cnt == n)break;
					for (int j = i; j <= 4 * n; j += i)a[j] = false;
				}
			}
			if (ans.size() == n) {
				for (int i = 0; i < ans.size(); ++i)cout << ans[i] << ' ';
				cout << '\n';
				break;
			}
			else start += 2;
		}
		
	}


	return 0;

}
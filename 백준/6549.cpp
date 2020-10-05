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

ll len[100000];

ll sol(int left, int right) {
	if (left == right)return len[left];
	int mid = (left + right) / 2;
	ll result = max(sol(left, mid), sol(mid + 1, right));

	ll h = min(len[mid], len[mid + 1]);
	result = max(result, h * 2);
	int l = mid - 1, r = mid + 2;
	while (l >= left || r <= right) {
		if (l == left - 1) {
			h = min(h, len[r]);
			result = max(result, h*(r - l));
			++r;
		}
		else if (r == right + 1) {
			h = min(h, len[l]);
			result = max(result, h*(r - l));
			--l;
		}
		else {
			if (len[l] > len[r]) {
				h = min(h, len[l]);
				result = max(result, h*(r - l));
				--l;
			}
			else {
				h = min(h, len[r]);
				result = max(result, h*(r - l));
				++r;
			}
		}
	}
	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i)cin >> len[i];

		cout << sol(0, n - 1) << '\n';
	}

	return 0;

}
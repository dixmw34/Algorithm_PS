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
		int n;
		cin >> n;
		vector<int>a(n), Min(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		Min[n - 1] = a[n - 1];
		for (int i = n-2; i > 0; --i) {
			Min[i] = min(Min[i + 1], a[i]);
		}
		bool flag = true; int left = a[0], right = 0;
		for (int i = 1; i < n - 1; ++i) {
			if (left + Min[i + 1] < a[i]) {
				flag = false;
				break;
			}
			left = min(left, a[i]-right);
			right = max(right, a[i] - left);
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
		
	}


	return 0;

}
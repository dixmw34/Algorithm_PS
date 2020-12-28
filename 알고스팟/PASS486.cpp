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

const int MAX = 10000000;
int fac[10000001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= MAX; ++i) {
		for (int j = 1; i*j<=MAX; ++j) {
			fac[i*j]++;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, lo, hi, ans = 0;
		cin >> n >> lo >> hi;
		for (int i = lo; i <= hi; ++i) {
			if (fac[i] == n)ans++;
		}
		cout << ans << '\n';
	}

	
	
	return 0;
}
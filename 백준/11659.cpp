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
#include <cassert>

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

int sum[100001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(sum, 0, sizeof(sum));

	int n, m, a, b;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		sum[i] = a + sum[i - 1];
	}
	
	while (m--) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	


	return 0;
}
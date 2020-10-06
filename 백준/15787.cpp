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

	int n, m, num, i, x;
	cin >> n >> m;
	vector<string>a(n, string(20, '0'));

	while (m--) {
		cin >> num >> i;
		if (num == 1) {
			cin >> x;
			a[i - 1][x - 1] = '1';
		}
		else if (num == 2) {
			cin >> x;
			a[i - 1][x - 1] = '0';
		}
		else if (num == 3) {
			for (int k = 19; k > 0; --k)a[i - 1][k] = a[i - 1][k - 1];
			a[i - 1][0] = '0';
		}
		else {
			for (int k = 0; k < 19; ++k)a[i - 1][k] = a[i - 1][k + 1];
			a[i - 1][19] = '0';
		}
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	cout << a.size() << '\n';

	return 0;

}
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

int a[100], b[100];

void sol(int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right)return;
	if (pre_left == pre_right) {
		cout << a[pre_left] << ' ';
		return;
	}
	for (int i = 0; i <= (in_right - in_left); ++i) {
		if (a[pre_left] == b[in_left + i]) {
			sol(pre_left + 1, pre_left + i, in_left, in_left + i - 1);
			sol(pre_left + i + 1, pre_right, in_left + i + 1, in_right);
			break;
		}
	}
	
	cout << a[pre_left] << ' ';
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> a[i];
		for (int i = 0; i < n; ++i)cin >> b[i];

		sol(0, n - 1, 0, n - 1);
		cout << '\n';
	}

	return 0;

}
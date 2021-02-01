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

bool arr[100][100];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(arr, 0, sizeof(arr));

	int x1, x2, y1, y2;

	for (int k = 0; k < 4; ++k) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				arr[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (arr[i][j])ans++;
		}
	}
	cout << ans << '\n';

	
	

	return 0;
}
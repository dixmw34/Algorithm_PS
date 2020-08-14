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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<vector<bool>>arr;

void sol(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[x + i][y + j] = !arr[x + i][y + j];
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int N, L, ans = 0, a;
	vector<bool>arr(1001, false);

	cin >> N >> L;

	while (N--) {
		cin >> a;
		arr[a] = true;
	}

	for (int i = 1; i <= 1000; i++) {
		if (arr[i]) {
			i += (L - 1);
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
	

}
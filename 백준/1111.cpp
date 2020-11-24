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
	cin.tie(0); cout.tie(0);

	int n, arr[50];

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];

	if (n < 3) {
		if (n == 2 && arr[0] == arr[1]) {
			cout << arr[0] << '\n';
		}
		else {
			cout << 'A' << '\n';
		}
	}
	else {
		if (arr[0] == arr[1]) {
			for (int i = 1; i < n; ++i) {
				if (arr[i] != arr[i - 1]) {
					cout << 'B' << '\n';
					return 0;
				}
			}
			cout << arr[0] << '\n';
			return 0;
		}
		int test = arr[2] - arr[1];
		if (test % (arr[1] - arr[0]) != 0) {
			cout << 'B' << '\n';
			return 0;
		}
		int a = test / (arr[1] - arr[0]);
		int b = arr[1] - a * arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i] != a * arr[i - 1] + b) {
				cout << 'B' << '\n';
				return 0;
			}
		}
		cout << arr[n - 1] * a + b << '\n';
	}

	

	return 0;
}
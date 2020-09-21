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

	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(101, 0);
		int num;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			arr[num]++;
		}
		int a = 0, b = 0;
		for (int i = 0; i <= 100; ++i) {
			if (arr[i] < 2) {
				a = i;
				break;
			}
		}
		for (int i = 0; i <= 100; ++i) {
			if (arr[i] < 1) {
				b = i;
				break;
			}
		}
		cout << a + b << '\n';

	}
	


	return 0;

}
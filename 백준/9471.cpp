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

	int t, idx, num;
	cin >> t;
	while (t--) {
		cin >> idx >> num;
		int i = 3;
		int one = 1, two = 1;
		while (1) {
			int r = two;
			two = (one + two) % num;
			one = r;
			if (one == 1 && two == 0) {
				cout << idx << ' ' << i << '\n';
				break;
			}
			++i;
		}
	}

	


	return 0;

}
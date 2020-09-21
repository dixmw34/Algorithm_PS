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
#include<string.h>

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
		int sum = 0, mx = 0, a;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			sum += a;
			mx = max(mx, a);
		}

		if (mx > sum - mx || sum % 2 == 1)cout << "T\n";
		else cout << "HL\n";
	}

	return 0;

}
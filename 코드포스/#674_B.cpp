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
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a[2][2], test = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
			if (a[0][1] == a[1][0])test++;
		}
		if (m % 2 || test == 0) {
			cout << "NO\n";
		}
		else cout << "YES\n";


	}
	

	return 0;

}
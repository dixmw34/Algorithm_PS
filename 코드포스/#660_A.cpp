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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n <= 30)cout << "NO\n";
		else {
			if (n == 36 || n == 40 || n == 44) {
				cout << "YES\n";
				cout << "6 10 15 " << n - 31 << '\n';
			}
			else {
				cout << "YES\n";
				cout << "6 10 14 " << n - 30 << '\n';
			}
		}
	}


}
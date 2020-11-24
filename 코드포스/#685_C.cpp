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

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string A, B;
		cin >> n >> k >> A >> B;
		vector<int>a(26, 0), b(26, 0);
		for (int i = 0; i < n; ++i) {
			a[A[i] - 'a']++;
			b[B[i] - 'a']++;
		}
		bool ans = true;
		for (int i = 0; i < 26; ++i) {
			if (a[i] < b[i]) {
				ans = false;
				break;
			}
			else {
				a[i] -= b[i];
				if(a[i]%k!=0) {
					ans = false;
					break;
				}
				if (i != 25)a[i + 1] += a[i];
			}
		}
		if (ans)cout << "YES\n";
		else cout << "NO\n";

	}

	

	return 0;
}
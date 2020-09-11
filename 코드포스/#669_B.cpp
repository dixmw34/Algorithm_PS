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

int gcd(int a, int b) {
	while (a%b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << a[n-1] << ' ';

		vector<vector<int>>arr(3001);
		int num = a[n - 1];
		while (1) {
			int max = 0;
			vector<int>v;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] && gcd(num, a[i]) > max) {
					max = gcd(num, a[i]);
					v = { i };
				}
				else if (a[i] && gcd(num, a[i]) == max)v.push_back(i);
			}
			if (max == 0 || max == 1)break;
			for (int i = 0; i < v.size(); i++) {
				cout << a[v[i]] << ' ';
				a[v[i]] = 0;
			}
			v.clear();
			num = max;
		}
		for (int i = 0; i < n-1; i++) {
			if(a[i])cout << a[i] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
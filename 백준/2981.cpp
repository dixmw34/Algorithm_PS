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
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	sort(a.begin(), a.end());

	int num = a[1] - a[0];
	for (int i = 2; i < n; ++i) {
		num = gcd(num, a[i] - a[i - 1]);
	}

	priority_queue<int>pq;
	for (int i = 1; i <= sqrt(num); ++i) {
		if (num%i == 0) {
			if (i != 1 && i*i != num)pq.push(-i);
			pq.push(-(num / i));
		}
	}

	while (!pq.empty()) {
		cout << -pq.top() << ' ';
		pq.pop();
	}
	cout << '\n';


	return 0;

}
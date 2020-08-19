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

struct Lec
{
	int cost;
	int day;
};

bool cmp(Lec a, Lec b) {
	if (a.day == b.day) {
		return a.cost > b.cost;
	}
	else return a.day > b.day;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, a, b, last = 0, ans = 0;
	vector<Lec>arr;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back(Lec{ a, b });
		last = max(last, b);

	}

	sort(arr.begin(), arr.end(), cmp);

	int j = 0;
	priority_queue<int>pq;
	for (int i = last; i >= 1; i--) {
		while (j < N && arr[j].day == i) {
			pq.push(arr[j++].cost);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';


	return 0;

}
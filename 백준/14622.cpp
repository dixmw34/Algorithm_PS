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

vector<vector<int>>arr(2);
int n;
ll score[2] = { 0, 0 };

bool prime(int num) {
	if (num < 2)return false;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num%i == 0)return false;
	}
	return true;
}

void sol(int num, int name) {
	if (!prime(num)) {
		if (arr[1 - name].size() < 3)score[1 - name] += (ll)1000;
		else score[1 - name] += (ll)arr[1 - name][arr[1 - name].size() - 3];
		return;
	}
	int idx = lower_bound(arr[0].begin(), arr[0].end(), num) - arr[0].begin();
	if (idx != arr[0].size() && arr[0][idx] == num) {
		score[name] -= (ll)1000;
		return;
	}

	idx = lower_bound(arr[1].begin(), arr[1].end(), num) - arr[1].begin();
	if (idx != arr[1].size() && arr[1][idx] == num) {
		score[name] -= (ll)1000;
		return;
	}

	idx = lower_bound(arr[name].begin(), arr[name].end(), num) - arr[name].begin();
	arr[name].insert(arr[name].begin() + idx, num);
	return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int a, b;

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		sol(a, 0);
		sol(b, 1);
	}

	if (score[0] > score[1]) {
		cout << "소수의 신 갓대웅\n";
	}
	else if (score[0] < score[1]) {
		cout << "소수 마스터 갓규성\n";
	}
	else cout << "우열을 가릴 수 없음\n";
	

	return 0;

}
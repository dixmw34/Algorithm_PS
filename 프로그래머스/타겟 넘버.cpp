#include <string>
#include <vector>

using namespace std;

int ans = 0, n, target;
vector<int>arr;

void dfs(int idx, int num) {
    if (idx == n) {
        if(num == target)ans++;
        return;
    }

    dfs(idx + 1, num + arr[idx]);
    dfs(idx + 1, num - arr[idx]);
}

int solution(vector<int> numbers, int a) {

    n = numbers.size();
    target = a;
    arr = numbers;

    dfs(0, 0);

    return ans;
}
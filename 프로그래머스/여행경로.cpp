#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool>visit;
vector<vector<string>>arr;
vector<string>v;
int n;

bool dfs() {
    if (v.size() == n+1)return true;

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == v[v.size() - 1] && !visit[i]) {
            v.push_back(arr[i][1]);
            visit[i] = true;
            if (dfs()) return true;
            else{
                v.pop_back();
                visit[i] = false;
            }
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    arr = tickets;
    n = arr.size();
    visit = vector<bool>(n, false);
    v.push_back("ICN");

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == "ICN") {
            visit[i] = true;
            v.push_back(arr[i][1]);
            if (dfs()) {
                return v;
            }
            visit[i] = false;
            v.pop_back();
        }
    }

}
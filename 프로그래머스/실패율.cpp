#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first)return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int>arr(N + 1, 0);
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] <= N)arr[stages[i]]++;
    }
    vector<pair<double, int>>ans;
    int n = stages.size();
    for (int i = 1; i <= N; i++) {
        if (n == 0) {
            ans.push_back(make_pair(0.0, i));
            continue;
        }
        ans.push_back(make_pair((double)arr[i] / (double)n, i));
        n -= arr[i];
    }

    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)answer.push_back(ans[i].second);

    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

pair<ll, ll>cal(string a) {
    ll end = 0;
    end += ((a[11] - '0') * 10 + (a[12] - '0'))*3600*1000;
    end += ((a[14] - '0') * 10 + (a[15] - '0'))*60*1000;
    end += ((a[17] - '0') * 10 + (a[18] - '0'))*1000;
    end += ((a[20] - '0') * 100 + (a[21] - '0') * 10 + (a[22] - '0'));

    ll time = 0; ll ind = 1000LL;
    for (int i = 24; i < a.size() - 1; ++i) {
        if (a[i] == '.')
            continue;
        time += (a[i] - '0')*ind;
        ind /= 10LL;
    }
    return make_pair(end - time + 1, end);
}

int solution(vector<string> lines) {
    int answer = 0;
    int n = lines.size();

    vector<pair<ll, ll>>arr;
    for (int i = 0; i < n; ++i) {
        arr.push_back(cal(lines[i]));
    }
    sort(arr.begin(), arr.end());
    priority_queue<ll, vector<ll>, greater<ll>>pq;

    for (int i = 0; i < n; ++i) {
        while (!pq.empty() && pq.top() <= arr[i].first - 1000)
            pq.pop();
        pq.push(arr[i].second);
        answer = max(answer, (int)pq.size());
    }

    return answer;
}
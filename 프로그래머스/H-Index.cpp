#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    vector<int>a = citations;

    sort(a.begin(), a.end());

    for (int i = a[a.size()-1]; i >= 0; i--) {
        int idx = lower_bound(a.begin(), a.end(), i) - a.begin();
        if (a.size() - idx >= i)return i;

    }

    return answer;
}
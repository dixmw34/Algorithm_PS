#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool>visit(100000000, false);

bool prime(int num) {
    if (num <= 1)return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num%i == 0)return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    int n = numbers.size();

    sort(numbers.begin(), numbers.end());

    vector<bool>a(n, false);
    for (int i = 1; i <= numbers.size(); i++) {
        a[n - i] = true;
        do {
            vector<char>b;
            for (int i = 0; i < numbers.size(); i++) {
                if (a[i])b.push_back(numbers[i]);
            }
            do {
                string s;
                for (int i = 0; i < b.size(); i++) {
                    s += b[i];
                }
                int num = atoi(s.c_str());
                if (!visit[num]) {
                    visit[num] = true;
                    if (prime(num))answer++;
                }
            } while (next_permutation(b.begin(), b.end()));

        } while (next_permutation(a.begin(), a.end()));
    }

    return answer;
}

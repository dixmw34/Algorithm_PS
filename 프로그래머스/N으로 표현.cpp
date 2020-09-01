#include <string>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int solution(int N, int number) {

    vector<set<ll>>arr(9);

    arr[1].insert((ll)N);
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; i - j >= 1; j++) {
            for (auto a : arr[j]) {
                for (auto b : arr[i - j]) {
                    ll num = a + b;
                    if (num == (ll)number)return i;
                    if (arr[i].find(num) == arr[i].end())arr[i].insert(num);

                    num = a - b;
                    if (num == (ll)number)return i;
                    if (arr[i].find(num) == arr[i].end())arr[i].insert(num);

                    num = a * b;
                    if (num == (ll)number)return i;
                    if (arr[i].find(num) == arr[i].end())arr[i].insert(num);

                    if (b != 0)num = a / b;
                    if (num == (ll)number)return i;
                    if (arr[i].find(num) == arr[i].end())arr[i].insert(num);
                }
            }
        }
        string s = string(i, '0' + N);
        arr[i].insert(atoi(s.c_str()));
        if (atoi(s.c_str()) == number)return i;
    }


    return -1;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, arr[N];
unordered_map<int, int> hashs;

int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 0, j = 0; i < n; i ++) {
        hashs[arr[i]] ++;
        while (j <= i && hashs[arr[i]] > 1) hashs[arr[j++]] --;
        if (j <= i) res = max(res, i - j + 1); 
    }
    cout << res << endl;
    return 0;
}
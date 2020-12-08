#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N], sum[N];
int n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    
    while (q --) {
        int l, r;
        cin >> l  >>r ;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int b[N];

// 差分操作：在[l, r]区间的数全部加上c
void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        insert(i, i, x);
    }
    while (m --) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1], printf("%d ", b[i]);
    
    return 0;
}
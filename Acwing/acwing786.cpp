#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int n, k;

int quick_sort(int l, int r, int k) {
    if (l == r) return a[l];
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j) swap(a[i], a[j]);       
    }
    if (k > (j - l + 1)) return quick_sort(j + 1, r, k - (j - l + 1));
    return quick_sort(l, j, k);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];
    cout << quick_sort(0, n - 1, k);
}
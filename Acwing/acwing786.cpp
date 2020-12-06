#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int arr[N];
int n, k;

int findk(int l, int r, int k) {
    if (l == r) return arr[l];
    int i = l - 1, j = r + 1, mid = arr[l + r >> 1];
    while (i < j) {
        while (arr[++i] < mid);
        while (arr[--j] > mid);
        if (i < j) swap(arr[i], arr[j]);
    }
    if (j - l + 1 >= k) return findk(l, j, k);
    else return findk(j + 1, r, k - (j - l + 1));
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    cout << findk(0, n - 1, k);
    
    return 0;
}
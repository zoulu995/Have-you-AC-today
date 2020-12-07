#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int arr[N], temp[N];

long long merge_sort(int l, int r) {
    if (l == r) return 0;
    int mid = l + r >> 1;
    long long ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            ans += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = 0, j = l; i < k; i ++, j ++) arr[j] = temp[i];
    return ans;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    cout << merge_sort(0, n - 1);
    return 0;
}
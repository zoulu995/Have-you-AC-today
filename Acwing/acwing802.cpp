﻿#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3e5 + 10;
int n, m;
typedef pair<int, int> PII;
vector<int> alls;
vector<PII> add, query;
int a[N], s[N];

int find(int num) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        // 答案在mid的左区间，不用+1
        int mid = l + r >> 1;
        if (alls[mid] >= num) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x, c; 
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i ++) {
        s[i] = s[i - 1] + a[i];
    }

    for (auto item : query) {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
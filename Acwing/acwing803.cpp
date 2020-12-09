#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int MIN = -2e9;  //最小值取错了！ 不是2e-9
typedef pair<int, int> PII;
vector<PII> segs, ans;
int n;

int merge(vector<PII>& segs) {
    int st = MIN, ed = MIN;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != MIN) {
                ans.push_back({st, ed});
            }
            st = seg.first;
            ed = seg.second;
        }
        else {
            ed = max(seg.second, ed);
        }
    }
    //cout << st << " " << ed << endl;
    if (st != MIN) ans.push_back({st, ed});

    return ans.size();
}

int main() {
    cin >> n;
    while (n --) {
        int l, r; 
        cin >> l >> r;
        segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    //for (auto seg : segs) cout << seg.first << " " << seg.second << endl;
    cout << merge(segs) << endl;

    return 0;
}

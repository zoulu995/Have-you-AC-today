#include <bits/stdc++.h>
using namespace std;

double x;

int main() {
    cin >> x;
    int flag = 0;
    if (x < 0) {
        flag = 1;
        x = -x;
    }
    double l = 0, r = x;
    while ((r - l) > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x) r = mid;
        else l = mid;
    }
    if (flag) l = -l;
    printf("%.6f", l);
    return 0;
}
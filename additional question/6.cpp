#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double bruteForce(vector<Point>& p, int l, int r) {
    double d = 1e18;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++)
            d = min(d, dist(p[i], p[j]));
    return d;
}

double stripClosest(vector<Point>& strip, double d) {
    sort(strip.begin(), strip.end(),
         [](Point a, Point b) { return a.y < b.y; });

    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1;
             j < strip.size() && (strip[j].y - strip[i].y) < d;
             j++)
            d = min(d, dist(strip[i], strip[j]));
    return d;
}

double closestUtil(vector<Point>& p, int l, int r) {
    if (r - l <= 3)
        return bruteForce(p, l, r);

    int mid = (l + r) / 2;
    double dl = closestUtil(p, l, mid);
    double dr = closestUtil(p, mid + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    double midx = p[mid].x;

    for (int i = l; i <= r; i++)
        if (abs(p[i].x - midx) < d)
            strip.push_back(p[i]);

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& p) {
    sort(p.begin(), p.end(),
         [](Point a, Point b) { return a.x < b.x; });

    return closestUtil(p, 0, p.size() - 1);
}

int main() {
    vector<Point> p = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    cout << fixed << setprecision(3)
         << closestPair(p);
}

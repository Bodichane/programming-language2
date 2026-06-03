#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// ============================================================
// POINT STRUCT
// ============================================================

struct Point {
    int x, y;
    string s;

    bool operator<(const Point& p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y, s + p.s};
    }
};

// ============================================================
// TASK 1 — sort by absolute value
// сортировка по модулю
// ============================================================
void sortByAbsoluteValue(vector<int>& v) {
    sort(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
}

// ============================================================
// TASK 2 — first unordered abs pair
// поиск первой пары, где |a| >= |b|
// ============================================================
vector<int> findFirstNonIncreasingAbsPair(const vector<int>& v) {
    auto it = adjacent_find(v.begin(), v.end(),
        [](int a, int b) { return abs(a) >= abs(b); });

    if (it == v.end()) return {};
    return {*it, *(it + 1)};
}

// ============================================================
// TASK 3 — remove |x| < k
// удаление элементов с модулем меньше k
// ============================================================
void removeLessThanK(vector<int>& v, int k) {
    v.erase(remove_if(v.begin(), v.end(),
        [k](int x) { return abs(x) < k; }), v.end());
}

// ============================================================
// TASK 4 — last element |x| > k
// поиск последнего элемента с |x| > k
// ============================================================
int findLastGreaterThanK(const vector<int>& v, int k) {
    auto it = find_if(v.rbegin(), v.rend(),
        [k](int x) { return abs(x) > k; });

    return (it == v.rend()) ? 0 : *it;
}

// ============================================================
// TASK 5 — count |x| <= k
// подсчёт элементов с модулем <= k
// ============================================================
int countAbsLessOrEqualK(const vector<int>& v, int k) {
    return count_if(v.begin(), v.end(),
        [k](int x) { return abs(x) <= k; });
}

// ============================================================
// TASK 6 — element-wise multiply
// поэлементное умножение
// ============================================================
vector<int> multiplyVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size());
    transform(a.begin(), a.end(), b.begin(), res.begin(), multiplies<int>());
    return res;
}

// ============================================================
// TASK 7 — subtract K
// вычитание константы
// ============================================================
vector<int> subtractK(const vector<int>& v, int k) {
    vector<int> res = v;
    transform(res.begin(), res.end(), res.begin(),
        [k](int x) { return x - k; });
    return res;
}

// ============================================================
// TASK 8 — linear combination
// линейная комбинация V1*K + V2
// ============================================================
vector<int> linearCombine(const vector<int>& a, const vector<int>& b, int k) {
    vector<int> res(a.size());
    transform(a.begin(), a.end(), b.begin(), res.begin(),
        [k](int x, int y) { return x * k + y; });
    return res;
}

// ============================================================
// TASK 9 — stable sort points
// сортировка точек
// ============================================================
vector<Point> sortPointsStable(vector<Point> v) {
    stable_sort(v.begin(), v.end());
    return v;
}

// ============================================================
// TASK 10 — replace positive points
// замена положительных точек
// ============================================================
vector<Point> replacePositivePoints(const vector<Point>& v, Point rep) {
    vector<Point> res;
    transform(v.begin(), v.end(), back_inserter(res),
        [rep](Point p) {
            return (p.x > 0 && p.y > 0) ? rep : p;
        });
    return res;
}

// ============================================================
// TASK 11 — stable partition
// разделение точек
// ============================================================
vector<Point> stablePartitionPoints(vector<Point> v) {
    Point origin{0,0,""};
    stable_partition(v.begin(), v.end(),
        [origin](const Point& p) {
            return p < origin;
        });
    return v;
}

// ============================================================
// TASK 12 — add point vectors
// сложение точек
// ============================================================
vector<Point> addPointVectors(vector<Point> a, const vector<Point>& b) {
    transform(a.begin(), a.end(), b.begin(), a.begin(), plus<Point>());
    return a;
}

// ============================================================
// TASK 13 — add constant point
// добавление константы
// ============================================================
vector<Point> addPointConstant(vector<Point> v, Point d) {
    transform(v.begin(), v.end(), v.begin(),
        [d](Point p) {
            return Point{p.x + d.x, p.y + d.y, p.s}; 
        });
    return v;
}

// ============================================================
// TASK 14 — transform points (linear + add)
// линейное преобразование точек
// ============================================================
vector<Point> transformPoints(vector<Point> a, vector<Point> b, int k) {
    transform(a.begin(), a.end(), a.begin(),
        [k](Point p) { return Point{p.x * k, p.y * k, p.s}; });

    transform(a.begin(), a.end(), b.begin(), a.begin(), plus<Point>());
    return a;
}
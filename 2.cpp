#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

// Вывод вектора
void printVector(const vector<int>& v) {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

// Вывод списка в прямом и обратном порядке
void printListForwardReverse(const list<int>& l) {
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(l.rbegin(), l.rend(), ostream_iterator<int>(cout, " "));
}

// Вывод второй половины затем первой
void printVectorSecondThenFirst(const vector<int>& v) {
    size_t h = v.size() / 2;
    copy(v.begin() + h, v.end(), ostream_iterator<int>(cout, " "));
    copy(v.begin(), v.begin() + h, ostream_iterator<int>(cout, " "));
}

// Вывод половин дека в обратном порядке
void printDequeHalvesReverse(const deque<int>& d) {
    size_t h = d.size() / 2;
    copy(d.rbegin() + h, d.rend(), ostream_iterator<int>(cout, " "));
    copy(d.rbegin(), d.rbegin() + h, ostream_iterator<int>(cout, " "));
}

// Вывод первой трети, затем остальных в обратном порядке
void printListThirds(const list<int>& l) {
    size_t n = l.size() / 3;

    auto it1 = l.begin();
    advance(it1, n);

    auto it2 = it1;
    advance(it2, n);

    copy(l.begin(), it1, ostream_iterator<int>(cout, " "));

    list<int>::const_reverse_iterator r2(it2), r1(it1);
    copy(r2, r1, ostream_iterator<int>(cout, " "));
    copy(l.rbegin(), list<int>::const_reverse_iterator(it2), ostream_iterator<int>(cout, " "));
}

// Удвоение первого, среднего и последнего элемента вектора
void doubleFirstMiddleLast(vector<int>& v) {
    v.front() *= 2;
    v.back() *= 2;
    v[v.size() / 2] *= 2;
}

// Обмен средних элементов вектора
void swapMiddleVector(vector<int>& v) {
    swap(v[v.size()/2 - 1], v[v.size()/2]);
}

// Вставка 5 нулей в середину вектора
void insertFiveZeros(vector<int>& v) {
    v.insert(v.begin() + v.size()/2, 5, 0);
}

// Вставка средних 5 элементов дека в начало
void insertMiddleFiveToFront(deque<int>& d) {
    int start = (d.size() - 5) / 2;
    d.insert(d.begin(), d.begin() + start, d.begin() + start + 5);
}

// Добавить первую треть списка в обратном порядке в конец
void appendFirstThirdReversed(list<int>& l) {
    int n = l.size() / 3;
    auto it = l.begin();
    advance(it, n);

    l.insert(l.end(), list<int>::reverse_iterator(it), list<int>::reverse_iterator(l.begin()));
}

// Вставить первые 5 элементов вектора (обратно) после 5-го элемента списка
void insertVectorFrontReverseIntoList(
    list<int>& l,
    const vector<int>& v
) {
    auto it = l.begin();
    advance(it, 5);

    l.insert(it, v.rbegin() + (v.size() - 5), v.rend());
}

// Вставка последних 5 элементов дека (обратно) в список
void insertDequeBackReverseIntoList(
    list<int>& l,
    const deque<int>& d
) {
    auto it = l.end();
    advance(it, -5);

    l.insert(it, d.rbegin(), d.rbegin() + 5);
}

// Обмен половинами vector и deque
void swapHalves(vector<int>& v, deque<int>& d) {
    size_t vh = v.size() / 2;
    size_t dh = d.size() / 2;

    v.insert(v.end(), d.begin(), d.begin() + dh);

    d.insert(d.begin(),
             vector<int>::reverse_iterator(v.begin() + vh),
             vector<int>::reverse_iterator(v.begin()));
}

// Вставка -1 после каждого элемента vector
void insertMinusOneAfterEach(vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        it = v.insert(++it, -1);
    }
}

// Вставка -1 перед каждым элементом первой половины deque
void insertMinusOneFirstHalf(deque<int>& d) {
    auto it = d.begin() + d.size() / 2;

    for (size_t i = 0; i < d.size() / 2; ++i) {
        it = d.insert(--it, -1);
    }
}

// Обмен половинами vector и deque (вторая часть)
void swapHalvesExtended(vector<int>& v, deque<int>& d) {
    size_t vh = v.size() / 2;
    size_t dh = d.size() / 2;

    v.insert(v.end(), d.begin(), d.begin() + dh);

    d.insert(d.begin(),
             vector<int>::reverse_iterator(v.begin() + vh),
             vector<int>::reverse_iterator(v.begin()));
}

// Вставка -1 перед каждым элементом первой половины дека (итераторный цикл)
void insertMinusOneDequeFirstHalf(deque<int>& d) {
    auto it = d.begin() + d.size() / 2;

    for (size_t i = 0; i < d.size() / 2; ++i) {
        it = d.insert(--it, -1);
    }
}

// То же через обратный итератор дека
void insertMinusOneDequeFirstHalfReverse(deque<int>& d) {
    auto r = d.rend();

    for (size_t i = 0; i < d.size() / 2; ++i) {
        auto ins = d.insert(--r.base(), -1);
        r = decltype(r)(ins);
    }
}

// Вставка -1 перед каждым элементом списка
void insertMinusOneList(list<int>& l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        l.insert(it, -1);
    }
}

// Вставка -1 после элементов первой половины списка
void insertMinusOneListFirstHalf(list<int>& l) {
    auto mid = l.begin();
    advance(mid, l.size() / 2);

    for (auto it = l.begin(); it != mid; ) {
        l.insert(++it, -1);
    }
}

// То же через reverse_iterator
void insertMinusOneListFirstHalfReverse(list<int>& l) {
    auto mid = l.begin();
    advance(mid, l.size() / 2);

    list<int>::reverse_iterator r(mid);

    while (r != list<int>::reverse_iterator(l.begin())) {
        ++r;
        l.erase(--(++r).base());
    }
}

// Перестановка элементов списка: конец-начало
void rearrangeListEnds(list<int>& l) {
    auto i = l.begin();
    auto r = l.end(); --r;

    size_t n = l.size();

    for (size_t k = 0; k < n / 2; ++k) {
        l.splice(i++, l, r--);
    }
}

// Перемежение двух списков
void interleaveLists(list<int>& l1, list<int>& l2) {
    auto i1 = l1.begin();
    auto i2 = l2.begin();

    size_t n = l1.size();

    for (size_t k = 0; k < n; ++k) {
        l2.splice(++i2, l1, i1++);
    }
}

// Удаление среднего элемента дека
void removeMiddleDeque(deque<int>& d) {
    d.erase(d.begin() + d.size() / 2);
}

// Удаление трёх средних элементов вектора
void removeThreeMiddleVector(vector<int>& v) {
    int m = v.size() / 2;
    v.erase(v.begin() + m - 1, v.begin() + m + 2);
}

// Перемещение среднего элемента списка в вектор
void moveMiddleListToVector(list<int>& l, vector<int>& v) {
    auto it = l.begin();
    advance(it, l.size() / 2);

    v.push_back(*it);
    l.erase(it);
}

// Перемещение первой половины дека в список
void moveDequeFirstHalfToList(deque<int>& d, list<int>& l) {
    int h = d.size() / 2;

    l.insert(l.begin(), d.begin(), d.begin() + h);
    d.erase(d.begin(), d.begin() + h);
}

// Перемещение среднего элемента L1 в L2 (splice)
void moveMiddleL1ToL2(list<int>& l1, list<int>& l2) {
    auto mid = l1.begin();
    advance(mid, l1.size() / 2);

    l2.splice(l2.end(), l1, mid);
}

// Перемещение первой половины L2 в L1
void moveFirstHalfL2ToL1(list<int>& l1, list<int>& l2) {
    auto mid = l2.begin();
    advance(mid, l2.size() / 2);

    l1.splice(l1.begin(), l2, l2.begin(), mid);
}

// Обмен половинами двух списков
void swapListHalves(list<int>& l1, list<int>& l2) {
    auto m1 = l1.begin(); advance(m1, l1.size() / 2);
    auto m2 = l2.begin(); advance(m2, l2.size() / 2);

    l1.splice(l1.begin(), l2, m2, l2.end());
    l2.splice(l2.end(), l1, m1, l1.end());
}

// Удаление элементов с нечётными индексами из вектора
void removeOddIndexVector(vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ) {
        it = v.erase(it);
        if (it != v.end()) ++it;
    }
}

// Удаление чётных элементов первой половины дека
void removeEvenFirstHalfDeque(deque<int>& d) {
    auto it = d.begin();

    for (size_t i = 0; i < d.size() / 4; ++i) {
        it = d.erase(++it);
    }
}

// То же через reverse_iterator дека
void removeEvenFirstHalfDequeReverse(deque<int>& d) {
    deque<int>::reverse_iterator r(d.begin() + d.size() / 2);

    for (size_t i = 0; i < d.size() / 4; ++i) {
        ++r;
        auto it = d.erase(--r.base());
        r = decltype(r)(it);
    }
}

// Удаление чётных элементов списка
void removeEvenList(list<int>& l) {
    for (auto it = l.begin(); it != l.end(); ) {
        it = l.erase(++it);
    }
}

// Удаление нечётных элементов первой половины списка
void removeOddFirstHalfList(list<int>& l) {
    auto mid = l.begin();
    advance(mid, l.size() / 2);

    for (auto it = l.begin(); it != mid; ) {
        l.erase(it++);
        if (it != mid) ++it;
    }
}

// То же через reverse_iterator списка
void removeOddFirstHalfListReverse(list<int>& l) {
    auto mid = l.begin();
    advance(mid, l.size() / 2);

    list<int>::reverse_iterator r(mid);

    while (r != list<int>::reverse_iterator(l.begin())) {
        ++r;
        l.erase(--(++r).base());
    }
}

// Перестановка элементов списка (конец-начало)
void reorderListEnds(list<int>& l) {
    auto i = l.begin();
    auto r = l.end(); --r;

    size_t n = l.size();

    for (size_t k = 0; k < n / 2; ++k) {
        l.splice(i++, l, r--);
    }
}

// Перемежение списков в L2
void interleaveIntoL2(list<int>& l1, list<int>& l2) {
    auto i1 = l1.begin();
    auto i2 = l2.begin();

    size_t n = l1.size();

    for (size_t k = 0; k < n; ++k) {
        l2.splice(++i2, l1, i1++);
    }
}

// Удаление среднего элемента дека (дубликат задачи)
void eraseMiddleDeque(deque<int>& d) {
    d.erase(d.begin() + d.size() / 2);
}

// Удаление трёх средних элементов вектора (дубликат)
void eraseThreeMiddleVector(vector<int>& v) {
    int m = v.size() / 2;
    v.erase(v.begin() + m - 1, v.begin() + m + 2);
}

// Перемещение среднего элемента списка в вектор
void moveMiddleListToVectorFinal(list<int>& l, vector<int>& v) {
    auto it = l.begin();
    advance(it, l.size() / 2);

    v.push_back(*it);
    l.erase(it);
}

// Перемещение первой половины дека в список
void moveDequeHalfToList(deque<int>& d, list<int>& l) {
    int h = d.size() / 2;

    l.insert(l.begin(), d.begin(), d.begin() + h);
    d.erase(d.begin(), d.begin() + h);
}

// Перемещение среднего элемента L1 в L2 через splice
void moveMiddleL1ToL2Final(list<int>& l1, list<int>& l2) {
    auto mid = l1.begin();
    advance(mid, l1.size() / 2);

    l2.splice(l2.end(), l1, mid);
}

// Перемещение первой половины L2 в L1
void moveFirstHalfL2ToL1Final(list<int>& l1, list<int>& l2) {
    auto mid = l2.begin();
    advance(mid, l2.size() / 2);

    l1.splice(l1.begin(), l2, l2.begin(), mid);
}

// Обмен половинами списков
void swapListHalvesFinal(list<int>& l1, list<int>& l2) {
    auto m1 = l1.begin(); advance(m1, l1.size() / 2);
    auto m2 = l2.begin(); advance(m2, l2.size() / 2);

    l1.splice(l1.begin(), l2, m2, l2.end());
    l2.splice(l2.end(), l1, m1, l1.end());
}
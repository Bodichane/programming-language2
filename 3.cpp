// ============================================================
// LAB 3: Associative STL Containers
// Part 1: tasks 1–10
// ============================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include <string>

using namespace std;

// ============================================================
// TASK 1
// Проверка: входит ли вторая половина в первую (includes)
// ============================================================
void task1_includes_second_half() {
    cout << "\n=== Task 1: includes check ===\n";

    vector<int> V = {1, 2, 3, 4, 2, 3};
    size_t half = V.size() / 2;

    set<int> S1(V.begin(), V.begin() + half);
    set<int> S2(V.begin() + half, V.end());

    // Проверка включения множества S2 в S1
    cout << boolalpha
         << includes(S1.begin(), S1.end(), S2.begin(), S2.end())
         << "\n";
}

// ============================================================
// TASK 2
// Подсчёт векторов, содержащих все элементы V0
// ============================================================
void task2_count_vectors_including_v0() {
    cout << "\n=== Task 2: vectors containing V0 ===\n";

    vector<int> V0 = {1, 2, 3};
    vector<vector<int>> Vs = {{1,2,3,4}, {1,3,5}, {2,3,1,7}, {4,5,6}};

    set<int> S0(V0.begin(), V0.end());
    int cnt = 0;

    for (const auto& Vi : Vs) {
        set<int> Si(Vi.begin(), Vi.end());
        if (includes(Si.begin(), Si.end(), S0.begin(), S0.end()))
            ++cnt;
    }

    cout << "Count: " << cnt << "\n";
}

// ============================================================
// TASK 3
// То же с учётом повторений (multiset)
// ============================================================
void task3_count_vectors_multiset() {
    cout << "\n=== Task 3: vectors including V0 with duplicates ===\n";

    vector<int> V0 = {1, 1, 2};
    vector<vector<int>> Vs = {{1,1,2,3}, {1,2,3}, {1,1,1,2}, {5,6}};

    multiset<int> MS0(V0.begin(), V0.end());
    int cnt = 0;

    for (const auto& Vi : Vs) {
        multiset<int> MSi(Vi.begin(), Vi.end());
        if (includes(MSi.begin(), MSi.end(), MS0.begin(), MS0.end()))
            ++cnt;
    }

    cout << "Count: " << cnt << "\n";
}

// ============================================================
// TASK 4
// Пересечение половин вектора → файл
// ============================================================
void task4_set_intersection_to_file(const string& filename) {
    cout << "\n=== Task 4: set intersection to file ===\n";

    vector<int> V = {1, 2, 3, 4, 2, 3, 5, 6};
    size_t half = V.size() / 2;

    set<int> S1(V.begin(), V.begin() + half);
    set<int> S2(V.begin() + half, V.end());

    ofstream fout(filename);

    // Общие элементы двух множеств
    set_intersection(
        S1.begin(), S1.end(),
        S2.begin(), S2.end(),
        ostream_iterator<int>(fout, " ")
    );

    cout << "Written to file: " << filename << "\n";
}

// ============================================================
// TASK 5
// Разность множеств (вторая половина - первая)
// ============================================================
void task5_set_difference_to_file(const string& filename) {
    cout << "\n=== Task 5: set difference to file ===\n";

    vector<int> V = {1, 2, 3, 4, 5, 6, 7, 2};
    size_t half = V.size() / 2;

    set<int, greater<int>> S1(V.begin(), V.begin() + half);
    set<int, greater<int>> S2(V.begin() + half, V.end());

    ofstream fout(filename);

    set_difference(
        S2.begin(), S2.end(),
        S1.begin(), S1.end(),
        ostream_iterator<int>(fout, "\n"),
        greater<int>()
    );

    cout << "Written to file: " << filename << "\n";
}

// ============================================================
// TASK 6
// Объединение multiset (с учётом повторений)
// ============================================================
void task6_set_union_multiset() {
    cout << "\n=== Task 6: multiset union ===\n";

    vector<int> V1 = {1, 1, 2, 3};
    vector<int> V2 = {1, 2, 2, 4};

    multiset<int> MS1(V1.begin(), V1.end());
    multiset<int> MS2(V2.begin(), V2.end());

    set_union(
        MS1.begin(), MS1.end(),
        MS2.begin(), MS2.end(),
        ostream_iterator<int>(cout, " ")
    );

    cout << "\n";
}

// ============================================================
// TASK 7
// Симметрическая разность multiset
// ============================================================
void task7_symmetric_difference() {
    cout << "\n=== Task 7: symmetric difference ===\n";

    vector<int> V1 = {1, 1, 2, 3, 3};
    vector<int> V2 = {1, 2, 2, 4};

    multiset<int, greater<int>> MS1(V1.begin(), V1.end());
    multiset<int, greater<int>> MS2(V2.begin(), V2.end());

    set_symmetric_difference(
        MS1.begin(), MS1.end(),
        MS2.begin(), MS2.end(),
        ostream_iterator<int>(cout, " "),
        greater<int>()
    );

    cout << "\n";
}

// ============================================================
// TASK 8
// Уникальные элементы без min/max
// ============================================================
void task8_unique_without_min_max() {
    cout << "\n=== Task 8: unique without min/max ===\n";

    vector<int> V = {5, 3, 1, 4, 2, 5, 3};

    set<int> S(V.begin(), V.end());

    auto rIt = S.rbegin();
    ++rIt; // skip max

    auto rEnd = S.rend();
    --rEnd; // skip min boundary approximation

    copy(rIt, rEnd, ostream_iterator<int>(cout, " "));
    cout << "\n";
}

// ============================================================
// TASK 9
// Без set: sort + unique
// ============================================================
void task9_sort_unique() {
    cout << "\n=== Task 9: sort + unique ===\n";

    vector<int> V = {5, 3, 1, 4, 2, 5, 3};

    sort(V.begin(), V.end());
    auto last = unique(V.begin(), V.end());

    copy(make_reverse_iterator(last - 1),
         make_reverse_iterator(V.begin() + 1),
         ostream_iterator<int>(cout, " "));

    cout << "\n";
}

// ============================================================
// TASK 10
// Все элементы кроме min/max (с повторениями)
// ============================================================
void task10_without_min_max() {
    cout << "\n=== Task 10: without min/max (multiset) ===\n";

    vector<int> V = {5, 3, 1, 4, 2, 5, 3, 1};
    multiset<int> MS(V.begin(), V.end());

    int minVal = *MS.begin();
    int maxVal = *MS.rbegin();

    auto from = MS.upper_bound(minVal);
    auto to = MS.lower_bound(maxVal);

    copy(from, to, ostream_iterator<int>(cout, " "));
    cout << "\n";
}

// ============================================================
// TASK 11
// Без multiset: sort + bounds
// ============================================================
void task11_sort_bounds() {
    cout << "\n=== Task 11: sort + bounds ===\n";

    vector<int> V = {5, 3, 1, 4, 2, 5, 3, 1};

    sort(V.begin(), V.end());

    auto from = upper_bound(V.begin(), V.end(), V.front());
    auto to   = lower_bound(V.begin(), V.end(), V.back());

    copy(from, to, ostream_iterator<int>(cout, " "));
    cout << "\n";
}

// ============================================================
// TASK 12
// Подсчёт повторений через multiset
// ============================================================
void task12_count_with_multiset() {
    cout << "\n=== Task 12: frequency via multiset ===\n";

    vector<int> V = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    multiset<int> MS(V.begin(), V.end());

    for (auto it = MS.begin(); it != MS.end();) {
        auto next = MS.upper_bound(*it);
        cout << *it << ":" << distance(it, next) << " ";
        it = next;
    }

    cout << "\n";
}

// ============================================================
// TASK 13
// Подсчёт повторений через sort + upper_bound
// ============================================================
void task13_count_with_sort() {
    cout << "\n=== Task 13: frequency via sort ===\n";

    vector<int> V = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    sort(V.begin(), V.end());

    for (auto it = V.begin(); it != V.end();) {
        auto next = upper_bound(it, V.end(), *it);
        cout << *it << ":" << (next - it) << " ";
        it = next;
    }

    cout << "\n";
}

// ============================================================
// TASK 14
// multiset + set + for_each + count
// ============================================================
void task14_count_with_for_each() {
    cout << "\n=== Task 14: count via for_each ===\n";

    vector<int> V = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    multiset<int> M(V.begin(), V.end());
    set<int> S(V.begin(), V.end());

    for_each(S.begin(), S.end(), [&M](int x) {
        cout << x << ":" << M.count(x) << " ";
    });

    cout << "\n";
}

// ============================================================
// TASK 15
// Частоты через map
// ============================================================
void task15_frequency_map() {
    cout << "\n=== Task 15: frequency map ===\n";

    vector<int> V = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    map<int, int> M;

    for (int x : V)
        M[x]++;

    for (auto it = M.begin(); it != M.end(); ++it)
        cout << it->first << ":" << it->second << " ";

    cout << "\n";
}

// ============================================================
// TASK 16
// Частоты через for_each
// ============================================================
void task16_frequency_for_each() {
    cout << "\n=== Task 16: frequency via for_each ===\n";

    vector<int> V = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    map<int, int> M;

    for_each(V.begin(), V.end(), [&M](int x) {
        M[x]++;
    });

    for_each(M.begin(), M.end(), [](const pair<int,int>& p) {
        cout << p.first << ":" << p.second << " ";
    });

    cout << "\n";
}

// ============================================================
// TASK 17
// Суммарная длина слов по первой букве
// ============================================================
void task17_word_length_by_first_letter() {
    cout << "\n=== Task 17: word length by first letter ===\n";

    vector<string> V = {"APPLE", "AVOCADO", "BANANA", "BLUEBERRY", "CHERRY"};
    map<char, int> M;

    for (auto &s : V)
        M[s[0]] += (int)s.size();

    for (auto it = M.begin(); it != M.end(); ++it)
        cout << it->first << ":" << it->second << " ";

    cout << "\n";
}

// ============================================================
// TASK 18
// То же через for_each
// ============================================================
void task18_word_length_for_each() {
    cout << "\n=== Task 18: word length via for_each ===\n";

    vector<string> V = {"APPLE", "AVOCADO", "BANANA", "BLUEBERRY", "CHERRY"};
    map<char, int> M;

    for_each(V.begin(), V.end(), [&M](const string& s) {
        M[s[0]] += (int)s.size();
    });

    for_each(M.begin(), M.end(), [](const pair<char,int>& p) {
        cout << p.first << ":" << p.second << " ";
    });

    cout << "\n";
}

// ============================================================
// TASK 19
// Группировка по последней цифре
// ============================================================
void task19_group_by_last_digit() {
    cout << "\n=== Task 19: group by last digit ===\n";

    vector<int> V = {12, 21, 33, 44, 52, 63, 74, 21};
    map<int, vector<int>> M;

    for (int x : V)
        M[abs(x) % 10].push_back(x);

    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << ": ";
        for (int x : it->second)
            cout << x << " ";
        cout << "\n";
    }
}

// ============================================================
// TASK 20
// Группировка слов по первой букве (multiset)
// ============================================================
void task20_group_words_multiset() {
    cout << "\n=== Task 20: group words multiset ===\n";

    vector<string> V = {"CHERRY", "APPLE", "BLUEBERRY", "AVOCADO", "BANANA", "CHERRY"};
    map<char, multiset<string>> M;

    for (const auto &s : V)
        M[s[0]].insert(s);

    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << ": ";
        for (const auto &s : it->second)
            cout << s << " ";
        cout << "\n";
    }
}

// ============================================================
// TASK 21
// Группировка по последней цифре (multimap)
// ============================================================
void task21_group_by_last_digit_multimap() {
    cout << "\n=== Task 21: multimap grouping by last digit ===\n";

    vector<int> V = {12, 21, 33, 44, 52, 63, 74, 21};
    multimap<int, int> M;

    for (int x : V)
        M.insert({abs(x) % 10, x});

    for (auto it = M.begin(); it != M.end(); ++it)
        cout << it->first << ":" << it->second << " ";

    cout << "\n";
}

// ============================================================
// TASK 22
// Группировка слов по последней букве (обратный порядок)
// ============================================================
void task22_group_words_reverse_multimap() {
    cout << "\n=== Task 22: multimap reverse insertion ===\n";

    vector<string> V = {"APPLE", "ORANGE", "TABLE", "SAMPLE", "ROPE"};
    multimap<char, string> M;

    for_each(V.rbegin(), V.rend(), [&M](const string &s) {
        M.insert({s.back(), s});
    });

    for (const auto &p : M)
        cout << p.first << ":" << p.second << " ";

    cout << "\n";
}

// ============================================================
// TASK 23
// Сумма групп (без первого элемента)
// ============================================================
void task23_group_sum_skip_first() {
    cout << "\n=== Task 23: group sum skip first ===\n";

    vector<int> V = {12, 21, 33, 44, 52, 63, 74, 21};
    map<int, vector<int>> M;

    for (int x : V)
        M[abs(x) % 10].push_back(x);

    for (auto &p : M) {
        auto &grp = p.second;
        int sum = (grp.size() > 1)
            ? accumulate(grp.begin() + 1, grp.end(), 0)
            : 0;

        cout << p.first << ":" << sum << " ";
    }

    cout << "\n";
}

// ============================================================
// TASK 24
// Сумма групп через multimap + equal_range
// ============================================================
void task24_group_sum_multimap() {
    cout << "\n=== Task 24: multimap group sum ===\n";

    vector<int> V = {12, 21, 33, 44, 52, 63, 74, 21};
    multimap<int, int> M;

    for (int x : V)
        M.insert({abs(x) % 10, x});

    set<int> keys;
    for (auto &p : M)
        keys.insert(p.first);

    for (int k : keys) {
        auto range = M.equal_range(k);
        auto it = range.first;

        if (it != range.second)
            ++it; // skip first

        int sum = 0;
        for (; it != range.second; ++it)
            sum += it->second;

        cout << k << ":" << sum << " ";
    }

    cout << "\n";
}

// ============================================================
// TASK 25
// Сумма без предварительной группировки (map)
// ============================================================
void task25_group_sum_map() {
    cout << "\n=== Task 25: group sum map ===\n";

    vector<int> V = {12, 21, 33, 44, 52, 63, 74, 21};

    map<int, int> sumMap;
    map<int, bool> seen;

    for (int x : V) {
        int key = abs(x) % 10;

        if (!seen[key]) {
            sumMap[key] = 0;
            seen[key] = true;
        } else {
            sumMap[key] += x;
        }
    }

    for (auto &p : sumMap)
        cout << p.first << ":" << p.second << " ";

    cout << "\n";
}

// ============================================================
// TASK 26
// Сумма строк (без последнего элемента)
// ============================================================
void task26_group_strings_concat() {
    cout << "\n=== Task 26: string group concat ===\n";

    vector<string> V = {"APPLE", "TABLE", "ORANGE", "ROPE", "SAMPLE", "TRIPLE"};
    map<char, vector<string>> M;

    for (const auto &s : V)
        M[s.back()].push_back(s);

    for (const auto &p : M) {
        string res = "";

        if (p.second.size() > 1) {
            res = accumulate(
                p.second.begin(),
                p.second.end() - 1,
                string(""),
                [](const string &a, const string &b) {
                    return a + b + " ";
                }
            );
        }

        cout << p.first << ":\"" << res << "\" ";
    }

    cout << "\n";
}

// ============================================================
// TASK 29
// Inner join by last digit
// ============================================================
void task29_inner_join_last_digit() {
    cout << "\n=== Task 29: inner join ===\n";

    vector<int> V1 = {11, 22, 33, 44};
    vector<int> V2 = {21, 32, 12, 43};

    map<int, vector<int>> M;
    for (int x : V2)
        M[abs(x) % 10].push_back(x);

    vector<pair<int,int>> result;

    for (int x1 : V1) {
        int key = abs(x1) % 10;

        if (M.find(key) != M.end()) {
            for (int x2 : M[key])
                result.push_back({x1, x2});
        }
    }

    cout << "Size: " << result.size() << "\n";

    for (auto &p : result)
        cout << "(" << p.first << "," << p.second << ") ";

    cout << "\n";
}

// ============================================================
// TASK 35
// Left outer join by last digit
// ============================================================
void task35_left_outer_join() {
    cout << "\n=== Task 35: left outer join ===\n";

    vector<int> V1 = {11, 22, 33};
    vector<int> V2 = {21, 12, 43, 32};

    map<int, vector<int>> M;
    for (int x : V2)
        M[abs(x) % 10].push_back(x);

    for (int x1 : V1) {
        int key = abs(x1) % 10;

        cout << x1 << ": ";

        if (M.find(key) != M.end()) {
            for (int x2 : M[key])
                cout << x2 << " ";
        } else {
            cout << 0;
        }

        cout << "| ";
    }

    cout << "\n";
}
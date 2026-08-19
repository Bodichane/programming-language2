#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cctype>

using namespace std;

// Найти количество нулей
int countZeros(const int* arr, int n) {
    return count(arr, arr + n, 0);
}

// Найти количество положительных чисел в файле
int countPositiveNumbers(const string& fileName) {
    ifstream fin(fileName);

    return count_if(
        istream_iterator<double>(fin),
        istream_iterator<double>(),
        [](double x) { return x > 0.0; }
    );
}

// Найти количество слов длины 6
int countWordsLengthSix(const string& fileName) {
    ifstream fin(fileName);

    return count_if(
        istream_iterator<string>(fin),
        istream_iterator<string>(),
        [](const string& s) { return s.size() == 6; }
    );
}

// Вывести вещественные числа
void printRealNumbers(const double* arr, int n) {
    copy(arr, arr + n, ostream_iterator<double>(cout, " "));
}

// Вывести целые числа из файла
void printIntegersFromFile(const string& fileName) {
    ifstream fin(fileName);

    copy(
        istream_iterator<int>(fin),
        istream_iterator<int>(),
        ostream_iterator<int>(cout, " ")
    );
}

// Записать символы в файл через пробел
void writeCharactersToFile(
    const char* arr,
    int n,
    const string& fileName
) {
    ofstream fout(fileName);

    copy(arr, arr + n, ostream_iterator<char>(fout, " "));
}

// Записать ненулевые числа в файл
void copyNonZeroNumbers(
    const string& inputFile,
    const string& outputFile
) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    remove_copy(
        istream_iterator<int>(fin),
        istream_iterator<int>(),
        ostream_iterator<int>(fout, "\n"),
        0
    );
}

// Записать слова длины не больше K
void copyWordsLengthAtMostK(
    const string& inputFile,
    const string& outputFile,
    int k
) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    remove_copy_if(
        istream_iterator<string>(fin),
        istream_iterator<string>(),
        ostream_iterator<string>(fout, "\n"),
        [k](const string& s) {
            return static_cast<int>(s.size()) > k;
        }
    );
}

// Вывести элементы с нечётными номерами
void printOddPositionElements(const string& fileName) {
    ifstream fin(fileName);

    int pos = 0;

    remove_copy_if(
        istream_iterator<int>(fin),
        istream_iterator<int>(),
        ostream_iterator<int>(cout, " "),
        [&pos](int) {
            return (++pos % 2) == 0;
        }
    );
}

// Вывести элементы с чётными номерами
void printEvenPositionElements(
    const double* arr,
    int n
) {
    int pos = 0;

    remove_copy_if(
        arr,
        arr + n,
        ostream_iterator<double>(cout, " "),
        [&pos](double) {
            return (++pos % 2) != 0;
        }
    );
}

// Заменить нули на 10 и записать в файл
void replaceZerosWithTen(
    const int* arr,
    int n,
    const string& fileName
) {
    ofstream fout(fileName);

    replace_copy(
        arr,
        arr + n,
        ostream_iterator<int>(fout, "  "),
        0,
        10
    );
}

// Вывести символы с заменой цифр на '_'
void replaceDigitsWithUnderscore(
    const char* arr,
    int n
) {
    replace_copy_if(
        arr,
        arr + n,
        ostream_iterator<char>(cout, ""),
        [](char c) {
            return isdigit(static_cast<unsigned char>(c));
        },
        '_'
    );
}

// Записать удвоенные коды символов в файл
void writeDoubledCharacterCodes(
    const char* arr,
    int n,
    const string& fileName
) {
    ofstream fout(fileName);

    transform(
        arr,
        arr + n,
        ostream_iterator<int>(fout, " "),
        [](char c) {
            return 2 * static_cast<int>(c);
        }
    );
}

// Вывести арифметическую прогрессию
void printArithmeticProgression(
    double firstTerm,
    double difference,
    int countTerms
) {
    double current = firstTerm;

    generate_n(
        ostream_iterator<double>(cout, " "),
        countTerms,
        [&current, difference]() {
            double value = current;
            current += difference;
            return value;
        }
    );
}

// Записать первые N заглавных латинских букв
void writeUppercaseLetters(
    const string& fileName,
    int countLetters
) {
    ofstream fout(fileName);

    char letter = 'A';

    generate_n(
        ostream_iterator<char>(fout, " "),
        countLetters,
        [&letter]() {
            return letter++;
        }
    );
}

// Объединить убывающие последовательности
void mergeDescendingSequences(
    const string& firstFile,
    const string& secondFile
) {
    ifstream f1(firstFile);
    ifstream f2(secondFile);

    merge(
        istream_iterator<int>(f1),
        istream_iterator<int>(),
        istream_iterator<int>(f2),
        istream_iterator<int>(),
        ostream_iterator<int>(cout, " "),
        greater<int>()
    );
}

// Объединить слова по длине и лексикографически
void mergeWordsByLength(
    const string& firstFile,
    const string& secondFile
) {
    ifstream f1(firstFile);
    ifstream f2(secondFile);

    auto compareWords = [](const string& a, const string& b) {
        return a.size() < b.size() ||
               (a.size() == b.size() && a < b);
    };

    merge(
        istream_iterator<string>(f1),
        istream_iterator<string>(),
        istream_iterator<string>(f2),
        istream_iterator<string>(),
        ostream_iterator<string>(cout, " "),
        compareWords
    );
}

// Вычислить разности B_i - A_i
void printDifferences(
    const string& firstFile,
    const string& secondFile
) {
    ifstream f1(firstFile);
    ifstream f2(secondFile);

    transform(
        istream_iterator<double>(f1),
        istream_iterator<double>(),
        istream_iterator<double>(f2),
        ostream_iterator<double>(cout, " "),
        [](double a, double b) {
            return b - a;
        }
    );
}

// Объединить слова через дефис и записать в файл
void combineWordsWithHyphen(
    const vector<string>& words,
    const string& inputFile,
    const string& outputFile
) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    transform(
        words.begin(),
        words.end(),
        istream_iterator<string>(fin),
        ostream_iterator<string>(fout, "\n"),
        [](const string& left, const string& right) {
            return left + "-" + right;
        }
    );
}
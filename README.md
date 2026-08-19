# C++ STL exercises

A collection of second-year exercises about the **C++ Standard Template Library
(STL)**: algorithms, iterators, sequence and associative containers. Each file
groups the exercises of one lab (comments in Russian).

## Contents

| File | Topic | Concepts covered |
|---|---|---|
| `lab1_sequential_algorithms.cpp` | Algorithms and iterators | `count`, `count_if`, `copy`, `remove_copy`, `replace_copy`, `transform`, `merge`, `generate_n`, stream iterators (`istream_iterator`, `ostream_iterator`) over arrays and files |
| `lab2_sequence_containers.cpp` | Sequence containers | `vector`, `list`, `deque`: forward/reverse traversal, insertion, splitting into halves/thirds, reverse iterators |
| `lab3_associative_containers.cpp` | Associative containers | `set`, `map`: insertion, lookup, aggregation |
| `lab4_sorting_and_structs.cpp` | Sorting and user types | sorting with custom comparators, a `Point` struct overloading `operator<` and `operator+` |

## Nature of the code

Each file is a **collection of functions** illustrating a concept — there is
intentionally no `main()`: the functions are meant to be read, reused or called
from a test program. They are therefore standalone translation units, not
executables.

## Compilation

The files compile to object modules (no `main` entry point):

```bash
g++ -c -std=c++17 -Wall lab1_sequential_algorithms.cpp
```

To run a specific function, write a small `main()` that calls it, then link it
with the corresponding module:

```bash
g++ -std=c++17 your_test.cpp lab1_sequential_algorithms.cpp -o test && ./test
```

## Build status

All four files compile to objects **without any warning** with
`g++ -std=c++17 -Wall`, verified file by file.

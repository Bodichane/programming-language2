# Exercices STL en C++

Recueil d'exercices de deuxième année portant sur la **bibliothèque standard
C++ (STL)** : algorithmes, itérateurs, conteneurs séquentiels et associatifs.
Chaque fichier regroupe les exercices d'un laboratoire (commentaires en russe).

## Contenu

| Fichier | Thème | Notions couvertes |
|---|---|---|
| `lab1_sequential_algorithms.cpp` | Algorithmes et itérateurs | `count`, `count_if`, `copy`, `remove_copy`, `replace_copy`, `transform`, `merge`, `generate_n`, itérateurs de flux (`istream_iterator`, `ostream_iterator`) sur tableaux et fichiers |
| `lab2_sequence_containers.cpp` | Conteneurs séquentiels | `vector`, `list`, `deque` : parcours direct/inverse, insertion, découpage en moitiés/tiers, itérateurs inverses |
| `lab3_associative_containers.cpp` | Conteneurs associatifs | `set`, `map` : insertion, recherche, agrégation |
| `lab4_sorting_and_structs.cpp` | Tri et types utilisateur | tri avec comparateurs personnalisés, structure `Point` surchargeant `operator<` et `operator+` |

## Nature du code

Chaque fichier est une **collection de fonctions** illustrant une notion — il
n'y a volontairement pas de `main()` : les fonctions sont destinées à être lues,
réutilisées ou appelées depuis un programme de test. Elles constituent donc des
unités de compilation autonomes, pas des exécutables.

## Compilation

Les fichiers se compilent en modules objets (aucun point d'entrée `main`) :

```bash
g++ -c -std=c++17 -Wall lab1_sequential_algorithms.cpp
```

Pour exécuter une fonction précise, écrivez un petit `main()` qui l'appelle,
puis liez-le au module correspondant :

```bash
g++ -std=c++17 votre_test.cpp lab1_sequential_algorithms.cpp -o test && ./test
```

## État de compilation

Les quatre fichiers compilent en objets **sans aucun avertissement** avec
`g++ -std=c++17 -Wall`, vérifié fichier par fichier.

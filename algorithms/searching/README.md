- [1. **Naive String Search Algorithm**](#1-naive-string-search-algorithm)
- [2. **Knuth-Morris-Pratt (KMP) Algorithm**](#2-knuth-morris-pratt-kmp-algorithm)
- [3. **Rabin-Karp Algorithm**](#3-rabin-karp-algorithm)
- [4. **Boyer-Moore Algorithm**](#4-boyer-moore-algorithm)
- [5. **Finite State Machine (FSM)**](#5-finite-state-machine-fsm)
- [6. **Aho-Corasick Algorithm**](#6-aho-corasick-algorithm)
- [7. **Suffix Tree/Array**](#7-suffix-treearray)
- [Summary](#summary)

String searching algorithms are techniques used to find a substring within a larger string (or text). Here are some of the most common string searching algorithms:

## 1. **Naive String Search Algorithm**
- **Description**: The simplest approach, where the algorithm checks every possible position in the text for the substring.
- **Complexity**: O(m * n) in the worst case, where `m` is the length of the substring and `n` is the length of the text.
- **How it works**:
  - Loop through each position in the text.
  - For each position, check if the substring matches starting from that position.

## 2. **Knuth-Morris-Pratt (KMP) Algorithm**
- **Description**: An efficient algorithm that preprocesses the substring to create a longest prefix-suffix (LPS) array, which helps skip unnecessary comparisons.
- **Complexity**: O(m + n) in both average and worst cases.
- **How it works**:
  - Build the LPS array for the substring.
  - Use the LPS array to skip characters in the text when a mismatch occurs.

## 3. **Rabin-Karp Algorithm**
- **Description**: A hashing-based algorithm that uses a hash function to compare the substring and segments of the text.
- **Complexity**: O(n + m) on average; O(n * m) in the worst case due to hash collisions.
- **How it works**:
  - Compute the hash value of the substring.
  - Slide over the text, computing hash values for each substring of the same length and compare them.

## 4. **Boyer-Moore Algorithm**
- **Description**: A highly efficient algorithm that skips sections of the text based on information gathered from the substring and mismatches.
- **Complexity**: O(n/m) in the best case and O(n + m) in the average case.
- **How it works**:
  - Use two heuristics: the bad character rule and the good suffix rule.
  - Upon a mismatch, shift the substring based on these heuristics to skip sections of the text.

## 5. **Finite State Machine (FSM)**
- **Description**: Constructs a state machine based on the substring to efficiently search in the text.
- **Complexity**: O(n) for the search phase, after an O(m * k) preprocessing phase, where `k` is the number of unique characters.
- **How it works**:
  - Build a state machine where each state corresponds to the progress made in matching the substring.
  - Transition between states based on characters in the text.

## 6. **Aho-Corasick Algorithm**
- **Description**: A multi-pattern string matching algorithm that builds a trie of all patterns and processes the text in a single pass.
- **Complexity**: O(n + m + z), where `z` is the number of matches found.
- **How it works**:
  - Construct a trie of the patterns, then create failure links to optimize search.
  - Process the text and transition through the trie, reporting matches as they occur.

## 7. **Suffix Tree/Array**
- **Description**: Data structures that provide a compact representation of all suffixes of a string, allowing for fast searching.
- **Complexity**: O(n) for building; O(m) for searching.
- **How it works**:
  - Construct a suffix tree or array for the text, then perform searches using the structure to find the substring efficiently.

## Summary
Each of these string searching algorithms has its strengths and weaknesses, making them suitable for different applications. The naive approach is simple but inefficient for large texts, while algorithms like KMP, Boyer-Moore, and Aho-Corasick offer more efficient searching capabilities, especially in scenarios involving multiple patterns or large datasets.

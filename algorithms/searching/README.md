
1. [**Naive String Search Algorithm**](naive/README.md)
2. [**Boyer-Moore Algorithm**](Boyer-Moore/README.md)
3. [**Jump search Algorithm**](jump/README.md)
4. [**Binary Search Algorithm**](binary/README.md)
5. [**Linear Search Algorithm**](linear/README.md)
6. [**Interpolation Search Algorithm**](interpolation/README.md)
7. **Knuth-Morris-Pratt (KMP) Algorithm**
8. **Rabin-Karp Algorithm**
9. **Finite State Machine (FSM)**
10. **Aho-Corasick Algorithm**
11. **Suffix Tree/Array**
12. Here are brief explanations and algorithm outlines for string matching algorithms like Boyer-Moore, Naive, Jump Search, Interpolation Search, and Ubiquitous Binary Search.

### 1. **Boyer-Moore Algorithm**

- **Description**: Boyer-Moore is a popular algorithm for string searching that skips sections of the text rather than checking each character. It uses two main heuristics: the **Bad Character** rule and the **Good Suffix** rule.
- **Complexity**: Best case <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mi mathvariant="normal">/</mi><mi>m</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n/m)</annotation></semantics></math>O(n/m), where <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math>n is the text length and <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>m</mi></mrow><annotation encoding="application/x-tex">m</annotation></semantics></math>m is the pattern length. Worst case <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo>⋅</mo><mi>m</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n \cdot m)</annotation></semantics></math>O(n⋅m).

**Steps**:

1. Preprocess the pattern to create a **Bad Character Table** and a **Good Suffix Table**.
2. Start matching from the end of the pattern with the current substring of text.
3. If there is a mismatch, use the tables to decide how far to shift the pattern.
4. Repeat until the pattern is out of the text bounds or a match is found.

### 2. **Naive Algorithm**

- **Description**: The Naive algorithm is a straightforward approach where the pattern is matched with every substring of the text.
- **Complexity**: <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo>⋅</mo><mi>m</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n \cdot m)</annotation></semantics></math>O(n⋅m) for both the best and worst cases.

**Steps**:

1. Loop through the text from the start to the position <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi><mo>−</mo><mi>m</mi></mrow><annotation encoding="application/x-tex">n - m</annotation></semantics></math>n−m (the last position where the pattern can match).
2. For each position, compare the substring of length <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>m</mi></mrow><annotation encoding="application/x-tex">m</annotation></semantics></math>m to the pattern.
3. If a match is found, record the position and continue to the next position.
4. If no match is found, continue to the next substring.

### 3. **Jump Search**

- **Description**: Jump Search is generally used for sorted arrays, not string matching. However, in the context of string searching, you can interpret "jumping" as moving by fixed intervals in the text to check for a substring match, and then doing linear search within the interval.
- **Complexity**: <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><msqrt><mi>n</mi></msqrt><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(\sqrt{n})</annotation></semantics></math>O(n<svg xmlns="http://www.w3.org/2000/svg" width="400em" height="1.08em" viewbox="0 0 400000 1080" preserveaspectratio="xMinYMin slice"><path d="M95,702
c-2.7,0,-7.17,-2.7,-13.5,-8c-5.8,-5.3,-9.5,-10,-9.5,-14
c0,-2,0.3,-3.3,1,-4c1.3,-2.7,23.83,-20.7,67.5,-54
c44.2,-33.3,65.8,-50.3,66.5,-51c1.3,-1.3,3,-2,5,-2c4.7,0,8.7,3.3,12,10
s173,378,173,378c0.7,0,35.3,-71,104,-213c68.7,-142,137.5,-285,206.5,-429
c69,-144,104.5,-217.7,106.5,-221
l0 -0
c5.3,-9.3,12,-14,20,-14
H400000v40H845.2724
s-225.272,467,-225.272,467s-235,486,-235,486c-2.7,4.7,-9,7,-19,7
c-6,0,-10,-1,-12,-3s-194,-422,-194,-422s-65,47,-65,47z
M834 80h400000v40h-400000z"></path></svg>​) on average for sorted arrays.

**Steps**:

1. Choose a jump interval size <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>k</mi><mo>=</mo><msqrt><mi>n</mi></msqrt></mrow><annotation encoding="application/x-tex">k = \sqrt{n}</annotation></semantics></math>k=n<svg xmlns="http://www.w3.org/2000/svg" width="400em" height="1.08em" viewbox="0 0 400000 1080" preserveaspectratio="xMinYMin slice"><path d="M95,702
c-2.7,0,-7.17,-2.7,-13.5,-8c-5.8,-5.3,-9.5,-10,-9.5,-14
c0,-2,0.3,-3.3,1,-4c1.3,-2.7,23.83,-20.7,67.5,-54
c44.2,-33.3,65.8,-50.3,66.5,-51c1.3,-1.3,3,-2,5,-2c4.7,0,8.7,3.3,12,10
s173,378,173,378c0.7,0,35.3,-71,104,-213c68.7,-142,137.5,-285,206.5,-429
c69,-144,104.5,-217.7,106.5,-221
l0 -0
c5.3,-9.3,12,-14,20,-14
H400000v40H845.2724
s-225.272,467,-225.272,467s-235,486,-235,486c-2.7,4.7,-9,7,-19,7
c-6,0,-10,-1,-12,-3s-194,-422,-194,-422s-65,47,-65,47z
M834 80h400000v40h-400000z"></path></svg>​.
2. Move through the text by increments of <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>k</mi></mrow><annotation encoding="application/x-tex">k</annotation></semantics></math>k, checking only at multiples of <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>k</mi></mrow><annotation encoding="application/x-tex">k</annotation></semantics></math>k.
3. Once within an interval where the pattern might exist, perform a linear search within that block.

### 4. **Interpolation Search** (Not typically for strings)

- **Description**: Interpolation Search is used for numerical data where the value is directly correlated to the index. It's less applicable to general string matching, but in the context of string searching, it could mean using a formula based on the expected character distribution to "guess" where a substring might begin.
- **Complexity**: Best case <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>log</mi><mo>⁡</mo><mi>log</mi><mo>⁡</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(\log \log n)</annotation></semantics></math>O(loglogn) and worst case <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(n)</annotation></semantics></math>O(n).

**Steps**:

1. Find an estimated position in the text by calculating a formula based on the distribution of characters.
2. If the match is not found, adjust the bounds to the left or right depending on whether the current substring is lexicographically less than or greater than the pattern.
3. Repeat until a match is found or the bounds converge.

### 5. **Ubiquitous Binary Search** (Binary Search in Pattern Matching Context)

- **Description**: Ubiquitous Binary Search is a more adaptive form of binary search. It’s designed for situations where the function to evaluate the mid-point differs and includes function-based checks, rather than simple mid-point comparisons.
- **Complexity**: <math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>O</mi><mo stretchy="false">(</mo><mi>log</mi><mo>⁡</mo><mi>n</mi><mo stretchy="false">)</mo></mrow><annotation encoding="application/x-tex">O(\log n)</annotation></semantics></math>O(logn) for standard binary search, with adaptations as necessary for the function evaluated.

**Steps**:

1. Implement binary search, but rather than only looking for exact matches, allow for the function evaluation at the mid-point to influence how you adjust the bounds.
2. Update the bounds based on the criteria defined by the function for the substring search.
3. Continue until you narrow down the bounds to find an exact match or determine that it doesn’t exist.

For actual string matching, **Boyer-Moore** and **Naive** are generally the most applicable algorithms. The **Jump Search**, **Interpolation Search**, and **Ubiquitous Binary Search** algorithms are typically used in sorted data contexts rather than direct string matching but can be adapted for specialized or pre-processed string searching scenarios.

# Competitive Programming Solutions

![Solutions](https://img.shields.io/badge/Solutions-78-blue.svg?style=flat-square)
![Standard](https://img.shields.io/badge/C%2B%2B-20-brightgreen.svg?style=flat-square)
![Compiler](https://img.shields.io/badge/GCC-16%2B-orange.svg?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-purple.svg?style=flat-square)

A structured, high-performance competitive programming repository featuring verified problem solutions, reusable algorithm libraries, automated test runners, debugging utilities, and contest scaffolding.

---

## Solutions Overview

<!-- STATS_TABLE_START -->
| Platform | Directory | Solved | Link |
| :--- | :--- | :---: | :--- |
| **AtCoder** | [`atcoder/`](atcoder/) | `36` | [Website](https://atcoder.jp) |
| **Codeforces** | [`CodeForces/`](CodeForces/) | `20` | [Website](https://codeforces.com) |
| **CSES** | [`CSES/`](CSES/) | `19` | [Website](https://cses.fi/problemset/) |
| **USACO** | [`USACO/`](USACO/) | `1` | [Website](http://www.usaco.org) |
| **Roadmap / Basics** | [`AlgorithmRoadmap/`](AlgorithmRoadmap/) | `2` | - |
| **Total** | | **`78`** | |
<!-- STATS_TABLE_END -->

---

## Quickstart: The `cprun` CLI

A zero-dependency CLI tool is included in the root directory to streamline compiling, testing, debugging, stress testing, and scaffolding solutions.

### 1. Compile & Run (Auto-detects Input)
Compiles with `-O2 -std=c++20 -DLOCAL` into `.build/` (keeping solution directories clean) and runs against local input:
```bash
./cprun run CodeForces/1669/G.cpp
```
*Note: If an `inp`, `input.txt`, or `<name>.in` file exists in the problem directory, `cprun` automatically feeds it into stdin!*

### 2. Debug with AddressSanitizer & UBSan
Compiles with `-fsanitize=address,undefined -g` to detect segmentation faults, out-of-bounds indexing, and integer overflows with full stack traces:
```bash
./cprun debug CodeForces/1669/G.cpp
```

### 3. Scaffold a New Contest or Problem
Creates the folder and populates all problem files with the starter template:
```bash
# Codeforces: creates CodeForces/1900/{A.cpp, B.cpp, C.cpp, D.cpp, inp}
./cprun new cf 1900 A B C D

# AtCoder: creates atcoder/abc395/{a.cpp, b.cpp, c.cpp, d.cpp, inp}
./cprun new atcoder abc395 a b c d

# CSES: creates CSES/1092.cpp
./cprun new cses 1092
```

### 4. Stress Testing
Automatically compares your solution against a brute-force solution using a random generator until a counterexample is found:
```bash
./cprun stress solution.cpp brute.cpp generator.cpp -n 500
```
When an output mismatch occurs, the failing test case is displayed immediately and saved to `cmp_fail.in`.

### 5. Check Stats & Update README
```bash
./cprun stats
python3 scripts/update_readme.py
```

---

## Templates & Local Debugging

### Template: `templates/template.cpp`
Includes fast I/O, `ckmin`/`ckmax` helpers, standard aliases (`ll`, `ar`, `db`), and `#ifdef LOCAL` debug hooks.

### Debug Macro: `templates/debug.h`
Supports printing primitives, pairs, tuples, vectors, arrays, maps, and sets to `stderr` with ANSI syntax highlighting:
```cpp
int x = 42;
vector<int> v = {1, 2, 3};
map<string, int> mp = {{"apple", 5}};
dbg(x, v, mp);
// Output: [solution.cpp:25] x = 42, v = [1, 2, 3], mp = [("apple", 5)]
```
> [!TIP]
> When submitted to online judges (without `-DLOCAL`), `dbg(...)` evaluates to a complete no-op with zero runtime overhead and requires no manual deletion before submission.

---

## Reusable Library (`library/`)

Ready-to-use, tested data structures and algorithms:

- **Data Structures**
  - [`library/data_structures/fenwick_tree.hpp`](library/data_structures/fenwick_tree.hpp) — 1D Fenwick Tree / Binary Indexed Tree (point add, prefix query).
  - [`library/data_structures/segment_tree.hpp`](library/data_structures/segment_tree.hpp) — Iterative Segment Tree (point update, range query).
  - [`library/data_structures/dsu.hpp`](library/data_structures/dsu.hpp) — Disjoint Set Union with path compression & component tracking.
- **Math & Number Theory**
  - [`library/math/modular.hpp`](library/math/modular.hpp) — Modular arithmetic `ModInt<MOD>` (`Mint` for $10^9+7$, `Mint998` for $998244353$).
  - [`library/math/sieve.hpp`](library/math/sieve.hpp) — Linear Sieve with smallest prime factor (SPF) and $O(\log N)$ prime factorization.
- **Graphs**
  - [`library/graphs/dijkstra.hpp`](library/graphs/dijkstra.hpp) — Dijkstra's single-source shortest path algorithm.
  - [`library/graphs/lca.hpp`](library/graphs/lca.hpp) — Lowest Common Ancestor (LCA) using Binary Lifting.

---

## Editor & LSP Integration

This directory is pre-configured for **Neovim** (LazyVim / clangd) and standard language servers:
- `.clang-format`: Formats C++ code with 2-space indentation and clean bracket conventions.
- `compile_flags.txt`: Configures `clangd` with C++20 standard, include paths (`templates/`, `library/`), and `-DLOCAL`.

### Optional Shell Alias
Add this to your `~/.bashrc` or `~/.zshrc` for fast access anywhere in your terminal:
```bash
alias cprun="/home/patryk_pc/Projects/whitebox/cprun"
```

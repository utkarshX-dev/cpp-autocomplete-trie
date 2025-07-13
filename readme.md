# Trie AutoComplete

A C++ command-line tool for fast word auto-completion using a Trie data structure.

## Features
- Instant prefix-based word suggestions
- Persistent word storage (`words.txt`)
- Add new words dynamically

## Technologies
C++, STL, File I/O, OOP

## Usage
1. Build the project using a C++ compiler.
2. Run the executable.
3. Follow the menu to search or insert words.

## Files
- `main.cpp` — CLI logic
- `trie.cpp` — Trie implementation
- `trieNode.cpp` — Trie node structure
- `words.txt` — Dictionary file

## How to Run

1. Open a terminal in the project directory.
2. Compile the code:
   ```
   g++ main.cpp trie.cpp -o autocomplete
   ```
3. Run the executable:
   ```
   ./autocomplete
   ```
   On Windows, use:
   ```
   autocomplete.exe
   ```
4. Follow the on-screen menu to search or insert words.
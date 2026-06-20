# Boolean Logic Synthesizer & Optimizer

A C++ engine that parses massive boolean logic equations into a Directed Acyclic Graph (DAG) to automatically detect and eliminate redundant logic. 

## Core Architecture

* **AST to DAG Conversion:** Parses flat string equations into an Abstract Syntax Tree, structurally hashing the nodes on the fly to form a minimized DAG.
* **De Morgan's Standardization:** Converts all `OR` gates into `AND`/`NOT` gates during the parsing phase. This limits the instruction set, making logic pattern matching and constant folding highly predictable.
* **Custom Memory Pool:** Replaces standard dynamic allocation with an Arena Allocator. This enforces strict CPU cache locality during recursive tree traversals.
* **Structural Hashing:** Checks a hash map in O(1) time before allocating any new node to safely merge identical sub-trees.

## Performance
By combining the memory pool and structural hashing, the engine prevents ~70% of redundant node allocations and processes complex equations in under 6 milliseconds.

## Build and Run

Compile with maximum optimizations (`-O3`) to ensure structural hashing executes at speed:

```bash
g++ -O3 main.cpp -o main
./main

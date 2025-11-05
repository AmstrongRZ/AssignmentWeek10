# Graphy-Theory_Algorithms-Implementation
Coding project to implement Hungarian Algorithm and Welsh-Powell Algorithm

### Group 5
Ardian Saptaguna Yudistira (5025241079)

Amstrong Roosevelt Zamzami(5025211191)

Dzaky Hasbullah Wahyudi (5025211264)

# Welsh–Powell Graph Coloring (C++ Implementation)

This project implements the **Welsh–Powell Algorithm** for **graph coloring** in C++.  
It assigns colors to graph nodes so that no two adjacent nodes share the same color, minimizing the total number of colors used.  
Additionally, it generates a **Graphviz** visualization of the colored graph.

---

## Algorithm Overview

The **Welsh–Powell Algorithm** is a greedy graph coloring method:

1. Sort vertices in **descending order of degree** (number of connections).
2. Assign the **first color** to the first vertex.
3. For each remaining vertex, assign the **same color** if it’s not adjacent to any vertex of that color.
4. Repeat with new colors until all vertices are colored.

---

## Features

- Reads custom **nodes** and **edges with cost**  
- Outputs **node–color mappings**  
- Generates a **Graphviz `.dot` file**  
- Auto-produces a **PNG graph visualization** (if Graphviz is installed)  
- Clean, simple C++ implementation with clear console output

---

## Requirements

- **C++17 or newer**
- **Graphviz**

### Install Graphviz
#### 🐧 Linux / macOS
```bash
sudo apt install graphviz
# or
brew install graphviz

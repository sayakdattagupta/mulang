<p align="center">
  <a href="https://git.io/typing-svg">
    <img src="https://readme-typing-svg.demolab.com?font=IBM+Plex+Sans&weight=800&size=40&duration=3000&pause=1000&color=F7D544&center=true&vCenter=true&width=434&lines=%CE%BC_Lang" alt="Typing SVG" />
  </a>
</p>

Lightweight, ahead-of-time compiled language written in pure C that currently targets x86_64 assembly code.

---

# Features
- Precedence Climbing/Pratt Parsing
- Can target different architectures by simple modification of cg.c and gen.c files
- Single-pass statement processing
- Basic error and syntax diagnostics

## Operators
- `+`
- `-`
- `*`
- `/`

## Keywords
- `print`
- `;`

## Example
`print 2*3+5;`

# Getting Started
## Prerequisites
- GCC
- GNU Make
- x86_64 Linux environment

## Running
`make` and then `make test` runs the test/in.txt file. Modify the makefile to target different files or just modify the in.txt file.

Use `make clean` to clean up build artifacts.

# TO-DO
- Variables
- Control flow structures (while, if-else, and for loops).
- Achieving bootstrap/self-hosting.

# License
Distributed under the GNU GPLv3.0 License.

# CRC Coursework

C++ assignments and labs for Cosumnes River College computer science courses.

## Courses

| Course | Description | Work |
|--------|-------------|------|
| CISP 310 | Discrete Structures | Labs 03–10 |
| CISP 360 | C++ Programming I | Labs 01–10 |
| CISP 400 | Object-Oriented Programming with C++ | Assignments A1–A7 |
| CISP 430 | Data Structures | Assignment A1 |

## Structure

```
cisp310/        # Lab exercises (text-based)
cisp360/        # C++ lab programs
cisp400/        # OOP assignments (classes, inheritance, templates)
cisp430/        # Data structures assignments
```

## Build

Each lab/assignment compiles with g++:

```bash
g++ -std=c++17 -o output filename.cpp
```

Multi-file projects (e.g. cisp400/A6) compile all sources together:

```bash
g++ -std=c++17 -o output *.cpp
```

## Author

Dinh Nguyen Le — nguyenld.work@gmail.com

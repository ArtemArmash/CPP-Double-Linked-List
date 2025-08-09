# C++ Doubly Linked List Implementation

This repository contains a robust, optimized, and memory-safe implementation of a generic Doubly Linked List in modern C++. This project demonstrates a deep understanding of dynamic memory management, advanced C++ concepts, and the efficiency of data structure design.

## Features

-   **Generic Templated Design (`DoublyLinkedList<T>`):** Supports any data type.
-   **Full Set of Operations:**
    -   `push_back()`, `push_front()`: Optimized for O(1) complexity.
    -   `pop_back()`, `pop_front()`: Efficient removal of head and tail elements.
    -   `insert(value, index)`: Inserts an element at a specific index.
    -   `erase(index)`: Removes an element by index.
    -   `find(value)`: Searches the list.
    -   `reverse()`: Reverses the list in-place.
-   **Optimized Indexing (`operator[]`):** Implements bidirectional traversal for O(N/2) average time complexity. Access from `head` for the first half of the list and from `tail` for the second half.
-   **Safe Access:**
    -   `operator[]` is overloaded for both const and non-const objects.
    -   Includes bounds checking, throwing `std::out_of_range` for invalid indices.
-   **Robust Memory Management:**
    -   **Rule of Three/Five Compliance:** Implements a deep copy constructor and assignment operator (`operator=`) to prevent shallow copying issues.
    -   **RAII Destructor:** Properly deallocates all nodes via `clear()` to prevent memory leaks.

## Core Concepts Demonstrated

-   **Dynamic Memory Management:** Correct use of `new` and `delete`.
-   **Pointers (pNext and pPrev):** Complex manipulation of bidirectional pointers.
-   **Templates:** Generic programming for type safety and reusability.
-   **Algorithmic Optimization:** Implementing O(1) append/prepend and O(N/2) indexing.
-   **Object-Oriented Programming:** Encapsulation via nested `struct Node`.
-   **Operator Overloading:** Customizing `operator[]` and `operator=`.

## How to Build and Run

This project is intended to be compiled with a modern C++ compiler (like g++ or Clang) supporting C++11 or newer.

```bash
# Clone the repository
git clone https://github.com/ArtemArmash/CPP-Double-Linked-List

# Compile (assuming your main code is in main.cpp)
g++ main.cpp -o doubly_linked_list_test -std=c++11

# Run the test
./doubly_linked_list_test
```

```

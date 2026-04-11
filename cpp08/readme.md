# CPP Module 08 – Complete Summary (42 School)

## Overview

This module introduces you to:

* STL containers
* Iterators
* Algorithms
* Templates
* Container adapters

You learned how to work with real C++ STL behavior and extend it safely.

---

# Ex00 – easyfind

## Goal

Find a value inside a container.

## Key idea

Use STL algorithm:

```cpp
std::find(begin, end, value);
```

## Requirements

* Function works with any container (vector, list, deque)
* Return iterator to found element
* Throw exception if not found

## Template function

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value);
```

## Important concepts

* Iterators
* std::find from <algorithm>
* Templates

---

# Ex01 – Span

## Goal

Store numbers and compute:

* shortest span
* longest span

---

## Key idea

A span = difference between two numbers.

---

## Functions

### Add one number

```cpp
void addNumber(int n);
```

### Add range of numbers

```cpp
template <typename Iterator>
void addNumber(Iterator begin, Iterator end);
```

---

## Shortest span

Steps:

1. Copy container
2. Sort it
3. Compare adjacent elements

```cpp
std::sort(tmp.begin(), tmp.end());
```

---

## Longest span

```cpp
max_element - min_element
```

---

## Important concepts

* std::sort
* std::min_element / std::max_element
* std::distance
* STL ranges

---

# Ex02 – MutantStack

## Goal

Create a stack that is iterable.

---

## Problem with std::stack

* No iterators
* Only LIFO access (top)

---

## Solution

Expose underlying container:

```cpp
this->c
```

---

## Internal structure

std::stack uses:

```cpp
std::deque<T>
```

So real storage is:

```text
[bottom -> top]
```

---

## Key implementation

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};
```

---

## Behavior difference

### Stack view (LIFO)

```text
top = last element
```

### Iteration view (container order)

```text
first inserted → last inserted
```

---

## Example

```cpp
push(8)
push(5)
push(3)
```

Iteration output:

```text
8
5
3
```

Top:

```text
3
```

---

## Comparison requirement (VERY IMPORTANT)

You must show that:

* MutantStack behaves like stack
* std::list behaves similarly when iterated

---

## list vs MutantStack idea

### MutantStack

```cpp
push()
begin()
end()
```

### list

```cpp
push_back()
begin()
end()
```

Both produce same iteration output.

---

# Important STL Concepts Learned

## 1. Containers

* vector
* list
* deque

## 2. Iterators

* begin / end
* range [begin, end)

## 3. Algorithms

* std::find
* std::sort
* std::min_element
* std::max_element

## 4. Templates

* generic functions
* range iterators

## 5. Container adapters

* std::stack
* underlying container access

---

# Common Mistakes

* Using .cpp for template functions ❌
* Forgetting <algorithm> ❌
* Using maxSize instead of size() ❌
* Not initializing variables ❌
* Confusing stack order with iteration order ❌

---

# Evaluation Checklist

You must be able to:

✔ Use STL algorithms correctly
✔ Work with iterators
✔ Implement template functions
✔ Understand container behavior
✔ Extend std::stack safely
✔ Compare STL containers behavior

---

# Final Mental Model

* stack = restricted interface
* deque = real storage
* iterator = way to traverse storage
* MutantStack = stack + iterator access

---

# What you should now know to finish CPP08

1. How iterators work
2. How STL containers store data
3. How to use STL algorithms
4. How to write template functions
5. How to expose underlying containers safely
6. Difference between interface vs implementation

---

# End of CPP08 Guide

You are now ready for evaluation if you understand all sections above.

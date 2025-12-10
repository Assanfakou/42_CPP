# CPP02 - Ad Hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

## Table of Contents
- [Overview](#overview)
- [What I Learned](#what-i-learned)
- [Exercises](#exercises)
- [Key Concepts](#key-concepts)
- [Resources](#resources)
- [Compilation](#compilation)

---

## Overview

This module introduces ad hoc polymorphism in C++, focusing on operator overloading and the Orthodox Canonical Form. The main goal is to understand how to make custom classes behave like built-in types and implement the fundamental structure that every C++ class should follow.

**Key Topics:**
- Orthodox Canonical Form (Rule of Three)
- Operator overloading
- Fixed-point arithmetic
- Member vs non-member functions
- Const correctness

---

## What I Learned

### Orthodox Canonical Form

Every C++ class should implement four essential methods to handle object lifecycle properly:

1. **Default Constructor** - Initializes an object with default values
2. **Copy Constructor** - Creates a new object as a copy of an existing one
3. **Copy Assignment Operator** - Assigns the value of one existing object to another
4. **Destructor** - Cleans up resources when an object is destroyed

```cpp
class Fixed {
    public:
        Fixed();                                    // Default constructor
        Fixed(const Fixed& other);                  // Copy constructor
        Fixed& operator=(const Fixed& other);       // Copy assignment operator
        ~Fixed();                                   // Destructor
};
```

This pattern ensures classes handle copying and resource management correctly, preventing memory leaks and undefined behavior.

### Operator Overloading

I learned how to overload operators to make custom classes work naturally with C++ syntax:

- **Comparison operators**: `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Arithmetic operators**: `+`, `-`, `*`, `/`
- **Increment/decrement**: `++`, `--` (both prefix and postfix)
- **Stream insertion**: `<<` for easy printing
- **Assignment operators**: `=`

The key insight is that operators are just functions with special syntax. Overloading them makes your classes intuitive to use.

```cpp
Fixed operator+(const Fixed& lhs, const Fixed& rhs);
bool operator<(const Fixed& lhs, const Fixed& rhs);
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
```

### Fixed-Point Numbers

I implemented a Fixed class representing numbers using fixed-point arithmetic instead of floating-point. This taught me:

- How computers represent fractional numbers
- The trade-offs between precision and range
- Bit manipulation and shifting operations
- When fixed-point is preferred over floating-point (embedded systems, financial calculations)

**How it works:**
Fixed-point numbers store an integer value that represents a real number scaled by a power of 2. For example, with 8 fractional bits, the value 256 represents 1.0 (256 / 2^8 = 1.0).

### Member vs Non-Member Functions

I learned when to implement operators as member functions versus non-member functions:

- **Member functions**: When the left operand is always your class type (assignment, compound assignment)
- **Non-member functions**: When you need symmetry or when the left operand might be a different type (arithmetic, comparison)

---

## Exercises

### ex00: My First Class in Orthodox Canonical Form

Basic implementation of a Fixed class with the four required methods. Established the foundation for all subsequent exercises.

**What it does:**
- Implements default constructor, copy constructor, copy assignment operator, and destructor
- Stores a fixed-point value as an integer
- Uses a static constant for the number of fractional bits

### ex01: Towards a More Useful Fixed-Point Number Class

Extended the Fixed class with constructors accepting different types and conversion functions.

**What it does:**
- Constructor accepting an integer
- Constructor accepting a floating-point number
- Conversion to integer (`toInt()`)
- Conversion to float (`toFloat()`)
- Overloaded insertion operator (`<<`) for output streams

### ex02: Now We're Talking

Implemented the full set of comparison and arithmetic operators. This is where the class became truly usable.

**What it does:**
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/decrement: `++`, `--` (prefix and postfix)
- Static member functions: `min()`, `max()` (with const overloads)

### ex03: BSP (Binary Space Partitioning)

**Not completed**, but would have applied the Fixed class to determine if a point lies inside a triangle using coordinate geometry. The concept involves:

- Representing 2D points with Fixed-point coordinates
- Using cross products to determine point position relative to triangle edges
- Applying the sign of cross products to check if a point is on the same side of all three edges

---

## Key Concepts

### Shallow vs Deep Copy
Understanding when you need to allocate new memory in copy operations versus just copying values. For classes managing dynamic memory, you need deep copying.

### Const Correctness
Methods that don't modify the object should be marked `const`. This is crucial for operator overloading and allows your objects to be used in const contexts.

```cpp
int toInt() const;  // This method doesn't modify the object
```

### Return Types Matter
- Assignment operators return references: `Fixed& operator=(const Fixed& other)`
- Arithmetic operators return new objects: `Fixed operator+(const Fixed& lhs, const Fixed& rhs)`
- Getting this wrong leads to bugs and inefficiency

### Orthodox Canonical Form is Non-Negotiable
Even if you think you don't need all four methods, implement them. The compiler will generate them for you anyway, and they might not do what you expect. Explicit is better than implicit.

### Prefix vs Postfix Increment
- Prefix (`++i`): Increments and returns the new value
- Postfix (`i++`): Returns the old value, then increments

```cpp
Fixed& operator++();        // Prefix: returns reference
Fixed operator++(int);      // Postfix: dummy int parameter, returns copy
```

---

## Resources

### Official Documentation
- [C++ Reference - Operators](https://en.cppreference.com/w/cpp/language/operators) - Complete reference for all C++ operators
- [C++ Reference - Rule of Three](https://en.cppreference.com/w/cpp/language/rule_of_three) - Explains the Orthodox Canonical Form
- [C++ Reference - Operator Overloading](https://en.cppreference.com/w/cpp/language/operators) - Detailed guide on overloading each operator

### Tutorials and Articles
- [LearnCpp - Operator Overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/) - Comprehensive tutorial series
- [GeeksforGeeks - Operator Overloading](https://www.geeksforgeeks.org/operator-overloading-c/) - Examples and explanations
- [Canonical Form in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/) - Understanding copy constructors and assignment

### Fixed-Point Arithmetic
- [Fixed-Point Arithmetic Basics](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) - Berkeley CS course notes
- [Understanding Q Format](https://en.wikipedia.org/wiki/Q_(number_format)) - Q notation for fixed-point numbers
- [Fixed-Point Math](http://x86asm.net/articles/fixed-point-arithmetic-and-tricks/) - Implementation tricks and techniques

### Videos and Courses
- Search "C++ operator overloading tutorial" on YouTube for visual explanations
- "The Rule of Three/Five/Zero" - Talks explaining when and why you need special member functions
- CppCon talks on operator overloading and class design

### Books
- "Effective C++" by Scott Meyers - Items on operator overloading and resource management
- "C++ Primer" by Lippman, Lajoie, and Moo - Chapter on overloaded operations

### 42 Network
- Fellow students who've completed CPP02
- 42 Slack channels for CPP discussions
- Peer evaluations and feedback

---

## Compilation

Each exercise has its own Makefile. To compile:

```bash
cd ex00  # or ex01, ex02, ex03
make
./program_name
```

To clean object files:
```bash
make clean
```

To clean everything including the executable:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

---

## Notes

This module is foundational for understanding how C++ classes should be structured and how to make them work seamlessly with the language's syntax. The concepts learned here about resource management, operator overloading, and proper class design will be used throughout all remaining CPP modules.

The Orthodox Canonical Form is the bedrock of safe C++ class design. Master it here, and you'll avoid countless bugs in future projects.

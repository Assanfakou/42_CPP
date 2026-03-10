# C++ Templates – Complete Concept Answers (CPP07)

This document answers all the essential conceptual questions about **C++ templates**, with a strong focus on **memory, compilation, and CPP07 expectations (C++98)**.

---

## 1. Fundamental template concepts

**1. What is a template in C++?**  
A template is a **compile-time blueprint** used by the compiler to generate real code when a concrete type is provided.

**2. When does a template become real code?**  
At **compile time**, when the template is instantiated with a real type (e.g., `Array<int>`).

**3. Why does the compiler need the full template definition at the point of use?**  
Because the compiler must see the entire implementation to generate concrete code for the specific type.

**4. Why can’t templates be compiled separately like normal `.cpp` files?**  
Because templates are not real code until instantiated, and instantiation happens where they are used.

**5. What is template instantiation?**  
The process where the compiler generates real classes or functions from a template using a specific type.

**6. Is `Array<int>` the same type as `Array<float>`?**  
No. They are completely different types with separate generated code.

---

## 2. Memory & instantiation

**7. How many copies of a template function exist if used with 3 types?**  
Three separate copies—one per type.

**8. Do `Array<int>` and `Array<float>` share memory or code?**  
No. Each has its own generated code and memory layout.

**9. Where does the template object itself live?**  
On the stack (unless dynamically allocated with `new`).

**10. Where does dynamically allocated data inside a template class live?**  
On the heap.

**11. Does the template itself occupy memory before instantiation?**  
No. Only instantiated templates generate memory usage.

---

## 3. Templates vs runtime polymorphism

**12. Why are templates compile-time polymorphism?**  
Because type resolution and code generation happen at compile time.

**13. Do templates use virtual tables?**  
No. Templates do not use vtables.

**14. Why are templates usually faster than virtual functions?**  
Because there is no runtime dispatch; calls are resolved at compile time.

**15. Can templates replace inheritance?**  
Yes, when behavior depends on type rather than runtime object hierarchy.

---

## 4. Function templates

**16. How does the compiler deduce template type `T`?**  
From the function arguments passed to the template.

**17. What happens if deduction fails?**  
Compilation fails with a template error.

**18. Can you explicitly specify a template type?**  
Yes, when deduction is ambiguous or impossible.

**19. Why must comparison operators exist for template types?**  
Because the template code uses them; unsupported operations cause compilation errors.

**20. What happens if a template uses an unsupported operation?**  
Compilation fails at instantiation.

---

## 5. Class templates (CPP07 core)

**21. Why must class template implementations be in `.hpp`?**  
So the compiler can generate code during instantiation.

**22. What happens if a method of a class template is never used?**  
No code is generated for it.

**23. Does the compiler generate code for unused methods?**  
No. Only used methods are instantiated.

**24. Why does `operator[]` return `T&`?**  
To allow modification of elements without copying.

**25. Why provide const and non-const `operator[]`?**  
To preserve const correctness.

---

## 6. Const correctness in templates

**26. Why does `const Array<T>` need a different `operator[]`?**  
Because it must prevent modification of elements.

**27. How does `const T&` help templates?**  
It avoids unnecessary copies and supports more types.

**28. What breaks if const correctness is ignored?**  
Compilation errors or unsafe modifications.

---

## 7. Errors & debugging templates

**29. Why are template errors long and confusing?**  
Because errors propagate through many instantiations.

**30. Why does a small mistake explode into many errors?**  
Because the compiler retries instantiation in multiple contexts.

**31. Why do template errors appear at instantiation?**  
Because that’s when code is actually generated.

**32. Why does “undefined reference” often mean “template not visible”?**  
Because the compiler couldn’t generate code during compilation.

---

## 8. C++98-specific (42 rules)

**33. Why can’t you use `nullptr` in C++98?**  
Because it was introduced in C++11.

**34. Why must template methods be written as `Array<T>::method`?**  
Because templates require explicit type context.

**35. Why do you sometimes need `typename`?**  
To tell the compiler that a dependent name is a type.

---

## 9. Design understanding

**36. When should you use a template?**  
When behavior depends on type at compile time.

**37. When should you not use a template?**  
When behavior must vary at runtime.

**38. What are the downsides of templates?**  
Long errors, larger binaries, slower compilation.

**39. Why can templates increase binary size?**  
Because each type generates its own code.

**40. Why is `std::vector` a template?**  
To work with any data type efficiently.

---

End of document.


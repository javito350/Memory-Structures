# Reflective Report

> In your own words, describe the difference between an `array` and a `linked list`.

An `array` stores elements in memory locations with a fixed size determined at creation, allowing direct access to any element via its index in constant time. A `linked list` stores elements in nodes scattered throughout memory, where each node contains data and a pointer to the next node, allowing dynamic size changes but requiring sequential traversal to access elements.

> Describe the relationship between `linked list`s and the `heap`.

Linked lists typically store their nodes on the `heap` because their size is dynamic and unknown at compile time. Each node is individually allocated using `malloc`, allowing the list to grow or shrink during program execution. This contrasts with stack allocation, which requires knowing the size beforehand and has limited space.

> In order to access memory on the `stack` or `heap`, we need to user `pointer`s. 
> What is a pointer? How is it useful? Why do you think we need to use them at all?

A `pointer` is a variable that stores a memory address rather than a direct value. Pointers are useful because they allow us to reference and manipulate data located anywhere in memory, enable dynamic memory allocation, and facilitate passing large data structures efficiently by reference rather than by value. We need pointers to work with heap memory since heap-allocated data doesn't have direct variable names—we can only access it through the addresses returned by allocation functions.

> `C` features a command that allows us to allocate memory in the heap (`malloc`). Speculate: why
> would we need a command to do that? What implication(s) does this have for memory usage?

> Hint: consider the idea of a `stack` growing infinitely on our device. If the heap can grow infinitely
> large, what might this mean?

We need `malloc` because heap memory must be explicitly requested and managed—unlike stack memory which is automatically allocated and deallocated. This gives us control over when and how much memory to use, but it also means we're responsible for freeing it with `free` to prevent memory leaks. If we don't manage heap memory properly, it can grow indefinitely and exhaust system resources, potentially causing the program or system to crash. This manual management is the tradeoff for having flexible, dynamic memory allocation.
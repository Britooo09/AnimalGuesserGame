# Project Guidelines

This document defines the rules for ensuring that the code is consistent and easy to integrate.

## References

Here are some useful resources:

* https://github.com/WoXy-Sensei/c-tree-data-structure/tree/main
* https://medium.com/@muskansanghai/trees-in-c-a-beginners-guide-to-understanding-and-implementing-fd0fc6026035
* https://alokgupta.hashnode.dev/understanding-and-implementing-tree-data-structures-in-c
* https://www.programiz.com/dsa/trees
* https://www.geeksforgeeks.org/dsa/tree-data-structure/
* https://www.geeksforgeeks.org/cpp/binary-tree-in-cpp/
* https://prepbytes.com/blog/data-structures-in-c-trees-graph-3/

## Important

In order to port the code to Qt without completely rewriting it, **the tree logic must not know that a screen exists**.

`cout` and `cin` should be avoided within logical functions. Instead of a function requesting data, the function should receive the data already prepared; that is, it should work with arguments, not directly requesting data.

For example:
* **Console version**: `main` (or a disposable function) requests the data via the console and passes it to the function in question as arguments, such as: `function(arg1, arg2, arg3)`.
* **Qt Version**: The Qt window requests the data in a form and passes it to the same function, so that the function can be used without having to be modified.

## Nomenclature

* **Classes and structures**: Use PascalCase (e.g., `ClassExample`).
* **Files, functions and variables**: Use camelCase (e.g., `variableExample`).
* **Constants**: Use MACRO_CASE (e.g., `CONSTANT_EXAMPLE`).
* **Pointers**: To differentiate a variable from a pointer at a glance, use the prefix "ptr" (e.g., `ptrPointer`).

## Formatting

* **Spacing**: Leave a space after commas and around operators (`a + b`, not `a+b`).
* **Pointers declaration**: When declaring a pointer type, place the asterisk next to the data type, instead of the pointer name. Avoid declaring more than one pointer in a single line. Example:

``` C++
int* pointer1;
int* pointer2;
```

* **Curly braces**: The opening braces go in the same line as the function or condition. Example:

``` C++
void function() {
    if (condition) {
        // code
    }
}
```

## GitHub rules

* **Branches**: Do not upload changes directly to main. Create a branch for each task. The format must be `type/task-name` (e.g., `feat/file-reading` or `fix/pointer-nomenclature`).
* **Commits**: Write clear messages in the present tense (e.g., `Add function to delete nodes`, and not `Changes made`).
* **Pull Requests (PR)**: Before merging a branch into main, at least one other person must review the code and approve it.

## More stuff

* **Pointer initialization**: Any pointer that does not point to something useful must be initialized as nullptr.
* **Avoid dangling pointers**: Immediately after deleting a pointer, it must be set to `nullptr`.
* **Using `new` and `delete`**: For every `new` written in the code, there must be a corresponding `delete` in the cleanup function.
* **Error Stream**: Use `std::cerr` for error messages and `std::cout` for normal messages.
* **File Structure**: Everything must be first declared in a .h header file and then included in a .cpp implementation file. Save the former in the `/include` folder, and the latter in the `/src` folder.
* **Include guards vs pragma once**: Use `#pragma once` instead of include guards at the start of a .h header file.
* **Strings vs Char arrays**: Always use std::string. Do not use char[] or char* for text unless strictly necessary.
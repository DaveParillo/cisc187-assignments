# Binary Search Trees
The goal of this lab is to introduce binary search trees
and become familiar with their properties.

We have already worked with some simple binary trees with when the
data had no special searching or sorting requirements.
Trees are most useful when applied to searching and sorting tasks.
This is why most languages implement sets and maps using trees.

A *binary tree* is a **binary search tree** if for every node:

- The tree value is greater than the values in all of its left children
- The tree value is less than the values in all of its right children

![example from wikipedia - public domain](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/288px-Binary_search_tree.svg.png)

The primary benefit of a binary search tree is that when the nodes are
visited using **infix** traversal, the data is sorted ascending.

We always search a binary search tree by comparing the 
value we’re searching for to the 'current' node value. 
If the target value is smaller, then we search the left subtree.
If the target value is larger, then we search the right subtree.

Look at the `contains` function in `tree_node.h` to see search in action.

In the lab steps below, complete the functions stubs
or implement the missing functions to complete the 
binary search tree class `bstree`.

Note that in `tree_node.h` all of the functions are in
the namespace `mesa::tree`.

## Steps

### 1. Function `min_element` and `max_element`
finish the functions that have been stubbed in `tree_node.h`.
These functions compile, but are incomplete.

Function `min_element` should return a pointer to the smallest value
in the tree.

Function `max_element` should return a pointer to the largest value
in the tree.

In both functions, if the value is not found, or if the tree is empty,
then return the `nullptr`.

### 2. Iterator Decrement

The tree iterator dereference and increment functions have already
been implemented.
Knowing that the decrement operators must traverse the tree in the 
opposite direction from increment,
implement overloads for **prefix** decrement and **postfix** decrement.

### 3. Functions `begin` and `end`
In our earlier trees, we arbitrarily chose the root node
as the begining and let the different traversals handle themselves.
Now we have rules.

Implement `begin` so that the iterator points to the
first element of the in order traversal.

As always, function `end` should represent a position past the last element.

Make sure your functions return the `const_iterator` type
and implement them in the `bstree` class.

A subtle point to notice in the bstree class.
Notice the definitions of iterator at the top of the bstree class:

```cpp
typedef const tree_iterator<T> const_iterator;
typedef const_iterator iterator;
```

The `iterator` is defined as a `const_iterator`. Why?

If we allow users to change tree values directly using the iterators
provided, then it breaks the rukes of the tree. Consider:

```cpp
auto it = my_tree.find(21);
*it = -9999;
```

The odds that `-9999` satisfies the binary search tree property are slim.


### 4. Function `insert`
Implement a `bstree` function that inserts the value provided.

Most of the work should be be done in the private helper:

```cpp
tree_node<T>* 
insert (const T& value, tree_node<T>*& node, tree_node<T>* parent)
```

### 5. Function `erase`
Implement a `bstree` function that erases the value provided.

```cpp
// delete all nodes from the tree
// use the helper erase(root) in tree_node.h to do all the work
void erase();

// delete the node from the tree containing 'value'
// if it exists.
// use the erase helper in tree_node.h to do the work.
void erase (const T& value);
```

The erase value function in `tree_node.h` should have the signature:

```cpp
void erase (const T& value, tree_node<T>*& root)
```

### 6. Function `find`
Implement a `bstree` function that finds the value provided.

```cpp
const_iterator find(const T& value) const noexcept;
```

Use the find helper in `tree_node.h` to do the work.

```cpp
template <class T>
  tree_node<T>* find (const T& value, tree_node<T>* root)
```


### 7. Function `main`
Write a main function that uses each of your `mesa::bstree` functions.
Add a range-for loop and use your iterator interface.
Consider `std::advance` or STL algorithms.


## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


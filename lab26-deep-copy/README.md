# Deep copy
This exercise is intended to increase familiarity with
using smart pointers and how to create copy constructors and
copy assignment functions
when the class contains pointers to objects.

## Steps

### 1. Run project 'as is'
You should be able to build and run this program.
The provided project should produce an executable named `copies`.

It should compile with warnings,
but we will be addressing these in the lab.

Run the program and notice the output:

```
Copy constructor test: 
Original: 	Alice	Bob	Carol	  	Copy: 	Alice	Bob	Carol	  
changing only the 'copy' objects: 
Original: 	Alice	222	333	  	Copy: 	111	222	333	  

Copy assignment test: 
Original: 	Dan	Edith	Fred	  	Copy: 	Dan	Edith	Fred	  
changing only the 'copy' objects: 
Original: 	Dan	222	333	  	Copy: 	111	222	333
```

This output is not correct.

This program defines a `Person` that contains a pointer to a child.
The child object contains another child.

So our example test program contains 3 objects,
`Alice`, `Bob`, and `Carol`:

- `Alice` is not a pointer and has a pointer to `Bob`
- `Bob` has a pointer to `Carol`.
- `Carol` points to nothing.

The code in the class `Person` is incomplete.

When main copies `Alice`,
what we **want** to happen is that changes to the copy
have no effect on `Alice` or *any of her children*.

Add code to `Person.cpp` so that `main.cpp` functions correctly.

Do **not** change anything in `main.cpp`.

### 2. `Person` copy constructor

Implement the `Person` copy constructor.
Replace the default (compiler provided) *shallow* copies
with your own *deep* copies.

**Hint:**

Use `std::shared_ptr::reset` to replace an existing
`std::shared_ptr` with a new object.

### 3. `Person` copy assignment operator
Implement the `Person` copy assignment operator.
This should behave much like the copy constructor,
minus any constructor initializers.

When complete with both steps 2 & 3,
the program should produce something similar to:

```
Copy constructor test: 
Original: 	Alice	Bob	Carol	  	Copy: 	Alice	Bob	Carol	  
changing only the 'copy' objects: 
Original: 	Alice	Bob	Carol	  	Copy: 	111	222	333	  

Copy assignment test: 
Original: 	Dan	Edith	Fred	  	Copy: 	Dan	Edith	Fred	  
changing only the 'copy' objects: 
Original: 	Dan	Edith	Fred	  	Copy: 	111	222	333
```

### 4. valgrind
You will need to run this on buffy (preferred),
or install `valgrind` yourself.

Ensure your copy functions do not potentially
result in any undefined behavior.

Results should look like:

```
==3597== Memcheck, a memory error detector
==3597== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3597== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==3597== Command: /var2/home/dparillo/solutions/lab14b_solution/copies
==3597== Parent PID: 3578
==3597== 
==3597== 
==3597== HEAP SUMMARY:
==3597==     in use at exit: 0 bytes in 0 blocks
==3597==   total heap usage: 26 allocs, 26 frees, 73,484 bytes allocated
==3597== 
==3597== All heap blocks were freed -- no leaks are possible
==3597== 
==3597== For counts of detected and suppressed errors, rerun with: -v
==3597== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

When run through `valgrind`, if you see the text

```
memory error detected
```

as part of the output, then you have a problem that needs fixing.

## Turnitin
There is a simple test target for step4
you can use to check your progress.

It simply compares the expected output to the output
generated by the copies program.
If you have finished, then this test should pass.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


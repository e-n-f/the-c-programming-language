the-c-programming-language
==========================

## Hello world

K&R use this to introduce strings and `printf`.

Treating wide strings as fundamental requires also introducing `setlocale`
as mysterious boilerplate, including its non-wide string argument.

Maybe this should do `wprintf` alone first, and then add `setlocale`
with a non-ASCII string.

I `return 0` because `main` has a type.

* [1.01-hello.c](1.01-hello.c)

## Temperature conversion

Essentially the same as K&R except for using `wprintf/setlocale/return`
and `//` comments.

`int` is still probably the right type for generic integer arithmetic
without any specific requirements.

* [1.02-fahr.c](1.02-fahr.c)

The floating point version is also basically the same. `float` isn't the
typical floating point type but saves an early explanation of why it is
called `double`.

* [1.02-fahr-float.c](1.02-fahr-float.c)

## Temperature conversion with for loop

Basically the same, again aside from `wprintf/setlocale/return`.

* [1.03-for.c](1.03-for.c)

## Temperature conversion with #define

Basically the same again.

* [1.04-define.c](1.04-define.c)

## Copying characters

I use `getwchar` and `putwchar`, which also requires introducing the first
non-fundamental type, `wint_t`.

* [1.05-characters.c](1.05-characters.c)

K&R introduce assignments as part of a loop condition, which still seems OK here.

* [1.05-characters-assign.c](1.05-characters-assign.c)

## Counting characters

Good thing we're using `getwchar` so we can really claim to be counting characters,
not bytes. Introduces `long` as an appropriate type for big integers.

I write `nc++` instead of `++nc` because the latter seems unidiomatic.

* [1.05.02-charcount.c](1.05.02-charcount.c)

K&R's use of `double` as a larger counter alternative is counterproductive now.
Use `long long` instead.

* [1.05.02-charcount-for.c](1.05.02-charcount-for.c)

## Counting lines

Introduces (wide) character constants.

* [1.05.03-linecount.c](1.05.03-linecount.c)

## Counting words

I introduce `stdbool.h` because it feels wrong now to use an `int` to track
a state with two-possibilities. Fortunately this is also the point that
boolean expressions are introduced.

* [1.05.04-wordcount-ctype.c](1.05.04-wordcount-ctype.c)

I also add a new example to introduce `wctype.h` because it also feels wrong
now to enumerate character classes by hand.

* [1.05.04-wordcount-ctype.c](1.05.04-wordcount-ctype.c)

## Arrays, counting digits

I immediately back of from `wctype` because `iswdigit` is underspecified
and the example needs to know exactly what the digit characters are.
I'm not actually sure the wide digits are guaranteed to be contiguous
and in order.

I introduce `size_t` as the type of array indices.

* [1.06-digits.c](1.06-digits.c)

## Exponentiation via function calls

K&R intentionally use different parameter names in the forward declaration
of `power` than in the definition. This seems like bad practice and I do not
follow it.

I use `size_t` as the type for a count, both in the function parameter and
in the iteration.

My `for` loop starts from `0` with `< n` instead of `1` and `<= n` because
the latter is so unidiomatic for C.

* [1.07-power.c](1.07-power.c)

## Counting down

Fortunately `size_t` is also OK for this case of counting down.

* [1.08-power2.c](1.08-power2.c)

## Character arrays

The characters are wide as before. I call my function `readline` instead of `getline`
to avoid conflict with the POSIX function.

This introduces `wchar_t` as the type of characters in non-FILE contexts.

K&R's loop conditional when reading lines seems needlessly complicated.
I use a `done` boolean instead, since `break` has not been introduced yet.

* [1.09-maxline.c](1.09-maxline.c)

## External global variables

This section seems inappropriate for this point in the book. There is no reason
to introduce `extern` before separate compilation.

I should have some other example where a global variable is appropriate, but
this is not it.

## Infodump

Chapter 2 is basically a giant infodump of how types and constants
and strings and enumerations and arithmetic and comparisons and type conversions work.

Section 2.7 introduces `ctype` in the context of showing that `tolower` can't be
implemented easily in EBCDIC, which a Unicode example would now demonstrate as well.

Increment and decrement, bitwise operationd, assignments, conditional expressions,
and operator precedence are all basically still true.

## Infodump and trim

Chapter 3 is another infodump. Statements, `if`, `else`, `switch`, `while`, `for`
are clarified.

There is new material for `do`, `break`, `continue`, and `goto`.

The `trim` example for `break` is contrived but is also a good example of how
counting down with `size_t` in the obvious way doesn't work. It doesn't say
what the return value is intended to mean, but if it's meant to be the trimmed
length of the string, it's off by one.

* [3.07-trim.c](3.07-trim.c)

## String matching

K&R make their `strstr` hard to read by introducing another variable just to avoid
having to do addition during the loop. I also changed my `readline` again, eliminating
the boolean variable, since `break` has been introduced.

* [4.01-fgrep.c](4.01-fgrep.c)

## String to floating point.

K&R reveal that all the functions so far have been `void` or have returned integers.
To a contemporary reader it would be more surprising *not* to be able to return
any arbitrary type.

The other part that seems bizarre now is the forward declaration of `atof` inside
the body of the calling function.

## External variables, in the context of maintaining a stack

This seems like a more reasonable place to talk about `extern`, although there's
no reason the stack couldn't be an argument instead of a global. But here K&R
*don't* talk about `extern`, but just use globals by their regular declaration.

## Header files

Here would be a reasonable place to talk about some example of an `extern` global,
but they don't; they only talk about `#define` and functions in the header file.

(Therefore talk about making your own header files here instead of in §4.11 below.)

## Static variables

At this point they should probably start declaring all functions that are not
general utility functions to be `static`.

And they really should have an example of a static variable inside a function!

This should also mention `inline` functions.

## Register variables

Nobody cares about this any more.

## Block structure

Extend this to also talk about declaring variables in the middle of a block.

## Initialization

And also talk about doing declarations with initialization in the
conditional of a loop.

## Recursion

Basically fine except for the anachronistic declaration of `swap` inside the body
of `qsort`.

The weird part of `qsort` is that the indices are of the first and last element
to be sorted instead of one past the end. Addressed below in the full `sort` program.

## Preprocessor

Refocus the function-like macros on things you can't do with an `inline` function.

## Pointers

Seems basically fine.

Unclear whether the `alloc` part should be emphasizing that generic memory allocation
is from `char`s, or talking about allocating memory of a particular type.
I'm going to treat it as generic in `sort` below.

Using `0` as a pointer value instead of `NULL` reads as weird now. Also weird that
`afree` silently does nothing with an invalid pointer, but there hasn't been anything
yet about writing to the standard error.

The part on `strlen` shouldn't be so dismissive of `size_t`.

## Pointers into strings

I would not encourage post-incrementing in the loop conditional or leaving the
`!= L'\0'` as implicit.

## Arrays of pointers

Finally another full example program, combining the memory allocator, sorting,
and line-oriented I/O.

The thing that felt important to change was to make the `sort`
bounds be the first element and one past the last element, rather
than the first and directly the last.

* [5.06-sort.c](5.06-sort.c)

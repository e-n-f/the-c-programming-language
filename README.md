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

K&R's loop conditional when reading lines seems needlessly complicated.
I use a `done` boolean instead, since `break` has not been introduced yet.

* [1.09-maxline.c](1.09-maxline.c)

## External global variables

This section seems inappropriate for this point in the book. There is no reason
to introduce `extern` before separate compilation.

I should have some other example where a global variable is appropriate, but
this is not it.

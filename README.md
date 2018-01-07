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

* [1.05.02-charcount.c](1.05.02-charcount.c)

K&R's use of `double` as a larger counter alternative is counterproductive now.
Use `long long` instead.

* [1.05.02-charcount-for.c](1.05.02-charcount-for.c)

## Counting lines

Introduces character constants.

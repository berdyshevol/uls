# uls
uls is C language implementation of a standard mac Os ls command.

# Implemented Flags
* 1, C, l, m
* a, A
* t, T, U, u, c
* g, n, o, i, h, s, k

# Bugs
Some bugs have been found:

./uls -l /tmp
./uls /dev/null
-lo -adds one extra space character
-ln
./uls Makefile/ - if there is / at the end
+chmod
./uls tmp/

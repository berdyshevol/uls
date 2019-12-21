# uls
uls is C language implimentation of a standart macOs ls command.

# Implimented Flags
* 1, C, l, m
* a, A
* t, T, U, u, c
* g, n, o, i, h, s, k

#Bugs
Some bugs have been found:

./uls -l /tmp
./uls /dev/null
-lo -adds one extra space character
-ln
./uls Makefile/ - if there is / at the end
+chmod
./uls tmp/

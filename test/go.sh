cd ..
echo compile..
make reinstall

echo Standart test:
echo "\n"

echo Test: ls
./uls ./Libmx/src 1> ./test/test.txt
ls ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -l
./uls -l 1> ./test/test.txt
ls -l 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt 
echo "\n"

echo Test: ls -l /
./uls -l / 1> ./test/test.txt
ls -l / 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -l /usr/bin
./uls -l /usr/bin 1> ./test/test.txt
ls -l /usr/bin 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls {link}
./uls ./test/lib_link 1> ./test/test.txt
ls ./test/lib_link 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -l {link}
./uls -l ./test/lib_link 1> ./test/test.txt
ls -l ./test/lib_link 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -la
./uls -la 1> ./test/test.txt
ls -la 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt 
echo "\n"

echo Test: ls -lA
./uls -lA 1> ./test/test.txt
ls -lA 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lf
./uls -lf 1> ./test/test.txt
ls -lf 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lu
./uls -lu 1> ./test/test.txt
ls -lu 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lat
./uls -lat 1> ./test/test.txt
ls -lat 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -ltc
./uls -ltc 1> ./test/test.txt
ls -ltc 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lT
./uls -lT 1> ./test/test.txt
ls -lT 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lSr
./uls -lSr ./Libmx/src 1> ./test/test.txt
ls -lSr ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lSa
./uls -lSa 1> ./test/test.txt
ls -lSa 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lS
./uls -lS 1> ./test/test.txt
ls -lS 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lag
./uls -lag 1> ./test/test.txt
ls -lag 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -l1
./uls -l1 1> ./test/test.txt
ls -l1 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -C
./uls -C ./Libmx/src 1> ./test/test.txt
ls -C ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -m
./uls -m ./Libmx/src 1> ./test/test.txt
ls -m ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -Cf
./uls -Cf ./Libmx/src 1> ./test/test.txt
ls -Cf ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -ln
./uls -ln ./Libmx/src 1> ./test/test.txt
ls -ln ./Libmx/src 1> ./test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

echo Test: ls -lh ./../../Desktop/uls/Libmx/src
./uls -lh ./../../Desktop/uls/Libmx/src 1> test/test.txt
ls -lh ./../../Desktop/uls/Libmx/src 1> test/std.txt
diff -q ./test/test.txt ./test/std.txt
echo "\n"

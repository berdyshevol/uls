cd ..
echo compile..
make reinstall

echo Standart test:
echo "\n"


echo Test: ls -lRh ./../
touch ./../../test.txt ./../../std.txt
ls -lRh ./../ 1> ./../../test.txt
ls -lRh ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"

echo Test: ls -lR ./../
touch ./../../test.txt ./../../std.txt
ls -lR ./../ 1> ./../../test.txt
ls -lR ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"


echo Test: ls -R ./../
touch ./../../test.txt ./../../std.txt
ls -R ./../ 1> ./../../test.txt
ls -R ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"


echo Test: ls -1R ./../
touch ./../../test.txt ./../../std.txt
ls -1R ./../ 1> ./../../test.txt
ls -1R ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"


echo Test: ls -mR ./../
touch ./../../test.txt ./../../std.txt
ls -mR ./../ 1> ./../../test.txt
ls -mR ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"

 echo Test: ls -CR ./../
touch ./../../test.txt ./../../std.txt
ls -CR ./../ 1> ./../../test.txt
ls -CR ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"


echo Test: ls -laR ./../
touch ./../../test.txt ./../../std.txt
ls -laR ./../ 1> ./../../test.txt
ls -laR ./../ 1> ./../../std.txt
diff -q ./../../std.txt ./../../test.txt
rm -rf ./../../test.txt ./../../std.txt
echo "\n"


echo "The END\n"

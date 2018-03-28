#!/bin/sh
## EPITECH PROJECT, 2018
## test automatisés Lem_in
## File description:
## test automatisés
##

# test 1 error : no arguments

echo "======== test 1 error : no arguments ========"
./lem_in < input_2-0
echo $? > test_1
diff test_1 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_1 fail == [KO] ==\n"
fi

# test 2 error : not enought arguments on start

echo "======== test 2 error : not enought arguments on start ========"
./lem_in < input_5-0
echo $? > test_2
diff test_2 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_2 fail == [KO] ==\n"
fi

# test 3 error : no start arguments

echo "======== test 3 error : no arguments on start ========"
./lem_in < input_6-0
echo $? > test_3
diff test_3 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_3 fail == [KO] ==\n"
fi

# test 4 error : 0 ant in the game

echo "======== test 4 error : 0 ant in the game ========"
./lem_in < input_7-0
echo $? > test_4
diff test_4 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_4 fail == [KO] ==\n"
fi

# test 5 error : bad parameters in the file

echo "======== test 5 error : bad parameters in the file ========"
./lem_in < input_10-0
echo $? > test_5
diff test_5 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_5 fail == [KO] ==\n"
fi

# test 6 error : useless file
#
#echo "======== test 6 error : useless file ========"
#./lem_in < input_12-0
#echo $? > test_6
#diff test_6 error
#error=$?
#if [ $error -eq 0 ]
#then
#    echo -e "The prgram return 84 == [OK] ==\n"
#elif [ $error -eq 1 ]
#then
#    echo -e "test_6 fail == [KO] ==\n"
#fi

# test 7 error : bad parameter in the file

echo "======== test 7 error : useless file ========"
./lem_in < input_13-0
echo $? > test_7
diff test_7 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_7 fail == [KO] ==\n"
fi

# test 8 error : multiples ends

echo "======== test 8 error : useless file ========"
./lem_in < input_15-0
echo $? > test_8
diff test_8 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_8 fail == [KO] ==\n"
fi

# test 9 error : not enought way to end

echo "======== test 9 error : not enought way to end ========"
./lem_in < input_16-0
echo $? > test_9
diff test_9 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_9 fail == [KO] ==\n"
fi

# test 10 error : not linked

echo "======== test 10 error : not linked ========"
./lem_in < input_17-0
echo $? > test_10
diff test_10 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_10 fail == [KO] ==\n"
fi

# test 11 error : no end way

echo "======== test 11 error : no end way ========"
./lem_in < input_18-0
echo $? > test_11
diff test_11 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_11 fail == [KO] ==\n"
fi

# test 12 error : unexistant room
#
#echo "======== test 12 error : unexistant room ========"
#./lem_in < input_19-0
#echo $? > test_12
#diff test_12 error
#error=$?
#if [ $error -eq 0 ]
#then
#    echo -e "The prgram return 84 == [OK] ==\n"
#elif [ $error -eq 1 ]
#then
#    echo -e "test_12 fail == [KO] ==\n"
#fi

# test 14 error : wrong coord for end way

echo "======== test 14 error : wrong coord for end way ========"
./lem_in < input_22-0
echo $? > test_14
diff test_14 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 == [OK] ==\n"
elif [ $error -eq 1 ]
then
    echo -e "test_14 fail == [KO] ==\n"
fi

# clean test files

rm test_*

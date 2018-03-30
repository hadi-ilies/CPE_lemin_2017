#!/bin/sh
## EPITECH PROJECT, 2018
## test automatisés Lem_in
## File description:
## test automatisés
##

# ======================== ERROR ============================

echo -e "\n\n\n//////////////////// ERROR TESTS (14 test) ////////////////////\n\n\n"

# test 1 error : no arguments

echo "======== test 1 error : no arguments ========"
./lem_in < input_2-0
echo $? > test_1
diff test_1 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_1 fail ===== [KO]\n"
fi

# test 2 error : not enought arguments on start

echo "======== test 2 error : not enought arguments on start ========"
./lem_in < input_5-0
echo $? > test_2
diff test_2 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_2 fail ===== [KO]\n"
fi

# test 3 error : no start arguments

echo "======== test 3 error : no arguments on start ========"
./lem_in < input_6-0
echo $? > test_3
diff test_3 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_3 fail ===== [KO]\n"
fi

# test 4 error : 0 ant in the game

echo "======== test 4 error : 0 ant in the game ========"
./lem_in < input_7-0 > tmp
echo $? > test_4
diff test_4 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_4 fail ===== [KO]\n"
fi

# test 5 error : bad parameters in the file

echo "======== test 5 error : bad parameters in the file ========"
./lem_in < input_10-0
echo $? > test_5
diff test_5 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_5 fail ===== [KO]\n"
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
#    echo -e "The prgram return 84 ===== [OK]\n"
#elif [ $error -eq 1 ]
#then
#    echo -e "test_6 fail ===== [KO]\n"
#fi

# test 7 error : bad parameter in the file

echo "======== test 6 error : useless file ========"
./lem_in < input_13-0 > tmp
echo $? > test_7
diff test_7 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_6 fail ===== [KO]\n"
fi

# test 8 error : multiples ends

echo "======== test 8 error : useless file ========"
./lem_in < input_15-0 > tmp
echo $? > test_8
diff test_8 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_8 fail ===== [KO]\n"
fi

# test 9 error : not enought way to end

echo "======== test 9 error : not enought way to end ========"
./lem_in < input_16-0
echo $? > test_9
diff test_9 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_9 fail ===== [KO]\n"
fi

# test 10 error : not linked

echo "======== test 10 error : not linked ========"
./lem_in < input_17-0
echo $? > test_10
diff test_10 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_10 fail ===== [KO]\n"
fi

# test 11 error : no end way

echo "======== test 11 error : no end way ========"
./lem_in < input_18-0
echo $? > test_11
diff test_11 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_11 fail ===== [KO]\n"
fi

# test 12 error : unexistant room
echo "======== test 12 error : unexistant room ========"
./lem_in < input_19-0 > tmp
echo $? > test_12
diff test_12 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_12 fail ===== [KO]\n"
fi

# test 14 error : wrong coord for end way

echo "======== test 14 error : wrong coord for end way ========"
./lem_in < input_22-0
echo $? > test_14
diff test_14 error
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 84 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_14 fail ===== [KO]\n"
fi



# ======================== FONCTIONAL ============================

echo -e "\n\n\n//////////////////// FONCTIONAL TESTS (10 tests) ////////////////////\n\n\n"

#test 15 fonctional : file with useless spaced commentaries

echo "======== test 15 fonctional : file with useless spaced commentaries ========"
./lem_in < input_0-1 > tmp
echo $? > test_15
diff test_15 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_15 fail ===== [KO]\n"
fi

# test 16 fonctional : file with useless commentaries

echo "======== test 16 fonctional : file with useless commentaries ========"
./lem_in < input_1-1 > tmp
echo $? > test_16
diff test_16 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_16 fail ===== [KO]\n"
fi

# test 17 fonctional : useless comentaries with the ##start point

echo "======== test 17 fonctional : useless comentaries with the ##start point ========"
./lem_in < input_3-1 > tmp
echo $? > test_17
diff test_17 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_17 fail ===== [KO]\n"
fi

# test 18 fonctional : useless comentaries in the path

echo "======== test 18 fonctional : useless comentaries in the path ========"
./lem_in < input_4-1 > tmp
echo $? > test_18
diff test_18 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_18 fail ===== [KO]\n"
fi

# test 19 fonctional : bad parameters in the path

echo "======== test 19 fonctional : bad parameters in the path ========"
./lem_in < input_8-1 > tmp
echo $? > test_19
diff test_19 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_19 fail ===== [KO]\n"
fi

# test 20 fonctional : swap ##start && ##end

echo "======== test 20 fonctional : swap ##start && ##end ========"
./lem_in < input_9-1 > tmp
echo $? > test_20
diff test_20 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_20 fail ===== [KO]\n"
fi

# test 21 fonctional : random spaces in the input file

echo "======== test 21 fonctional : random spaces in the input file ========"
./lem_in < input_11-1 > tmp
echo $? > test_21
diff test_21 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_21 fail ===== [KO]\n"
fi

# test 22 fonctional : different ##test check point

echo "======== test 22 fonctional : different ##test check point ========"
./lem_in < input_14-1 > tmp
echo $? > test_22
diff test_22 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_22 fail ===== [KO]\n"
fi

# test 23 fonctional : comment in ##end

echo "======== test 23 fonctional : comment in ##end ========"
./lem_in < input_20-1 > tmp
echo $? > test_23
diff test_23 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_23 fail ===== [KO]\n"
fi

# test 24 fonctional : a lot of way to end

echo "======== test 24 fonctional : a lot of way to end ========"
./lem_in < input_21-1 > tmp
echo $? > test_24
diff test_24 ok
error=$?
if [ $error -eq 0 ]
then
    echo -e "The prgram return 0 ===== [OK]\n"
elif [ $error -eq 1 ]
then
    echo -e "test_24 fail ===== [KO]\n"
fi

# clean test files

rm test_*
rm tmp

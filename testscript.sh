#!/bin/sh
echo "================================="
echo "ERROR MANAGEMENT: 2 x usage if OK"
echo "================================="
./fillit
./fillit a a
echo "									"
echo "================================="
echo " INVALID FILES: 8 x error if OK"
echo "================================="
./fillit ./eval_files/error1
./fillit ./eval_files/too_large
./fillit ./eval_files/too_small
./fillit ./eval_files/not_square
echo "______________________________"
./fillit ./eval_files/other_chr
./fillit ./eval_files/invalid_file
./fillit ./eval_files/empty
./fillit ./eval_files/too_many
echo "================================="
echo " VALID FILES: "
echo "================================="
echo "Correct answer:	EASY"
cat ./eval_files/easy_answer
echo "Test result:	EASY"
./fillit ./eval_files/easy
echo "______________________________"
echo "Correct answer MEDIUM"
cat ./eval_files/medium_answer
echo "Test result: MEDIUM"
./fillit ./eval_files/medium
echo "______________________________"
echo "Correct answer HARD"
cat ./eval_files/hard_answer
echo "Test result: HARD"
./fillit ./eval_files/hard
echo "================================="
echo " SPEED: "
echo "================================="
echo "If result more than 1 second -> fail"
time ./fillit ./eval_files/test1
echo "______________________________"
echo "Correct answer test7"
cat ./eval_files/test_7_answer
echo "______________________________"
echo "Test result test7: "
time ./fillit ./eval_files/test7
echo "result 			< 1 second: 		5 points
result between 		1 and 5 second: 	4 points
result between 		5 and 10 second: 	3 points
result between 		10 and 20 second: 	2 points
result between 		20 and 30 second: 	1 points
result more than 	30 second:		0 points "
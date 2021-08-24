//==============================================
// Name:           Hung Truong
// Student Number: 147779193
// Email:          htruong19@myseneca.ca
// Section:        NAA
// Date:           May 30, 2020 
//==============================================
// Workshop:       1
// Part:           2
//==============================================

#ifndef MARKS_H
#define MARKS_H

namespace num { //contains constants
	const int MAX_WORD_LEN = 40;
	const int MAX_NUM_LEN = 10;
	const int MIN_NUM_MARKS = 5;
	const int MAX_NUM_MARKS = 50;
	const int MIN_GRADE = 0;
	const int MAX_GRADE = 100;
}

using namespace num;

struct Program {
	char name[MAX_WORD_LEN];
	int marks[MAX_NUM_MARKS];
	float markSum;
	int pass;
};

void programTitle();
void markstat();
void marking(int* mark, int numMarks);
void sort(int* mark, int numMarks);


#endif
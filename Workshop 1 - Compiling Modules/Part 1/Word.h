/* ------------------------------------------------------
Workshop 1 part 1
Module: N/A
Filename: Word.h
Author	Hung Truong
Revision History
-----------------------------------------------------------
Date       Reason
2020/5/26  Split from w1w1.cpp, implement namespace and function prototype
-----------------------------------------------------------*/

#ifndef WORD_H
#define WORD_H

namespace sdds {
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;   
}

using namespace sdds;

struct Word {
    char letters[MAX_WORD_LEN];
    int count;
};


int searchWords(const Word words[], int num, const char word[]);
void addWord(Word words[], int* index, const char newWord[]);
void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
void listWords(const Word words[], int noOfWords, const char* theTitle);
void wordStats();
void programTitle();
void sort(Word words[], int cnt, int sortType);


#endif
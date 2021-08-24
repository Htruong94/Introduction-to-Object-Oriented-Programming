/* ------------------------------------------------------
Workshop 1 part 1
Module: N/A
Filename: Utils.h
Author	Hung Truong
Revision History
-----------------------------------------------------------
Date       Reason
2020/5/26  Preliminary release
-----------------------------------------------------------*/

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>

char ToLower(char ch);
int StrCmp(const char* s1, const char* s2);
void StrCpy(char* des, const char* src);
int StrLen(const char* str);
bool isAlpha(char ch);
void trim(char word[]);
void toLowerCaseAndCopy(char des[], const char source[]);
void title(const char* value, int len);
void endList();
void print(const Word* w, bool gotoNextLine, int len);
int findMaxLen(const Word words[], int noOfWords);
void swap(Word* p1, Word* p2);
int totalCount(const Word* words, int num);

#endif
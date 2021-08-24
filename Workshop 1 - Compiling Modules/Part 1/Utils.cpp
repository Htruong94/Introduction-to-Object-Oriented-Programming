/* ------------------------------------------------------
Workshop 1 part 1
Module: N/A
Filename: Utils.cpp
Author	Hung Truong
Revision History
-----------------------------------------------------------
Date       Reason
2020/5/26  Split from w1w1.cpp
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include "Word.h"
#include "Utils.h"
using namespace std;

char ToLower(char ch) {
    if (ch >= 'a' && ch <= 'z') ch += ('A' - 'a');
    return ch;
}
int StrCmp(const char* s1, const char* s2) {
    int i;
    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}
void StrCpy(char* des, const char* src) {
    int i;
    for (i = 0; src[i]; i++) des[i] = src[i];
    des[i] = 0;
}
int StrLen(const char* str) {
    int len;
    for (len = 0; str[len]; len++);
    return len;
}
bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
void trim(char word[]) {
    int i;
    while (word[0] && !isAlpha(word[0])) {
        StrCpy(word, word + 1);
    }
    i = StrLen(word);
    while (i && !isAlpha(word[i - 1])) {
        word[i-- - 1] = 0;
    }
}
void toLowerCaseAndCopy(char des[], const char source[]) {
    int i = 0, j = 0;
    for (; source[i] != 0; i++) {
        des[j++] = ToLower(source[i]);
    }
    des[j] = 0;
}
void title(const char* value, int len) { // uses iomanip header file
    cout << value << endl;
    cout << setw(len) << left << "Word";
    cout << "No of  occurrence." << endl << "------------------------------------------------" << endl;
}
void endList() {
    cout << "------------------------------------------------" << endl;
}
void print(const Word* w, bool gotoNextLine, int len) { // uses iomanip header file
    cout << setw(len) << left << w->letters;
    cout << setw(3) << right << w->count;
    if (gotoNextLine) cout << endl;
}

int findMaxLen(const Word words[], int noOfWords) {
    int longest = 0;
    int i;
    for (i = 0; i < noOfWords; i++) {
        if (longest < StrLen(words[i].letters))
            longest = StrLen(words[i].letters);
    }
    return longest;
}
void swap(Word* p1, Word* p2) {
    Word w;
    w = *p1;
    *p1 = *p2;
    *p2 = w;
}

int totalCount(const Word* words, int num) {
    int total = 0;
    do {
        total += words[--num].count;
    } while (num);
    return total;
}

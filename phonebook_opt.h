#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 21911

#define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
    struct __PHONE_BOOK_DETAIL *pDetail;
} entry;

typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

entry *findName(char lastName[], entry *e[]);
void append(char lastName[], entry *e[]);
unsigned int BKDRHash(char *str);
#endif

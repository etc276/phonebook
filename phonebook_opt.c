#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_opt.h"

entry *findName(char lastName[], entry *e[])
{
    int hash = BKDRHash(lastName)%TABLE_SIZE;
    entry *tmp = e[hash];
    while (tmp) {
        if (!strcasecmp(lastName, tmp->lastName))
            return tmp;
        tmp = tmp->pNext;
    }
    return NULL;
}
void append(char lastName[], entry *e[])
{
    int hash = BKDRHash(lastName)%TABLE_SIZE;
    entry *tmp = e[hash];
    while (tmp->pNext) {
        tmp = tmp->pNext;
    }
    entry *node = (entry *) malloc(sizeof(entry));
    tmp->pNext = node;
    strcpy(node->lastName, lastName);
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131, hash = 0; // 31 131 1313 13131 131313 etc.
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}


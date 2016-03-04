#ifndef _ITEM_
#define _ITEM_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_ID_LEN 100

typedef struct item_s
{
    char name[MAX_NAME_LEN];
    double price;
    int count;
    int type;			/* 0x01->95折, 0x10->买二送一 */
    char id[MAX_ID_LEN];	/* for example: 'ITEM000001' */
}item_t;
/* interfaces */
item_t * ItemMakeitem(char *id, int count);
item_t * ItemMakeitemEx(char *id, double price, char *name, int type, int count);
int ItemShow(void *item);

typedef struct price_s
{
    char name[MAX_NAME_LEN];
    double price;
    int type;			/* 0x01->95折, 0x10->买二送一 */
    char id[MAX_ID_LEN];	/* for example: 'ITEM000001' */
}price_t;

#endif

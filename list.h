#ifndef _LIST_
#define _LIST_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

typedef struct list_node_s
{
    void *data;
    struct list_node_s *next;
}list_node_t;

typedef struct list_s
{
    int size;
    list_node_t *head;
}list_t;

/* interfaces */
list_t *ListInit();
int ListPushBack(list_t *L, void * obj);
/* int ListPushFront(list_t *L, void * obj); */
int ListFree(list_t *L);
void *ListIsNodeInListById(list_t *L, char * id);
int ListShow(list_t *L);


typedef struct gift_list_s
{
    void *data;
    struct gift_list_s *next;
}gift_list_t;
gift_list_t *gListInit(gift_list_t *L);
int gListFree(gift_list_t *L);
int gListInsert(gift_list_t *L, void *data);

#endif

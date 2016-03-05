#include "list.h"

list_t *ListInit()
{
    list_t *L = (list_t*)malloc(sizeof(list_t));
    if(L)
    {
	L->size = 0;
	L->head = (list_node_t*)malloc(sizeof(list_node_t));
	L->head->next = NULL;
	L->head->data = NULL;
	return L;
    }
    else
    {
	return NULL;
    }
}

int ListPushBack(list_t *L, void * obj)
{
    if(L == NULL || obj == NULL)
	return -1;

    list_node_t * temp = L->head;
    while(temp->next)
    {
	temp = temp->next;
    }

    list_node_t *node = (list_node_t*)malloc(sizeof(list_node_t));
    node->next = NULL;
    node->data = obj;
    temp->next = node;

    L->size++;

    return 0;
}

int ListFree(list_t *L)
{
    list_node_t *previous = L->head;
    list_node_t *lattter = L->head->next;

    while(lattter)
    {
	free(previous->data);
	free(previous);

	previous = lattter;
	lattter = lattter->next;
    }
    free(previous->data);
    free(previous);

    return 0;
}

void *ListIsNodeInListById(list_t *L, char * id)
{
    list_node_t *node = L->head->next;

    while(node)
    {
	if(strcmp(((item_t*)(node->data))->id, id) == 0)
	{
	    return (void *)(node->data);
	}

	node = node->next;
    }

    return NULL;
    
}

int ListShow(list_t *L)
{
    if(L == NULL)
    {
	return -1;
    }
	
    printf("\n\nlist size = %d\n",L->size);
    printf("=========================================================\n\n\n");

    list_node_t *p = L->head->next;
    while(p)
    {
	item_t *node = (item_t*)p->data;
	printf("[name = %s\t",node->name);
	printf("id = %s\t",node->id);
	printf("type = 0x%x\t",node->type);
	printf("price = %f\t",node->price);
	printf("count = %d]",node->count);
	printf("\n");
	p = p->next;
    }

    return 0;
    
}

gift_list_t *gListInit(gift_list_t *L)
{
    L = (gift_list_t*)malloc(sizeof(gift_list_t));
    
    L->next = NULL;
    L->data = NULL;

    return L;
}
int gListFree(gift_list_t *L)
{
    if(L == NULL)
	return 0;

    gift_list_t *temp = L->next;
    while(temp)
    {
	free(L);
	L = temp;
	temp = temp->next;
    }

    free(L);
    return 0;
}
int gListInsert(gift_list_t *L, void *data)
{
    if(L == NULL)
    {
	return -1;
    }
    
    gift_list_t *temp_node = (gift_list_t *)malloc(sizeof(gift_list_t));

    temp_node->data = data;
    temp_node->next = L->next;

    L->next = temp_node;
    
    return 0;
}

int ListShowPrice(list_t *L)
{
    if(L == NULL)
    {
	return -1;
    }
	
    printf("\n\nmy_price list size = %d\n",L->size);
    printf("=========================================================\n\n\n");

    list_node_t *p = L->head->next;
    while(p)
    {
	price_t *node = (price_t*)p->data;
	printf("[name = %s\t",node->name);
	printf("id = %s\t",node->id);
	printf("type = 0x%x\t",node->type);
	printf("price = %f\t",node->price);
	printf("quantifier = %s\t",node->quantifier);
	/* printf("count = %d]",node->count); */
	printf("\n");
	p = p->next;
    }

    return 0;
    
}

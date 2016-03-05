#include "item.h"
#include "list.h"

#define MAX_PRICE_LEN 5		/* 总共商口种类 */
extern list_t *my_price;

item_t * ItemMakeitem(char *id, int count)
{

    price_t *node = NULL;
    list_node_t *temp_node = my_price->head->next;

    while(temp_node)
    {
	node = (price_t*)temp_node->data;


	if(strcmp(node->id, id) == 0)
	{
	    char *name = node->name;
	    int type = node->type;
	    double price = node->price;
	    char *quantifier = node->quantifier;
	    return ItemMakeitemEx(id, price, name, type, count, quantifier);
	}

	temp_node = temp_node->next;
    }
    return NULL;
}

item_t * ItemMakeitemEx(char *id, double price, char *name, int type, int count, char *quantifier)
{
    if(id == NULL || name == NULL)
    {
	return NULL;
    }
    item_t *it = (item_t*)malloc(sizeof(item_t));

    it->price = price;
    it->type = type;
    strcpy(it->name, name);
    strcpy(it->id, id);
    strcpy(it->quantifier, quantifier);
    it->count = count;

    return it;
}

int ItemShow(void *item)
{
    if(item == NULL)
    {
	return -1;
    }

    item_t *node = (item_t*)item;

    printf("name = %s\t",node->name);
    printf("id = %s\t",node->id);
    printf("type = 0x%x\t",node->type);
    printf("price = %f\t",node->price);
    printf("count = %d\t",node->count);
    printf("\n");

    return 0;
}


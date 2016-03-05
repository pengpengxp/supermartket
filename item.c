#include "item.h"
#include "list.h"

#define MAX_PRICE_LEN 5		/* 总共商口种类 */
/* 这就是整个价格表与是否打折等信息，其中type最后一位为1表示95折，倒数
 * 第二位为1表示买二送一，均为0表示普通商品 */

/* price_t my_price[MAX_PRICE_LEN] = { */
/*     {"可口可乐", 3.00, 0x01, "ITEM000001"}, */
/*     {"羽手球", 1.00, 0x10, "ITEM000002"}, */
/*     {"苹果", 5.00, 0x00, "ITEM000003"}, */
/*     {"梨", 3.50, 0x00, "ITEM000004"}, */
/*     {"裤子", 49.00, 0x11, "ITEM000005"}, */
/* }; */

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


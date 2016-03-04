#include "item.h"

#define MAX_PRICE_LEN 5		/* 总共商口种类 */
/* 这就是整个价格表与是否打折等信息，其中type最后一位为1表示95折，倒数
 * 第二位为1表示买二送一，均为0表示普通商品 */
price_t my_price[MAX_PRICE_LEN] = {
    {"可口可乐", 3.00, 0x01, "ITEM000001"},
    {"羽手球", 1.00, 0x10, "ITEM000002"},
    {"苹果", 5.00, 0x00, "ITEM000003"},
    {"梨", 3.50, 0x00, "ITEM000004"},
    {"裤子", 49.00, 0x11, "ITEM000005"},
};

item_t * ItemMakeitem(char *id, int count)
{
    int i;
    for (i = 0; i < MAX_PRICE_LEN; i++) 
    {
	if((strcmp(my_price[i].id, id)) == 0)
	{
	    char *name = my_price[i].name;
	    int type = my_price[i].type;
	    double price = my_price[i].price;

	    return ItemMakeitemEx(id, price, name, type, count);
	}
    }

    return NULL;
}

item_t * ItemMakeitemEx(char *id, double price, char *name, int type, int count)
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


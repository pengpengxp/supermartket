#include "function.h"

enum
{
    COMMON = 1,
    DISCOUNT,
    GIFT
};

int ParseLine(char * buffer, char * result, int * number)
{
    if((buffer == NULL) || (result == NULL) || (number == NULL))
    {
	return -1;
    }

    char *begin, *end;

    if((begin = strstr(buffer,"'")) != NULL)
    {
	if(((end = strstr((begin + 1), "-")) != NULL)
	   || ((end = strstr((begin + 1),  "'")) != NULL))
	{
	    if(*end == '-')
	    {
		*number = atoi(end + 1);

		memcpy(result, (begin + 1), (end - begin - 1));
		result[end - begin] = '\0';
	    }
	    else
	    {
		memcpy(result, (begin + 1), (end - begin - 1));
		result[end - begin] = '\0';
		*number = 1;
	    }
	}
    }
    else
    {
	return -1;
    }

    return 0;
    
}

int WhichType(int type)
{
    if(type & 0x10)
    {
	return GIFT;
    }
    else if(type & 0x01)
    {
	return DISCOUNT;
    }
    return COMMON;
}



/* make the output */
static double sum = 0.0;
static double discount_sum = 0.0;
static int gift_flag = 0;
gift_list_t *g_list= NULL;

int CalculateSum(list_t *L)
{

    sum = 0.0;
    discount_sum = 0.0;
    gift_flag = 0;
    g_list = gListInit(g_list);

    printf("***<没钱赚商店>购物清单***\n");
    
    list_node_t *temp = L->head->next;
    item_t *node = NULL;
    while(temp)
    {
	node = (item_t*)temp->data;
	int type = WhichType(node->type);

	switch(type)
	{
	case COMMON:
	    /* printf("common\n"); */
	    /* ItemShow((void*)node); */
	    CalculateCommon(node);
	    break;
	case DISCOUNT:
	    /* printf("discount\n"); */
	    /* ItemShow((void*)node); */
	    CalculateDiscount(node);
	    break;
	case GIFT:
	    /* printf("gift\n"); */
	    /* ItemShow((void*)node); */
	    gift_flag = 1;
	    CalculateGift(node);
	    break;
	default:
	    printf("unknown type\n");
	    break;
	}
	temp = temp->next;
    }

    if(gift_flag == 1)
    {
	printf("-------------------------\n");
	printf("买二赠一商品\n");
	gift_list_t *temp_node = g_list->next;
	while(temp_node)
	{
	    printf("名称：%s，数量：%d\n", ((item_t *)(temp_node->data))->name,((item_t *)(temp_node->data))->count / 3);
	    temp_node = temp_node->next;
	}
    }
    printf("-------------------------\n");
    printf("总计：%f（元）\n", sum);
    printf("节省：%f（元）\n", discount_sum);

    gListFree(g_list);

    return 0;
}

int CalculateCommon(item_t *node)
{
    printf("名称：%s，数量：%d，单价：%f（元），小计：%f（元）\n",node->name, node->count, node->price, (node->price * node->count));
    sum += (node->price * node->count);
    return 0;
}

int CalculateDiscount(item_t *node)
{
    printf("名称：%s，数量：%d，单价：%f（元），小计：%f（元），节省%f（元）\n",node->name, node->count, node->price, \
	   (node->price * node->count * 0.95), (node->price * node->count * 0.05));
    sum += (node->price * node->count * 0.95);
    discount_sum += (node->price * node->count * 0.05);
    return 0;
}

int CalculateGift(item_t *node)
{
    int actual_count = node->count - (node->count / 3); /* 这里还需要改正一下，计算方法不对 */
    printf("名称：%s，数量：%d，单价：%f（元），小计：%f（元）\n",node->name, node->count, node->price, (node->price * actual_count));
    sum += (node->price * actual_count);
    discount_sum += (node->price * (node->count - actual_count));

    gListInsert(g_list, (void *)node);

    return 0;
}

#include "head.h"

extern list_t *my_price;

int main(int argc, char *args[])
{
    char *buffer = (char *)malloc(MAX_LINE_LEN);;
    char *result = (char *)malloc(MAX_LINE_LEN);;
    int number;
    int dwnum;

    dwnum = GetPrice();
    if(dwnum != 0)
    {
	return dwnum;
    }
    list_t *L = ListInit();
    if(L == NULL)
    {
	return ERRNO_NULL_POINTER;
    }

    while(fgets(buffer, MAX_LINE_LEN, stdin))
    {
	number = 0;
	memset(result, 0, MAX_LINE_LEN);
	dwnum = ParseLine(buffer, result, &number);

	if(dwnum == 0)
	{
	    item_t* curnode;
	    if((curnode = ListIsNodeInListById(L, result)) != NULL)
	    {
		curnode->count += number;
		continue;
	    }

	    item_t * node = ItemMakeitem(result, number);
	    if(node == NULL)
	    {
		return ERRNO_MAKEITEM_FAIL;
	    }

	    dwnum = ListPushBack(L, (void*) node);
	    if(dwnum != 0)
	    {
		return ERRNO_LISTPUSHBACK_FAIL;
	    }
	}
    }

    dwnum = CalculateSum(L);
    if(dwnum != 0)
    {
	return ERRNO_CALCULATESUM_FAIL;	
    }

    ListFree(L);
    ListFree(my_price);
    free(buffer);
    free(result);
    return 0;
}

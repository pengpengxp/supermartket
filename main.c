#include "head.h"

extern list_t *my_price;

int main(int argc, char *args[])
{
    char *buffer = (char *)malloc(MAX_LINE_LEN);;
    char *result = (char *)malloc(MAX_LINE_LEN);;
    int number;
    int dwnum;

    GetPrice();

    list_t *L = ListInit();

    FILE * file = fopen("input.txt", "r");
    while(fgets(buffer, MAX_LINE_LEN, file))
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
	    ListPushBack(L, (void*) node);
	}
    }

    /* ListShow(L); */
    CalculateSum(L);
    ListFree(L);

    ListFree(my_price);

    fclose(file);
    free(buffer);
    free(result);
    return 0;
}

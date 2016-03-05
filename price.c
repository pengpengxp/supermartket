#include "price.h"

list_t *my_price;

int GetPrice()
{
    my_price = ListInit();
    
    FILE *file = fopen("price.txt", "r");
    char *buffer = (char *)malloc(MAX_LINE_LEN);;
    char *p, *begin, *end;

    char name[MAX_NAME_LEN];
    double price;
    int type;			/* 0x01->95折, 0x10->买二送一 */
    char id[MAX_ID_LEN];	/* for example: 'ITEM000001' */
    char quantifier[MAX_QUANTIFIER_LEN];

    while(fgets(buffer, MAX_LINE_LEN, file))
    {
	/* printf("buffer = %s\n", buffer); */
	sscanf(buffer,"%s %lf %d %s %s\n" ,name, &price, &type,id, quantifier);
	DeleteDoubleQuotes(name);
	DeleteDoubleQuotes(quantifier);
	DeleteDoubleQuotes(id);

	price_t *temp_node = (price_t*)malloc(sizeof(price_t));
	temp_node->price = price;
	temp_node->type = type;
	strncpy(temp_node->name, name, strlen(name) + 1);
	strncpy(temp_node->id, id, strlen(id) + 1);
	strncpy(temp_node->quantifier, quantifier, strlen(quantifier) + 1);

	/* printf("name = %s, price = %f, type = %d, id = %s, quantifier = %s\n",temp_node->name ,temp_node->price, temp_node->type, temp_node->id, temp_node->quantifier); */

	ListPushBack(my_price, (void*)temp_node);
	
    }

    /* printf("size = %d\n",my_price->size); */
    /* ListShowPrice(my_price); */

    fclose(file);
    free(buffer);
    return 0;
}

int DeleteDoubleQuotes(char *s)
{
    if(s == NULL)
	return -1;
    int len = strlen(s);

    char *buffer = (char*)malloc(len - 1);
    memset(buffer, 0, (len -1 ));
    memcpy(buffer, (s + 1), (len - 2));

    memset(s, 0, len);
    memcpy(s, buffer, (len - 1));
    free(buffer);
    return 0;
}

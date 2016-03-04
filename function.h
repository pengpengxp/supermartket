#ifndef _FUNCTION_
#define _FUNCTION_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "head.h"
#include "list.h"

/* other function */
int ParseLine(char * buffer, char * result, int * num);
int CalculateSum(list_t *L);
int WhichType(int type);
int CalculateCommon(item_t *node);
int CalculateDiscount(item_t *node);
int CalculateGift(item_t *node);
#endif

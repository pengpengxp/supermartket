#ifndef _HEAD_
#define _HEAD_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* my lib */
#include "list.h"
#include "item.h"
#include "function.h"
#include "price.h"

/* some macro */
#define MAX_LINE_LEN 1024

/* errno */
enum
{
    ERRNO_NULL_POINTER = 1,
    ERRNO_MAKEITEM_FAIL,
    ERRNO_LISTPUSHBACK_FAIL,
    ERRNO_CALCULATESUM_FAIL,
};

#endif

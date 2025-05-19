
#ifndef __DIV_H__
#define __DIV_H__

#include "calculator.h"

#define TYPE_DIV (div_get_type())
G_DECLARE_FINAL_TYPE(Div, div, , DIV, Calculator)

struct _Div
{
    Calculator parent_instance;
};


#endif
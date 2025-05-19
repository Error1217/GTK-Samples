
#ifndef __ADD_H__
#define __ADD_H__

#include "calculator.h"

#define TYPE_ADD (add_get_type())
G_DECLARE_FINAL_TYPE(Add, add, , ADD, Calculator)

struct _Add
{
    Calculator parent_instance;
};


#endif
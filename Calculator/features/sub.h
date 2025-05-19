
#ifndef __SUB_H__
#define __SUB_H__

#include "calculator.h"

#define TYPE_SUB (sub_get_type())
G_DECLARE_FINAL_TYPE(Sub, sub, , SUB, Calculator)

struct _Sub
{
    Calculator parent_instance;
};

#endif
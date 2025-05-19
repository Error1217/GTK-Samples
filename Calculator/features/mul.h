
#ifndef __MUL_H__
#define __NUL_H__

#include "calculator.h"

#define TYPE_MUL (mul_get_type())
G_DECLARE_FINAL_TYPE(Mul, mul, , MUL, Calculator)

struct _Mul
{
    Calculator parent_instance;
};


#endif
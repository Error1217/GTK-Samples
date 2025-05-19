
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <glib-object.h>

#define TYPE_CALCULATOR (calculator_get_type())

G_DECLARE_DERIVABLE_TYPE (Calculator, calculator, , CALCULATOR, GObject)

struct _CalculatorClass{
    GObjectClass parent_class;

    int (*compute)(Calculator *self, int num1, int num2);
};

int compute(Calculator *self, int num1, int num2);

#endif

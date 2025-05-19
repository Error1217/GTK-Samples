
#include "div.h"

G_DEFINE_TYPE(Div, div, TYPE_CALCULATOR)

static int div_compute(Calculator *self, int num1, int num2)
{
    return num1 / num2;
}

static void div_class_init(DivClass *klass)
{
    CalculatorClass *parent = _CALCULATOR_CLASS(klass);
    parent->compute = div_compute;
}

static void div_init(Div *self)
{
}

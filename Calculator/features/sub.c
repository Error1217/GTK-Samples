
#include "sub.h"

G_DEFINE_TYPE(Sub, sub, TYPE_CALCULATOR)

static int sub(Calculator *self, int num1, int num2)
{
    return num1 - num2;
}

static void sub_class_init(SubClass *klass)
{
    CalculatorClass *parent = _CALCULATOR_CLASS(klass);
    parent->compute = sub;
}

static void sub_init(Sub *self)
{

}

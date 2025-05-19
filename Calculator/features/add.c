#include "add.h"

G_DEFINE_TYPE(Add, add, TYPE_CALCULATOR)

static int add(Calculator *self, int num1, int num2)
{
    int result = num1 + num2;
    return result;
}

static void add_class_init(AddClass *klass)
{
    CalculatorClass *parent_class = _CALCULATOR_CLASS(klass);
    parent_class->compute = add;
}

static void add_init(Add *self)
{
    // g_print("[add init]");
}
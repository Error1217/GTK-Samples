
#include "mul.h"

G_DEFINE_TYPE(Mul, mul, TYPE_CALCULATOR)

static int mul(Calculator *self, int num1, int num2)
{
    return num1 * num2;
}

static void mul_class_init(MulClass *klass)
{
    CalculatorClass *parent = _CALCULATOR_CLASS(klass);
    parent->compute = mul;
}

static void mul_init(Mul *self)
{

}
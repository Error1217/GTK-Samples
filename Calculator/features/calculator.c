#include "calculator.h"

G_DEFINE_TYPE(Calculator, calculator, G_TYPE_OBJECT)

static int base_compute(Calculator *self, int num1, int num2) {
    return 0;
}

int compute(Calculator *self, int num1, int num2) {
    CalculatorClass *klass = _CALCULATOR_GET_CLASS(self);
    if(klass->compute){
        klass->compute(self, num1, num2);
    }
}

static void calculator_class_init(CalculatorClass *klass){
    klass->compute = base_compute;
}

static void calculator_init(Calculator *self){
    // g_print("[calculator init]");
}


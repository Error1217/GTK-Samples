#ifndef __UI_CALCULATOR_H__
#define __UI_CALCULATOR_H__

#include<gtk/gtk.h>
#include "../features/calculator.h"

#define WINDOW_TITLE "calculator"
#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 400
#define WINDOW_DORDER_WIDTH 10

#define BUTTON_ROW 4
#define BUTTON_COL 4

#define CSS_PATH "E:\\WindowDevelop\\gtk-Samples\\Calculator\\style\\main.css"

typedef struct {
    GtkWidget *window;
    GtkWidget *entry;
    GtkWidget *buttons[BUTTON_ROW][BUTTON_COL];
} UICalculator;

typedef struct {
    UICalculator *ui;
    Calculator *add, *sub, *mul, *div;

    Calculator *current_op;

    int num1;
    gboolean waiting_for_num2;
} CalculatorContext;

#define UI_CALCULATOR (UICalculator *)
#define CALCULATOR_CONTEXT (CalculatorContext *)

void init_ui_calculator(UICalculator *ui, GtkApplication *app);
void connect_signals(UICalculator *ui, CalculatorContext *ctx);

#endif
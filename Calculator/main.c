#include "features/calculator.h"
#include "features/add.h"
#include "features/sub.h"
#include "features/mul.h"
#include "features/div.h"

#include "ui/ui_calculator.h"


void on_active(GtkApplication *app, gpointer user_data)
{
    UICalculator *ui = g_new0(UICalculator, 1);
    CalculatorContext *ctx = g_new0(CalculatorContext, 1);

    init_ui_calculator(ui, app);

    ctx->ui = ui;
    ctx->add = g_object_new(TYPE_ADD, NULL);
    ctx->sub = g_object_new(TYPE_SUB, NULL);
    ctx->mul = g_object_new(TYPE_MUL, NULL);
    ctx->div = g_object_new(TYPE_DIV, NULL);

    connect_signals(ui, ctx);

    gtk_widget_show_all(ui->window);
}

static int run(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.Calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_active), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}




int main(int argc, char **argv){    
    int status;
    status = run(argc, argv);
    
    
    return status;
}




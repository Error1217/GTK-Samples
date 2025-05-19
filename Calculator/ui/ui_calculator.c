
#include "ui_calculator.h"

const char *button_labels[4][4] = {
    {"7", "8", "9", "/"},
    {"4", "5", "6", "X"},
    {"1", "2", "3", "-"},
    {"C", "0", "=", "+"}};

void init_ui_calculator(UICalculator *ui, GtkApplication *app)
{
    // init
    ui->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(ui->window), WINDOW_TITLE);
    gtk_window_set_default_size(GTK_WINDOW(ui->window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_container_set_border_width(GTK_CONTAINER(ui->window), WINDOW_DORDER_WIDTH);
    gtk_window_set_resizable(GTK_WINDOW(ui->window), FALSE);

    // 布局方式
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 25);
    gtk_container_add(GTK_CONTAINER(ui->window), box);

    // 輸入框
    ui->entry = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(ui->entry), FALSE);
    gtk_entry_set_alignment(GTK_ENTRY(ui->entry), 1.0);
    gtk_box_pack_start(GTK_BOX(box), ui->entry, TRUE, TRUE, 0);

    //
    GtkWidget *grid = gtk_grid_new();

    gtk_grid_set_row_spacing(GTK_GRID(grid), 2);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 2);

    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

    for (int row = 0; row < BUTTON_ROW; row++)
    {
        for (int col = 0; col < BUTTON_COL; col++)
        {
            ui->buttons[row][col] = gtk_button_new_with_label(button_labels[row][col]);
            // gtk_widget_set_name(ui->buttons[row][col], "button");

            gtk_widget_set_hexpand(ui->buttons[row][col], TRUE);
            gtk_widget_set_vexpand(ui->buttons[row][col], TRUE);

            gtk_grid_attach(GTK_GRID(grid), ui->buttons[row][col], col, row, 1, 1);
        }
    }

    // 組件命名
    gtk_widget_set_name(ui->window, "window");
    gtk_widget_set_name(ui->entry, "entry");
    for (int row = 0; row < BUTTON_ROW; row++)
    {
        for (int col = 0; col < BUTTON_COL; col++)
        {
            gtk_widget_set_name(ui->buttons[row][col], "button");
        }
    }

    // 載入樣式
    GError *error = NULL;

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_file(provider, g_file_new_for_path(CSS_PATH), &error);
    GtkStyleContext *context = gtk_widget_get_style_context(ui->window);

    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);
}

static void on_button_clickd(GtkWidget *button, gpointer data)
{
    CalculatorContext *ctx = CALCULATOR_CONTEXT(data);
    const char *label = gtk_button_get_label(GTK_BUTTON(button));
    const char *current = gtk_entry_get_text(GTK_ENTRY(ctx->ui->entry));

    if (strcmp(label, "C") == 0)
    {
        gtk_entry_set_text(GTK_ENTRY(ctx->ui->entry), "");
        ctx->current_op = NULL;
        ctx->num1 = 0;
        ctx->waiting_for_num2 = FALSE;
        return;
    }

    if (strcmp(label, "=") == 0 && ctx->current_op)
    {

        int num2 = atoi(current);
        int result = compute(ctx->current_op, ctx->num1, num2);

        char result_str[50];
        snprintf(result_str, sizeof(result_str), "%d", result);

        gtk_entry_set_text(GTK_ENTRY(ctx->ui->entry), result_str);

        ctx->current_op = NULL;
        ctx->waiting_for_num2 = FALSE;
        return;
    }

    if (strcmp(label, "+") == 0 || strcmp(label, "-") == 0 || strcmp(label, "X") == 0 || strcmp(label, "/") == 0)
    {

        if (ctx->current_op)
        {
            int num2 = atoi(current);
            int result = compute(ctx->current_op, ctx->num1, num2);
            ctx->num1 = result;
        }
        else
        {
            ctx->num1 = atoi(current);
            ctx->waiting_for_num2 = TRUE;
        }

        gtk_entry_set_text(GTK_ENTRY(ctx->ui->entry), "");

        if (strcmp(label, "+") == 0)
            ctx->current_op = ctx->add;
        if (strcmp(label, "-") == 0)
            ctx->current_op = ctx->sub;
        if (strcmp(label, "X") == 0)
            ctx->current_op = ctx->mul;
        if (strcmp(label, "/") == 0)
            ctx->current_op = ctx->div;
        return;
    }

    gchar *new_text = g_strconcat(current, label, NULL);
    gtk_entry_set_text(GTK_ENTRY(ctx->ui->entry), new_text);
    g_free(new_text);
}

void connect_signals(UICalculator *ui, CalculatorContext *ctx)
{
    for (int row = 0; row < BUTTON_ROW; row++)
    {
        for (int col = 0; col < BUTTON_COL; col++)
        {
            g_signal_connect(ui->buttons[row][col], "clicked", G_CALLBACK(on_button_clickd), ctx);
        }
    }
}
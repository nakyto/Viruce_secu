#include <gtk/gtk.h>

typedef struct{
  gboolean isRunning;
  gboolean play;
  gdouble timeRemaning;
} TIMER;

typedef TIMER *Timer;

typedef struct{
  Timer timer;
  GtkWidget* label;
  GtkWidget* button;
  GtkWidget* spinButton;
} DATA;

typedef DATA *Data;

void updateRemaningTime(Data data){
  GtkLabel* label = data->label;
  Timer timer = data->timer;
  
  gchar *str = g_strdup_printf ("rest time %d minutes %d seconds.", (gint)timer->timeRemaning/60, (gint)timer->timeRemaning%60);
  gtk_label_set_text (GTK_LABEL (label), str);
  g_free(str);
}

gboolean 
time_handler(Data data) {
  Timer timer = data->timer;

  if(timer->isRunning)
    if(timer->timeRemaning != 0)
      timer->timeRemaning --;
    else if(timer->timeRemaning == 0)
    {
      if(timer->play == TRUE){
        system("aplay ALARM.WAV");
        gtk_button_set_label((GtkButton*)data->button, "start timer");
        timer->isRunning = FALSE;
        timer->timeRemaning = 0;
      }
    }

  updateRemaningTime(data);

  if(timer->isRunning)
    return TRUE;
  else
    return FALSE;
}

static void
spin_clicked (GtkSpinButton *spinbutton, Data data)
{
   GtkWidget *label = data->label;
   gint value = gtk_spin_button_get_value_as_int (spinbutton);

   gchar *str = g_strdup_printf ("rest time %d minutes.", value);
   gtk_label_set_text (GTK_LABEL (label), str);

   g_free(str);
}

static void
button_clicked (GtkWidget *button, Data data)
{
  Timer timer = data->timer;
  GtkLabel *label = data->label;

  if(timer->isRunning){
    gtk_button_set_label((GtkButton*)button, "start timer");
    timer->isRunning = FALSE;
    timer->timeRemaning = 0;
  }
  else{
    gtk_button_set_label((GtkButton*)button, "stop timer");
    timer->play = TRUE;
    timer->isRunning = TRUE;
    timer->timeRemaning = gtk_spin_button_get_value (data->spinButton)*60;
    g_timeout_add(1000, (GSourceFunc) time_handler, data);
  }

  updateRemaningTime(data);
}

static void
activate (GtkApplication *app, gpointer user_data)
{
  /* Declare variables */
  GtkWidget *window;
  GtkWidget *label;
  GtkWidget *grid;
  GtkWidget *spinButton;
  GtkWidget *button;
  GtkAdjustment *adjustment;


  printf("timer declaration \n");
  /* Timer */
  Timer timer = malloc(sizeof(TIMER));
  timer->isRunning = FALSE;
  timer->timeRemaning = 0;
  timer->play = TRUE;

  /* Window */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "mon timer");
  gtk_window_set_default_size (GTK_WINDOW (window), 300, 150);
  gtk_container_set_border_width (GTK_CONTAINER (window), 5);

  /* label */
  label = gtk_label_new ("");

  /* SpinButton */
  adjustment = gtk_adjustment_new (0, 0, 100, 1, 0, 0);
  spinButton = gtk_spin_button_new (adjustment, 1, 0);
  gtk_spin_button_set_value(spinButton, 0);
  gtk_widget_set_hexpand (spinButton, TRUE);
  

  /* Button */
  adjustment = gtk_adjustment_new (0, 50, 100, 1, 0, 0);
  button = gtk_button_new();
  gtk_widget_set_hexpand (button, TRUE);
  gtk_button_set_label(button, "start timer");


  /* Data */
  Data data = malloc(sizeof(DATA));
  data->timer = timer;
  data->label = label;
  data->spinButton = spinButton;
  data->button = button;

  /* Signals */
  g_signal_connect (spinButton, "value-changed", G_CALLBACK (spin_clicked), data);
  g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), data);

  /* grid */
  grid = gtk_grid_new ();
  gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_column_homogeneous (GTK_GRID (grid), TRUE);
  gtk_grid_attach (GTK_GRID (grid), spinButton, 0, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), label, 0, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  gtk_container_add (GTK_CONTAINER (window), grid);
  gtk_widget_show_all (window);
}


int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
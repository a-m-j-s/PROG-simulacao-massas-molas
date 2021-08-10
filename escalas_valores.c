#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>
#include"main.h"

//funcao que cria escalas argumentos:valor minimo, maximo, inccremento, valor inicial
GtkWidget *
cria_escala (double min,double max,double incremento,double valor)
{
  GtkWidget *w ;

  w = gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, min, max, incremento);
  gtk_scale_set_digits (GTK_SCALE(w),3);
  gtk_scale_set_value_pos (GTK_SCALE(w), GTK_POS_TOP);
  gtk_range_set_value (GTK_RANGE(w),valor);

  return w;
}

//funcao que cria spinbuttons, argumentos: valor inicial, minimo, maximo, incremento
GtkWidget*
criar_coisa_para_inserir_valores (double vi, double min, double max, double in)
{

  GtkWidget      *spinButton ;
  GtkAdjustment  *adj1       ;

  adj1 = (GtkAdjustment *) gtk_adjustment_new (vi, min, max, in, 1.0, 0);
  spinButton = gtk_spin_button_new (adj1, 0, 2);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON(spinButton), TRUE);

  return spinButton;
}

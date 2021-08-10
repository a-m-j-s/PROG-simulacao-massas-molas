#include"main.h"
#include<gtk/gtk.h>
#include <stdio.h>
#include<math.h>


gboolean
mudar_valor_pos1x(GtkWidget *w)
{  double x,y;

   x=pos1x;

   pos1x=gtk_range_get_value (GTK_RANGE(w));
   pos1xi=pos1x;

   y=pos1x-x;

   gtk_range_set_range(GTK_RANGE(sx22),pos1x,pos1x+L1-L2);

   pos2x=pos2x+y;
   pos2xi=pos2xi+y;

   gtk_range_set_value(GTK_RANGE(sx22),pos2x);

   return FALSE;
}

gboolean
mudar_valor_m1(GtkWidget *w)
{
   m1=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_v1(GtkWidget *w)
{
   v1=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_pos2x(GtkWidget *w)
{
   pos2x=gtk_range_get_value (GTK_RANGE(w));
   pos2xi=pos2x;
   return FALSE;
}

gboolean
mudar_valor_m2(GtkWidget *w)
{
   m2=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_v2(GtkWidget *w)
{
   v2=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}


gboolean
mudar_valor_L1(GtkWidget *w)
{
   L1=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   gtk_range_set_range(GTK_RANGE(sx22),pos1x,pos1x+L1-L2);
   return FALSE;
}

gboolean
mudar_valor_H1(GtkWidget *w)
{
   H1=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_L2(GtkWidget *w)
{
   L2=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   gtk_range_set_range(GTK_RANGE(sx22),pos1x,pos1x+L1-L2);
   return FALSE;
}

gboolean
mudar_valor_H2(GtkWidget *w)
{
   H2=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_k1(GtkWidget *w)
{
   k1=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_h1(GtkWidget *w)
{
   h1=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_n1(GtkWidget *w)
{
   n1=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}


gboolean
mudar_valor_k2(GtkWidget *w)
{
   k2=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_h2(GtkWidget *w)
{
   h2=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_n2(GtkWidget *w)
{
   n2=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_k3(GtkWidget *w)
{
   k3=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_h3(GtkWidget *w)
{
   h3=gtk_spin_button_get_value (GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_n3(GtkWidget *w)
{
   n3=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_l01(GtkWidget *w)
{
   l01=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_l02(GtkWidget *w)
{
   l02=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_l03(GtkWidget *w)
{
   l03=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_escaladx(GtkWidget *w)
{
   escaladx=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_escalady(GtkWidget *w)
{
   escalady=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}


gboolean
mudar_valor_escalagx(GtkWidget *w)
{
   escalagx=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
mudar_valor_escalagy(GtkWidget *w)
{
   escalagy=gtk_spin_button_get_value(GTK_SPIN_BUTTON(w));
   return FALSE;
}

gboolean
color_chooser_color2 (GtkWidget *w)
{
  gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER(w), &color2);

  return FALSE;
}

gboolean
color_chooser_color1 (GtkWidget *w)
{
  gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER(w), &color1);

  return FALSE;
}

gboolean
cb_buttonx1 (GtkWidget  *w    ,
            gpointer    data )
{
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(w)))
    condicaox1=1;
  else
  {
    condicaox1=0;
  }
  return FALSE;
}


gboolean
cb_buttonx2 (GtkWidget  *w    ,
            gpointer    data )
{
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(w)))
    condicaox2=1;
  else
  {
    condicaox2=0;

  }
  return FALSE;
}





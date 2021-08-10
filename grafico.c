
#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>
#include"main.h"
#include"funcao_mola.h"
#include"funcao_mov.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


gboolean
cb_draw_event_grafico(GtkWidget  *darea , cairo_t    *cr    , gpointer    data )
{
  GtkAllocation  alloc1 ;
  double x0,y0,xf,yf,xbarra,ybarra;
  int i,max,diferenca;

  gtk_widget_get_allocation (darea, &alloc1);
  cairo_scale (cr, escalagx, escalagy);
  // o zero do cairo e o canto superior esquerdo x0e y0 estao na interseccao das duas retas---------------------------------------------
  x0=(alloc1.width*0.05)*(1/escalagx);
  y0=(alloc1.height*(1-0.05))*(1/escalagy);
  xf=(alloc1.width*(1-0.05))*(1/escalagx);
  yf=(alloc1.height*0.05)*(1/escalagy);
  max=pontosmaximo;
  pontosmaximo=(xf-x0)/5;



 //eixos------------------------------------------------------------------------------------------------------------------------------

  cairo_rectangle (cr,0,0,x0, alloc1.height*(1/escalagy));
  cairo_rectangle(cr,0,0,alloc1.width*(1/escalagx),yf);
  cairo_rectangle(cr,0,y0,alloc1.width*(1/escalagx),y0);
  cairo_rectangle(cr,xf,yf,alloc1.width*(1/escalagx),alloc1.height*(1/escalagy));
  cairo_set_source_rgb (cr, 0.9, 0.9, 0.9);
  cairo_stroke_preserve (cr);
  cairo_fill (cr);

  /*cairo_rectangle(cr,x0,yf,xf-x0,y0-yf);
  cairo_set_source_rgb (cr, 0.85, 0.85, 0.85);
  cairo_stroke_preserve (cr);
  cairo_fill (cr);*/


  cairo_move_to (cr, x0,y0 );
  cairo_set_line_width (cr, 4.0*(1/escalagx));
  cairo_line_to (cr, x0, yf);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

  cairo_move_to (cr, x0,y0);
  cairo_set_line_width (cr, 4.0*(1/escalagy));
  cairo_line_to (cr, xf, y0);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

 xbarra=x0+50;
  while(xbarra<xf)
  {
    cairo_move_to(cr,xbarra,y0);
    cairo_line_to(cr,xbarra,y0+13*(1/escalagy));
    cairo_set_line_width (cr, 1.5*(1/escalagx));
    cairo_stroke(cr);
    xbarra=xbarra+50;
  }


  ybarra=y0-50;
  while(ybarra>yf)
  {
    cairo_move_to(cr,x0-13*(1/escalagx),ybarra);
    cairo_line_to(cr,x0,ybarra);
    cairo_set_line_width (cr, 1.5*(1/escalagy));
    cairo_stroke(cr);
    ybarra=ybarra-50;
  }

  cairo_move_to (cr,xf-10,y0+20);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_set_font_size (cr,15);
  cairo_show_text (cr, "t(s)");

  if(condicaox1==1)
  {
    cairo_move_to (cr,5,yf+5);
    cairo_set_source_rgb (cr,color1.red,color1.green,color1.blue);
    cairo_set_font_size (cr,15);
    cairo_show_text (cr, "x1 (m)");
  }

  if(condicaox2==1)
  {
    cairo_move_to (cr,5,yf+20);
    cairo_set_source_rgb (cr,color2.red,color2.green,color2.blue);
    cairo_set_font_size (cr,15);
    cairo_show_text (cr, "x2 (m)");
  }

  //------------------------


  if(condicao==1)
  {

    if(max==pontosmaximo)
    {
      if(contador<pontosmaximo)
       {
         vt[contador]=5*contador;
         vx1[contador]=pos1x*500;
         vx2[contador]=pos2x*500;
         ++contador;
      }
     else
      {
        for(i=0;i<pontosmaximo-1;++i)
          {
           vx1[i]=vx1[i+1];
           vx2[i]=vx2[i+1];
          }
        vx1[i]=pos1x*500;
        vx2[i]=pos2x*500;
     }

   }
   else
   {

    if(pontosmaximo<contador)
      {
         diferenca=contador-pontosmaximo+1;
         contador=pontosmaximo;
         for(i=0;i<pontosmaximo-1;++i)
           {
             vx1[i]=vx1[i+diferenca];
             vx2[i]=vx2[i+diferenca];
           }
         vx1[i]=pos1x*500;
         vx2[i]=pos2x*500;
         vx1=(double*)realloc(vx1,pontosmaximo*sizeof(double));
         vx2=(double*)realloc(vx2,pontosmaximo*sizeof(double));
      }

    else
      {
        vx1=(double*)realloc(vx1,pontosmaximo*sizeof(double));
        vx2=(double*)realloc(vx2,pontosmaximo*sizeof(double));
        vt=(double*)realloc(vt,pontosmaximo*sizeof(double));
        vt[contador]=5*contador;
        vx1[contador]=pos1x*500;
        vx2[contador]=pos2x*500;
        ++contador;

     }
   }
  }

 //Desenhar---------------------------------------------------------------------
  if(contador<pontosmaximo)
   {
      for(i=0;i<contador-1;++i)
        {
           if(condicaox1==1)
           {
             cairo_move_to(cr,x0+vt[i],y0-vx1[i]);
             cairo_set_line_width (cr, 2.0*(1/escalagy));
             cairo_set_source_rgb (cr, color1.red,color1.green,color1.blue);
             cairo_line_to(cr,x0+vt[i+1],y0-vx1[i+1]);
             cairo_stroke(cr);
          }

          if(condicaox2==1)
          {
            cairo_move_to(cr,x0+vt[i],y0-vx2[i]);
            cairo_set_line_width (cr, 2.0*(1/escalagy));
            cairo_line_to(cr,x0+vt[i+1],y0-vx2[i+1]);
            cairo_set_source_rgb (cr, color2.red, color2.green, color2.blue);
            cairo_stroke(cr);
          }
        }
    }
  else
    {
      for(i=0;i<pontosmaximo-1;++i)
        {

        if(condicaox1==1)
          {
            cairo_move_to(cr,x0+vt[i],y0-vx1[i]);
            cairo_set_line_width (cr, 2.0*(1/escalagy));
            cairo_line_to(cr,x0+vt[i+1],y0-vx1[i+1]);
            cairo_set_source_rgb (cr, color1.red,color1.green,color1.blue);
            cairo_stroke(cr);
          }
        if(condicaox2==1)
          {
            cairo_move_to(cr,x0+vt[i],y0-vx2[i]);
            cairo_line_to(cr,x0+vt[i+1],y0-vx2[i+1]);
            cairo_set_source_rgb (cr, color2.red, color2.green, color2.blue);
            cairo_stroke(cr);
          }

       }

  }



  return FALSE;
}



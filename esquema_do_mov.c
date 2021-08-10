#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>
#include"main.h"
#include"funcao_mola.h"
#include"funcao_mov.h"


//variaveis globais necessarias
//posicao de objeto 1- pos1x, posicao de objeto 2- pos2x
//comprimento de objeto 1 L1 e objeto 2 L2
//altura de objeto 1 e 2 H1 e H2
//h1 h2 h3 alturas das molas
//n1 n2 n3 numero de espiras das molas

gboolean
cb_draw_event_esquema(GtkWidget  *darea ,cairo_t    *cr    ,gpointer    data )
{


  GtkAllocation  alloc1 ;
  double y0,yf,x0,xf,xbarra;
  double x1,y1,x2,y2,x1i,x2i;
  double Hd1,Hd2,Ld1,Ld2,hd1,hd2,hd3;


  gtk_widget_get_allocation (darea, &alloc1);
  cairo_scale (cr, escaladx, escalady);
  // o zero do cairo e o canto superior esquerdo x0e y0 estao na interseccao das duas retas------
  x0=(alloc1.width*0.05)*(1/escaladx);
  y0=(alloc1.height*(1-0.05))*(1/escalady);
  xf=(alloc1.width*(1-0.05))*(1/escaladx);
  yf=(alloc1.height*0.05)*(1/escalady);

  gtk_range_set_range(GTK_RANGE(sx11),0,xf/1000-L1-x0/1000);

  Hd1=H1*1000;
  Hd2=H2*1000;
  Ld1=L1*1000;
  Ld2=L2*1000;
  hd1=h1*1000;
  hd2=h2*1000;
  hd3=h3*1000;
  //printf("func %lf %lf\n",x0,xf);
  //mudar posicoes do centro de massa para o canto superior esquerdo do retangulo-----------
  x1=x0+pos1x*1000;
  x1i=x0+pos1xi*1000;
  y1=y0-Hd1-5;
  x2=x0+pos2x*1000;
  x2i=x0+pos2xi*1000;
  y2=y0-Hd1-Hd2-10;

  //eixos----------------------------------------------------------------------------

  cairo_rectangle (cr,0,0,x0, alloc1.height*(1/escalady));
  cairo_rectangle(cr,0,0,alloc1.width*(1/escaladx),yf);
  cairo_rectangle(cr,0,y0,alloc1.width*(1/escaladx),y0);
  cairo_rectangle(cr,xf,yf,alloc1.width*(1/escaladx),alloc1.height*(1/escalady));
  cairo_set_source_rgb (cr, 0.9,0.9,0.9);
  cairo_stroke_preserve (cr);
  cairo_fill (cr);

  cairo_move_to (cr, x0,y0 );
  cairo_set_line_width (cr, 4.0*(1/escaladx));
  cairo_line_to (cr, x0, yf);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

  cairo_move_to (cr, x0,y0);
  cairo_set_line_width (cr, 4.0*(1/escalady));
  cairo_line_to (cr, xf, y0);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

  xbarra=x0+100;
  while(xbarra<xf)
  {
    cairo_move_to(cr,xbarra,y0);
    cairo_line_to(cr,xbarra,y0+13*(1/escalady));
    cairo_set_line_width (cr, 1.5*(1/escaladx));
    cairo_stroke(cr);
    xbarra=xbarra+100;
  }





  //retangulo1-----------------------------------------------------------------------
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr,x1 ,y1, Ld1, Hd1);
  cairo_stroke_preserve (cr);
  cairo_set_source_rgb (cr, color1.red, color1.green, color1.blue);
  cairo_fill (cr);


  //Mola1-----------------------------------------------------------------------------
  desenhar_mola(x0,y0-5,x1i-x0,x1-x0,hd1,n1,cr);

  //barras verticais------------------------------------------------------------------
  cairo_move_to (cr, x1,y0-5);
  cairo_line_to (cr, x1,y0-Hd1-2*Hd2-10);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

  cairo_move_to (cr, x1+Ld1,y0-5);
  cairo_line_to (cr, x1+Ld1,y0-Hd1-2*Hd2-10);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke(cr);

  //retangulo 2----------------------------------------------------------------------
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr,x2 ,y2, Ld2, Hd2);
  cairo_stroke_preserve (cr);
  cairo_set_source_rgb (cr, color2.red, color2.green, color2.blue);
  cairo_fill (cr);


  //Mola 2---------------------------------------------------------------------------
  desenhar_mola(x1,y0-Hd1-10,x2i-x1i,x2-x1,hd2,n2,cr);


  //Mola 3---------------------------------------------------------------------------
  desenhar_mola(x1+Ld1,y0-Hd1-10,-((x1i+Ld1)-(x2i+Ld2)),-((x1+Ld1)-(x2+Ld2)),hd3,n3,cr);


  if(condicaolegendas==1)
  {
    cairo_move_to (cr,x1,y0-10);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_set_font_size (cr,15);
    cairo_show_text (cr, "Objeto 1");
    cairo_stroke (cr);

    cairo_move_to (cr,x0+5,y0-hd1-10);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_show_text (cr, "Mola 1");
    cairo_stroke (cr);

    cairo_move_to (cr,x2,y1-10);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_show_text (cr, "Objeto 2");
    cairo_stroke (cr);

    cairo_move_to (cr,x1+5,y1-Hd2-10);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_show_text (cr, "Mola 2");
    cairo_stroke (cr);

    cairo_move_to (cr,x1+Ld1-60,y1-Hd2-10);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_show_text (cr, "Mola 3");
    cairo_stroke (cr);

  }

  if(condicao==1)
  {
    funcao_mov();
  }

  return FALSE;
}

#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>

#include"main.h"

//as coordenadas xx0 e yy0, sao o vertice do retangulo que contem a mola e que está parado
//xi e o comprimeto inicial da mola
//x e o comprimento varialvel da mola
//h e a altura da mola
//n numero de espiras
//*cr

void
desenhar_mola(double xx0,double yy0, double xi, double x,double h,double n, cairo_t *cr )
{
  double l,L,xx1,xx2,xx3,xx4,xx5,HH1,HH2;
  int i;

  L=xi/10;
  l=(x-2*L)/(2*n+1);

  xx1=xx0+L;
  xx2=xx1+0.5*l;
  xx3=xx2+2*n*l;
  xx4=xx3+0.5*l;
  xx5=xx4+L;
  HH1=yy0-h;
  HH2=yy0-h/2;

  cairo_move_to (cr, xx0,HH2);
  cairo_set_line_width (cr, 2.0);
  cairo_line_to (cr, xx1, HH2);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_line_to (cr, xx2, yy0);
  cairo_stroke(cr);

  for(i=0;i<n;++i)
   {
      cairo_move_to (cr,xx2+(2*i*l) ,yy0 );
      cairo_set_line_width (cr, 2.0);
      cairo_line_to(cr,xx2+(2*i*l)+l,HH1);
      cairo_set_source_rgb (cr, 0, 0, 0);
      cairo_set_line_width (cr, 2.0);
      cairo_line_to(cr,xx2+(2*i*l)+2*l,yy0);
      cairo_set_source_rgb (cr, 0, 0, 0);
      cairo_stroke(cr);
  }

  cairo_move_to (cr,xx3,yy0);
  cairo_set_line_width (cr, 2.0);
  cairo_line_to (cr, xx4, HH2);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_line_to (cr, xx5, HH2);
  cairo_stroke(cr);

}




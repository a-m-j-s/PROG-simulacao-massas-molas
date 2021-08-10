#include<gtk/gtk.h>

  extern double pos1x;//posicao variavel de objeto 1
  extern double pos2x;//posicao variavel de objeto 2
  extern double pos1xi;//posicao inicial de objeto 1
  extern double pos2xi;//posicao inicial de objeto 2
  extern double L1;//=400;//comprimento de retangulo 1
  extern double L2;//=200;//comprimento de retangulo 2
  extern double H1;//=40;//altura de retangulo 1
  extern double H2;//=40;//altura de ratangulo 2
  extern double m1;//massa de objeto 1
  extern double v1;//velocidade inicial de objeto 1
  extern double m2;//massa de objeto 1
  extern double v2;//velocidade inicial de objeto 2
  extern double k1;//contante de mola 1
  extern double k2;//constante de mola 2
  extern double k3;//constante de mola 3
  extern double h1;//altura de mola 1
  extern double h2;//altura de mola 2
  extern double h3;//altura de mola 3
  extern int n1;//numero de espiras para mola 1
  extern int n2;//numero de espiras para mola 2
  extern int n3;//numero de espiras para a mola 3
  extern double l01;//comprimento natural da mola1
  extern double l02;//comprimento natural da mola 2
  extern double l03;//comprimento natural da mola 3
  extern double t;
  extern double dt;
  extern int condicao;//condicao de paragem ou movimento
  extern double escaladx;
  extern double escalady;
  extern double escalagx;
  extern double escalagy;
  extern GtkWidget *sx11;//escala para a posicao de objeto 1
  extern GtkWidget *sx22; //escala para posicao de objeto 2
  extern GtkWidget *bm11;//spinbutton de massa 1
  extern GtkWidget *bv11;//spinbutton de velocidade 1
  extern GtkWidget *bm22;//spinbutton de massa 2
  extern GtkWidget *bv22;//spinbutton de velocidade 2
  extern GtkWidget *sbk1;
  extern GtkWidget *sbk2;
  extern GtkWidget *sbk3;
  extern double *vt;
  extern double *vx1;
  extern double *vx2;
  extern int contador;
  extern int pontosmaximo;
  extern int condicaox1;
  extern int condicaox2;
  extern int condicaolegendas;
  extern GdkRGBA color1;
  extern GdkRGBA color2;
  void
  condicoes_iniciais();


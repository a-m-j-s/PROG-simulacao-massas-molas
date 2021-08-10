#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>
#include <glib.h>
#include<string.h>
#include<stdlib.h>

#include"main.h"
#include"esquema_do_mov.h"
#include"funcao_mola.h"
#include"botoes.h"
#include"escalas_valores.h"
#include "mudar_valores.h"
#include"menu_nova_janela.h"
#include "funcao_mov.h"
#include"grafico.h"

  double pos1x;//posicao variavel de objeto 1
  double pos2x;//posicao variavel de objeto 2
  double pos1xi;//posicao inicial de objeto 1
  double pos2xi;//posicao inicial de objeto 2
  double L1;//=400;//comprimento de retangulo 1
  double L2;//=200;//comprimento de retangulo 2
  double H1;//=40;//altura de retangulo 1
  double H2;//=40;//altura de ratangulo 2
  double m1;//massa de objeto 1
  double v1;//velocidade inicial de objeto 1
  double m2;//massa de objeto 1
  double v2;//velocidade inicial de objeto 2
  double k1;//contante de mola 1
  double k2;//constante de mola 2
  double k3;//constante de mola 3
  double h1;//altura de mola 1
  double h2;//altura de mola 2
  double h3;//altura de mola 3
  int n1;//numero de espiras para mola 1
  int n2;//numero de espiras para mola 2
  int n3;//numero de espiras para a mola 3
  double l01;//comprimento natural da mola1
  double l02;//comprimento natural da mola 2
  double l03;//comprimento natural da mola 3
  double t;//tempo
  double dt;
  int condicao;//condicao de paragem ou movimento
  double escaladx;//escala do desenho e x
  double escalady;//escala do desenho em y
  double escalagx;//escala do grafico em x
  double escalagy;//escala do desenho em y
  GtkWidget *sx11;//escala para a posicao de objeto 1
  GtkWidget *sx22; //escala para posicao de objeto 2
  GtkWidget *bm11;//spinbutton de massa 1
  GtkWidget *bv11;//spinbutton de velocidade 1
  GtkWidget *bm22;//spinbutton de massa 2
  GtkWidget *bv22;//spinbuttton de velocidade
  GtkWidget *sbk1;
  GtkWidget *sbk2;
  GtkWidget *sbk3;
  double *vt,*vx1,*vx2;//vetores para guardar o tempo, posicao do objeto 1 e posicao de objeto 2
  int contador;
  int pontosmaximo;
  int condicaox1;//para desenhar ou nao o grafico correspondente ao objeto 1
  int condicaox2;//para desenhar ou nao o grafico correspondente ao objeto 2
  GdkRGBA color1;//cor do objeto 1
  GdkRGBA color2;//cor do objeto 2
  int condicaolegendas;

//funcao para dar valores as variaveis-----------------------------------------------------------------------------------------------------------
void
condicoes_iniciais()
{
  pos1x= 0.350;
  pos1xi=0.350;
  pos2x=0.400;
  pos2xi=0.400;
  L1=0.400;
  L2=0.200;
  H1=0.040;
  H2=0.040;
  h1=0.040;
  h2=0.020;
  h3=0.020;
  n1=6;
  n2=4;
  n3=4;
  condicao=0;
  m1=5;
  m2=2;
  v1=0.01;
  v2=0.01;
  l01=0.400;
  l02=0.300;
  l03=0.300;
  t=0;
  dt=10e-5;
  k1=1.5;
  k2=1;
  k3=1;
  escaladx=1;
  escalady=1;
  escalagx=1;
  escalagy=1;
  contador=0;
  pontosmaximo=400;
  condicaox1=1;
  condicaox2=1;
  color1.red=0.25;
  color1.green=0.25;
  color1.blue=0.5;
  color1.alpha=1;
  color2.red=1;
  color2.green=0.25;
  color2.blue=0;
  color2.alpha=1;
  condicaolegendas=1;
}


gboolean
time_handler (GtkWidget *widget)
{
 if ((!GTK_IS_WIDGET(widget)) || (!gtk_widget_get_window (widget)))//testar se a janela existe
   return FALSE;

  gtk_widget_queue_draw(widget);

  return TRUE;
}

//----------------------------------------------------------------------------------------------------------------------------
int
main (int argc, char **argv)
{

  //declaracao de variaveis----------------------------------------------------------------------
  GtkWidget *window;//janelas
  GtkWidget *daread,*dareag;//areas de desenho
  GtkWidget *BOX,*BBOX,*box1,*box2,*box22,*box21;//boxes
  GtkWidget *sep,*sep2;//separadores
  GtkWidget *frame1,*frame2;//frames
  GtkWidget *start, *stop,*reset;//botoes
  GtkWidget *lm11,*lx11,*lv11,*lx22,*lm22,*lv22;//labels
  GtkWidget *frame3, *box31, *box311, *box312, *box1m, *box1v, *box1p;
  GtkWidget *frame4, *box41, *box411, *box412, *box2m, *box2v, *box2p;
  GtkWidget *frame5,*box5, *box51, *box52 ,*box53, *labelk1 , *labelk2, *labelk3;
  GtkWidget *menubar;
  int width, height;

  condicoes_iniciais();

  vt=(double*)malloc(500*sizeof(double));
  vx1=(double*)malloc(500*sizeof(double));
  vx2=(double*)malloc(500*sizeof(double));

  gtk_init (&argc, &argv);//--------------------------------------------------------------


  //resolucao do ecra (para a janela ficar do tamaho do ecra)-------------------------------
  width=gdk_screen_width();
  height=gdk_screen_height()-40;


  //Janela--------------------------------------------------------------------------------------------------------
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window),width,height);
  gtk_window_set_title (GTK_WINDOW (window), "Projeto_final");
  gtk_window_maximize(GTK_WINDOW(window));



  //BOX e BBOX-----------------------------------------------------------------------------------------------------
  BBOX=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  gtk_container_add (GTK_CONTAINER(window), BBOX);
  BOX=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
  gtk_box_pack_end(GTK_BOX(BBOX),BOX,TRUE,TRUE,0);




  //box1 e box2---------------------------------------------------------------------------------------------------------
  box1=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  gtk_box_pack_start(GTK_BOX(BOX),box1,TRUE,TRUE,10);

  sep = gtk_separator_new (GTK_ORIENTATION_VERTICAL);
  gtk_box_pack_start (GTK_BOX(BOX), sep, FALSE, TRUE,10);

  box2=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  gtk_box_pack_end(GTK_BOX(BOX),box2,FALSE,TRUE,10);
  gtk_widget_set_size_request (box2, 0.25*width, height);


  //frames em box1-------------------------------------------------------------------------------------------------------
  frame1=gtk_frame_new("Esquema do Movimento");
  gtk_box_pack_start(GTK_BOX(box1),frame1,FALSE,TRUE,5);
  gtk_widget_set_size_request(frame1,0.5*width,0.4*height);
  gtk_frame_set_label_align(GTK_FRAME(frame1),0,1);


  frame2=gtk_frame_new("Grafico");
  gtk_box_pack_end(GTK_BOX(box1),frame2,TRUE,TRUE,5);
  gtk_frame_set_label_align(GTK_FRAME(frame2),0,1);



  //area de desenho com esquema-----------------------------------------------------------------------------------------
  daread=gtk_drawing_area_new ();
  gtk_container_add (GTK_CONTAINER (frame1), daread);
  g_signal_connect (G_OBJECT(daread), "draw", G_CALLBACK(cb_draw_event_esquema), NULL);



  //area de desenho com grafico-------------------------------------------------------------------------------------------
  dareag=gtk_drawing_area_new ();
  gtk_container_add (GTK_CONTAINER (frame2), dareag);
  g_signal_connect (G_OBJECT(dareag), "draw", G_CALLBACK(cb_draw_event_grafico), NULL);



  //em box2------------------------------------------------------------------------------------------------------------------
  box21=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  gtk_box_pack_start(GTK_BOX(box2),box21,TRUE,TRUE,0);

  sep2 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box2), sep2, FALSE, TRUE,0);

  box22=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
  gtk_box_pack_end(GTK_BOX(box2),box22,FALSE,FALSE,20);
  gtk_widget_set_size_request (box22, 0.25*width, height*0.05);




  //botoes em box22 START STOP RESET---------------------------------------------------------------------------------------
  start = gtk_button_new_with_label ("Start");
  gtk_widget_set_size_request (start, 50, 15);
  gtk_box_pack_start (GTK_BOX (box22), start, TRUE, TRUE, 20);
  g_signal_connect (start, "clicked", G_CALLBACK(comecar), NULL);

  stop = gtk_button_new_with_label ("Stop");
  gtk_widget_set_size_request (stop, 50, 15);
  gtk_box_pack_start (GTK_BOX (box22), stop, TRUE, TRUE, 20);
  g_signal_connect (stop, "clicked", G_CALLBACK(parar), NULL);

  reset = gtk_button_new_with_label ("Reset");
  gtk_widget_set_size_request (reset, 50, 15);
  gtk_box_pack_start (GTK_BOX (box22), reset, TRUE, TRUE, 20);
  g_signal_connect(reset,"clicked",G_CALLBACK(reset1),NULL);



  //Objeto 1--------------------------------------------------------------------------------------------------------------------
  GdkRGBA color={0.9,0.9,0.9,1};
  frame3=gtk_frame_new("Objeto 1");
  gtk_box_pack_start(GTK_BOX(box21),frame3,TRUE,TRUE,10);
  gtk_frame_set_label_align(GTK_FRAME(frame3),0.5,1);
  //gtk_widget_override_color (GTK_FRAME(frame3), GTK_STATE_NORMAL, &color1);
  gtk_widget_override_background_color (frame3, GTK_STATE_NORMAL, &color);

  box31=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_container_add(GTK_CONTAINER(frame3),box31);
  box311=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
  gtk_box_pack_start(GTK_BOX(box31),box311,TRUE,TRUE,5);
  box1p=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box311),box1p,TRUE,TRUE,5);
  box312=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
  gtk_box_pack_start(GTK_BOX(box31),box312,TRUE,TRUE,5);
  box1m=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box312),box1m,TRUE,TRUE,5);
  box1v=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box312),box1v,TRUE,TRUE,5);


  lx11=gtk_label_new("Posicao (m)");
  gtk_box_pack_start (GTK_BOX(box1p),lx11,TRUE,TRUE,5);

  sx11= cria_escala (0,2,0.01,pos1x);
  gtk_box_pack_start (GTK_BOX(box1p), sx11, TRUE, FALSE, 3);
  g_signal_connect(G_OBJECT(sx11),"value-changed",G_CALLBACK(mudar_valor_pos1x),NULL);

  lm11=gtk_label_new("Massa (Kg)");
  gtk_box_pack_start (GTK_BOX(box1m),lm11,TRUE,TRUE,5);

  bm11= criar_coisa_para_inserir_valores (m1,0.001,100,0.01);
  gtk_box_pack_start (GTK_BOX (box1m), bm11, TRUE, FALSE, 5);
  g_signal_connect (bm11, "value-changed", G_CALLBACK (mudar_valor_m1), NULL);

  lv11=gtk_label_new("Velocidade (m/s)");
  gtk_box_pack_start (GTK_BOX(box1v),lv11,TRUE,TRUE,5);

  bv11= criar_coisa_para_inserir_valores (v1,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1v), bv11, TRUE, FALSE, 5);
  g_signal_connect (bv11, "value-changed", G_CALLBACK (mudar_valor_v1), NULL);




 //Objeto 2---------------------------------------------------------------------------------------------------------------------------------
  frame4=gtk_frame_new("Objeto 2");
  gtk_box_pack_start(GTK_BOX(box21),frame4,TRUE,TRUE,10);
  gtk_frame_set_label_align(GTK_FRAME(frame4),0.5,1);
  gtk_widget_override_background_color (frame4, GTK_STATE_NORMAL, &color);

  box41=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_container_add(GTK_CONTAINER(frame4),box41);
  box411=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
  gtk_box_pack_start(GTK_BOX(box41),box411,TRUE,TRUE,5);
  box2p=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box411),box2p,TRUE,TRUE,5);
  box412=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
  gtk_box_pack_start(GTK_BOX(box41),box412,TRUE,TRUE,5);
  box2m=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box412),box2m,TRUE,TRUE,5);
  box2v=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box412),box2v,TRUE,TRUE,5);

  lx22=gtk_label_new("Posicao (m)");
  gtk_box_pack_start (GTK_BOX(box2p),lx22,TRUE,TRUE,5);

  sx22= cria_escala (pos1x,pos1x+L1-L2,0.01,pos2x);
  gtk_box_pack_start (GTK_BOX(box2p), sx22, TRUE, FALSE, 3);
  g_signal_connect(G_OBJECT(sx22),"value-changed",G_CALLBACK(mudar_valor_pos2x),NULL);

  lm22=gtk_label_new("Massa (Kg)");
  gtk_box_pack_start (GTK_BOX(box2m),lm22,TRUE,TRUE,5);

  bm22= criar_coisa_para_inserir_valores (m2,0.001,100,0.01);
  gtk_box_pack_start (GTK_BOX (box2m), bm22, TRUE, FALSE, 5);
  g_signal_connect (bm22, "value-changed", G_CALLBACK (mudar_valor_m2), NULL);

  lv22=gtk_label_new("Velocidade (m/s)");
  gtk_box_pack_start (GTK_BOX(box2v),lv22,TRUE,TRUE,5);

  bv22= criar_coisa_para_inserir_valores (v2,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box2v), bv22, TRUE, FALSE, 5);
  g_signal_connect (bv22, "value-changed", G_CALLBACK (mudar_valor_v2), NULL);



  //Molas--------------------------------------------------------------------------------------------------------------------------
  frame5=gtk_frame_new("Molas");
  gtk_box_pack_start(GTK_BOX(box21),frame5,FALSE,TRUE,10);
  gtk_frame_set_label_align(GTK_FRAME(frame5),0.5,1);
  gtk_widget_override_background_color (frame5, GTK_STATE_NORMAL, &color);

  box5=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
  gtk_container_add(GTK_CONTAINER(frame5),box5);
  box51=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box5),box51,TRUE,TRUE,5);
  box52=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box5),box52,TRUE,TRUE,5);
  box53=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
  gtk_box_pack_start(GTK_BOX(box5),box53,TRUE,TRUE,5);

  labelk1=gtk_label_new("Constante K1 ");
  gtk_box_pack_start (GTK_BOX(box51),labelk1,FALSE,TRUE,20);

  sbk1= criar_coisa_para_inserir_valores (k1,0,10,0.1);
  gtk_box_pack_start (GTK_BOX (box51), sbk1, TRUE, FALSE, 10);
  g_signal_connect (sbk1, "value-changed", G_CALLBACK (mudar_valor_k1), NULL);

  labelk2=gtk_label_new("Constante K2 ");
  gtk_box_pack_start (GTK_BOX(box52),labelk2,FALSE,TRUE,20);

  sbk2= criar_coisa_para_inserir_valores (k2,0,10,0.1);
  gtk_box_pack_start (GTK_BOX (box52), sbk2, TRUE, FALSE, 10);
  g_signal_connect (sbk2, "value-changed", G_CALLBACK (mudar_valor_k2), NULL);

  labelk3=gtk_label_new("Constante K3 ");
  gtk_box_pack_start (GTK_BOX(box53),labelk3,FALSE,TRUE,20);

  sbk3= criar_coisa_para_inserir_valores (k3,0,10,0.1);
  gtk_box_pack_start (GTK_BOX (box53), sbk3, TRUE, FALSE, 10);
  g_signal_connect (sbk3, "value-changed", G_CALLBACK (mudar_valor_k3), NULL);



  //menu--------------------------------------------------------------------------------------------------------------------------------

  menubar = cria_barra_de_menus(window);
  gtk_box_pack_start(GTK_BOX(BBOX),menubar,FALSE,FALSE,0);


  //------------------------------------------------------------------------------------------------------------------------------------
  g_timeout_add (100, (GSourceFunc) time_handler, daread);
  g_timeout_add (100, (GSourceFunc) time_handler, dareag);


  //quit---------------------------------------------------------------------------------------------------------------------------------
  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  free(vt);
  free(vx1);
  free(vx2);

  return 0;
}

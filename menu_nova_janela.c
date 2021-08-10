#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include"main.h"
#include"escalas_valores.h"
#include"mudar_valores.h"

//janela para mudar variaveis relacionadas com objeto 1--------------------------------------------------------------------------------------
gboolean
criar_window_ob1(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win1;//janela

  GtkWidget *BOXwin1,*box1win1,*box2win1;//boxes
  GtkWidget *labelL1,*labelH1,*labelcor;//labels
  GtkWidget *sep3,*sep4;//separadores
  GtkWidget *sbL1;//spinbutton em janela 1 para L1 (comprimento do objeto 1)
  GtkWidget *sbH1;//spintutton em janela 1 para H1 (altura do objeto 1)
  GtkWidget *bcolor1;

  //criar a janela
  win1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win1),500,300);
  gtk_window_set_position(GTK_WINDOW(win1),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win1), "Objeto 1");
  g_signal_connect (G_OBJECT(win1), "destroy", G_CALLBACK(gtk_widget_destroy), win1);

  //criar as boxes
  BOXwin1=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
  gtk_container_add (GTK_CONTAINER(win1), BOXwin1);

  box1win1=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_box_pack_start(GTK_BOX(BOXwin1),box1win1,TRUE,TRUE,10);

  box2win1=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
  gtk_box_pack_end(GTK_BOX(box1win1),box2win1,FALSE,FALSE,10);

  //em box 1--------------------------------------
  //comprimento
  labelL1=gtk_label_new("Comprimento");
  gtk_box_pack_start (GTK_BOX(box1win1),labelL1,FALSE,TRUE,10);
  sbL1= criar_coisa_para_inserir_valores (L1,L2,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win1), sbL1, TRUE, FALSE, 10);
  g_signal_connect (sbL1, "value-changed", G_CALLBACK (mudar_valor_L1), NULL);

  sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win1), sep3, FALSE, TRUE, 0);

  //altura
  labelH1=gtk_label_new("Altura");
  gtk_box_pack_start (GTK_BOX(box1win1),labelH1,FALSE,TRUE,10);
  sbH1= criar_coisa_para_inserir_valores (H1,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win1), sbH1, TRUE, FALSE, 10);
  g_signal_connect (sbH1, "value-changed", G_CALLBACK (mudar_valor_H1), NULL);

  sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win1), sep4, FALSE, TRUE, 0);


  //em box 2----------------------------------------------
  //cor
  bcolor1=gtk_color_button_new();
  gtk_box_pack_end (GTK_BOX(box2win1), bcolor1, TRUE, TRUE, 10);
  gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(bcolor1),&color1);
  gtk_widget_set_size_request(bcolor1,50,50);
  g_signal_connect (bcolor1, "color-set", G_CALLBACK (color_chooser_color1), NULL);

  labelcor=gtk_label_new("Cor:");
  gtk_box_pack_start (GTK_BOX(box2win1),labelcor,TRUE,TRUE,10);


  gtk_widget_show_all (win1);

  return FALSE;
}



//janela para mudar variaveies de objeto 2---------------------------------------------------------------------------------
gboolean
criar_window_ob2(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win2;//janela

  GtkWidget *BOXwin2,*box1win2,*box2win2;//boxes
  GtkWidget *labelL2,*labelH2,*labelcor;//labels
  GtkWidget *sep3,*sep4;//separadores
  GtkWidget *sbL2;//spinbutton em janela 2 para L2 (comprimento do objeto 2)
  GtkWidget *sbH2;//spintutton em janela 2 para H2 (altura do objeto 2)
  GtkWidget *bcolor2;


  //criar a janela
  win2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win2),500,300);
  gtk_window_set_position(GTK_WINDOW(win2),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win2), "Objeto 2");
  g_signal_connect (G_OBJECT(win2), "destroy", G_CALLBACK(gtk_widget_destroy), win2);

  //criar as boxes
  BOXwin2=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
  gtk_container_add (GTK_CONTAINER(win2), BOXwin2);

  box1win2=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_box_pack_start(GTK_BOX(BOXwin2),box1win2,TRUE,TRUE,10);

  box2win2=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
  gtk_box_pack_end(GTK_BOX(box1win2),box2win2,TRUE,TRUE,10);


  //em box 1----------------------------------------------
  //comprimento
  labelL2=gtk_label_new("Comprimento");
  gtk_box_pack_start (GTK_BOX(box1win2),labelL2,FALSE,TRUE,10);

  sbL2= criar_coisa_para_inserir_valores (L2,0,L1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win2), sbL2, TRUE, FALSE, 10);
  g_signal_connect (sbL2, "value-changed", G_CALLBACK (mudar_valor_L2), NULL);

  sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win2), sep3, FALSE, TRUE, 0);

  //altura
  labelH2=gtk_label_new("Altura");
  gtk_box_pack_start (GTK_BOX(box1win2),labelH2,FALSE,TRUE,10);

  sbH2= criar_coisa_para_inserir_valores (H2,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win2), sbH2, TRUE, FALSE, 10);
  g_signal_connect (sbH2, "value-changed", G_CALLBACK (mudar_valor_H2), NULL);

  sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win2), sep4, FALSE, TRUE, 0);

  //box2---------------------------------------------------------------
  bcolor2=gtk_color_button_new();
  gtk_box_pack_end (GTK_BOX(box2win2), bcolor2, TRUE, TRUE, 10);
  gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(bcolor2),&color2);
  g_signal_connect (bcolor2, "color-set", G_CALLBACK (color_chooser_color2), NULL);
  gtk_widget_set_size_request(bcolor2,50,50);

  labelcor=gtk_label_new("Cor:");
  gtk_box_pack_start (GTK_BOX(box2win2),labelcor,TRUE,TRUE,10);


  gtk_widget_show_all (win2);

  return FALSE;
}



//janela para mudar variaveis de mola1-------------------------------------------------------------------------------------------
gboolean
criar_window_mola1(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win3;//janela

  GtkWidget *BOXwin3,*box1win3;//boxes
  GtkWidget *labelh1,*labeln1,*labell01;//labels
  GtkWidget *sep3,*sep4;//separadores
  GtkWidget *sbh1;//spinbutton em janela 3 para h1(altura da mola)
  GtkWidget *sbn1;//spinbutton em janela 3 para n1(numero de espiras?)
  GtkWidget *sbl01;

  //criar a janela
  win3 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win3),500,300);
  gtk_window_set_position(GTK_WINDOW(win3),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win3), "Mola 1");
  g_signal_connect (G_OBJECT(win3), "destroy", G_CALLBACK(gtk_widget_destroy), win3);

  //criar as boxes
  BOXwin3=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
  gtk_container_add (GTK_CONTAINER(win3), BOXwin3);

  box1win3=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_box_pack_start(GTK_BOX(BOXwin3),box1win3,TRUE,TRUE,10);

  //em box1
  labelh1=gtk_label_new("Altura"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win3),labelh1,FALSE,TRUE,10);


  sbh1= criar_coisa_para_inserir_valores (h1,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win3), sbh1, TRUE, FALSE, 10);
  g_signal_connect (sbh1, "value-changed", G_CALLBACK (mudar_valor_h1), NULL);

  sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win3), sep3, FALSE, TRUE, 0);

  labeln1=gtk_label_new("Numero de espiras"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win3),labeln1,FALSE,TRUE,10);

  sbn1= criar_coisa_para_inserir_valores (n1,0,50,1);
  gtk_box_pack_start (GTK_BOX (box1win3), sbn1, TRUE, FALSE, 10);
  g_signal_connect (sbn1, "value-changed", G_CALLBACK (mudar_valor_n1), NULL);

  sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win3), sep4, FALSE, TRUE, 0);

  labell01=gtk_label_new("Comprimento da mola"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win3),labell01,FALSE,TRUE,10);

  sbl01= criar_coisa_para_inserir_valores (l01,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win3), sbl01, TRUE, FALSE, 10);
  g_signal_connect (sbl01, "value-changed", G_CALLBACK (mudar_valor_l01), NULL);




  gtk_widget_show_all (win3);
  return FALSE;
}



//janela para mudar variaveis da mola 2------------------------------------------------------------------------------------------------
gboolean
criar_window_mola2(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win4;//janela

  GtkWidget *BOXwin4,*box1win4;//boxes
  GtkWidget *labelh2,*labeln2,*labell02;//labels
  GtkWidget *sep3,*sep4;//separadores
  GtkWidget *sbh2;//spinbutton em janela 4 para h2
  GtkWidget *sbn2;//spinbutton em janela 4 para n2(numero de espiras?)
  GtkWidget *sbl02;

  //criar a janela
  win4 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win4),500,300);
  gtk_window_set_position(GTK_WINDOW(win4),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win4), "Mola 2");
  g_signal_connect (G_OBJECT(win4), "destroy", G_CALLBACK(gtk_widget_destroy), win4);

  //criar as boxes
  BOXwin4=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
  gtk_container_add (GTK_CONTAINER(win4), BOXwin4);

  box1win4=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_box_pack_start(GTK_BOX(BOXwin4),box1win4,TRUE,TRUE,10);

  //em box1

  labelh2=gtk_label_new("Altura"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win4),labelh2,FALSE,TRUE,10);

  sbh2= criar_coisa_para_inserir_valores (h2,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win4), sbh2, TRUE, FALSE, 10);
  g_signal_connect (sbh2, "value-changed", G_CALLBACK (mudar_valor_h2), NULL);

  sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win4), sep3, FALSE, TRUE, 0);

  labeln2=gtk_label_new("Numero de espiras"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win4),labeln2,FALSE,TRUE,10);

  sbn2= criar_coisa_para_inserir_valores (n2,0,50,1);
  gtk_box_pack_start (GTK_BOX (box1win4), sbn2, TRUE, FALSE, 10);
  g_signal_connect (sbn2, "value-changed", G_CALLBACK (mudar_valor_n2), NULL);

  sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win4), sep4, FALSE, TRUE, 0);

  labell02=gtk_label_new("Comprimento da mola"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win4),labell02,FALSE,TRUE,10);


  sbl02= criar_coisa_para_inserir_valores (l02,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win4), sbl02, TRUE, FALSE, 10);
  g_signal_connect (sbl02, "value-changed", G_CALLBACK (mudar_valor_l02), NULL);



  gtk_widget_show_all (win4);
  return FALSE;
}



//janela para mudar variaveis da mola 3----------------------------------------------------------------------------------------
gboolean
criar_window_mola3(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win5;//janela

  GtkWidget *BOXwin5,*box1win5;//boxes
  GtkWidget *labelh3,*labeln3,*labell03;//labels
  GtkWidget *sep3,*sep4;//separadores
  GtkWidget *sbh3;//spinbutton em janela 5 para h3(altura da mola)
  GtkWidget *sbn3;//spinbutton em janela 5 para n3(numero de espiras?)
  GtkWidget *sbl03;


  //criar a janela
  win5 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win5),500,300);
  gtk_window_set_position(GTK_WINDOW(win5),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win5), "Mola 3");
  g_signal_connect (G_OBJECT(win5), "destroy", G_CALLBACK(gtk_widget_destroy), win5);

  //criar as boxes
  BOXwin5=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
  gtk_container_add (GTK_CONTAINER(win5), BOXwin5);

  box1win5=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  gtk_box_pack_start(GTK_BOX(BOXwin5),box1win5,TRUE,TRUE,10);

  //em box1

  labelh3=gtk_label_new("Altura"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win5),labelh3,FALSE,TRUE,10);


  sbh3= criar_coisa_para_inserir_valores (h3,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win5), sbh3, TRUE, FALSE, 10);
  g_signal_connect (sbh3, "value-changed", G_CALLBACK (mudar_valor_h3), NULL);

  sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win5), sep3, FALSE, TRUE, 0);

  labeln3=gtk_label_new("Numero de espiras"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win5),labeln3,FALSE,TRUE,10);

  sbn3= criar_coisa_para_inserir_valores (n3,0,50,1);
  gtk_box_pack_start (GTK_BOX (box1win5), sbn3, TRUE, FALSE, 10);
  g_signal_connect (sbn3, "value-changed", G_CALLBACK (mudar_valor_n3), NULL);

  sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(box1win5), sep4, FALSE, TRUE, 0);

  labell03=gtk_label_new("Comprimento da mola"); //nome do objecto a que correspondem as caracteristicas
  gtk_box_pack_start (GTK_BOX(box1win5),labell03,FALSE,TRUE,10);


  sbl03= criar_coisa_para_inserir_valores (l03,0,1,0.01);
  gtk_box_pack_start (GTK_BOX (box1win5), sbl03, TRUE, FALSE, 10);
  g_signal_connect (sbl03, "value-changed", G_CALLBACK (mudar_valor_l03), NULL);



  gtk_widget_show_all (win5);
  return FALSE;
}


//janela para mudar escalas do desenho/esquema
gboolean
criar_window_escala_desenho(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win1;//janela

  GtkWidget *label1,*label2,*BOX,*sbescaladx,*sbescalady;

  //criar a janela
  win1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win1),500,300);
  gtk_window_set_position(GTK_WINDOW(win1),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win1), "Escala do Desenho");
  g_signal_connect (G_OBJECT(win1), "destroy", G_CALLBACK(gtk_widget_destroy), win1);

  BOX=gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
  gtk_container_add (GTK_CONTAINER(win1), BOX);


  label1=gtk_label_new("Escala em X");
  gtk_box_pack_start (GTK_BOX(BOX),label1,FALSE,TRUE,10);

  sbescaladx= criar_coisa_para_inserir_valores (escaladx,0.001,5,0.1);
  gtk_box_pack_start (GTK_BOX (BOX), sbescaladx, TRUE, FALSE, 10);
  g_signal_connect (sbescaladx, "value-changed", G_CALLBACK (mudar_valor_escaladx), NULL);

  label2=gtk_label_new("Escala em Y");
  gtk_box_pack_start (GTK_BOX(BOX),label2,FALSE,TRUE,10);

  sbescalady= criar_coisa_para_inserir_valores (escalady,0.001,5,0.1);
  gtk_box_pack_start (GTK_BOX (BOX), sbescalady, TRUE, FALSE, 10);
  g_signal_connect (sbescalady, "value-changed", G_CALLBACK (mudar_valor_escalady), NULL);

  gtk_widget_show_all (win1);
  return FALSE;
}


//janela para mudar escalas do grafico
gboolean
criar_window_escala_grafico(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win1;//janela

  GtkWidget *label1,*label2,*BOX,*sbescalagx,*sbescalagy;

  //criar a janela
  win1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win1),500,300);
  gtk_window_set_position(GTK_WINDOW(win1),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win1), "Escala do Desenho");
  g_signal_connect (G_OBJECT(win1), "destroy", G_CALLBACK(gtk_widget_destroy), win1);

  BOX=gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
  gtk_container_add (GTK_CONTAINER(win1), BOX);

  label1=gtk_label_new("Escala em X");
  gtk_box_pack_start (GTK_BOX(BOX),label1,FALSE,TRUE,10);

  sbescalagx= criar_coisa_para_inserir_valores (escalagx,0.001,2,0.1);
  gtk_box_pack_start (GTK_BOX (BOX), sbescalagx, TRUE, FALSE, 10);
  g_signal_connect (sbescalagx, "value-changed", G_CALLBACK (mudar_valor_escalagx), NULL);

  label2=gtk_label_new("Escala em Y");
  gtk_box_pack_start (GTK_BOX(BOX),label2,FALSE,TRUE,10);

  sbescalagy= criar_coisa_para_inserir_valores (escalagy,0.001,2,0.1);
  gtk_box_pack_start (GTK_BOX (BOX), sbescalagy, TRUE, FALSE, 10);
  g_signal_connect (sbescalagy, "value-changed", G_CALLBACK (mudar_valor_escalagy), NULL);

  gtk_widget_show_all (win1);

  return FALSE;
  }



//janela para escolher valors para o eixo y do grafico
gboolean
criar_window_eixos(GtkWidget *w,GtkWidget  *win )
{
  GtkWidget *win1,*buttonx1,*buttonx2,*label,*box;//janela

  GtkWidget *BOX;

  //criar a janela
  win1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(win1),300,300);
  gtk_window_set_position(GTK_WINDOW(win1),GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (win1), "Escala do Desenho");
  g_signal_connect (G_OBJECT(win1), "destroy", G_CALLBACK(gtk_widget_destroy), win1);

  BOX=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
  gtk_container_add (GTK_CONTAINER(win1), BOX);
  box=gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
  gtk_box_pack_start(GTK_BOX(BOX),box,TRUE,TRUE,20);

  label=gtk_label_new("Escolha valores para o eixo do Y:");
  gtk_box_pack_start (GTK_BOX(box),label,FALSE,TRUE,10);


  buttonx1 = gtk_check_button_new_with_label ("Posicao do Objeto 1");
  if(condicaox1==1)
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(buttonx1), TRUE);
  gtk_box_pack_start (GTK_BOX(box), buttonx1, TRUE, TRUE, 3);
  g_signal_connect(G_OBJECT(buttonx1), "clicked", G_CALLBACK(cb_buttonx1), NULL);


  buttonx2 = gtk_check_button_new_with_label ("Posicao do Objeto 2");
  if(condicaox2==1)
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(buttonx2), TRUE);
  gtk_box_pack_start (GTK_BOX(box), buttonx2, TRUE, TRUE, 3);
  g_signal_connect(G_OBJECT(buttonx2), "clicked", G_CALLBACK(cb_buttonx2), NULL);



  gtk_widget_show_all (win1);
  return FALSE;
  }

gboolean
legendas(GtkWidget *w)
{
  if(condicaolegendas==1)
  condicaolegendas=0;
  else
  condicaolegendas=1;

  return FALSE;
}

//----------------------------------------------------------------------------------------------------------------
GtkWidget *
cria_barra_de_menus (GtkWidget *window)
{
  GtkWidget *menubar, *mib_file, *menu_file, *mi_quit;
  GtkWidget *menu_opcoes, *mi_objeto1, *mib_opcoes, *mi_objeto2, *mi_mola1, *mi_mola2, *mi_mola3,*mi_escala_desenho, *mi_legendas;
  GtkWidget *menu_grafico,*mib_grafico, *mi_escalag, *mi_eixos;

  menubar = gtk_menu_bar_new ();

  //--------------------------------------------------
  mib_file = gtk_menu_item_new_with_mnemonic ("Ficheiro");
  gtk_menu_shell_append (GTK_MENU_SHELL(menubar), mib_file);

  menu_file = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM(mib_file), menu_file);

  mi_quit = gtk_menu_item_new_with_label ("Quit");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_file), mi_quit);
  g_signal_connect (G_OBJECT(mi_quit), "activate", G_CALLBACK(gtk_main_quit), NULL);

  //-------------------------------------------------------------

  mib_opcoes = gtk_menu_item_new_with_mnemonic ("Esquema");
  gtk_menu_shell_append (GTK_MENU_SHELL(menubar), mib_opcoes);


  menu_opcoes = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM(mib_opcoes), menu_opcoes);

  mi_objeto1 = gtk_menu_item_new_with_label ("Objeto 1");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_objeto1);
  g_signal_connect (G_OBJECT(mi_objeto1), "activate", G_CALLBACK(criar_window_ob1), NULL);

  mi_objeto2 = gtk_menu_item_new_with_label ("Objeto 2");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_objeto2);
  g_signal_connect (G_OBJECT(mi_objeto2), "activate", G_CALLBACK(criar_window_ob2), NULL);

  mi_mola1 = gtk_menu_item_new_with_label ("Mola 1");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_mola1);
  g_signal_connect (G_OBJECT(mi_mola1), "activate", G_CALLBACK(criar_window_mola1), NULL);

  mi_mola2= gtk_menu_item_new_with_label ("Mola 2");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_mola2);
  g_signal_connect (G_OBJECT(mi_mola2), "activate", G_CALLBACK(criar_window_mola2), NULL);

  mi_mola3 = gtk_menu_item_new_with_label ("Mola 3");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_mola3);
  g_signal_connect (G_OBJECT(mi_mola3), "activate", G_CALLBACK(criar_window_mola3), NULL);

  mi_escala_desenho = gtk_menu_item_new_with_label ("Escala do Desenho");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_escala_desenho);
  g_signal_connect (G_OBJECT(mi_escala_desenho), "activate", G_CALLBACK(criar_window_escala_desenho), NULL);

  mi_legendas = gtk_menu_item_new_with_label ("Colocar/Retirar Legendas ");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_opcoes), mi_legendas);
  g_signal_connect (G_OBJECT(mi_legendas), "activate", G_CALLBACK(legendas), NULL);


  //-----------------------------------------------------------------
  mib_grafico = gtk_menu_item_new_with_mnemonic ("Grafico");
  gtk_menu_shell_append (GTK_MENU_SHELL(menubar), mib_grafico);

  menu_grafico = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM(mib_grafico), menu_grafico);

  mi_eixos = gtk_menu_item_new_with_label ("Eixos");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_grafico), mi_eixos);
  g_signal_connect (G_OBJECT(mi_eixos), "activate", G_CALLBACK(criar_window_eixos), NULL);


  mi_escalag = gtk_menu_item_new_with_label ("Escala");
  gtk_menu_shell_append (GTK_MENU_SHELL(menu_grafico), mi_escalag);
  g_signal_connect (G_OBJECT(mi_escalag), "activate", G_CALLBACK(criar_window_escala_grafico), NULL);


  return menubar;

}

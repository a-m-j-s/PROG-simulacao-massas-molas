#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"main.h"
#include"esquema_do_mov.h"
#include"funcao_mola.h"
#include"botoes.h"
#include"escalas_valores.h"
#include "mudar_valores.h"
#include"menu_nova_janela.h"


//funcao ligada ao botao comecar
void
comecar()
{
  condicao=1;
}

//funcao ligada ao botao stop
void
parar()
{
  condicao=0;
}

//funcao ligada ao boao reset
void
reset1()
{
  condicoes_iniciais();

  gtk_range_set_value(GTK_RANGE(sx11),pos1x);
  gtk_range_set_range(GTK_RANGE(sx22),pos1x,pos1x+L1-L2);
  pos2x=0.400;
  pos2xi=0.400;
  gtk_range_set_value(GTK_RANGE(sx22),pos2x);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(bm11),m1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(bv11),v1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(bm22),m2);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(bv22),v2);

  gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbk1),k1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbk2),k2);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbk3),k3);


  vt=(double*)calloc(pontosmaximo,sizeof(double));
  vx1=(double*)calloc(pontosmaximo,sizeof(double));
  vx2=(double*)calloc(pontosmaximo,sizeof(double));
}


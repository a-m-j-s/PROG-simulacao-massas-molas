#include<gtk/gtk.h>
#include<cairo.h>
#include<math.h>

#include"main.h"
#include"esquema_do_mov.h"
#include"funcao_mola.h"
#include"botoes.h"
#include"escalas_valores.h"
#include "mudar_valores.h"
#include"menu_nova_janela.h"

//funcao que resolve a equacao diferencial
void
funcao_mov()
{
   double x;
   int i;


   for(i=0;i<1000;++i)
     {
       v2=v2+((-k2*(pos2x-pos1x-l02)+k3*(pos1x-pos2x+L1-L2-l03))/m2)*dt;
       x=pos2x+v2*dt;

       v1=v1+((-k1*(pos1x-l01)+k2*(pos2x-pos1x-l02)-k3*(pos1x-pos2x+L1-L2-l03))/m1)*dt;

       pos1x=pos1x+v1*dt;
       pos2x=x;

       t=t+dt;
    }


}

# PROG-simulacao-massas-molas

This is the final project for the programming course of the MEFT (integrated master's in physics engineering) degree in the 2015/2016 year.

This was a group project written in C with the GTK+ librariy to make windows with a representation of the system and with graphs of the objects coordinates in function of time, along with buttons, slider, etc to change the various parameters (masses, initial positions and velocities, sping constants...).

The system has two masses (m1 and m2) conected to each other and to a wall with three springs (K1, K2, K3). An image can be seen in the relatorioprojeto2.pdf within this repository. The masses of the springs are not considered.

The equations are in the Trabalhos_Finais_1516.pdf.

Description of the files:

main.c - the functions that give the general apreance to the main window and the start, stop and reset buttons are in this file.

menu_nova_janela.c - functions for the task bar.

mudar_valor.c - functions to change the different variables for the two objets, three spings, scales, colors,...

grafico.c - functions that draw the graphs of the objects coordinates in function of time.

esquema_movimento.c - function that draw the representation of the system.

funcao_mov.c - function that solves the equations numerically.

funcao_mola.c - function that draws the springs.

botoes.c - functions that are connected to the start, reset and stop buttons.

escalas_valores.c - fucntions that create the sliders for the different values.




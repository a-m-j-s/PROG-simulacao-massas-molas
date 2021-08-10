
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o esquema_do_mov.o -c esquema_do_mov.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o funcao_mola.o -c funcao_mola.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o escalas_valores.o -c escalas_valores.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o botoes.o -c botoes.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o menu_nova_janela.o -c menu_nova_janela.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o mudar_valores.o -c mudar_valores.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o funcao_mov.o -c funcao_mov.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o grafico.o -c grafico.c
gcc -Wall $(pkg-config --cflags gtk+-3.0) -o main.o -c main.c
gcc -o projeto esquema_do_mov.o funcao_mola.o escalas_valores.o botoes.o menu_nova_janela.o mudar_valores.o funcao_mov.o grafico.o main.o $(pkg-config --libs gtk+-3.0)
./projeto

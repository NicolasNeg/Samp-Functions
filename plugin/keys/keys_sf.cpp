#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_SYMBOL_MONEY 36
#define KEY_QUESTION 63
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_E 101
#define KEY_I 105
#define KEY_P 112
#define KEY_Q 113
#define KEY_R 114
#define KEY_T 116
#define KEY_U 117

#define MAX_PLAYERS 1000

int money_[MAX_PLAYERS];

void DetectKeys(int playerid)
{
     char KEY_PRESSED;
     while (1)
     {
          KEY_PRESSED = getch();
          switch(KEY_PRESSED)
          {
               case KEY_QUESTION:
               {
                    printf("\r\n[?] Debug: Menu de ayuda...");
                    break;
               }
               case KEY_SYMBOL_MONEY:
               {
                    printf("\r\n[$] Money(playerid: %d): %d",playerid,money_[playerid]);
                    money_[playerid] += 1500;
                    break;
               }
               case KEY_UP:
               {
                    printf("\r\n[Up] Debug: Arriba...");
                    break;                    
               }
               case KEY_DOWN:
               {
                    printf("\r\n[Down] Debug: Abajo...");
                    break;                    
               }
               case KEY_LEFT:
               {
                    printf("\r\n[Left] Debug: Izquierda...");
                    break;
               }
               case KEY_RIGHT:
               {
                    printf("\r\n[Right] Debug: Derecha...");
                    break;                    
               }
               case KEY_BACKSPACE:
               {
                    printf("\r\n[Retroceso] Debug: Regresando atras...");
                    break;
               }
               case KEY_SPACE:
               {
                    printf("\r\n[Espacio] Debug: Saltando...");
                    break;
               }
               case KEY_ENTER:
               {
                    printf("\r\n[Enter] Debug: Cambiando de playerid...");
                    playerid ++;
                    break;
               }
               case KEY_T:
               {
                    printf("\r\n[T] Debug: Chat activado...");
                    break;                    
               }
               case KEY_R:
               {
                    printf("\r\n[R] Debug: Recargando arma...");
                    break;                    
               }
               case KEY_Q:
               {
                    printf("\r\n[Q] Debug: Tiraste un arma de csgo...");
                    break;
               }
               case KEY_P:
               {
                    printf("\r\n[P] Debug: Pausaste el juego...");
                    break;
               }
               case KEY_E:
               {
                    printf("\r\n[E] Debug: Estas corriendo...");
                    break;
               }
          }
     }
}

int main()
{
     DetectKeys(0);
     return 0;
}
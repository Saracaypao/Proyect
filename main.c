/***proyecto 
 * Segunda parte***/


#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* a crear
-hacer que cuando una fila se termine la fila de abajo se suba
-sistema de puntos completo
-el ultimo numero que no es un 0 en el grid se puede juntar con el primero numero en el array 
-tener los numeros afuera del tablero que digan las coordenadas 
-hacer un check al final que vea si todos os pares tienen al menos un adyacente, sino termina el juego
*/

int main()
{

srand(time(NULL));
int tablerodeljuego[9][9];

int i;
int j;
int k;

int cordx = 0; //para el usario 
int cordy = 0;
int cordx2 = 0;
int cordy2 = 0;

int match = 0; //variables occupadas en while loops
int repeat = 1;
int counter =0;


//----------------------------------------------------------------------------------------------------- pre programa


for(int i=0 ; i<9 ; i++) //llena el tablero con numeros aleatorios entre 1 y 9
{
    for(int j = 0 ; j<9 ; j++)
     {
         tablerodeljuego[i][j]=rand() % 9+1 ;
     }
} 



int matchcounter = 0; // esto debe contar cuantos matches hay en el array, este debe ser calculado en el principio del programa
int repeticiones = 0;


for (k=1 ; k<10 ; k++) //compara cuantas veces esta un numero en el tablero entre 1 y 9
{    
    repeticiones = 0;
    printf("\n");
    
     for (i = 0 ; i<9 ; i++) 
     {
         for (j = 0 ; j<9 ; j++)
         {
             if (k == tablerodeljuego[i][j])
             {
                 repeticiones = repeticiones+1; //cada vez que el loop encuentra el numero k adentro del tablero se le agrega un 1 al valor de repeticiones
                 printf("%d se repite %d vez \t",k,repeticiones);
                 if (repeticiones % 2 == 0) //cada vez que la cantidad de repeticiones de un numero es igual a un numero par se le agrega un 1 al valor de matchcounter
                 {
                     matchcounter= matchcounter+1;
                 }
             }
         }
     }
}
printf("\n");
printf("%d matchcounter \n",matchcounter);



//------------------------------------------------------------------------------------------------------ introduccion al usuario

printf("\t**Match10!!!**");  //imprime el primer tablero

     for (i = 0 ; i<9 ; i++) 
     {
         printf("\n");
         
         for (j = 0 ; j<9 ; j++)
         {
             printf("|%d| ", tablerodeljuego[i][j]);
         }  
     }

printf("\n");



//MAIN LOOP -----------------------------------------------------------------------------------------------
while ( counter<matchcounter) //cuando la variable counter se igual a matchcounter(la cantidad total de matches en el tablero), el juego termina
{
     printf("\n");
     match = 0; //variable que indica cuando se encuentra un par de cartas
     repeat=1;
     
     //reseta las cords cada vez que se repite el loop 
     cordx=0;
     cordy=0;
     cordx2=0;
     cordy2=0;
     
     printf(" \nel counter es %d \n",counter); //indica al programador cuantos matches se han encontrado por el jugador
     
     
     while (match != 1) //cuando un match es encontrado regresa aqui para otro turno
     {
         
         if (tablerodeljuego==0) //bypass of array char restriction, just uses the 0 as a conditional instead to print an empty space.
         {
              printf("| |");
         }
        for (i = 0 ; i<9 ; i++) //imprime el tablero
        {
             printf("\n");
             
              for (j = 0 ; j<9 ; j++)
             {
                 if (tablerodeljuego[i][j]==0)
                 {
                      printf("| |");
                 }
                 if (tablerodeljuego[i][j]!=0)
                 {
                      printf("|%d|", tablerodeljuego[i][j]);
                 }
                  
             }  
         }       
         
            repeat=1; //variable para evitar que el jugador elija una casilla vacia
            while (repeat == 1)
            {
                
                 printf("\n");  //pregunta al usuario su primera casilla
                 printf("eliga su primera casilla\n");
                 printf("cuantas lineas abajo \n");
                 scanf("%d",&cordy);
                 printf("cuantas lineas a la derecha \n");
                 scanf("%d",&cordx);
                 
                 
                 if (tablerodeljuego[cordy][cordx]==0) //checkea si se elijio una casilla vacia
                 {
                    printf("esta casilla ya esta descubierta \n");
                 }
                 else 
                 {
                     
                     repeat = 0;
                 }
                 
            }   
            repeat = 1; //variable para evitar que el jugador elija una casilla vacia
             
             for (i = 0 ; i<9 ; i++) //imrpime el tablero 
                 {
                     printf("\n");
                            
                     for (j = 0 ; j<9 ; j++)
                     {
                     printf("|%d|", tablerodeljuego[i][j]);
                     }   
                 }
              
             while (repeat == 1)
             {
             printf("\n");  //pregunta la segunda casilla a elegir
             printf("eliga su segunda casilla\n");
             printf("cuantas lineas abajo \n");
             scanf("%d",&cordy2);
             printf("cuantas lineas a la derecha \n");
             scanf("%d",&cordx2);
              
                 if (tablerodeljuego[cordy2][cordx2]==0)  //checkea si se elijio una casilla vacia
                 {
                    printf("esta casilla ya esta descubierta \n");
                 }
                 else 
                 {
                     repeat = 0;
                 }
                 
             }
            
            
             while (cordx2 == cordx && cordy2 == cordy) //loop solo para evitar que causen un error por elejir la misma casilla does veces
             {
                
             printf("no puede elegir la misma casilla dos veces \n");
             printf("\n");
             printf("eliga su segunda casilla\n");
             printf("cuantas lineas abajo \n");
             scanf("%d",&cordy2);
             printf("cuantas lineas a la derecha \n");
             scanf("%d",&cordx2);
            
            }
            
            
            
            if (tablerodeljuego[cordy][cordx]==tablerodeljuego[cordy2][cordx2]) //largo check que busca saber si la segunda casilla es adyacente a la primera y que el valor de la casilla 1 es = a casilla 2            
            {
                if(cordx2 == cordx-1 ||
                   cordx2 == cordx+1 ||
                   cordy2 == cordy+1 ||
                   cordy2 == cordy-1 ||
                   (cordy2 == cordy+1 && cordx2 == cordx+1) ||
                   (cordy2 == cordy-1 && cordx2 == cordx-1) ||
                   (cordy2 == cordy+1 && cordx2 == cordx-1) ||
                   (cordy2 == cordy-1 && cordx2 == cordx+1))
                   {
                     printf("\nencontro un match \n");
                     match = 1; //un match encotrado entonces el loop termina aqui inmediatamente 
                     counter = counter +  1; //cantidad de pares encontrados + 1
                     tablerodeljuego[cordy][cordx]=0;
                     tablerodeljuego[cordy2][cordx2]=0;
                   }
                }
            
            if(match == 0) //si no fue un match cambia de jugador y no cambia nada en el tablero
            {   
                 printf("\nNo Match \n");    
            }
            
     }       
}
printf("\n todas las parejas de tarjetas fueron encontradas");
    
    return 0;
}
#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include<ctime>

using namespace std;

int main(){
 srand(time(NULL));
    int opcion;
    bienvenida();

    while(true){
        char nombre1[20],nombre2[20],respuesta,respuestaRelanzar;
        int dados[6],puntajeTotaljugador[2],contRonda=0,lanzamientoDados[2],puntajeRonda=0,banderaGeneralaServida[2];
        int flagGenerala[2];
        ponerCero(puntajeTotaljugador,2);
        ponerCero(lanzamientoDados,2);
        ponerCero(flagGenerala,2);
        ponerCero(banderaGeneralaServida,2);
        system("cls");
        opcion=menu();//funcion para ver menu principal

        switch (opcion){        ///modo de un solo jugador
                case 1:
                system("cls");
                cin.ignore();
                nombreJugador(nombre1,1);

                while(contRonda<10 && flagGenerala[0]==0){
                system("cls");
                contRonda++;

                turnoPuntajeRonda(nombre1,puntajeTotaljugador[0],contRonda);

                lanzamientoDados[0]=cargarDadosmanualmente(dados,5);
                if(lanzamientoDados[0]==0){
                tirarDados(dados,5);
                turnoPuntajeRonda(nombre1,puntajeTotaljugador[0],contRonda);
                mostrarDados(dados,5);
                lanzamientoDados[0]=algunosDados(dados);}
                puntajeRonda=combinacionesGanadoras(dados,lanzamientoDados[0],banderaGeneralaServida);
                flagGenerala[0]=banderaGeneralaServida[0];
                puntajeTotaljugador[0]+=puntajeRonda;
                system("pause");
                }
                cierreGeneralaSolitario(nombre1,puntajeTotaljugador[0],contRonda);
                system("pause");
                break;


                case 2:
                system("cls");
                cin.ignore();

                nombreJugador(nombre1,1);

                nombreJugador(nombre2,2);

                while(contRonda<10&&flagGenerala[0]==0&&flagGenerala[1]==0){
                system("cls");
                contRonda++;
                ///turno jugador numero 1
                tablero(nombre1,nombre2,nombre1,contRonda,puntajeTotaljugador[0],puntajeTotaljugador[1]);

                lanzamientoDados[0]=cargarDadosmanualmente(dados,5);

                if(lanzamientoDados[0]==0){
                tirarDados(dados,5);
                turnoPuntajeRonda(nombre1,puntajeTotaljugador[0],contRonda);
                mostrarDados(dados,5);
                lanzamientoDados[0]=algunosDados(dados);}

                puntajeRonda=combinacionesGanadoras(dados,lanzamientoDados[0],banderaGeneralaServida);
                flagGenerala[0]=banderaGeneralaServida[0];
                system("pause");

                puntajeTotaljugador[0]+=puntajeRonda;

                tablero(nombre1,nombre2,nombre2,contRonda,puntajeTotaljugador[0],puntajeTotaljugador[1]);

                system("pause");
                ///turno del jugador numero 2

                lanzamientoDados[1]=cargarDadosmanualmente(dados,5);

                if(lanzamientoDados[1]==0){
                tirarDados(dados,5);
                turnoPuntajeRonda(nombre2,puntajeTotaljugador[1],contRonda);
                mostrarDados(dados,5);
                lanzamientoDados[1]=algunosDados(dados);}

                puntajeRonda=combinacionesGanadoras(dados,lanzamientoDados[0],banderaGeneralaServida);
                flagGenerala[1]=banderaGeneralaServida[0];
                system("pause");
                puntajeTotaljugador[1]+=puntajeRonda;

                system("pause");}

                buscarGanador(contRonda,nombre1,nombre2,puntajeTotaljugador[0],puntajeTotaljugador[1],flagGenerala);
                system("pause");

                break;

            case 0:
                return 0;
                    break;


            default:

                cout << "\n\nUps.... me parece que has seleccionado una opcion incorrecta! "<<endl<<endl<< endl;
                system("pause");
                break;
        }
    }
}


#include<iostream>
#include<conio.h>
#include "funciones.h"
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;
void MenuPrincipal(){

srand(time(NULL));
    int opcion;
    bienvenida();

    while(true){
        char nombre1[20],nombre2[20],respuesta,respuestaRelanzar,nombrePuntuacion[20];
        int dados[6],puntajeTotaljugador[2],contRonda=0,lanzamientoDados[2],puntajeRonda=0,banderaGeneralaServida[2];
        int flagGenerala[2],banderaPuntacion=0,cantRondasPuntuacion,puntosPuntuacion;
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
                return ;
                    break;


            default:

                cout << "\n\nUps.... me parece que has seleccionado una opcion incorrecta! "<<endl<<endl<< endl;
                system("pause");
                break;
        }
    }


}


void bienvenida(){
    cout << "---------------------------------------------------------------------------------------------------";
    cout << "\n\n\n\n\n\n\t\t\t\tBienvenidos al Juego de la Generala!";
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\tPresione enter para comenzar\n\n\n\n";
    cout << "---------------------------------------------------------------------------------------------------";
    system("pause");
    system("cls");}

int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}

int minimoVector(int v[], int tam){
    int i, posMin=0;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]) {
                posMin=i;
        }
    }
    return posMin;
}

void PuntuacionMasAlta(int puntuacion,char *Nombre,int cantRondas,int *puntosRecord,int *rondasRecord,char *nombreRecord,int *bandera){///recibe nombre , puntuacion y cantidad de rondas


    if(bandera==0){
        return;
    }



}

void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  //srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero)
            cant++;
        }
    return cant;
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

int copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam ){
   int i;
    for(i=0;i<tam;i++){
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

int trampa(int dados[],int tam){
    int x,intentos=0;
    char respuesta;
    for(x=0;x<tam;x++){
        cout << "Valor del dado numero " <<x+1<< ":";
        cin >> dados[x];}
        intentos++;
        cout << "\nDesea volver a cargar manualmente los dados? (S/N)";
        cin >> respuesta;
    while(intentos<=3&&respuesta=='s'||respuesta=='S'){
        intentos++;
        for(x=0;x<tam;x++){
        cout << "Valor del dado numero " <<x+1<< ":";
        cin >> dados[x];}
        if(intentos<3){
        cout<< "\nDesea volver a cargar manualmente los dados? (S/N)";
        cin >> respuesta;   }
        else{   respuesta='n';
        }   }
        return intentos;  }


void tirarDados(int vecDados[], int cantDados){
    int i;
    //srand(time(NULL));
    for(i=0;i<cantDados;i++){
       vecDados[i]=(rand()%6)+1;
     }
    }
void relanzarDados(int vecDado[],int pos){
    vecDado[pos-1] = (rand()%6)+1;
}

void mostrarDados(int v[], int tam){
    int i;
    cout << "Dado 1" "\t\tDado 2" "\t\tDado 3" "\t\tDado 4" "\t\tDado 5"<<endl;
    for(i=0;i<tam;i++){
        cout<<"\t"<<v[i]<<"\t";
    }
    cout<<endl;
    }

void nombreJugador(char nombre[20],int numJugador){

    cout << "\n\n\t";
    cout << "\tIngrese el nombre del jugador numero "<<numJugador<< ": ";

    cin.getline(nombre,20);}


int algunosDados(int dados[]){
    int reDado,intentos=1,lanzamientos,x;
    char respuesta='a';
    cout<< "Continuar lanzando dados? (S/N)";
    cin >> respuesta;
    while(intentos<=3&&respuesta=='s'||respuesta=='S'){
        intentos++;
        cout << "Cuantos dados volves a tirar?:  ";
        cin>>lanzamientos;
        for(x=1;x<=lanzamientos;x++){
            cout << "\nCual dado vas a volver a tirar?:  ";
            cin >> reDado;
            relanzarDados(dados,reDado);
        }
        mostrarDados(dados,5);
        if(intentos<3){
        cout<< "Continuar lanzando dados? (S/N)";
        cin >> respuesta;}
        else{   respuesta='n';
        }
        }
return intentos;
}

bool escalera (int dados[],int cantDado){

    int numAnt=dados[0],anterior=0,i;

    for(i=1;i<cantDado;i++){
        if (numAnt+1==dados[i]){
            anterior++;
            numAnt=dados[i];
        }}
    if(anterior==4){
        return true;
    }
    return false;}



int jugadaNumeros(int dados[]){
    int i,iguales,puntaje=0;
     for (i=1;i<=6;i++){
        iguales=contarNumerosRepetidos(dados,i,5);
        if(iguales>1){
            cout << "\n\n\t\tHiciste combinacion de " << i <<endl;
            puntaje+=iguales*i;}
     }

            return puntaje;}

bool jugadaFull(int dados[],int cantDados){
    int i,iguales,full=0;
    for (i=1;i<=6;i++){
        iguales=contarNumerosRepetidos(dados,i,cantDados);
        if(iguales>=2&&iguales<=3){
            full+=iguales;
        }}
        if(full==5){
            return true;
        }
        else {
            return false;
        }}

bool jugadaPoker (int dados[],int cantDados){
    int i,iguales;
    for (i=1;i<=6;i++){
        iguales=contarNumerosRepetidos(dados,i,cantDados);
        if(iguales==4){
            return true;
        }}
            return false;}

bool jugadaGenerala(int dados[],int cantDados){
    int i,iguales;
    for (i=1;i<=6;i++){
        iguales=contarNumerosRepetidos(dados,i,cantDados);
        if(iguales==5){
            return true;
        }}
        return false;}

int combinacionesGanadoras(int dados[],int cantLanzamientos,int banderaGeneralaServida[1]){
    int puntaje=0;
    bool casoEscalera,full,poker,generala;
    ponerCero(banderaGeneralaServida,1);
    //if(cantLanzamientos>0){
    ordenarVector(dados,5);///ordena el vector para que evaluarlo sea mas facil
    //mostrarVector(dados,5);

    generala=jugadaGenerala(dados,5);///evalua si tenes tanta suerte como para sacar generala
    if (generala==true){
            if(cantLanzamientos==1){
                    cout << "\n\n\n\t\t\tSACASTE GENERALA SERVIDA!!!!"<<endl;
                    system("pause");
                    banderaGeneralaServida[0]=1;
                    puntaje=50;
                    return puntaje;}

            else{
        cout << "\n\n\t\tSacaste generala!!!";
        puntaje+=50;}

    }else {

    full=jugadaFull(dados,5);///evalua si la jugada es full
    if (full==true){
        cout << "\n\n\t\tSacaste un full!!!";
        puntaje+=30;
    }else{

    poker=jugadaPoker(dados,5);///evalua si la jugada es Poker
    if(poker==true){
        cout << "\n\n\t\tSacaste Poker!!!";
        puntaje+=40;
    }else{

    casoEscalera=escalera(dados,5);///evalua si la jugada es escalera
    if(casoEscalera==true){
        cout<< "\n\n\t\tSacaste escalera!! "<<endl<<endl;
        puntaje+=25;
    }else{

    puntaje=jugadaNumeros(dados);}}}}/// en caso de que no sea escalera, full,poker,o genarala, evalua la jugada por pares


    cout<< "\n\tTu puntaje en esta ronda es: " << puntaje <<endl<<endl;
    return puntaje;
}

int menu(){
    int opcion;
    cout << "\t\tElija una de las siguientes opciones"<< endl;  //menu de opcion de cantidad de jugadores
    cout << "\n\t1. Juego Nuevo, un solo jugador"<<endl;
    cout << "\n\t2. Juego nuevo, dos jugadores" << endl;
    cout << "\n\t0. Salir del juego" << endl<<endl;
    cout << "\tSeleccione una opcion: ";
    cin >> opcion;
    return opcion;
}


int cargarDadosmanualmente (int dados[],int cantDados){
    char respuesta;
    int lanzamientoDados=0;
    cout << "\t\n\nDesea cargar los dados manualmente? (S/N)";
    cin >> respuesta;

    system("cls");

    if(respuesta=='s'|| respuesta=='S'){
    lanzamientoDados=trampa(dados,cantDados);
    mostrarDados(dados,5);
    system("pause");}
    return lanzamientoDados;    }

void turnoPuntajeRonda (char nombre[20],int puntaje,int ronda){
    system("cls");

    cout << "\n\n\n\t\tTurno de: " << nombre<<endl;
    cout << "\t\tPuntaje total hasta ahora es: " <<puntaje<<endl;
    cout << "\t\tRonda numero " <<ronda<<endl<<endl<<endl;

}

void cierreGeneralaSolitario(char nombre1[20],int puntaje, int ronda){
    system("cls");
    cout << "\t\t\n\n\n\n\n";
    cout << "\t\t********************************************\n\n\n";
    cout << "\t\t\tHAS FINALIZADO LA PARTIDA "<<nombre1<<" !!"<<endl;
    cout << "\t\t\tTU PUNTAJE FINAL ES: " << puntaje<<endl;
    cout << "\t\t\tLO HAS LOGRADO EN "<<ronda<< " RONDAS!"<<endl;
    cout << "\t\t\t\tBIEN HECHO!"<<endl<<endl;
    cout << "\t\t********************************************\n\n\n";}


void tablero(char jugador1[20],char jugador2[20],char proximoJugador[20],int ronda,int puntajeJugador1,int puntajeJugador2){
    system("cls");
    cout << "\n\n\n\t\t\t\tRonda numero: "<<ronda<<endl;
    cout << "\t\t\t Proximo turno: "<<proximoJugador<<endl<<endl<<endl;

    cout << "\n\t\t\t Puntaje "<<jugador1<< ": "<<puntajeJugador1<< " puntos"<<endl;
    cout << "\n\t\t\t Puntaje "<<jugador2<< ": "<<puntajeJugador2<< " puntos"<<endl;}

void buscarGanador(int cantRondas,char jugador1[20],char jugador2[20],int puntajeJugador1,int puntajeJugador2,int flagGenerala[2]){
    system("cls");
    if(flagGenerala[0]==1&&flagGenerala[1]==1||puntajeJugador1==puntajeJugador2){
    cout << "\t\t\n\n\n\n\n";
    cout << "\t\t********************************************************\n\n\n";
    cout << "\t\t\tHAN FINALIZADO LA PARTIDA "<<jugador1<< " Y "<<jugador2<<"!!!!!"<<endl;
    cout << "\t\t\tHA SIDO UN EMPATE, AMBOS HAN LOGRADO "<<puntajeJugador1<< " PUNTOS!!"<<endl;
    cout << "\t\t\tLO HAN LOGRADO EN "<<cantRondas<< " RONDAS!"<<endl;
    cout << "\t\t\t\tBIEN HECHO!"<<endl<<endl;
    cout << "\t\t********************************************************\n\n\n";}

    else{
        if(flagGenerala[0]==1||puntajeJugador1>puntajeJugador2){
        cout << "\t\t\n\n\n\n\n";
        cout << "\t\t********************************************************\n\n\n";
        cout << "\t\t\tHAN FINALIZADO LA PARTIDA "<<jugador1<< " Y "<<jugador2<<"!!!!!"<<endl;
        cout << "\t\t\tEL GANADOR ES: " << jugador1<< "!!!!"<<endl;
        cout << "\t\t\tFELICITACIONES HAS LOGRADO " <<puntajeJugador1<< " PUNTOS!!"<<endl;
        cout << "\t\t\t\tEN SOLO " <<cantRondas<< " RONDAS!! "<<endl;
        cout << "\t\t********************************************************\n\n\n";
        }
        else {
                cout << "\t\t\n\n\n\n\n";
                cout << "\t\t********************************************************\n\n\n";
                cout << "\t\t\tHAN FINALIZADO LA PARTIDA "<<jugador1<< " Y "<<jugador2<<"!!!!!"<<endl;
                cout << "\t\t\tEL GANADOR ES: " << jugador2<< "!!!!"<<endl;
                cout << "\t\t\tFELICITACIONES HAS LOGRADO " <<puntajeJugador2<< " PUNTOS!!"<<endl;
                cout << "\t\t\t\tEN SOLO " <<cantRondas<< " RONDAS!! "<<endl;
                cout << "\t\t********************************************************\n\n\n";
            }}}





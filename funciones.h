#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void MenuPrincipal();

void PuntuacionMasAlta(int ,char *,int ,int *,int *,char *,int *);

void MostrarRecord(char *,int *,int *);

int contarNumerosRepetidos(int v[], int tam , int numero);///cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el máximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el mínimo en el vector
void ponerCero(int v[], int tam);

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

int copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam );/// compara los dos vectores que recibe. Si son iguales devuelve true, si no devuelve false

void mostrarVector(int v[], int tam); ///mostrar vector

void tirarDados(int vecDados[], int cantDados);///tener en cuenta la cantidad de dados a tirar

void mostrarDados(int v[], int tam);///muestra el contenido de todas las caras del vector

void nombreJugador(char nombre[20],int numJugador);//carga el nombre de un jugador

void relanzarDados(int vecDado[],int pos);//funcion para relanzar dados, tiene que pasar el vector con la Posicion del dado a relanzar, se hace de uno por vez

int algunosDados(int dados[]);//interactua con el ususario para volver a relanzar algunos dados y muestra como quedo la jugada

int combinacionesGanadoras(int dados[],int cantLanzamientos,int banderaGeneralaServida[1]);

bool escalera (int dados[],int cantDado);///Evalua si los dados formaron escalera

int trampa(int dados[],int tam);///da la posibilidad al usuario de cargar de manera manual los dados

int jugadaNumeros(int dados[]);///evalua la tipo de jugada armada en caso de que no sea una escalera, poker o full o claro generala =)

bool jugadaFull(int dados[],int cantDados);/// evalua si la jugada obtenida es full

bool jugadaGenerala(int dados[],int cantDados);/// evalua si la jugada es generala

int cargarDadosmanualmente (int dados[],int cantDados);

void turnoPuntajeRonda (char nombre[20],int puntaje,int ronda);

void bienvenida();

int menu(int *,char *,int *,int *);

void cierreGeneralaSolitario(char nombre1[20],int puntaje, int ronda);

void tablero(char jugador1[20],char jugador2[20],char proximoJugador[20],int ronda,int puntajeJugador1,int puntajeJugador2);

void buscarGanador(int cantRondas,char jugador1[20],char jugador2[20],int puntajeJugador1,int puntajeJugador2,int flagGenerala[2]);
#endif // FUNCIONES_H_INCLUDED


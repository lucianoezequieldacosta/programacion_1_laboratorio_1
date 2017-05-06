#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[25] ;
    char apellido[25] ;
    int idDuenio;
    char direccion[25] ;
    int creditCard ;
    int estado;

}EPersona;

typedef struct
{
    char patente[10] ;
    int marca;
    int idDuenio;
    int horarioEntrada;
    int estado;

}Evehiculo;

void comenzarEstados(EPersona personas[], int tam);

int obtenerEspacioLibre(EPersona personas[], int tam);

void cargarUsuario(EPersona personas[], int tam, int posicion);

int buscarPrimerOcurrencia(EPersona personas[],int tam,int valor);

#endif // FUNCIONES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void comenzarEstados(EPersona personas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado = 0;
    }
}

int obtenerEspacioLibre(EPersona personas[], int tam)
{
    int i;
    int auxFlag= 0;
    int disponible;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 0)
        {
            disponible= i;
            auxFlag= 1;
            break;
        }
    }

    if(auxFlag==0)
    {
        disponible= -1;
    }

    return disponible;
}

void cargarUsuario(EPersona personas[], int tam, int posicion)
{
    printf("\nIngresar su nombre: ");
    gets(personas[posicion].nombre);

    printf("\nIngresar su apellido: ");
    fflush(stdin);
    gets(personas[posicion].apellido);

    printf("\nIngresar su direccion: ");
    fflush(stdin);
    gets(personas[posicion].direccion);

    printf("\nIngrese su idDuenio: ");
    scanf("%d", &personas[posicion].idDuenio);

    printf("\nIngrese su num de tarjeta de credito: \n\n");
    scanf("%d", &personas[posicion].creditCard);

    personas[posicion].estado = 1;
}

int buscarPrimerOcurrencia(EPersona personas[],int tam,int valor)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personas[i].creditCard == valor)
        {
            return i;
        }
    }
    return -1;
}


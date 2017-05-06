#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 20

int main()
{
    char seguir= 's';
    int opcion= 0;
    EPersona propietario [CANT];
    Evehiculo autos [CANT];
    int flagPropietario= 0;
    int flagVehiculo= 0;
    int personaLibre;
    int estacionamientoLibre;
    int resultadoBusqueda;
    int auxCreditCard;

    while(seguir=='s')
     {
        printf("1- Alta de duenio\n2- Modificacion de duenio\n3- Ingreso del automovil\n4- Egreso del automovil\n5-Informar\n6-Salir\n\n");
        printf("\n\nIntroduzca opcion (1, 2, 3, 4, 5, 6)\n\n");

        scanf("\n%d", &opcion);

        switch(opcion)
         {
            case 1:
                if(flagPropietario == 0)
                {
                    comenzarEstados(propietario, CANT);
                    flagPropietario= 1;
                }

                personaLibre = obtenerEspacioLibre(propietario,CANT);

                if(personaLibre == -1)
                {
                    printf("\nDisculpa, ya no quedan lugares disponibles para registrarse\n");
                    break;
                }

                cargarUsuario(propietario,CANT,personaLibre);
                    break;

            case 2:
                printf("ingrese su numero de CreditCard para modificar: ");
                scanf("%d", &auxCreditCard);

                resultadoBusqueda= buscarPrimerOcurrencia (propietario, CANT, atoi(auxCreditCard));
                if(resultadoBusqueda == -1)
                {
                    printf("\n\nel id ingresado no existe\n");
                    break;
                }

                strcpy(propietario[resultadoBusqueda].creditCard, auxCreditCard);
                break;

            case 3:
                 if(flagVehiculo == 0)
                    {
                    comenzarEstados(autos, CANT);
                    flagVehiculo= 1;
                    }
                estacionamientoLibre = obtenerEspacioLibre(autos,CANT);
                if(estacionamientoLibre == -1)
                {
                    printf("\nDisculpa, ya no quedan lugares disponibles para estacionar\n");
                    break;
                }

                cargarUsuario(autos,CANT,estacionamientoLibre);

                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                seguir = 'n';
                break;
        }

     }

    return 0;
}

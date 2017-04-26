#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 10

typedef struct
{
    int id;
    char nombre[20];
    int idCategoria;
    float sueldo;

}eProgramador;

typedef struct
{
    int id;
    char descripcion[20];

}eCategoria;

int menu();
void inicializarProgramadores(eProgramador[], int);
int buscarLibre(eProgramador[], int);
int buscarXId(eProgramador[], int, int);
int buscarCategoria(eCategoria[], int, int);
void mostrarCategorias(eCategoria[], int);
void mostrarCategoria(eCategoria);
int altaProgramador(eProgramador[], int, eCategoria[], int);
void obtenerDescripcion(char[], eCategoria[], int, int);
int cantidadXcategoria(eProgramador[], int, eCategoria[], int, char[]);
void mostrarProgramadores(eProgramador[], int, eCategoria[], int);
void mostrarProgramador(eProgramador, eCategoria[], int);

int main()
{
    int flag = 1;
    eProgramador plantel[CANT];
    eCategoria categorias[]= {{1, "Junior"},{2,"SemiSenior"},{3,"Senior"}};
    int cantJunior=0;
    int cantSemiSenior = 0;
    int cantSenior = 0;

    inicializarProgramadores(plantel, CANT);

    do
    {

    switch(menu())
    {
    case 1:
        if(altaProgramador(plantel, CANT, categorias, 3))
        {
            printf("Alta exitosa!!!\n\n");
        }
        else
        {
            printf("No se pudo efectuar el alta\n\n");
        }
        system("pause");
        break;

    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        mostrarProgramadores(plantel, CANT, categorias, 3);


        break;

    case 6:
        cantJunior = cantidadXcategoria(plantel, CANT, categorias, 3, "Junior");
        cantSemiSenior = cantidadXcategoria(plantel, CANT, categorias, 3, "SemiSenior");
        cantSenior = cantidadXcategoria(plantel, CANT, categorias, 3, "Senior");

        printf("\nJunior: %d   SemiSenior: %d   Senior: %d\n\n", cantJunior, cantSemiSenior, cantSenior);

        system("pause");

        break;

    case 7:

        break;

    case 8:
        flag = 0;
        break;

    default:
        printf("\nOpcion invalida\n");
        system("pause");

        break;
    }

     }while(flag);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("**Menu de opciones**\n\n");
    printf("1- Alta Programador\n");
    printf("2- Modificacion Programador\n");
    printf("3- Baja Programador\n");
    printf("4- Mostrar Programador\n");
    printf("5- Mostrar Programadores\n");
    printf("6- Categoria con mas programadores\n");
    printf("7- ---- Programador\n");
    printf("8- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void inicializarProgramadores(eProgramador x[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        x[i].id = -1;
    }
}

int buscarLibre(eProgramador x[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == -1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarXId(eProgramador x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarCategoria(eCategoria x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(x[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaProgramador(eProgramador p[], int tamP, eCategoria c[], int tamC)
{
    int todoOk = 0;
    int indice = buscarLibre(p, tamP);

    if(indice == -1)
    {
        printf("\nNo hay lugar en el sistema para mas programadores!!!\n\n");
        system("pause");
    }
    else
    {
        int id;
        int esta;
        printf("\nIngrese id: ");
        scanf("%d", &id);

        esta = buscarXId(p, tamP, id);

        if(esta != -1)
        {
            printf("\nExiste un programador con ese id!!!\n\n");
            system("pause");
        }
        else
        {
            p[indice].id = id;
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            gets(p[indice].nombre);
            mostrarCategorias(c, tamC);
            printf("\nIngrese categoria: ");
            scanf("%d", &p[indice].idCategoria);
            printf("\nIngrese sueldo: ");
            scanf("%f", &p[indice].sueldo);

            todoOk = 1;
        }
    }

    return todoOk;
}

void mostrarCategorias(eCategoria c[], int tam)
{
    int i;
    for(i= 0; i<tam; i++)
    {
        mostrarCategoria(c[i]);
    }
    printf("\n");

}

void mostrarCategoria(eCategoria cat)
{
    printf("\n%d %s", cat.id, cat.descripcion);
}

void mostrarProgramadores(eProgramador p[], int tamP, eCategoria c[], int tamC)
{
    int i;
    printf("\nId   Nombre     Categoria     Sueldo\n\n");
    for(i=0; i< tamP; i++)
    {
        if(p[i].id != -1)
        {
             mostrarProgramador(p[i], c, tamC);
        }

    }

    printf("\n\n");

    system("pause");

}

void mostrarProgramador(eProgramador p, eCategoria c[], int tamC)
{
    char descripcionCat[20];

    obtenerDescripcion(descripcionCat, c, tamC, p.idCategoria);


    printf("\n%5d %s %s %.2f", p.id, p.nombre, descripcionCat, p.sueldo);
}

void obtenerDescripcion(char descripcion[],  eCategoria c[], int tamC, int idCat)
{
    int i;
    for(i=0; i< tamC; i++)
    {
        if(c[i].id == idCat)
        {
            strcpy(descripcion, c[i].descripcion);
        }
    }
}

int cantidadXcategoria(eProgramador p[], int tamP, eCategoria c[], int tamC, char descripcion[])
{
    int cantidad = 0;
    int i;
    int idCat;

    for(i=0; i< tamC; i++)
    {
        if(strcmp(c[i].descripcion, descripcion) == 0)
        {
            idCat = c[i].id;
            break;
        }
    }

    for(i=0; i< tamP; i++)
    {
        if(p[i].idCategoria == idCat)
        {
            cantidad++;
        }
    }

    return cantidad;

}





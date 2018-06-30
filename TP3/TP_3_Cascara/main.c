#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "utn.h"

#define CANT_MAX 200


int main()
{
    int opcion=0;
    char auxTitulo[4096];
    int cantActual=0;
    EMovie* arrayMovie[CANT_MAX];

    do
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        getValidInt("\nIngrese la opcion deseada: ","\nNo valida\n",&opcion,1,5,1);

        switch(opcion)
        {
            case 1:
                movie_read(arrayMovie, &cantActual, CANT_MAX);
                movie_alta(arrayMovie, &cantActual, CANT_MAX);
                getChar("\n\nENTER (para continuar)");
                break;
            case 2:
                    movie_read(arrayMovie, &cantActual, CANT_MAX);
                    movie_mostrar(arrayMovie, cantActual);
                    if(!getValidStringAlfaNumerico("\nTitulo: ","","",auxTitulo,21,1))
                        movie_baja(arrayMovie, cantActual, auxTitulo);
                    getChar("\n\nENTER (para continuar)");
                break;
            case 3:
                    movie_read(arrayMovie, &cantActual, CANT_MAX);
                    movie_mostrar(arrayMovie, cantActual);
                    if(!getValidStringAlfaNumerico("\nTitulo: ","","",auxTitulo,21,1))
                        movie_modificacion(arrayMovie, cantActual, auxTitulo);
                    getChar("\n\nENTER (para continuar)");
               break;
            case 4:
                    movie_read(arrayMovie, &cantActual, CANT_MAX);
                    movie_generateIndex(arrayMovie, cantActual);
                    getChar("\n\nENTER (para continuar)");
                break;
        }
    }while(opcion != 5);
    return 0;
}

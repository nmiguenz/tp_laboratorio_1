#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "utn.h"

#define CANT_MAX 200

int main()
{
    int opcion=0;
    int auxId;
    int cantidadActual=0;
    EMovie* arrayMovie[CANT_MAX];

    do
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        getValidInt("\nIngrese la opcion deseada: ","\nNo es una opción válida [1-5]\n",&opcion,1,5,1);

        switch(opcion)
        {
            case 1:
                movie_read(arrayMovie, &cantidadActual, CANT_MAX);
                movie_alta(arrayMovie, &cantidadActual, CANT_MAX);
                break;
            case 2:
                movie_read(arrayMovie, &cantidadActual, CANT_MAX);
                movie_mostrar(arrayMovie, cantidadActual);
                if(!getValidInt("\nID?: ","\nNo es un ID valido",&auxId,0,9999,2));
                {
                    movie_baja(arrayMovie, cantidadActual, auxId);
                }
                break;
            case 3:
                movie_read(arrayMovie, &cantidadActual, CANT_MAX);
                movie_mostrar(arrayMovie, cantidadActual);
                if(!getValidInt("\nID?: ","\nNo es un ID valido",&auxId,0,9999,2));
                {
                    movie_modificacion(arrayMovie, cantidadActual, auxId);
                }
               break;
            case 4:
                movie_read(arrayMovie, &cantidadActual, CANT_MAX);
                movie_generarPagina(arrayMovie, cantidadActual);
                break;
        }
    }while(opcion != 5);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define QTY 20


int main()
{
    char seguir='s';
    int opcion=0;
    int auxDNI;
    EPersona persona[QTY];

    persona_init(persona,QTY);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(persona, QTY);
                break;
            case 2:
                persona_mostrar(persona,QTY);
                getValidInt("\nIngrese DNI de la persona a borrar: ","Ese no es un DNI valido", &auxDNI,00000001,99999999,1);
                persona_baja(persona,QTY,auxDNI);
                break;
            case 3:
                persona_ordenarPorNombre(persona,QTY,1);
                persona_mostrarPorNombre(persona,QTY);
                break;
            case 4:
                imprimir_grafico(persona,QTY);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

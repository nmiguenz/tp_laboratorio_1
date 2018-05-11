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
/*
    persona_altaForzada(persona,QTY,"Adrian",12,40132458);
    persona_altaForzada(persona,QTY,"Marta",13,30132458);
    persona_altaForzada(persona,QTY,"Matias",5,40152458);
    persona_altaForzada(persona,QTY,"Jose",17,40142458);
    persona_altaForzada(persona,QTY,"Coti",29,40132958);
    persona_altaForzada(persona,QTY,"Lau",54,10132458);
    persona_altaForzada(persona,QTY,"Gonza",35,13132458);
    persona_altaForzada(persona,QTY,"Ernest",37,40132458);
    persona_altaForzada(persona,QTY,"Adrian",42,31132458);
    persona_altaForzada(persona,QTY,"Adrian",12,40154458);
    persona_altaForzada(persona,QTY,"Adrian",8,40952458);
    persona_altaForzada(persona,QTY,"Adrian",81,40132458);
    persona_altaForzada(persona,QTY,"Sofi",79,40132478);
    persona_altaForzada(persona,QTY,"Adrian",12,27132458);
    persona_altaForzada(persona,QTY,"Adrian",15,99132458);
    persona_altaForzada(persona,QTY,"Dani",12,40132458);
    persona_altaForzada(persona,QTY,"Adrian",65,14132458);
    persona_altaForzada(persona,QTY,"Nico",12,40542458);
    persona_altaForzada(persona,QTY,"Adrian",12,30132458);
    persona_altaForzada(persona,QTY,"Lucas",49,20132458);
*/
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

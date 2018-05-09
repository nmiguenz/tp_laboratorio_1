#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

static int obtenerEspacioLibre(EPersona* personas, int limite);
static int proximoId(void);

int persona_init(EPersona* personas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            personas[i].isEmpty=1;
        }
    }
    return retorno;
}
//Usada
int persona_mostrar(EPersona* personas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!personas[i].isEmpty)
                printf("DNI %d - NOMBRE: %s - EDAD %d\n",personas[i].dni, personas[i].nombre, personas[i].edad);
        }
    }
    return retorno;
}

int persona_mostrarPorNombre(EPersona* personas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!personas[i].isEmpty)
                printf("NOMBRE: %s - EDAD %d - DNI %d\n",personas[i].nombre, personas[i].edad,personas[i].dni);
        }
    }
    return retorno;
}

int persona_alta(EPersona* personas,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    int auxEdad;
    int auxDni;
    if(limite > 0 && personas != NULL)
    {
        i = obtenerEspacioLibre(personas,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese nombre: ","\nEso no es un nombre","El maximo es 50 caracteres", auxNombre,50,2))
            {
                if(!getValidInt("\nIngrese edad: ","\nEsa no es una edad valida", &auxEdad,1,160,2))
                {
                    if(!getValidInt("\nIngrese DNI: ","\nEse no es un DNI valido", &auxDni,00000001,99999999,2))
                    {
                        retorno = 0;
                        strcpy(personas[i].nombre,auxNombre);
                        personas[i].edad = auxEdad;
                        personas[i].dni = auxDni;
                        personas[i].idPersona = proximoId();
                        personas[i].isEmpty = 0;
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int persona_baja(EPersona* personas,int limite, int dniABorrar)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!personas[i].isEmpty && personas[i].dni==dniABorrar)
            {
                personas[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int persona_ordenarPorNombre(EPersona* personas,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && personas != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!personas[i].isEmpty && !personas[i+1].isEmpty)
                {
                    if((strcmp(personas[i].nombre,personas[i+1].nombre) > 0 && orden) || (strcmp(personas[i].nombre,personas[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = personas[i];
                        personas[i] = personas[i+1];
                        personas[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int obtenerEspacioLibre(EPersona* personas, int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && personas != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(personas[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int persona_altaForzada(EPersona* personas,int limite,char* auxNombre,int auxEdad, int auxDni)
{

    int retorno = -1;
    int i;

    if(limite > 0 && personas != NULL)
    {
        i = obtenerEspacioLibre(personas,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(personas[i].nombre,auxNombre);
            personas[i].edad = auxEdad;
            personas[i].dni = auxDni;
            personas[i].idPersona = proximoId();
            personas[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int imprimir_grafico(EPersona* persona, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int contadorMenores=0;
    int contadorIntermedio=0;
    int contadorMayores=0;
    int maximoAsterisco=0;

    char imprimirPosiciones[3];

    for (i=0;i<limite;i++)
    {
        if(persona[i].edad>0 && persona[i].edad<=18)
            contadorMenores++;

        else if(persona[i].edad>18 && persona[i].edad<=35)
            contadorIntermedio++;

        else
            contadorMayores++;
    }

    imprimirPosiciones[0]=contadorMenores;
    imprimirPosiciones[1]=contadorIntermedio;
    imprimirPosiciones[2]=contadorMayores;

    for (i=0;i<2;i++)
    {
        if (imprimirPosiciones[i]>maximoAsterisco)
        {
            maximoAsterisco = imprimirPosiciones[i];
        }
    }
    for (i=maximoAsterisco;i>0;i--)
    {
        for (j=0;j<3;j++)
        {
            if(i<=imprimirPosiciones[j])
                printf(" *   ");

            else
                printf("     ");
        }
        printf("\n");
    }

    printf("<18 18-35 >35\n\n");
    return retorno =0;
}

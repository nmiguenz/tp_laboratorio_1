#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

static int obtenerEspacioLibre(EPersona* personas, int limite);
static int proximoId(void);

/** \brief Inicializa la estructura
 *
 * \param personas EPersona* Estructura que representa persona
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok
 *
 */
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
/** \brief Muestra los campos de la estructura para cada persona
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Muestra los campos de la estructura para las personas ingresadas empezando por el nombre.
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Dá de alta las personas
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Dá de baja a las personas con el DNI
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \param dniABorrar int recibe el DNI a ser borrado.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Ordena los array de la estructura por nombre
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \param orden int [1] ordena de menor a mayor, [0] de mayor a menor.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Busca los espacios libres en el array de la estructura
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Incrementa el Id
 *
 * \return int devuelve el valor del Id que va a ser usado en el próximo alta.
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
/** \brief Fuerza el alta de las personas (para probar el código)
 *
 * \param personas EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \param auxNombre char* recibe el nombre a forzar
 * \param auxEdad int recibe la edad a forzar
 * \param auxDni intrecibe el DNI a forzar
 * \return int [-1] Error [0] Ok.
 *
 */
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
/** \brief Imprime por consola un grafico de barras por edad
 *
 * \param persona EPersona* Estructura que representa persona.
 * \param limite int cantidad maxima de items en la estructura.
 * \return int [-1] Error [0] Ok.
 *
 */
int imprimir_grafico(EPersona* persona, int limite)
{
    fflush(stdin);
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

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXINT 32767
#define MININT -32768
#define MAXLONG 2147483647

int getInt (int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    long auxiliarLong;
    do
    {
        reintentos--;
        printf("%s", mensaje);
        scanf("%ld", &auxiliarLong);
        if (auxiliarLong>=minimo && auxiliarLong<=maximo)
        {
            *resultado = (int) auxiliarLong;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while (reintentos >=0);
    return retorno;
}

/** \brief Suma de dos enteros
 *
 * \param x int primer entero ingresado
 * \param y int segundo entero ingresado
 * \param z int* puntero al total
 * \return int [-1] Error [0] Ok
 *
 */
int sumaEnteros(int x, int y, int *z)
{
    long resultadoAuxiliar;
    int flagRetorno = -1;
    resultadoAuxiliar = x + y;
    if(resultadoAuxiliar <= MAXINT)
    {
        *z = resultadoAuxiliar;
        flagRetorno = 0;
    }
    return flagRetorno;
}

/** \brief Resta dos enteros
 *
 * \param x int primer entero ingresado
 * \param y int segundo entero ingresado
 * \param z int* puntero al total
 * \return int [-1] Error [0] Ok
 *
 */
int restaEnteros(int x, int y, int *z)
{
    long resultadoAuxiliar;
    int flagRetorno = -1;
    resultadoAuxiliar = x - y;
    if(resultadoAuxiliar >= MININT)
    {
        *z = resultadoAuxiliar;
        flagRetorno = 0;
    }
    return flagRetorno;
}

/** \brief División de dos enteros
 *
 * \param x int primer numero ingresado
 * \param y int segundo numero ingresado
 * \param z float* puntero al totalDivision
 * \return int [-1] Error [0] Ok
 *
 */
int divisionEnteros(int x, int y, float *z)
{
    double resultadoAuxiliar;
    int flagRetorno = -1;
    resultadoAuxiliar = x / (float)y;
    if(resultadoAuxiliar >= MININT && y!=0)
    {
        *z = resultadoAuxiliar;
        flagRetorno = 0;
    }
    return flagRetorno;
}


/** \brief Multiplica dos enteros
 *
 * \param x int primer numero ingresado
 * \param y int segundo numero ingresado
 * \param z long* puntero al totalLong
 * \return int [-1] Error [0] Ok
 *
 */
int multiplicarEnteros(int x, int y, long *z)
{
    float resultadoAuxiliar;
    int flagRetorno = -1;
    resultadoAuxiliar = x * y;
    if(resultadoAuxiliar <= MAXLONG)
    {
        *z = (long)resultadoAuxiliar;
        flagRetorno = 0;
    }
    return flagRetorno;
}

/** \brief Calcula el factorial del primer numero
 *
 * \param x int primer numero ingresado
 * \param z long* puntero al totalLong
 * \return int [-1] Error [0] Ok
 *
 */
int factorial(int x, long *z)
{
    int flagRetorno = -1;
    long resultadoAuxiliar;
    resultadoAuxiliar = x;
    do
    {
        x --;
        resultadoAuxiliar = resultadoAuxiliar * x;
        if ( resultadoAuxiliar > 1 && resultadoAuxiliar < MAXLONG)
        {
            *z = resultadoAuxiliar;
            flagRetorno = 0;
        }
    } while (x > 0);
    return flagRetorno;
}

/** \brief Imprime el resultado de todas las operaciones
 *
 * \param x int primer numero ingresado
 * \param y int segundo numero ingresado
 * \return void no devuelve nada
 *
 */
void CalcularTodasLasOperaciones (int x, int y)
{
    int total;
    float totalDivision;
    long totalLong;

    if(!sumaEnteros(x, y, &total))
    {
        printf("El resultado de la suma es %d\n", total);
    }
    else
    {
        printf("Error overflow\n");
    }
    if(!restaEnteros(x,y,&total))
    {
        printf("El resultado de la resta es %d\n", total);
    }
    else
    {
        printf("Error overflow\n");
    }
    if(!divisionEnteros(x, y, &totalDivision))
    {
        printf("El resultado de la division es %.2f\n", totalDivision);
    }
    else
    {
        printf("Error overflow\n");
    }
    if(!multiplicarEnteros(x,y, &totalLong))
    {
        printf("El resultado de la multiplicacion es %ld\n", totalLong);
    }
    else
    {
        printf("Error overflow\n");
    }
    if(!factorial(x,&totalLong))
    {
        printf("El valor del factorial de %d es: %ld\n", x, totalLong);
    }
    else
    {
        printf("Error overflow\n");
    }
    return;
}

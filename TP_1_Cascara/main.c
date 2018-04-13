#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXINT 32767
#define MININT -32768

int getInt (int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int sumaEnteros(int x, int y, int *z);
int restaEnteros(int x, int y, int *z);
int divisionEnteros(int x, int y, float *z);
int multiplicarEnteros(int x, int y, long *z);
int factorial(int x, long *z);
void CalcularTodasLasOperaciones (int x, int y);

int main()
{
    char seguir='s';
    int opcion=0;
    int A = 0;
    int B = 0;
    int total;
    float totalDivision;
    long totalLong;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A= %d)\n",A);
        printf("2- Ingresar 2do operando (B= %d)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if (getInt (&A , "Ingrese el 1er operando: ", "El operando no se encuentra dentro del rango [-32768 - 32767]\n", -32768, 32767, 2)==0)
                {

                }
                else
                {
                    printf("\nError\n");
                }
                break;
            case 2:
                if (getInt (&B , "Ingrese el 2do operando: ", "El operando no se encuentra dentro del rango [-32768 - 32767]\n", -32768, 32767, 2)==0)
                {

                }
                else
                {
                    printf("\nError\n");
                }
                break;
            case 3:
                if(!sumaEnteros(A, B, &total))
                {
                    printf("El resultado de la suma es %d\n", total);
                }
                else
                {
                    printf("Error overflow\n");
                }
                break;
            case 4:
                if(!restaEnteros(A, B, &total))
                {
                    printf("El resultado de la resta es %d\n", total);
                }
                else
                {
                    printf("Error overflow\n");
                }
                break;
            case 5:
                if(!divisionEnteros(A, B, &totalDivision))
                {
                    printf("El resultado de la division es %.2f\n", totalDivision);
                }
                else
                {
                    printf("Error overflow\n");
                }
                break;
            case 6:
                if(!multiplicarEnteros(A, B, &totalLong))
                {
                    printf("El resultado de la multiplicacion es %ld\n", totalLong);
                }
                else
                {
                    printf("Error overflow\n");
                }
                break;
            case 7:
                if(!factorial(A,&totalLong))
                {
                    printf("El valor del factorial de %d es: %ld\n", A, totalLong);
                }
                else
                {
                    printf("Error overflow\n");
                }
                break;
            case 8:
                CalcularTodasLasOperaciones (A, B);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

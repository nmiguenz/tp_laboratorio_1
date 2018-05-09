#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int idPersona;
    int edad;
    int dni;
    int isEmpty;

}EPersona;

int persona_init(EPersona* personas,int limite);
int persona_mostrar(EPersona* personas,int limite);
int persona_mostrarPorNombre(EPersona* personas,int limite);
int persona_alta(EPersona* personas,int limite);
int persona_baja(EPersona* personas,int limite, int dniABorrar);
int persona_ordenarPorNombre(EPersona* personas,int limite, int orden);
int persona_altaForzada(EPersona* personas,int limite,char* auxNombre,int auxEdad, int auxDni);
int imprimir_grafico(EPersona* persona, int limite);
#endif // FUNCIONES_H_INCLUDED

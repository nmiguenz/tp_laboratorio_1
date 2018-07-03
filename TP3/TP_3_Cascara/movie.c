#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "utn.h"


static int isValidTitulo(char* titulo);
static int isValidGenero(char* genero);
static int isValidDuracion(int duracion);
static int isValidDescripcion(char* descripcion);
static int isValidPuntaje(float puntaje);
static int isValidLinkImagen(char* linkImagen);


EMovie* movie_new(void)
{
    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));
    return returnAux;
}

int movie_delete(EMovie* this)
{
    if(this != NULL)
    {
        free(this);
        return 0;
    }
    return -1;
}

EMovie* movie_newParameters(char* stringId, char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen)
{
    int id;
    EMovie* this = movie_new();

    id = atoi(stringId);

    if( !movie_setId(this, id) &&
        !movie_setTitulo(this, titulo) &&
        !movie_setGenero(this, genero) &&
        !movie_setDuracion(this, duracion) &&
        !movie_setDescripcion(this, descripcion) &&
        !movie_setPuntaje(this, puntaje) &&
        !movie_setLinkImagen(this, linkImagen))
    {
        return this;
    }
    movie_delete(this);
    return NULL;
}

int movie_guardar(EMovie* this)
{
    FILE *pFile;
    pFile=fopen("movies.dat","ab");

    if(pFile != NULL && this != NULL)
    {
        fwrite(this,sizeof(EMovie),1,pFile);
        fclose(pFile);
        return 0;
    }
    return -1;
}

int movie_escribirArchivo(EMovie** this, int cantidadActual)
{
    int i;
    FILE *pFile;
    pFile=fopen("movies.dat","wb");

    if(pFile != NULL && this != NULL)
    {
        for(i=0; i<cantidadActual; i++)
        {
            if(*(this+i) != NULL)
            {
                fwrite(*(this+i),sizeof(EMovie),1,pFile);
            }
        }
        fclose(pFile);
        return 0;
    }
    return -1;
}

int movie_read(EMovie** this, int* cantidadActual, int cantidadMaxima)
{
    int r, i=0;
    *cantidadActual=0;
    FILE* pFile;
    pFile=fopen("movies.dat","rb");

    if(pFile != NULL && this != NULL)
    {
        while(!feof(pFile))
        {
            *(this+i) = movie_new();
            r = fread(*(this+i),sizeof(EMovie),1,pFile);
            if((*cantidadActual) == cantidadMaxima || r != 1)
            {
                movie_delete(*(this+i));
                break;
            }

            (*cantidadActual)++;
            i++;
        }
        fclose(pFile);
        return 0;
    }
    return -1;
}

int movie_alta(EMovie** this, int* cantidadActual, int cantidadMaxima)
{
    int id;
    char titulo[4096];
    char genero[4096];
    int duracion;
    char descripcion[4096];
    float puntaje;
    char linkImagen[4096];
    if((*cantidadActual) < cantidadMaxima && this != NULL)
    {
        if( !getValidStringAlfaNumerico("\nTitulo: ","\nNo es un titulo válido","\nEl titulo supera la cantidad de caracteres",titulo,50,1) &&
            !getValidString("\nGenero: ","\nNo es un genero valido","\nNo se acepta esa cantidad de caracteres",genero,21,1) &&
            !getValidInt("\nDuracion: ","\nNo es una duracion valida[10-1000]",&duracion,10,1000,1) &&
            !getValidDescripcion("\nDescripcion: ","\nNo es una descripcion valida",descripcion,750,1) &&
            !getValidFloat("\nPuntaje[1-10]: ","\nNo es un puntaje valido",&puntaje,1,10,1) &&
            !getValidLink("\nLink foto: ","\nNo es un link valido","\nEl link tiene una extension que supera la permitida",linkImagen,300,1))
        {

            *(this + (*cantidadActual)) = movie_newParameters(id,titulo,genero,duracion,descripcion,puntaje,linkImagen);
            movie_guardar(*(this + (*cantidadActual)));

            (*cantidadActual)++;

            printf("\nPelicula agregada con exito\n");
            return 0;
        }
        else
        {
            printf("\nError, datos ingresados de manera erronea\n");
            return -2;
        }
    }
    printf("\nError\n");
    return -1;
}

int movie_mostrar(EMovie** this, int cantidadActual)
{
    int i;
    int id;
    char titulo[4096];
    char genero[4096];
    int duracion;
    char descripcion[4096];
    float puntaje;
    char linkImagen[4096];
    if(this != NULL)
    {
        for(i=0; i<cantidadActual; i++)
        {
            if((*(this+i))!=NULL && !movie_getId(*(this+i),id) &&
               !movie_getTitulo(*(this+i),titulo) && !movie_getGenero(*(this+i),genero) &&
               !movie_getDuracion(*(this+i),&duracion) && !movie_getDescripcion(*(this+i),descripcion) &&
               !movie_getPuntaje(*(this+i),&puntaje) && !movie_getLinkImagen(*(this+i),linkImagen))
            {
                printf("\nID: %d - Titulo: %s - Genero: %s \nDuracion: %d - Puntaje: %.1f \nDescripcion: %s\nLink Imagen: %s\n",id,titulo,genero,duracion,puntaje,descripcion,linkImagen);
            }
        }
        return 0;
    }
    return -1;
}

int movie_baja(EMovie** this, int cantidadActual, int id)
{
    int i;
    if(this != NULL)
    {
        i = movie_getById(this, cantidadActual, id);
        if(i != -1)
        {
            *(this + i) = NULL;
            movie_escribirArchivo(this, cantidadActual);
            printf("\nPelicula eliminada correctamente\n");
            return 0;
        }
        else
        {
            printf("\nLa película que quiere eliminar no existe\n");
            return -2;
        }
    }
    return -1;
}

int movie_getById(EMovie** this, int cantidadActual, int id)
{
    int i;
    int auxId = 0;
    if(this != NULL)
    {
        for(i=0; i<cantidadActual; i++)
        {
            if(*(this+i) != NULL)
            {
                movie_getId(*(this+i),auxId);
                if(auxId == id)
                    return i;
            }
        }
    }
    return -1;
}

int movie_modificacion(EMovie** this, int cantidadActual, int id)
{
    int i;
    char titulo[4096];
    char genero[4096];
    int duracion;
    char descripcion[4096];
    float puntaje;
    char linkImagen[4096];
    if(this != NULL)
    {
        i = movie_getById(this, cantidadActual, id);
        if(i != -1)
        {
            if(!getValidStringAlfaNumerico("\nTitulo: ","\nNo es un titulo válido","\nEl titulo supera la cantidad de caracteres",titulo,50,1) &&
            !getValidString("\nGenero: ","\nNo es un genero valido","\nNo se acepta esa cantidad de caracteres",genero,21,1) &&
            !getValidInt("\nDuracion: ","\nNo es una duracion valida[10-1000]",&duracion,10,1000,1) &&
            !getValidDescripcion("\nDescripcion: ","\nNo es una descripcion valida",descripcion,750,1) &&
            !getValidFloat("\nPuntaje[1-10]: ","\nNo es un puntaje valido",&puntaje,1,10,1) &&
            !getValidLink("\nLink foto: ","\nNo es un link valido","\nEl link tiene una extension que supera la permitida",linkImagen,300,1))
            {
                if( !movie_setTitulo(*(this + i), titulo) &&
                !movie_setGenero(*(this + i), genero) &&
                !movie_setDuracion(*(this + i), duracion) &&
                !movie_setDescripcion(*(this + i), descripcion) &&
                !movie_setPuntaje(*(this + i), puntaje) &&
                !movie_setLinkImagen(*(this + i), linkImagen))
                {
                    movie_escribirArchivo(this, cantidadActual);
                    printf("\nPelicula modificada correctamente\n");
                    return 0;
                }
            }
            else
            {
                printf("\nError, datos ingresados de manera erronea\n");
                return -2;
            }
        }
        else
        {
            printf("\nError\n");
            return -2;
        }
    }
    return -1;
}

int movie_generarPagina(EMovie** this,int cantidadActual)
{
    int i;
    char titulo[4096];
    char genero[4096];
    int duracion;
    char descripcion[4096];
    float puntaje;
    char linkImagen[4096];
    FILE *pFile;
    pFile=fopen("template/index.html","w");

    if(pFile!= NULL && this != NULL)
    {
        fprintf(pFile,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");

            for(i=0; i<cantidadActual; i++)
            {
                if((*(this+i))!=NULL &&
                !movie_getTitulo(*(this+i),titulo) &&
                !movie_getGenero(*(this+i),genero) &&
                !movie_getDuracion(*(this+i),&duracion) &&
                !movie_getDescripcion(*(this+i),descripcion)&&
                !movie_getPuntaje(*(this+i),&puntaje) &&
                !movie_getLinkImagen(*(this+i),linkImagen))
                {
                    fprintf(pFile,"<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%.1f</li><li>Duración:%d</li></ul><p>%s</p></article><!-- Repetir esto para cada pelicula -->",linkImagen,titulo,genero,puntaje,duracion,descripcion);
                }
            }

        fprintf(pFile,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
        fclose(pFile);
        printf("\nLa pagina fue generada correctamente\n");
        return 0;
    }
    return -1;
}

//Setters y getters
int movie_setId(EMovie* this, int id)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            ultimoId++;
            this->id = ultimoId;
            retorno = 0;
        }
        if(id > ultimoId)
        {
            this->id = id;
            ultimoId = id;
            retorno = 0;
        }
    }
    return retorno;
}


int movie_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int movie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && !isValidTitulo(titulo))
    {
        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}


int movie_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = 0;
    }
    return retorno;
}


int movie_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && !isValidGenero(genero))
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}


int movie_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero,this->genero);
        retorno = 0;
    }
    return retorno;
}


int movie_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL && !isValidDuracion(duracion))
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}


int movie_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}


int movie_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && !isValidDescripcion(descripcion))
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}


int movie_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno = 0;
    }
    return retorno;
}


int movie_setPuntaje(EMovie* this, float puntaje)
{
    int retorno = -1;
    if(this != NULL && !isValidPuntaje(puntaje))
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}


int movie_getPuntaje(EMovie* this, float* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}


int movie_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL && !isValidLinkImagen(linkImagen))
    {
        strcpy(this->linkImagen,linkImagen);
        retorno = 0;
    }
    return retorno;
}


int movie_getLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(linkImagen,this->linkImagen);
        retorno = 0;
    }
    return retorno;
}

//VALIDACIONES
static int isValidTitulo(char* titulo)
{
    int i = 0;
    if(strlen(titulo) < 50)
    {
        while(titulo[i] != '\0')
        {
            if((titulo[i] == '.'))
                return -1;
            i++;
        }
    }
    return 0;
}


static int isValidGenero(char* genero)
{
    int i = 0;
    if(strlen(genero) < 21)
    {
        while(genero[i] != '\0')
        {
            if((genero[i] != ' ') && (genero[i] < 'a' || genero[i] > 'z') && (genero[i] < 'A' || genero[i] > 'Z'))
                return -1;
            i++;
        }
    }
    return 0;
}


static int isValidDuracion(int duracion)
{
    if(duracion < 10 || duracion > 1000)
        return -1;
    return 0;
}


static int isValidDescripcion(char* descripcion)
{
    if(strlen(descripcion) > 1000)
        return -1;
    return 0;
}


static int isValidPuntaje(float puntaje)
{
    if(puntaje < 0 || puntaje > 10.0)
        return -1;
    return 0;
}


static int isValidLinkImagen(char* linkImagen)
{
    int i = 0;
    if(strlen(linkImagen) < 400)
    {
        while(linkImagen[i] != '\0')
        {
            if(linkImagen[i] == ' ')
                return -1;
            i++;
        }
    }
    return 0;
}

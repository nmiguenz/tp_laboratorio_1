#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct{
    int id;
    char titulo[50];
    char genero[21];
    int duracion;
    char descripcion[201];
    float puntaje;
    char linkImagen[201];
}EMovie;

/** \brief Aloca una nueva arrayList en la cantidad actual de peliculas
 * \param void
 * \return EMovie* Retorna NULL si hubo error, retorna puntero al nuevo arrayList si todo esta ok
 *
 */
EMovie* movie_new(void);

/** \brief Aloca una nueva arrayList en la cantidad actual de peliculas
 * \param stringId Es el id de la pelicula
 * \param titulo Es el titulo de la pelicula
 * \param genero Es el genero de la pelicula
 * \param duracion Es la duracion de la pelicula
 * \param descripcion Es la descripcion de la pelicula
 * \param puntaje Es el puntaje de la pelicula
 * \param linkImagen Es el link de la imagen de la pelicula a setear
 * \return EMovie* [NULL] error, retorna puntero al nuevo arrayList si ok
 */
EMovie* movie_newParameters(int id, char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen);

/** \brief Libera un espacio de memoria
 * \param this Puntero al espacio de memoria que se desea eliminar
 * \return Retorna [-1] ERROR, [0] OK
 */
int movie_delete(EMovie* this);

/** \brief Escribe en un archivo una pelicula
 * \param this Puntero al espacio de memoria en el que se almacena la pelicula
 * \return Retorna [-1] ERROR, [0] OK
 */
int movie_guardar(EMovie* this);

/** \brief Escribe en un archivo un arrayList de peliculas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacena las peliculas
 * \param cantidadActual de peliculas
 * \return Retorna [-1] ERROR, [0] OK
 */
int movie_escribirArchivo(EMovie** this, int cantidadActual);

/** \brief Lee de un archivo un arrayList de peliculas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param cantMaxima Cantidad maxima de peliculas a agregar
 * \return Retorna [-1] ERROR, retorna [0] ok
 */
int movie_read(EMovie** this, int* cantidadActual, int cantidadMaxima);

/** \brief Da de alta a una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual de peliculas
 * \param cantidadMaxima de peliculas a agregar
 * \return Retorna [-2] ingreso incorrecto,[-1] No hay mas espacio,[0] OK
 */
int movie_alta(EMovie** this, int* cantidadActual, int cantidadMaxima);

/** \brief Modifica una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual de peliculas
 * \param id de la pelicula a modificar
 * \return Retorna [-2] ingreso incorrecto,[-1] No hay mas espacio,[0] OK
 */
int movie_modificacion(EMovie** this, int cantidadActual, int id);

/** \brief Da de baja una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual de peliculas
 * \param id de la pelicula a eliminar
 * \return Retorna [-2] ingreso incorrecto,[-1] No hay mas espacio,[0] OK
 */
int movie_baja(EMovie** this, int cantidadActual, int id);

/** \brief Muestra las peliculas cargadas por consola
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual Cantidad actual de peliculas
 * \return Retorna [-1] ERROR,[0] OK
 */
int movie_mostrar(EMovie** this, int cantidadActual);

/** \brief Obtiene el indice de la posicion de una pelicula por ID
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual de peliculas
 * \param id de la pelicula que se esta buscando
 * \return Retorna [-1] ERROR, [>-1] el indice de la pelicula
 */
int movie_getById(EMovie** this, int cantidadActual, int id);

/** \brief Genera el index.html
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantidadActual de peliculas
 * \return Retorna [-1] ERROR,[0] OK
 */
int movie_generarPagina(EMovie** this,int cantidadActual);


int movie_setId(EMovie* this, int id);
int movie_getId(EMovie* this, int* id);
int movie_setTitulo(EMovie* this, char* titulo);
int movie_getTitulo(EMovie* this, char* titulo);
int movie_setGenero(EMovie* this, char* genero);
int movie_getGenero(EMovie* this, char* genero);
int movie_setDuracion(EMovie* this, int duracion);
int movie_getDuracion(EMovie* this, int* duracion);
int movie_setDescripcion(EMovie* this, char* descripcion);
int movie_getDescripcion(EMovie* this, char* descripcion);
int movie_setPuntaje(EMovie* this, float puntaje);
int movie_getPuntaje(EMovie* this, float* puntaje);
int movie_setLinkImagen(EMovie* this, char* linkImagen);
int movie_getLinkImagen(EMovie* this, char* linkImagen);


#endif // MOVIE_H_INCLUDED

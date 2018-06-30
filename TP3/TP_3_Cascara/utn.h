#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#endif // UTN_H_INCLUDED

char getChar(char* mensaje);
int getInt(char* mensaje);
float getFloat(char* mensaje);

char getNumeroAleatorio(int desde,int hasta,int iniciar);

void getString(char* mensaje,char* input);
int getStringLetras(char* mensaje,char* input);
int getStringNumeros(char* mensaje,char* input);
int getStringNumerosFlotantes(char* mensaje,char* input);
int getStringAlfaNumerico(char* mensaje,char* input);
int getStringLink(char* mensaje,char* input);
int getStringDescripcion(char* mensaje,char* input);

int getValidString(char* requestMessage,char* errorMessage,char* errorMessageLenght,char* input,int maxLenght,int attemps);
int getValidInt(char* requestMessage,char* errorMessage,int* input,int lowLimit,int hiLimit,int attemps);
int getValidFloat(char* requestMessage,char* errorMessage,float* input,float lowLimit,float hiLimit,int attemps);
int getValidStringAlfaNumerico(char* requestMessage,char* errorMessage,char* errorMessageLenght,char* input,int maxLenght,int attemps);
int getValidLink(char* requestMessage,char* errorMessage,char* errorMessageLenght,char* input,int maxLenght,int attemps);
int getValidDescripcion(char* requestMessage,char* errorMessageLenght,char* input,int maxLenght,int attemps);

int esSoloLetras(char* str);
int esLink(char* str);
int esNumerico(char* str) ;
int esNumericoFlotante(char* str);
int esAlfaNumerico(char* str);
int esTelefono(char* str);
int esCuil(char* str);
int esPassword(char* str);

void clearStdin(void);
void pause(void);
void clearScreen(void);
void showDate(void);

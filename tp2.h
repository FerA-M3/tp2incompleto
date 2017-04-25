

typedef struct
{
    int legajo;
    int dni;
    char nombre[50];
    char apellido[50];
    int estado;
}ePersona;


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

int esTelefono(char str[]);
int esNumerico(char  str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);

void defineEstado(ePersona personaArray[],int arrayLength,int value);





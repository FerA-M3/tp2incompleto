#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.h"

#define MAX_QTY 20


 int getInt(char mensaje[])
 {
     int auxiliar;
     printf("%s",mensaje);
     scanf("%d",&auxiliar);
     return auxiliar;
 }



 char getChar(char mensaje[])
 {
     char auxiliar;
     printf("%s",mensaje);
     fflush(stdin);
     scanf("%c",&auxiliar);
     return auxiliar;
 }



/**
* \brief verifica si el valor recibido contiene solo numeros
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo '' y letras y 0 si no lo es
*
*/



int esNumerico(char  str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
        {
            return 0;
            i++;
        }
        return 1;
    }
}




/**
* \brief verifica si el valor recibido contiene solo letras
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo '' y letras y 0 si no lo es
*
*/


int esSoloLetras(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&& (str[i]< 'a'|| str[i]> 'z')&& (str[i]<'A' || str[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}

    /**
  * \brief solicita un texto al usuario y lo devuelve
  * \param mesnsaje es el Mensaje a ser mostrado
  * \param input Array donde se cargara el texto ingresado
  * \return void
  */

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s", input);
}

/**
  * \brief solicita un texto al usuario y lo devuelve
  * \param mensaje Es el mensaje a ser mostrado
  * \param input Array donde se cargara el texto ingresado
  * \return 1 si el texto contiene solo letras
  */


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
  * \brief solicita un texto al usuario y lo devuelve
  * \param mensaje Es el mensaje a ser mostrado
  * \param input Array donde se cargara el texto ingresado
  * \return 1 si el texto contiene solo numeros
  */

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;

}

void inicializarArrayPersona(ePersona personaArray[],int arrayLength,int value)
{
    int i;
    for(i=0;i<arrayLength;i++)
    {
        personaArray[i].estado=value;
    }
}

//describir parametros

int buscaLugarLibre(ePersona personaArray[],int arrayLength)
{
    int i;
    for(i=0;i<arrayLength;i++)
    {
        if(personaArray[i].estado==0)
        return i;
    }
    return -1;
}

int buscarPersonaPorLegajo(ePersona personaArray[], int arrayLenght, int legajo)
{
    int i;
    for(i=0;i<arrayLenght;i++)
    {
        if(personaArray[i].legajo==legajo && personaArray[i].estado==1)
        {
            return i;
        }
    }return -1;

}

void defineEstado(ePersona personaArray[],int arrayLength,int value)
{
    int i;
    for(i=0;i<arrayLength;i++)
    {
        personaArray[i].estado=value;
    }
}






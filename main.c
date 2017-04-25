#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp2.h"

#define MAX_QTY 20


int main()
{
    ePersona personaArray[MAX_QTY];
    ePersona personaAux; // esto nose para q gaver

    int opcion=0;
    int i;

    int legajoAux;
    int dniAux;
    char nombreAux;
    char apellidoAux;

    char legajoAuxStr[50];
    char dniAuxStr[50];
    char nombreAuxStr[50];
    char apellidoAuxStr[50];

    int indiceLugarLibre;
    int buscarIndice;

    defineEstado(personaArray,MAX_QTY,0);


    while(opcion!=5)
    {

        opcion=getInt("\n\n\n1 - Agregar persona \n2 - Borrar Persona \n3 - Imprimir por nombre \n4 - Imprimir grafico \n5 - Salir\n\n\n");

        switch(opcion)
          {
            case 1:

                indiceLugarLibre=buscaLugarLibre(personaArray,MAX_QTY);
                if(indiceLugarLibre==-1)    // ver si esta bien asignarle un -1
                {
                    printf("\nNo hay lugares libres: ");
                    break;
                }
                printf("\nALTA\n\n");
                if(!getStringNumeros("Ingrese legajo:",legajoAuxStr))
                {
                    printf("El legajo debe ser numerico\n");
                    break;
                }
                legajoAux=atoi(legajoAuxStr);

                // tengo que saber si este legajo ya existe entonces
                if(buscaLugarLibre(personaArray,MAX_QTY,legajoAux)==-1)  // cambie el != por el ==
                {
                    printf("\nEl legajo ya existe!!!\n");
                    break;
                }
                if(!getStringLetras("Ingrese nombre",nombreAuxStr))
                {
                    printf("\nEl nombre deber ser solo letras\n");
                    break;
                }

                if(!getStringLetras("Ingrese el apellido",apellidoAuxStr))
                {
                    printf("\nEl apellido deber ser solo letras\n");
                    break;
                }

                if(!getStringNumeros("Ingrese DNI:",dniAuxStr))
                {
                    printf("El DNI debe ser numerico\n");
                    break;
                }
                dniAux=atoi(dniAuxStr);

                personaArray[indiceLugarLibre].legajo=legajoAux;
                personaArray[indiceLugarLibre].dni=dniAux;
                personaArray[indiceLugarLibre].estado=1;
                strcpy(personaArray[indiceLugarLibre].nombre,nombreAux);
                strcpy(personaArray[indiceLugarLibre].apellido,apellidoAux);

                    break;
            case 2:
                    if(!getStringNumeros("\nIngrese legajo a dar de baja:",legajoAuxStr))
                    {
                        printf("\nEl legajo debe ser numerico!!");
                        break;
                    }
                    legajoAux=atoi(legajoAuxStr);

                    buscarIndice=buscarPersonaPorLegajo(personaArray,MAX_QTY,legajoAux);
                    if(buscarIndice==-1)
                    {
                        printf("\nNo se encuentra el legajo!!!");
                        break;
                    }
                    personaArray[buscarIndice].estado=-2;   // -2 pone en estado de baja logica


                break;



            case 3:
                break;
            case 4:
                break;
            case 5:

                break;
        }
    }

    return 0;
}

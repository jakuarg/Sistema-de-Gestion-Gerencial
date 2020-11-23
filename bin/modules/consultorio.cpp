/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo N 					   **
  *   Veterinaria					*
  ***********************************
  **********CONSULTORIO**************
  ***********************************
*/
//DECLARACIONES DE LIBRERIAS
#include<stdio.h>//Funciones de entrada
#include<stdlib.h>//Funciones system
//PARA HABILITAR EL USO DE CARACTERES ESPECIALES
#include <wchar.h>
#include <locale.h>
//PARA HABILITAR FUNCIONES DE TEXTO
#include <ctype.h>
#include <string.h>
//PARA HABILITAR FUNCIONES ESPECIALES DE MANIPULACION DE VENTANA,ETC
#include <windows.h>
#include "functions/admin.h"

struct fecha{

int dia;
int mes;
int anio;

};

struct documentacion{ // Documentacion del due�o del animal.

	char Apeynom[30];
	int dni;
	char Localidad[20];
	char informeMascota[380];
	bool borrado;
	 fecha fec;
};

int menuprincipal();
void evolucionMascota(FILE *archMascota);

main()
{
	setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
	int opc; //variable declarada para acceder a las opciones 
	FILE *archMascota = fopen("Mascotas.dat", "r+b");
	if (archMascota == NULL)	{
		fclose(archMascota);
		archMascota = fopen("Mascotas.dat", "w+b");
	}
	do{
		opc = menuprincipal();
		switch(opc){
			case 1:{
				
			}
			case 2:{
				evolucionMascota(archMascota);
				system("PAUSE");						
				break;		
			}
			case 3:{
			
				break;
			}
		}
	}while(opc!=4);


}


int menuprincipal()
{
	int op;
	system("CLS");
	printf("\n\t\t\t    =============================================     ");
	printf("\n\t\t\t            Modulo Consultorio Veterinario            ");
	printf("\n\t\t\t  	==============================================    ");
	printf("\n\t\t\t    1.- Visualizar Lista de Espera de Turnos (informe)");
	printf("\n\t\t\t	2.- Registrar Evolucion de la Mascota             ");
	printf("\n\t\t\t    3.- Cerrar la aplicacion.                         ");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t\t 	 Ingrese una opcion: 	"); 
	scanf("%d", &op);
	return op;

}


void evolucionMascota(FILE *archMascota)
{
	documentacion reg;
	int edadDuenio;
	printf ("Ingrese la fecha de nacimiento del dueño : dd/mm/aaaa ");
	scanf("%2d", &reg.fec.dia);
	scanf("%2d", &reg.fec.mes);
	scanf("%4d", &reg.fec.anio);
	edadDuenio = 2020 - reg.fec.anio;
	printf ("\n La edad del duenio es %d ", edadDuenio); // Mostramos la edad del duenño de la mascota.	printf ("\nIngrese el Apellido y nombre de la mascota : ");
	_flushall();
	gets(reg.Apeynom);
	printf ("\nIngrese el dni del dueno de la mascota : ");
	scanf ("%d", &reg.dni);
	printf ("\nIngrese la localidad del dueno : ");
	_flushall();
	gets(reg.Localidad);
	printf ("\nIngrese la evolucion de la mascota ");
	gets(reg.informeMascota);
	fseek(archMascota,0,2); // Comienza desde el final del archivo
	fwrite(&reg,sizeof(documentacion),1,archMascota); // Guarda desde donde quedo el puntero anterior.

}

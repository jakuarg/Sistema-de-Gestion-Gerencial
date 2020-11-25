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


int menuprincipal();
void evolucionMascota(FILE *archMascota);
void Listaespera();
main()
{
	setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

	int opc; //variable declarada para acceder a las opciones 

	FILE *archMascota = fopen("bin/modules/Mascotas.dat", "r+b");

	if (archMascota == NULL)	{
		fclose(archMascota);
		archMascota = fopen("bin/modules/Mascotas.dat", "w+b");
	}
	do{
		opc = menuprincipal();
		switch(opc){
			case 1:{
				Listaespera();
				system("PAUSE");
				break;
			}
			case 2:{
				evolucionMascota(archMascota);
				system("PAUSE");						
				break;		
			}
			case 3:{
				system("PAUSE");
				exit(1);
				break;
			}
			default:{
				printf ("El valor ingresado no es correcto ");
				system("PAUSE");
				break;
			}
		}
	}while(opc!=3);


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
	Datos_pet pet;
	documentacion reg;
	Turno reg1;
	int edadDuenio;
	
	//EDAD
	rewind (archMascota);
	fread(&reg1,sizeof(Turno),1,archMascota);
	printf("%d",feof(archMascota));
	do
	{
		printf ("\n La edad de la mascota es %d ", 2020-pet.de_nacimiento.anio); // Mostramos la edad del duenño de la mascota.	
		fread(&reg1,sizeof(Turno),1,archMascota);
	}while(!feof(archMascota));

	//OTROS
	rewind(archMascota);
	fread(&pet,sizeof(Datos_pet),1,archMascota);
	printf("%d",feof(archMascota));
	printf ("\nIngrese el Apellido y nombre de la mascota : ");
	_flushall();
	gets(reg.Apeynom);
	while(!feof(archMascota))
	{
		if(strcmp(pet.Apeynom_pet,reg.Apeynom)== 0)
		{
			printf ("\nel dni del dueno de la mascota %d", pet.DNI_DUENIO);
			printf ("\nla localidad del dueno : ");
			_flushall();
			puts(pet.localidad);
			printf ("\nIngrese la evolucion de la mascota : ");
			gets(reg.informeMascota);
			reg.borrado = true;
			//fseek(archMascota,0,2); // Comienza desde el final del archivo
			fwrite(&reg,sizeof(documentacion),1,archMascota); // Guarda desde donde quedo el puntero anterior.		
		}
		fread(&pet,sizeof(Datos_pet),1,archMascota);
	}
	
}

void Listaespera()
{
	FILE *ArchTurno = fopen("bin/modules/Turno.dat","r+b");
	Turno reg;
	
	rewind (ArchTurno);
	fread(&reg,sizeof(Turno),1,ArchTurno);
	while(!feof(ArchTurno))
	{
		printf("\nFecha de turno");
   		printf("DIA: %2d", reg.fec.dia);
    	printf("MES: %2d", reg.fec.mes);
   		printf("ANIO: %4d", reg.fec.anio);
 	   printf("\nDNI del Dueño: %d", reg.DNI_DUENIO);
 	   puts(reg.detalle_de_atencion);
 	   fread(&reg,sizeof(Turno),1,ArchTurno);
	}
	
}
    

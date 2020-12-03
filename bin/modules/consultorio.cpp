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
void evolucionMascota(FILE *archMascota,int &pn);
void Listaespera();

main()
{
	setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
	int matricula,pn;
	int opc,aux; //variable declarada para acceder a las opciones 
	auth reg;
	FILE *archMascota = fopen("bin/modules/Mascotas.dat", "r+b");
	if (archMascota == NULL)	{
		fclose(archMascota);
		archMascota = fopen("bin/modules/Mascotas.dat", "w+b");
	}
	{
	do{
		opc = menuprincipal();
		switch(opc){
			case 1:{

				Listaespera();
				system("PAUSE");
				break;
			}
			case 2:{
				evolucionMascota(archMascota,pn);
				system("PAUSE");						
				break;		
			}
			case 3:{
				system("PAUSE");
				remove("Auxiliar.dat");
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

}


int menuprincipal()
{
	int auxx = 1;
	aux auxiliar;
	auth reg;
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	do{
		if (reg.modulo == auxiliar.modulo)	
		{
			auxx = 0;
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
		}
		
	}while(!feof(arch_admin) and !feof(archaux1) and auxx == 1);
	{
		system("CLS");
		int op;
		system("CLS");
		printf("\n\t\t\t    =============================================     ");
		printf("\n\t\t\t          Modulo %d Consultorio Veterinario           ", auxiliar.modulo);
		printf("\n\t\t\t  	==============================================    ");
		printf("\n  				    Veterinario a cargo : %s              ",auxiliar.names);
		printf("\n\t\t\t    1.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n\t\t\t	2.- Registrar Evolucion de la Mascota             ");
		printf("\n\t\t\t    3.- Cerrar la aplicacion.                         ");
		printf("\n\t\t\t =======================================");
		printf("\n\t\t\t\t 	 Ingrese una opcion: 	"); 
		scanf("%d", &op);
		return op;
	}	

}


void evolucionMascota(FILE *archMascota,int &pn)
{
	int auxx = 1;
	Datos_pet pet;
	Turno reg1;
	int edadDuenio;
	aux auxiliar;
	auth reg;
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	do{
		if (reg.modulo == auxiliar.modulo)	
		{
			auxx = 0;
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
		}
		
	}while(!feof(arch_admin) and !feof(archaux1) and auxx == 1);

	rewind(archMascota);
	fread(&pet,sizeof(Datos_pet),1,archMascota);
	char nom[60];
	printf("%d",feof(archMascota));
	printf ("\nIngrese el Apellido y nombre de la mascota : ");
	_flushall();
	gets(nom);
	while(!feof(archMascota))
	{
		if(strcmp(pet.Apeynom_pet,nom)== 0)
		{
			printf ("\nel dni del dueno de la mascota %d", pet.DNI_DUENIO);
			printf ("\nla localidad del dueno : ");
			_flushall(); 
			puts(pet.localidad);
			printf ("\nIngrese la evolucion de la mascota : ");
			gets(pet.informeMascota);
			fwrite(&pet,sizeof(Datos_pet),1,archMascota); // Guarda desde donde quedo el puntero anterior.	
			printf ("%s", reg.names);
			fwrite(&reg,sizeof(auth),1,arch_admin);
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
	while(!feof(ArchTurno) and reg.borradoTurno==false)
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
    

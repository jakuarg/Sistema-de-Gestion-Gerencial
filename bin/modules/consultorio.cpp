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


int menuprincipal(int &pn);
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
	FILE *Arch = fopen("bin/modules/Usuarios.dat","r+b");

	fseek(Arch,sizeof(auth),1);
	fread(&reg,sizeof(auth),1,Arch);
	
	printf ("Ingrese la matricula del veterinario : ");
	scanf ("%d", &matricula);
	for (int i = 0;i<=reg.veterinario;i++)
	{
		if (reg.matricula == matricula){
			aux = 1;
			pn = matricula;
		}
		fread(&reg,sizeof(auth),1,Arch);
	}
	printf ("\nMATRICULA = %d y REG.MATRICULA = %d  AUX = %d PN = %d\n",matricula,reg.matricula,aux,pn);

	if (aux == 1)
	{
	do{
		opc = menuprincipal(pn);
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
		else
	{
		printf ("La matricula ingresada no es valida...");
	}
	fclose(Arch);	
}


int menuprincipal(int &pn)
{
	FILE *arch = fopen("bin/modules/Usuarios.dat","r+b");
	auth reg;
	rewind(arch);
	fread(&reg,sizeof(auth),1,arch);	
	int aux;
	do{
		if (reg.matricula == pn){
			aux = 1;
		}
		else{fread(&reg,sizeof(auth),1,arch);}
	}while(!feof(arch) and aux == 0);
	fseek(arch,sizeof(auth),SEEK_CUR);
	printf ("\n%d y matricula = %d aux = %d ",pn,reg.matricula,aux);
	system("PAUSE");
	if (aux == 1)
	{
		system("CLS");
		int op;
		system("CLS");
		printf("\n\t\t\t    =============================================     ");
		printf("\n\t\t\t          Modulo %d Consultorio Veterinario           ", reg.modulo);
		printf("\n\t\t\t  	==============================================    ");
		printf("\n  				    Veterinario a cargo : %s              ", reg.names);
		printf("\n\t\t\t    1.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n\t\t\t	2.- Registrar Evolucion de la Mascota             ");
		printf("\n\t\t\t    3.- Cerrar la aplicacion.                         ");
		printf("\n\t\t\t =======================================");
		printf("\n\t\t\t\t 	 Ingrese una opcion: 	"); 
		fread(&reg,sizeof(auth),1,arch);
		scanf("%d", &op);
		return op;
	}	
	fclose(arch);
}


void evolucionMascota(FILE *archMascota,int &pn)
{
	Datos_pet pet;
	Turno reg1;
	int edadDuenio;
	
	FILE *arch = fopen("bin/modules/Usuarios.dat","r+b");
	auth reg;
	rewind(arch);
	fread(&reg,sizeof(auth),1,arch);	
	int aux;
	do{
		if (reg.matricula == pn){
			aux = 1;
		}
		else{fread(&reg,sizeof(auth),1,arch);}
	}while(!feof(arch) and aux == 0);
	
	fseek(arch,sizeof(auth),SEEK_CUR);
	
	printf ("\n%d y matricula = %d aux = %d ",pn,reg.matricula,aux);
	
	system("PAUSE");
	
	
 	if (aux == 1){
	printf("\n  				    Veterinario a cargo : %s              ", reg.names);
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
			reg.atenciones++;
			fwrite(&reg,sizeof(auth),1,arch);
			fwrite(&pet,sizeof(Datos_pet),1,archMascota); // Guarda desde donde quedo el puntero anterior.		
		}
		fread(&pet,sizeof(Datos_pet),1,archMascota);
	}
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
    

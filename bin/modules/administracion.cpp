 /*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo N 					   **
  *   Veterinaria					*
  ***********************************
  **********ADMINISTRACION***********
  ***********************************
*/
//DECLARACIONES DE LIBRERIAS
#include<stdio.h>//Funciones de entrada
#include<stdlib.h>//Funciones system
//#include <wchar.h>
#include <locale.h>// Añade paquete de idiomas
//PARA HABILITAR FUNCIONES DE TEXTO
#include <ctype.h>
#include <string.h>
//PARA HABILITAR FUNCIONES ESPECIALES DE MANIPULACION DE VENTANA,ETC
#include <windows.h>
//HABILITA LA LIBRERIA PROPIA
#include "functions/admin.h"

//Funciones

int Atenciones(int mes);
void Ranking();

main()
{
	// Establecer el idioma a español
    setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
	
	//ALTA
	arch_admin=fopen("bin/modules/Usuarios.dat","r+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
		system("PAUSE");
		exit(1);
	}
	//TERMINAR ALTA

	system("CLS");
	//SECCION DE DECLARACIONES 
	int error,op_1,seguir=1,smes;
	//
	error=1;
	do
	{
		system("CLS");
		error=1;
		while(error==1)
		{
			system("CLS");
			printf("Modulo Administracion");
			printf("\n=======================");
			printf("\n1.- Registrar Veterinario");
		 	printf("\n2.- Registrar Asistente");
		 	printf("\n3.- Atenciones por Veterinarios");
		 	printf("\n4.- Ranking de Veterinarios por Atenciones");
		 	printf("\n\n5.- Volver al menu principal");
		 	printf("\n6.- Cerrar la aplicacion.");
		 	printf("\n\nIngrese una opcion: ");
		 	scanf("%d",&op_1);
		 	
		 	//Validacion de entrada
		 	if(op_1<1 && op_1>5)
		 	{
		 		printf("\nIngrese una opcion correcta\n");
		 		system("PAUSE");
		 		system("CLS");
		 	}else error=0;
		
		}
		switch(op_1)
		{
			case 1://Registrar Veterinario
				
				do
				{
					//system("PAUSE");
					system("CLS");
					printf("Registro Veterinario");
					printf("\n=======================\n");
				}while(SignUp(2)==0);
				break;
			case 2:
				do
				{
					//system("PAUSE");
					system("CLS");
					printf("Registro Asistente");
					printf("\n=======================\n");
				}while(SignUp(3)==0);
				break;
			case 3:
				printf("Ingrese el mes que desea buscar:");
				scanf("%d",&smes);
				Atenciones(smes);
				break;
			case 4:{
				printf("\nRanking:");
				_flushall();
				Ranking();
				system("PAUSE");	
				break;
			}
			case 5:
				seguir=0;
				break;
			case 6:
				printf("Saliendo...");
				exit(1);
				break;
			default: break;
		}
	}while(seguir==1);
	fclose(arch_admin);
}

int Atenciones(int mes)// Listar Atenciones por Veterinarios
{
    arch_admin=fopen("bin/modules/Usuarios.dat","rb");
    FILE *arch_turno=fopen("bin/modules/Turnos.dat","rb");
	if(arch_turno==NULL)
	{
		printf("\nNo hay turnos registrados.");
		exit(1);
	}
	Turno reg;
	auth reg1;
	
	int c=0,c2=0;
	
    printf("\nLISTADO DE ATENCION DEL MES %d",mes);
    printf("\n===================");
    
    rewind(arch_admin);
    rewind(arch_turno);
    fread(&reg, sizeof(Turno), 1,arch_turno);
	fread(&reg1,sizeof(auth),1,arch_admin);
	
    while(!feof(arch_admin))
	{
        c=0;
		while(!feof(arch_turno) && reg.borradoTurno==false)
        {
        	if(reg.fec.mes==mes && strcmp(reg1.names,reg.veterinario)==0 && reg.borradoTurno!=0 && reg1.modulo==2)
			{
			 	c++;
			}
		}
		printf("%s: %d",reg1.veterinario,c);
		
		fread(&reg1,sizeof(auth) , 1,arch_admin);
        fread(&reg ,sizeof(Turno), 1,arch_turno);
    } 
    fclose(arch_turno);
    fclose(arch_admin);
    printf("\n");
    system("pause");
}

void Ranking()//Ranking por veterinario 
{
	FILE*Arch = fopen("bin/modules/Turnos.dat", "r+b"); 
	FILE*Arch2 = fopen("bin/modules/Usuarios.dat","r+b");
	FILE *arch = fopen("bin/modules/ranking.dat", "r+b");
	if (arch == NULL)
	{
		fclose(arch);
		arch = fopen("ranking.dat","w+b");
	}
	
	auth reg; // registro.
	Turno reg1; // turno
	ranking guardar;
	rewind (Arch);
	rewind (Arch2);
	fread (&reg,sizeof(auth),1,Arch2);
	fread (&reg1,sizeof(Turno),1,Arch);
	printf ("%d y %d",feof(Arch),feof(Arch2));	
	int salir = 1,aux;
	do
	{
		printf ("matricula vet : %d, matricula : %d", reg1.matricula_de_veterinario,reg.matricula);
		if (reg1.matricula_de_veterinario == reg.matricula)
		{
			rewind(Arch);
			while(!feof(Arch))
			{
			if (reg1.borradoTurno == true)
				{
					strcpy(guardar.nom,reg1.veterinario);
					aux = guardar.atencion + 1;
					guardar.atencion = aux;
					fwrite(&guardar,sizeof(ranking),1,arch);
				}
				else
				{
					fread(&reg1,sizeof(Turno),1,Arch);			
				}			
			}

		}
		else
		{
			fread (&reg,sizeof(auth),1,Arch2);
			fread (&reg1,sizeof(Turno),1,Arch);			
		}
		if (feof(Arch)==0 and feof(Arch2)==0)
		{
			salir = 0;
		}
		
	}while (salir == 1);
	system("PAUSE");
	printf ("SALIII!!!! %d ", salir);
	system("PAUSE");
}

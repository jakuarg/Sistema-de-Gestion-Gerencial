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
int Atenciones();
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
		printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
		system("PAUSE");
		exit(1);
	}
	//TERMINAR ALTA

	system("CLS");
	//SECCION DE DECLARACIONES 
	int error,op_1;
	//
	error=1;
	while(error==1)
	{
		printf("Modulo Administracion");
		printf("\n=======================");
		printf("\n1.- Registrar Veterinario");
	 	printf("\n2.- Registrar Asistente");
	 	printf("\n3.- Atenciones por Veterinarios");
	 	printf("\n4.- Ranking de Veterinarios por Atenciones");
	 	printf("\n\n5.- Cerrar la aplicacion.");
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
				system("CLS");
				printf("Registro Veterinario");
				printf("\n=======================\n");
			}while(SignUp(2)==0);
			break;
		case 2:
			do
			{
				system("CLS");
				printf("Registro Asistente");
				printf("\n=======================\n");
			}while(SignUp(3)==0);
			break;
	}
	fclose(arch_admin);
}

int Atenciones()
{
	FILE*arch=fopen(&);
	
	int c;
	rewind(arch_admin);
	fread()
	while(!feof())
	{
		c++;
	}
	return c;
}
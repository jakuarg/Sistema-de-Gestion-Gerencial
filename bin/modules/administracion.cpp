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

#include "functions\valuser.h"

//DEFINICIONES DE LA LONGITUD DEL USUARIO Y CONTRASENIA

typedef char ownerlen[60]; //Longitud de 60



struct fecha//ESTRUCTURA DE FECHA
{
	int dia;
	int mes;
	int anio;
};

struct cliente//ESTRUCTURA DEL CLIENTE
{
	ownerlen	ApeyNomb;
	ownerlen	Domicilio;
	int			DNI;
	ownerlen	Localidad;
	fecha		fechadenac;
	float		peso;
	char		telefono[25];
};

//FUNCIONES de validacion
int val_user(userlen usuario, passlen contrasenia, int matricula);
//FUNCIONES de registro
void Reg_Veterinario(FILE*arch_admin);
void Reg_UsuarioAsist();

main()
{
	// Establecer el idioma a español
    setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

	//ALTA
	FILE*arch_admin;
	arch_admin=fopen("Usuarios.dat","a+b");
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
	 	printf("\n2.- Registrar Usuario Asistente");
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
		case 1:
			Reg_Veterinario(arch_admin);
			break;
		case 2:
			//Reg_UsuarioAsist();
			break;
	}
	fclose(arch_admin);
}

void Reg_Veterinario(FILE*arch_admin)
{
	system("CLS");
	//Llamada al registro
	auth rv;
	//Declaracion de Variables
	int error,error_2;
	int op_2;
	//Inicio interfaz de ingresado
	printf("Registrar Veterinario");
	printf("\n=======================\n");
	error=1;
	while(error==1)
	{
		_flushall();
		printf("Usuario:    "); 
		gets(rv.user);
		printf("\nContraseña: ");
		gets(rv.password);
		printf("\nApellido y Nombre: ");
		gets(rv.ApeyNomb);
		printf("\nIngrese Matricula:");
		scanf("%d",&rv.matricula);
		error_2=1;
		while(error_2==1)
		{
			printf("\nIngrese Modulo al que pertenece:");
			printf("\n 1-.Administrador");
			printf("\n 2-.Veterinario");
			printf("\n 3-.Asistente\n");
			scanf("%d",&rv.mod);

			if(rv.mod>=1 && rv.mod<=3)
			{
				error_2=0;
			}
			else 
			{
				error_2=1;
				printf("\nIngrese un modulo correcto.\n");
			}
		}
		

		if(val_user(rv.user,rv.password,rv.matricula,arch_admin,rv.mod)==0)
		{
			system("CLS");
			printf("Ingreso fallido. Nombre o Contraseña no valido.\n");
			system("PAUSE");
		}
		else
		{
			
			error=0;
			system("CLS");
			printf("\nEl usuario y contraseña se han ingresado correctamente.\n\n");
			fwrite(&rv.user     , sizeof(userlen),1, arch_admin);
			fwrite(&rv.password , sizeof(userlen),1, arch_admin);
			fwrite(&rv.matricula, sizeof(int)    ,1, arch_admin);
			fwrite(&rv.mod      , sizeof(int)    ,1, arch_admin);
			system("PAUSE");
		}

		error_2=1;
		while(error_2==1)
		{
			system("CLS");
			printf("\nDesea Registrar otro veterinario? (1 para si y 0 para no):\n");
			scanf("%d",&op_2);
			if(op_2==1 || op_2==0)
			{
				error_2=0;
				if(op_2==1)
				{
					error=1;
					system("CLS");
				}
				else
				{
					error=0;
					system("CLS");
				}
			}else printf("\nIngrese una decision correcta.");system("PAUSE");
		}
	}
}

/*void Reg_UsuarioAsist()
{
	;
	/*system("CLS");
	//Llamada al registro
	auth rv;
	//Declaracion de Variables
	int error;
	int op_2;
	//Inicio interfaz de ingresado
	printf("Registrar Veterinario");
	printf("\n=======================\n");
	error=1;
	while(error==1)
	{
		_flushall();
		printf("Usuario:    "); 
		gets(rv.user);
		printf("\nContraseña: ");
		gets(rv.password);
		printf("Ingrese Matricula:");
		scanf("%d",&rv.matricula);
		if(val_user(rv.user,rv.password,rv.matricula)==0)
		{
			printf("Ingreso fallido. Nombre o Contraseña no valido.\n");
		}
		else
		{
			
			error=0;
			system("CLS");
			printf("\nEl usuario y contraseña se han ingresado correctamente.");
			system("PAUSE");
		}

		error=1;
		while(error==1)
		{
			system("CLS");
			printf("\nDesea Registrar otro veterinario? (1 para si y 0 para no)");
			scanf("%d",&op_2);
			if(val_in(op_2,0,1)==1)
			{
				error=0;
			}else printf("\nIngrese una decision correcta.");system("PAUSE");
		}
	}
}*/

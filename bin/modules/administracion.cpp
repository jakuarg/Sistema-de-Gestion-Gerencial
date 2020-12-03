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
//void Ranking();

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
	int error,op_1,seguir=1;
	//
	error=1;
	do
	{
		error=1;
		while(error==1)
		{
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
				printf("\nAntencion por el veterinario es :%d",Atenciones());
				break;
			case 4:
				printf("\nRanking:");
				break;
			case 5:
				seguir=0;
				break;
			case 6:
				printf("Saliendo...");
				exit(1);
				break;
			default: break;
		}
	}while(1);
	fclose(arch_admin);
}
/*
int Atenciones()// Listar Atenciones por Veterinarios
{
    auth reg1;
	Turno reg;
	int bandera;

	FILE*arch = fopen("bin/modules/Mascotas.dat", "r+b");
	int c=0,search_mat=0;
	printf("Ingrese la matricula del medico: ");
	scanf("%d",&search_mat);
	bandera=0;
	
	rewind(arch_admin);
	fread(&reg1,sizeof(auth),1,arch);
	
	while(!feof(arch))
	{
		if(search_mat==reg1.matricula && reg1.modulo == 2){

			bandera=1;
            break;
		}else{
			bandera=0;
			fclose(arch);
		}
		fread(&reg1,sizeof(auth),1,arch);
	}

	rewind(arch);
	fread(&reg,sizeof(Turno),1,arch);

	if (bandera=1){


        while(!feof(arch)){
                
             if(reg.fec.dia !=NULL && reg.fec.mes != NULL && reg.fec.anio != NULL){
				 reg.atenciones++;
			 }
            fread(&reg,sizeof(Turno),1,arch);
		}

        return reg.atenciones;
	}
	else{
			printf("NO hay turnos");
	}
	
}
*/
/*
void Ranking(){ //Ranking por veterinario 

FILE*Arch = fopen("bin/modules/Mascotas.dat", "r+b");  



}*/

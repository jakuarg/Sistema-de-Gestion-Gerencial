 /*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo 2 					   **
  *   Veterinaria					*
  ***********************************
  **********ADMINISTRACION***********
  ***********************************
*/
//DECLARACIONES DE LIBRERIAS
#include<stdio.h>//Funciones de entrada
#include<stdlib.h>//Funciones system
//#include <wchar.h>
#include <locale.h>// AÃ±ade paquete de idiomas
//PARA HABILITAR FUNCIONES DE TEXTO
#include <ctype.h>
#include <string.h>
//PARA HABILITAR FUNCIONES ESPECIALES DE MANIPULACION DE VENTANA,ETC
#include <windows.h>
//HABILITA LA LIBRERIA PROPIA
#include "functions/admin.h"

//Funciones
void Atenciones(int mes);// Listar Atenciones por Veterinarios
void Ranking2();

void Ranking(FILE *Arch,FILE *Arch2,FILE *arch);

main()
{
	color(245);
	AltEnter();
	Spanish();
	
	//ALTA
	arch_admin=fopen("bin/modules/Usuarios.dat","r+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\t\t\t\t\t\t\tSE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
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
			printf("\n\t\t\t\t\t\t\t   ===================================================    ");
			printf("\n\t\t\t\t\t\t\t                    Módulo Administración");
			printf("\n\t\t\t\t\t\t\t   ===================================================    ");
			printf("\n\t\t\t\t\t\t\t   1.- Registrar Veterinario");
		 	printf("\n\t\t\t\t\t\t\t   2.- Registrar Asistente");
		 	printf("\n\t\t\t\t\t\t\t   3.- Atenciones por Veterinarios");
		 	printf("\n\t\t\t\t\t\t\t   4.- Ranking de Veterinarios por Atenciones");
		 	printf("\n\t\t\t\t\t\t\t   5.- Cerrar");
		 	printf("\n\t\t\t\t\t\t\t   ===================================================    ");
		 	printf("\n\t\t\t\t\t\t\t   Ingrese una opción: ");
		 	scanf("%d",&op_1);
		 	
		 	//Validacion de entrada
		 	if(op_1<1 && op_1>5)
		 	{
		 		printf("\n\t\t\t\t\t\t\tIngrese una opción correcta\n");
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
					printf("\n\t\t\t\t\t\t\t=======================\n");
					printf("\n\t\t\t\t\t\t\tRegistro Veterinario");
					printf("\n\t\t\t\t\t\t\t=======================\n");
				}while(SignUp(2)==0);
				break;
			case 2:
				do
				{
					//system("PAUSE");
					system("CLS");
					printf("\n\t\t\t\t\t\t\t=======================\n");
					printf("\n\t\t\t\t\t\t\tRegistro Asistente");
					printf("\n\t\t\t\t\t\t\t=======================\n");
				}while(SignUp(3)==0);
				break;
			case 3:
				printf("\n\t\t\t\t\t\t\tIngrese el mes que desea buscar:");
				scanf("%d",&smes);
				Atenciones(smes);
				system("PAUSE");
				break;
			case 4:
				Ranking2();
				break;
			case 5:
				fclose(arch_admin);
				seguir=0;
				break;
			default: break;
		}
	}while(seguir==1);
	fclose(arch_admin);
}

void Atenciones(int mes)// Listar Atenciones por Veterinarios
{
    //Listado Final
    
	FILE *arch_turno;
	arch_admin=fopen("bin/modules/Usuarios.dat","rb");
	if(arch_admin==NULL)
	{
		printf("No hay usuarios registrados");
		fclose(arch_turno);
		fclose(arch_admin);
		exit(1);
	}
	else
	{
		arch_turno=fopen("bin/modules/Turno.dat","rb");
		if(arch_turno==NULL)
		{
			printf("No hay turnos registrados");
			fclose(arch_turno);
			fclose(arch_admin);
			exit(1);
		}
	}

	Turno regtur;
	auth  regus;
	int c=0,c2=0;
	system("CLS");
	printf("\n\t\t\t\t\t\t\tLISTADO DE ATENCIÓN DEL MES %d",mes);
	printf("\n\t\t\t\t\t\t\t===============================");

	rewind(arch_admin);
	rewind(arch_turno);
	fread(&regtur, sizeof(Turno), 1,arch_turno);
	fread(&regus,sizeof(auth),1,arch_admin);

	while(!feof(arch_admin))
	{
		c=0;
		if (regus.modulo == 2)
		{
			rewind(arch_turno);
			fread(&regtur,sizeof(Turno), 1,arch_turno);	
			while(!feof(arch_turno))
	        {
				if(regtur.fec.mes==mes && regtur.borradoTurno==1 && strcmp(regus.names,regtur.veterinario)==0)
				{
					c++;
				}
				fread(&regtur ,sizeof(Turno), 1,arch_turno);
			}
			printf("\n\t\t\t\t\t\t\t%s: %d\n",regus.names,c);
		}
		fread(&regus,sizeof(auth) , 1,arch_admin);
    }
    fclose(arch_turno);
    fclose(arch_admin);
    printf("\n");

}

void Ranking2()
{
	system("CLS");
	/*------------Seccion de Declaracion------------*/
	////////// Registros //////////
	
	Turno reg_turno,reg_v[100],reg_aux;
	
	////////// Variables//////////
	
	int i=0,n=0,b=0;
	
	////////// Archivos//////////
	
	FILE *arch_turno;
	arch_turno=fopen("bin/modules/Turno.dat","a+b");
	if(arch_turno==NULL)
	{
		printf("\n\t\t\t\t\t\t\tNo hay turnos.");
		exit(1);
	}
	
	/*------------Seccion Funcional------------*/
	
	////////// 1.Pasar el registro a un vector //////////
	
	rewind(arch_turno);
	fread(&reg_turno, sizeof(Turno),1,arch_turno);
	i=0;
	while(!feof(arch_turno))
	{
		reg_v[i]=reg_turno;
		i++;
		fread(&reg_turno, sizeof(Turno),1,arch_turno);
	}
	n=i;
	////////// 2.Ordena los registros del vector //////////
	do
	{
		b=0;
		for(i=0;i<n-1;i++)
		{
			if(reg_v[i].atenciones<reg_v[i+1].atenciones)
			{
				reg_aux=reg_v[i];
				reg_v[i]=reg_v[i+1];
				reg_v[i+1]=reg_aux;
				b=1;
			}
		}
	}while(b==1);
	fclose(arch_turno);
	////////// 3. Imprimir //////////
    
    printf("\n\t\t\t\t\t\t\t|ATENCIONES| NOMBRES\n");
	i=0;
	do
    {
		
		printf("\n\t\t\t\t\t\t\t|    %d    | %s",reg_v[i].atenciones,reg_v[i].veterinario);
		i++;
	}while(i<n);
	printf("\n\t\t\t\t\t\t\t");
    system("PAUSE");
	
}


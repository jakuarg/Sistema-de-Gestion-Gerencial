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
int Atenciones(int mes)// Listar Atenciones por Veterinarios
{
    printf("\n/ENTRO/\n");
	arch_admin=fopen("bin/modules/Usuarios.dat","rb");
	printf("\n/ENTRO2/\n");
    FILE *arch_turno=fopen("bin/modules/Turnos.dat","rb");
    printf("\n/ENTRO3/\n");
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

void Ranking(FILE *Arch,FILE *Arch2,FILE *arch);

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
				system("PAUSE");
				break;
			case 4:{
				fclose(arch_admin);
				fclose(archaux1);
				FILE *Arch = fopen("bin/modules/Turno.dat", "r+b"); 		
				FILE *Arch2 = fopen("bin/modules/Usuarios.dat","r+b");
				FILE *arch = fopen("bin/modules/ranking.dat", "r+b");
				if (arch == NULL)
				{
					fclose(arch);
					arch = fopen("bin/modules/ranking.dat","w+b");
				}else
				if (Arch == NULL)
				{
					fclose(Arch);
					FILE *Arch = fopen("bin/modules/Turno.dat", "rb"); 		
					printf ("El archivo Arch osea turno no se abrio ");
				}else if (Arch2 == NULL){
					printf ("El archivo Arch2 no se abrio ");
				}else if (arch == NULL){
					printf ("El archivo arch no se abrio ");
				}
				if (arch != NULL and Arch2 != NULL and Arch != NULL)
				{
					printf ("Se ejecuto !! ");
					printf("\nRanking:");
					Ranking(Arch,Arch2,arch);
					system("PAUSE");	
					break;
				}
				else
				{
					printf ("No se ejecuto !");
					system("PAUSE");
					break;
				}	
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

void Ranking(FILE *Arch, FILE *arch, FILE *Arch2)//Ranking por veterinario 
{
	
	int salir = 1,aux,contador,num=0;
	auth reg; // registro.
	Turno reg1; // turno
	ranking guardar;
	rewind (Arch);
	rewind (Arch2);
	fread (&reg,sizeof(auth),1,Arch2);
	fread (&reg1,sizeof(Turno),1,Arch);	
	while (!feof(Arch2)){
		if (reg1.matricula_de_veterinario == reg.matricula)
		{
			rewind(Arch);
			fread(&reg1,sizeof(Turno),1,Arch);		
			while(!feof(Arch))
			{
			if (reg1.borradoTurno == true)
				{
					do{
						num++;
						strcpy(guardar.nom,reg1.veterinario);
						aux = guardar.atencion + 1;
						guardar.atencion = aux;
						fwrite(&guardar,sizeof(ranking),1,arch);
						if (!feof(Arch)){
							salir = 0;
						}
					}while(num!=reg1.atenciones or salir == 1);
					break;
				}
				else
				{
					fread(&reg1,sizeof(Turno),1,Arch);			
				}			
			}

		}	
		fread(&reg,sizeof(auth),1,Arch2);
		fread (&reg1,sizeof(Turno),1,Arch);	
	}
	
	int b,i=0,n;
	ranking v[99],regaux;
	
	fclose(arch);
	arch=fopen("ranking.dat","rb");
	rewind (arch);
	
	//1. Pasa los registros a un array
	
	fread(&guardar,sizeof(ranking),1,arch);	
	while(feof(arch)==0)
	{
		v[i]=guardar;
		i++;
		fread(&guardar,sizeof(ranking),1,arch);	
	}
	n=i;
	
	//2.Ordena los registros del array
	do
	{
		b=0;
		for (i=0;i<n-1;i++)
		{
			if (v[i].atencion>v[i+1].atencion)
			{
				regaux=v[i];
				v[i]=v[i+1];
				v[i+1]=regaux;
				b=1;
			}
		}
	}while (b==1);
	fclose(arch);
	
	//3. Pasa los registros del array al archivo//
	arch=fopen("ranking.dat","rb");
	
	for (i=0;i<n;i++)
	{
		guardar=v[i];
		fread(&guardar,sizeof(ranking),1,arch);	
	}
	fclose(arch);
	
	system("CLS");
	
	//4. Muestra el ranking ordenado
	printf("\n\nArch Ordenado\n\n");
	arch=fopen("ranking.dat","rb");
	fread(&guardar,sizeof(ranking),1,arch);	
	printf("|ATENCIONES| NOMBRES");
	while(!feof(arch))
	{
		printf("|    %d    | %s",guardar.atencion);
		printf("Apellido y Nombre: %s\n",guardar.nom);
		fread(&guardar,sizeof(ranking),1,arch);	
	}
	fclose(arch);
}

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
#include<stdio.h>
#include<stdlib.h>
//PARA HABILITAR EL USO DE CARACTERES ESPECIALES
#include <wchar.h>
#include <locale.h>

#include <windows.h>

//DEFINICIONES DE LA LONGITUD DEL USUARIO Y CONTRASENIA
typedef char userlen[12];//Longitud del n. usuario(10)
typedef char passlen[34];//Longitud de la contrasenia(32)

//ESTRUCTURAS
struct auth //ESTRUCTURA DEL USUARIO
{
	userlen	user;
	passlen password;
	
};

//FUNCIONES
int val_user(userlen usuario,passlen contrasenia,int usorpass);//int usorpass es la bandera para ver si se manda un usuario o una contrasenia
int val_in(int entrada,int lim_min, int lim_max);
main()
{
	setlocale(LC_ALL, "SPANISH");
	system("CLS");
	
	//ALTA
	FILE*archauth;
	archauth=fopen("usuarios.dat","w+b");
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
	 	printf("\n\nIngrese una opcion: _");
	 	scanf("%d",&op_1);
	 	
	 	//Validacion de entrada
	 	if(val_in(op_1,1,5)==0)
	 	{
	 		printf("\nIngrese una opcion correcta");
	 		system("PAUSE");
	 		system("CLS");
	 	}else printf("\nSe iniciara la opcion.");error=0;
	}
	switch(op_1)
	{
		case 1:
			break;//Reg_Vet();
	}
	fclose(archauth);
}

int val_user(userlen usuario,passlen contrasenia,int usorpass)
{
	switch(usorpass)
	{
		case 1://usuario
			break;
		case 2://contrasenia
			 break; 
	}
}
int val_in(int entrada,int lim_min, int lim_max)
{
	if(lim_max>lim_min)
	{
		if(entrada >= lim_min && entrada <= lim_max)
		{
			return 1;
		}else return 0;
	}else printf("\nEl limite minimo no puede ser mayor al maximo.");
	
}

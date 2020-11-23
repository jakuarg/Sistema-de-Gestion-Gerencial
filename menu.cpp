#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"bin/modules/functions/login.h"


main()
{
	//Llamada al registro
	auth rv;
	//Declaracion de Variables
	int error,error_2;
	int op_2,op_3;
	int correct;
	printf("Bienvenido al software de la veterinaria\n");
	printf("========================================\n");
	FILE*arch_admin;
	arch_admin=fopen("bin\\modules\\Usuarios.dat","rb");
	
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("ES LA PRIMERA SESION, POR LO TANTO SE CREARA EL PRIMER USUARIO ADMIN\n");
		system("PAUSE");
		system("CLS");
		arch_admin=fopen("bin\\modules\\Usuarios.dat","a+b");
		if(arch_admin==NULL)
		{
			system("CLS");
			printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
			system("PAUSE");
			exit(1);
		}
		
		/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
		
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
			printf("Ingrese Matricula:");
			scanf("%d",&rv.matricula);
			rv.mod=1;
			if(val_user(rv.user,rv.password,rv.matricula,arch_admin,rv.mod)==0)
			{
				printf("Ingreso fallido. Nombre o Contraseña no valido.\n");
				correct=0;
			}
			else
			{
				fwrite(&rv.user     , sizeof(userlen),1, arch_admin);
				fwrite(&rv.password , sizeof(userlen),1, arch_admin);
				fwrite(&rv.matricula, sizeof(int)    ,1, arch_admin);
				fwrite(&rv.mod      , sizeof(int)    ,1, arch_admin);
				error=0;
				system("CLS");
				printf("\nEl usuario y contraseña se han ingresado correctamente.");
				system("PAUSE");
				correct=1;
			}
		}
	}
	
	//LOGIN
	error=1;
	
	while(error=1)
	{
		_flushall();
		printf("Usuario:"); 
		gets(rv.user);
		printf("\nContrasenia:");
		gets(rv.password);
		printf("%s",rv.user);
		printf("%s",rv.password);
		if( login(rv.user,rv.password,arch_admin)==1 )
		{
			system("CLS");
			printf("\nLogin Suscess");
			correct=1;
			error=0;
		}
		else 
		{
			printf("\nLogin Failed\n");
			correct=0;
			system("PAUSE");
			exit(1);
		}
	}
	fclose(arch_admin);
	

	if(correct==1)
	{
		op_3=searchmodule(rv.user,rv.password,arch_admin);
		switch(op_3)
		{
			case 1:
				system("bin\\module\\administracion.exe");
				break;
			case 2:
				system("bin\\module\\consultorio.exe");
				break;
			case 3:
				system("bin\\module\\recepcion.exe");
				break;
		};
	}
}

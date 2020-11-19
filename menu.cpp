#include<stdio.h>
#include<stdlib.h>
//#include"bin/modules/functions/valuser.h"
#include"bin/modules/functions/login.h"


main()
{
	//Llamada al registro
	auth rv;
	//Declaracion de Variables
	int error,error_2;
	int op_2;
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
			if(val_user(rv.user,rv.password,rv.matricula,arch_admin)==0)
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

			error_2=1;
			while(error_2==1)
			{
				system("CLS");
				printf("\nDesea Registrar otro veterinario? (1 para si y 0 para no)");
				scanf("%d",&op_2);
				if(op_2==1)
				{
					error_2=0;
				}
				else 
				{
					if(op_2==0)
					{
						error_2=0;
						error=0;
					}
					else error_2=1;printf("\n\nINGRESE UNA OPCION CORRECTA");
				}
				
			}
			error=1;
		}
	}
	
	//LOGIN
	error=1;
	
	while(error=1)
	{
		_flushall();
		printf("Usuario:    "); 
		gets(rv.user);
		printf("\nContrase�a: ");
		gets(rv.password);
		if(login(rv.user,rv.password,arch_admin)==1)
		{
			system("CLS");
			printf("\nLogin Suscess");
			error=0;
		}
		else 
		{
			printf("\nLogin Failed\n");
			system("PAUSE");
			system("CLS");
		}
	}
	fclose(arch_admin);

}

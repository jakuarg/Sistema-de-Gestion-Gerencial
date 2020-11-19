#include<stdio.h>
#include<stdlib.h>
#include"bin/functions/valuser.h"


main()
{
	printf("Bienvenido al software de la veterinaria\n");
	printf("========================================\n");
	FILE*arch_admin;
	arch_admin=fopen("bin\\modules\\Usuarios.dat","rb");
	if(arch_admin==NULL)
	{
		//fclose()
		printf("\n\n\nES LA PRIMERA SESION, POR LO TANTO SE CREARA EL PRIMER USUARIO ADMIN\n");
		arch_admin=fopen("bin\\modules\\Usuarios.dat","a+b");
		if(arch_admin==NULL)
		{
			system("CLS");
			printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
			system("PAUSE");
			exit(1);
		}
		
		/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
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
			printf("\nApellido y Nombre: ");
			gets(rv.ApeyNomb);
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
					printf ("Eligio 1");
					error=0;
				}else printf("\nIngrese una decision correcta.");system("PAUSE");
			}
			error=1;
		}
	}
	
	//ALTA
	/*FILE*arch_admin;//Archivo donde se guardan el usuario y la constrasenia
	arch_admin=fopen("bin\\modules\\Usuarios.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
		system("PAUSE");
		exit(1);
	}
	//FIN DE ALTA*/

}

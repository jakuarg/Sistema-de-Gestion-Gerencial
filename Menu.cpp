/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo 2				       **
  *   Veterinaria					*
  ***********************************
  **********MENU*********************
  ***********************************
*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"bin/modules/functions/admin.h"//Login,SignUp

main()
{
	color(240);
	AltEnter();
	Spanish();
	int m,error=0;//Guarda el modulo proveniente del login
	char op='n';
	
	do
	{
		system("CLS");
	    
		arch_admin=fopen("bin/modules/Usuarios.dat","r+b");//Se abre en modo lectura para verificar si ya existe el archivo //    bin\\modules
		
		printf("\t\t\t\t\t\t\t   ===================================================    ");
		printf("\n\t\t\t\t\t\t\t               Bienvenido al menu principal.");
	    printf("\n\t\t\t\t\t\t\t   ===================================================    \n");
		if(arch_admin==NULL)//Si no existe el archivo...
		{
			fclose(arch_admin);//...Lo cierra...
			system("CLS");
			printf("ES LA PRIMERA SESI�N, POR LO TANTO SE CREARA EL PRIMER Y �NICO ADMINISTRADOR\n");
			system("PAUSE");
			system("CLS");
			/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
	        do
			{
				printf("Primer Registro");
				printf("\n=======================\n");
			}while(SignUp(1)==0);
			
	        m=1;
	        
	        system("CLS");
	        
			printf("\nPor ser primera sesi�n, se ejecutar� el modulo de administraci�n para poder ingresar nuevos usuarios.\n");
	        
			system("PAUSE");
	        system("CLS");
			fclose(arch_admin);//...Lo cierra
	    }
		else//Si existe el archivo...
		{
			archaux1=fopen("bin/modules/Auxiliar.dat","w+b");
			if (archaux1 != NULL)
			{
				m=LogIn(arch_admin,archaux1);//Se ejecuta el login
			    fclose(arch_admin);
				fclose(archaux1);
			}
		}
		
		switch(m)
	    {
	    	case 1:
				printf("\nEjecutando Modulo de Administraci�n...\n");
				system("start bin/modules/administracion.exe");
				
				break;
	    	case 2:
	    		
	    		printf("\nEjecutando Modulo de Consultorio...\n");
				system("start bin/modules/consultorio.exe");
				
	    		break;
			case 3:
				printf("\nEjecutando Modulo de Asistente...\n");
				system("start bin/modules/recepcion.exe");
				
				break;
			default: break;	
		};
		
		error=1;
		do
		{
			printf("Desea salir? (s/n): ");
			scanf("%c",&op);
			if(op=='s' or op=='S' or op=='n' or op=='N')
			{
				error=0;
			}else printf("\nIngrese un valor correcto.\n");
		}while(error==1);
		
	}while(op=='n' or op=='N');
}

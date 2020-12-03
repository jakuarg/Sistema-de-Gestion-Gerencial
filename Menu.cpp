/*Menu Principal*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"bin/modules/functions/admin.h"//Login,SignUp

main()
{
		system("CLS");
	    int m;//Guarda el modulo proveniente del login
		arch_admin=fopen("bin/modules/Usuarios.dat","r+b");//Se abre en modo lectura para verificar si ya existe el archivo //    bin\\modules
		printf("Bienvenido al menu principal.\n");
	    printf("=============================\n");
		if(arch_admin==NULL)//Si no existe el archivo...
		{
			fclose(arch_admin);//...Lo cierra...
			system("CLS");
			printf("ES LA PRIMERA SESION, POR LO TANTO SE CREARA EL PRIMER Y UNICO ADMINISTRADOR\n");
			getch();
			system("CLS");
			/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
	        do
			{
				printf("Primer Registro");
				printf("\n=======================\n");
			}while(SignUp(1)==0);
	        m=1;
	        
	        system("CLS");
	        
			printf("\nPor ser primera sesion, se ejecutara el modulo de administracion para poder ingresar nuevos usuarios.");
	        
			getch();
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
				printf("\nEjecutando Modulo de Administracion...\n");
				system("start bin/modules/administracion.exe");		
				break;
	    	case 2:
	    		
	    		printf("\nEjecutando Modulo de Consultorio\n");
				 system("start bin/modules/consultorio.exe");
	    		break;
			case 3:
				printf("\nEjecutando Modulo de Asistente\n");
				system("start bin/modules/recepcion.exe");
				break;
				default: break;	
		};
}

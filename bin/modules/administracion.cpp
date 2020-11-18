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
//PARA HABILITAR EL USO DE CARACTERES ESPECIALES
#include <wchar.h>
#include <locale.h>
//PARA HABILITAR FUNCIONES DE TEXTO
#include <ctype.h>
#include <string.h>
//PARA HABILITAR FUNCIONES ESPECIALES DE MANIPULACION DE VENTANA,ETC
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

//FUNCIONES de validacion
int val_user(userlen usuario,passlen contrasenia);
int val_in(int entrada,int lim_min, int lim_max);
//FUNCIONES de registro
void Reg_Veterinario();

main()
{
	setlocale(LC_ALL, "spanish");
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
			Reg_Veterinario();
			break;//Reg_Vet();
	}
}

int val_user(userlen usuario,passlen contrasenia)//Verifica si el usuario y contra es correcta
{
	//CONTADORES
	int lmay=0;//LETRAS MAYUSCULAS
	int cdig=0;//CONTADOR DIGITOS
	//BANDERAS DE LAS CONDICIONES
	int band=0;//BANDERA

	//VALIDACION DE USUARIO

	if(strlen(usuario)>=6 && strlen(usuario)<=10)//Verifica si el usuario tiene como minimo 6 y maximo 10 caracteres
	{
		if(islower(usuario[0])!=0)//verifica si el primer caracter es minuscula
		{
			for(int i=0;i<strlen(usuario);i++)//contador de mayusculas
			{
				if(isupper(usuario[i])!=0)//verifica mayuscula
				{
					lmay++;
				}
			}
			if(lmay>2)//verifica si tiene al menos 2 mayusculas
			{
				band = 0;
			}
			else
			{
				band = 1;
			}

			for(int i=0;i<strlen(usuario);i++)//contador de digitos
			{
				if(isdigit(usuario[i])!=0) //verifica digito
				{
					cdig++;
				}
			}

			if(cdig<=3)
			{
				band=0;
			}
			else
			{
				band=1;
			}
		}
		else
		{
			band = 1;
		}
	}
	else
	{
		band = 1;
	}

	if(band==1)//CONDICION FINAL
	{
		return 0;//no se cumplieron todas
	}else return 1;//se cumplieron todas
}
int val_in(int entrada,int lim_min, int lim_max)//Ingresa una entrada y verifica si esta entre los limites
{
	if(lim_max>lim_min)
	{
		if(entrada >= lim_min && entrada <= lim_max)
		{
			return 1;
		}else return 0;
	}else printf("\nEl limite minimo no puede ser mayor al maximo.");
	
}

void Reg_Veterinario()
{
	system("CLS");
	//ALTA
	FILE*arch_admin;
	arch_admin=fopen("USERSinf.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO");
		system("PAUSE");
		exit(1);
	}
	//FIN DE ALTA

	//Llamada al registro
	auth rv; //rv=registroveterinario
	//Declaracion de Variables
	int error;
	//Inicio interfaz de ingresado
	printf("Registrar Veterinario");
	printf("\n=======================\n");
	error=1;
	while(error==1)
	{
		_flushall();
		printf("Usuario:    "); gets(rv.user);
		_flushall();
		printf("\nContraseña: "); gets(rv.password);

		if(val_user(rv.user,rv.password)==0)
		{
			printf("Ingreso fallido. Nombre o Contraseña no valido.\n");
		}
		else 
		{
			error=0;printf("El usuario y contraseña se han ingresado correctamente.");
		}	
	}
	//BAJA
	fclose(arch_admin);
}
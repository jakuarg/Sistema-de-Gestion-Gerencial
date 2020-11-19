#include<stdio.h>//Funciones de entrada
#include<stdlib.h>//Funciones system
//#include <wchar.h>
#include <locale.h>// Añade paquete de idiomas
//PARA HABILITAR FUNCIONES DE TEXTO
#include <ctype.h>
#include <string.h>
//PARA HABILITAR FUNCIONES ESPECIALES DE MANIPULACION DE VENTANA,ETC
#include <windows.h>

typedef char userlen[12];  //Longitud del n. usuario(10)
typedef char passlen[34];  //Longitud de la contrasenia(32)

//ESTRUCTURAS
struct auth //ESTRUCTURA DEL USUARIO
{
	userlen	user;
	passlen password;
	char	ApeyNomb[60];
	int		matricula;
};

int val_user(userlen usuario,passlen contrasenia,int matricula)//Verifica si el usuario y contra es correcta
{
	// Establecer el idioma a español
    setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    //ALTA
	FILE*arch_admin;//Archivo donde se guardan el usuario y la constrasenia
	arch_admin=fopen("Usuarios.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO");
		system("PAUSE");
		exit(1);
	}
	//FIN DE ALTA

	//APERTURA REGISTRO
	auth reg;
	//CONTADORES 
	int lmay=0;//LETRAS MAYUSCULAS
	int cdig=0;//CONTADOR DIGITOS
	int lmin=0;//LETRAS MINUSCULAS
	
	int ccar=0;//CARACTERES
	

	//BANDERAS DE LAS CONDICIONES
	int buser=0;//usuario
	int bpass=0;//contrasenia
	int bdcon=0;//3 digitos consecutivos
	int bccon=0;//2 caracteres consecutivos
	int balf=0;//Contador alfanumerico



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
			if(lmay>=2)//verifica si tiene al menos 2 mayusculas
			{
				for(int i=0;i<strlen(usuario);i++)//contador de digitos
				{
					if(isdigit(usuario[i])!=0) //verifica digito
					{
						cdig++;
					}
				}

				if(cdig<=3)//verifica si tiene 3 digitos
				{
					rewind(arch_admin);
					fread(&reg.user, sizeof(userlen), 1, arch_admin);
					while(!feof(arch_admin))
					{
						if(strcmp(usuario,reg.user)==0)
						{
							buser=1;
						}
						else
						{
							buser=0;
						}
						
					}
				}
				else
				{
					buser = 1;
				}
			}
			else
			{
				buser = 1;
			}
		}
		else
		{
			buser = 1;
		}
	}
	else
	{
		buser = 1;
	}
	//FIN DE VALIDACION DE USUARIO

	//REINICIO DE CONTADORES
	lmay=0;
	cdig=0;
	lmin=0;
	
	//VALIDACION DE CONTRASENIA

	for(int i=0;i<strlen(contrasenia);i++)
	{
		if(islower(contrasenia[i])!=0)//verifica minuscula
		{
			lmin++;
		}
		else
		{
			if(isupper(contrasenia[i])!=0)//verifica mayuscula
			{
				lmay++;
			}
			else
			{
				if(isdigit(contrasenia[i])!=0)//verifica digito
				{
					cdig++;
					if((i>=3) && (((contrasenia[i])==(contrasenia[i-1]))==(contrasenia[i-2])))
					{
						bdcon=1;
					}
				}
				else
				{
					if(isalnum(contrasenia[i])==0)//verifica alfanumerico
					{
						balf++;
					}
				}
			}
			
		}
		if(toupper(contrasenia[i])==toupper(contrasenia[i+1]))
		{
			bccon=1;
		}
	}

	if(lmay>=1 && lmin>=1 && cdig>=1 && balf==0 && strlen(contrasenia)>=6 && strlen(contrasenia)<=32 && bdcon==0)//mayusculas,minusculas,numeros,solo alfanumericos,entre 6 y 32 caracteres, 3 caracteres numericos consecutivos,2 letras consecutivas ascendentes
	{
		bpass=1;
	}

	
	if(buser==0 && bpass==1)//CONDICION FINAL e INGRESO AL ARCHIVO
	{
		fwrite(&usuario    , sizeof(userlen),1, arch_admin);
		fwrite(&contrasenia, sizeof(userlen),1, arch_admin);
		fwrite(&matricula,   sizeof(int)    ,1, arch_admin);
		//BAJA
		fclose(arch_admin);

		return 1;//se cumplieron todas
	}
	else
	{
		//BAJA
		fclose(arch_admin);
		return 0;//no se cumplieron todas
	}
}
int val_in(int entrada,int lim_min, int lim_max)//Devuelve 1 si la entrada esta entre el lim_min y el lim_max
{
	if(lim_max>lim_min)
	{
		if(entrada >= lim_min && entrada <= lim_max)
		{
			return 1;
		}else return 0;
	}else printf("\nEl limite minimo no puede ser mayor al maximo.");
	
}
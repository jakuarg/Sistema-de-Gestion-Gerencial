/************************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo 2				       **
  *   Veterinaria					*
  ***********************************
  **********Admin.h******************
  ***********************************
/*Base de datos de usuarios*/
/*
  En esta libreria se encuentran las funciones:
  SignUp:
  		 Sirve para Registrar usuarios.(CON TIPO, devuelve 1 si se pudo registrar y 0 si no.)
  		 Tiene una bandera llamada registrado que indica el tipo de modulo que se ingresara
  LogIn:
  		Sirve para logear usuarios.(CON TIPO, devuelve el modulo al que pertenece.)
  ChangePass:
  		Sirve para cambiar contrasenias de usuarios ya existentes.(CON TIPO, devuelve 1 si se pudo cambiar y 0 si no.)

*/
//Librerias Principales
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Librerias para los string
#include<string.h>
#include<ctype.h>
//Librerias de ventanas y el tiempo
#include <windows.h>
#include <time.h>
#include <locale.h>
//Libreria propia.
#include "Estructuras.h"

FILE *arch_admin;
FILE *archaux1;

int SignUp(int registrado);
int LogIn(FILE *arch,FILE *archaux);
void gotoxy(int x,int y);

int SignUp(int registrado)//funcion que devuelve 1 si se pudo registrar y 0 si no. Sirve para registrar
{
	bool debug=0;//0 des 1 act
	//ALTA DEL ARCHIVO
	arch_admin=fopen("bin/modules/Usuarios.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO");
		system("PAUSE");
		return 0;
	}

	//FIN DE ALTA DEL ARCHIVO

    /*---Seccion de Declaraciones.---*/
    
    //Declaraciones comunes
    int aprobado=0,i,error;//Bandera si el usuario y contrasenia cumplen con los requisitos

    //Declaraciones de variables auxiliares
    userlen useraux;//Aloja el usuario ingresado por teclado
    passlen passaux;//Aloja la contrasenia ingresada por teclado

    //Declaraciones para el usuario(Contadores y Banderas)
    int udig=0,umay=0;//digito y mayuscula
    int usim=0;//Simbolo no aceptado
    int uexiste;//Bandera si existe el usuario registrado
    int ubandera;//Bandera si el usuario cumple con los requisitos
    
    

    //Declaraciones para la contrasenia(Contadores)
    int cmay=0,cmin=0,cdig=0;//mayuscula, minuscula ,digito
    int calfa=0;//alfanumerico
    int cleng=0;//longitud
    int cccon=0;//caracter consecutivo
    int calfc=0;//letras alfabeticamente consecutivas
    int cbandera;//Bandera si la contrasenia cumple con los requisitos

    
    //Apertura de el registro
    auth reg;

    /*---Empieza la validacion---*/
    aprobado=0;
    do
    {
        //Resetear variables
		aprobado=0,i=0;
        udig=0,umay=0,usim=0,uexiste=0,ubandera=0;
		cmay=0,cmin=0,cdig=0,calfa=0,cleng=0,cccon=0,calfc=0,cbandera=0;
		reg.matricula = 0;
		//INGRESO
        _flushall();
        printf("Usuario: ");
        gets(useraux);
        _flushall();
        printf("ContraseÒa: ");
        gets(passaux);
        
        //Validacion de usuario
		if(strlen(useraux)>=6 && strlen(useraux)<=10)
        {
            if(islower(useraux[0])!=0)
            {
				for(i=0 ; i < strlen(useraux) ; i++)
                {
					if(isupper(useraux[i])!=0)
                    {
						umay++;
                    }
                    else
                    {
                    	if(isdigit(useraux[i])!=0)
	                    {
							udig++;
	                    }
	                    else
	                    {
	                    	if(useraux[i]=='+' || useraux[i]=='-' || useraux[i]=='*' || useraux[i]=='?' || useraux[i]=='ø' || useraux[i]=='!' || useraux[i]=='ø')
		                    {
		                    }
		                    else 
							{
								if(isalnum(useraux[i])==0)
								{
									usim++;
								}
							}
						}
					}
                }//Fin del for
                
                if(umay>=2 && udig<=3 && usim==0)
                {
                    ubandera=1;
                }
            }
        }
		if(ubandera==1)
        {
            rewind(arch_admin);
            fread(&reg, sizeof(auth), 1, arch_admin);
            while(!feof(arch_admin))
            {
                if(strcmp(useraux,reg.user)==0)
                {
                    uexiste=1;
                    printf("\nEl usuario ya existe.\n");
                    system("PAUSE");
                    fclose(arch_admin);
					return 0;
                    break;
                }else {uexiste=0;}
                fread(&reg, sizeof(auth), 1, arch_admin);
            }
        }
        if(debug==1)
        {
        	printf("CONDICIONES USUARIO:\n");
			if(uexiste==1){
	        	printf("a. Ser ˙nico para cada usuario registrado.(NO CUMPLIDO)\n");
			}else printf("a. Ser ˙nico para cada usuario registrado.\n");
			
			if(islower(useraux[0])==0){
	        		printf("b. Comenzar con una letra min˙scula.(NO CUMPLIDO)\n");
			}else printf("b. Comenzar con una letra min˙scula.\n");
			
			if(umay<2){
	        	printf("c. Tener al menos 2 letras may˙sculas.(NO CUMPLIDO)\n");	
			}else printf("c. Tener al menos 2 letras may˙sculas.\n");
			
			if(udig>3){
	        	printf("d. Tener como m·ximo 3 dÌgitos.(NO CUMPLIDO)\n");
			}else printf("d. Tener como m·ximo 3 dÌgitos.\n");
		}

        if(uexiste==0 && ubandera==1 && strlen(passaux)>=6 && strlen(passaux) <=32)
        {
            //Validacion de contrasenia
            for(i=0;i<strlen(passaux);i++)
            {
				if(isupper(passaux[i])!=0)
				{
					cmay++;
                }
                if(islower(passaux[i])!=0)
                {
					cmin++;
                }
                if(isdigit(passaux[i])!=0)
                {
					cdig++;
                }
                if(isalnum(passaux[i])==0)
                {
					calfa++;
                }
                if(passaux[i]==passaux[i+1]-1 && passaux[i]==passaux[i+2]-2)
                {
					cccon++;
                }
                if(passaux[i]+1==passaux[i+1] && passaux[i+1]+1==passaux[i+2])
                {
                    calfc++;
                }
            }
            if(cmay>=1 && cmin>=1 && cdig>=1)
            {
                cbandera=1;
            }
        }
		if(debug==1)
        {
        	printf("CONDICIONES CONTRASE—A:\n");
			if(cmay>=1 && cmin>=1 && cdig>=1)
			{
				printf("a. Deber· contener al menos una letra may˙scula, una letra min˙scula y un n˙mero.\n");
			}else printf("a. Deber· contener al menos una letra may˙scula, una letra min˙scula y un n˙mero.(NO CUMPLIDO)\n");
			
			if(calfa==0){
				printf("b. No podr· contener ning˙n car·cter de puntuaciÛn, ni acentos, ni espacios. SÛlo caracteres alfanumÈricos.\n");
			}else printf("b. No podr· contener ning˙n car·cter de puntuaciÛn, ni acentos, ni espacios. SÛlo caracteres alfanumÈricos.(NO CUMPLIDO)\n");
			
			if(strlen(passaux)>=6 && strlen(passaux) <=32){
				printf("c. Deber· tener entre 6 y 32 caracteres.\n");
			}else printf("c. Deber· tener entre 6 y 32 caracteres.(NO CUMPLIDO)\n");
			
			if(cccon==0)
			{
				printf("d. No debe tener m·s de 3 caracteres numÈricos consecutivos.\n");
			}else printf("d. No debe tener m·s de 3 caracteres numÈricos consecutivos.(NO CUMPLIDO)\n");
			
			if(calfc==0)
			{
				printf("e. No debe tener 2 caracteres consecutivos que refieran a letras alfabÈticamenteconsecutivas (ascendentemente).\n");
				printf("Este criterio es v·lido tanto para letras may˙sculas,min˙sculas o combinaciÛn de ambas.\n");
			}
			else{
				printf("e. No debe tener 2 caracteres consecutivos que refieran a letras alfabÈticamenteconsecutivas (ascendentemente).\n");
				printf("Este criterio es v·lido tanto para letras may˙sculas,min˙sculas o combinaciÛn de ambas.(NO CUMPLIDO)\n");
			}
    	}
		
        //Validacion final

        if(cbandera==1 && ubandera==1)
        {
            aprobado=1;
        }
        else
        {
            aprobado=0;printf("\nEl usuario o ContraseÒa no cumplen con los requisitos.\n");
        }

    } while (aprobado==0);

    if(aprobado==1)
    {
        printf("Apellido y Nombre:\n");
        _flushall();
        gets(reg.names);
        
        if(registrado==1)//Admin
        {
            reg.modulo=1;
		}
		if(registrado==2)//Veterinario
        {
            _flushall();
			printf("MatrÌcula:\n");
            scanf("%d",&reg.matricula);
            reg.modulo=2;
            reg.veterinario = reg.veterinario + 1;
        }
        
        if(registrado==3)//Asistente
        {	
        	reg.matricula = 0;
        	if (reg.matricula == 0)
        	{
        	    reg.modulo=3;
			}
			else
			{
				reg.matricula = 0;
				//printf ("%d", reg.matricula);
			}
        }

        strcpy(reg.user,useraux);
        strcpy(reg.password,passaux);

        fwrite(&reg, sizeof(auth),1,arch_admin);
        fclose(arch_admin);
        return 1;
    }else fclose(arch_admin);return 0;

}

int LogIn(FILE *arch,FILE *archaux)//funcion que devuelve 1 si se pudo logear y 0 si no. Sirve para logear
{
    //No hace falta abrir el archivo ya que lo abrimos en main.
    
	//Declaramos auxiliares
	userlen	useraux;
    passlen	passaux;
    
	//Abrimos registro
    auth reg;
    aux auxiliar;
    
    int found=0,found_2=0, i;//encontrado
    
  	_flushall();
	printf("Usuario: ");
	gets(useraux);
	_flushall();
	printf("ContraseÒa: ");
	
	passlen passaux_1;
	i=0;

	int conta=0;
	i=0;
	   
	//Se piden caracteres hasta que se introduca enter
	while(passaux_1[i]!=13)
	{
		//Capturamos car·cter
		passaux_1[i]=getch();
		    
		//Si es un car·cter v·lido y no se ha sobrepasado el lÌmite de 20 caracteres se imprime un asterisco
		if(passaux_1[i]>32 && i<20)
		{
		    putchar('*');
		    i++;
		}
		//Si se pulsa la tecla RETROCESO, se retrocede un car·cter, se imprime un espacio para eliminar el asterisco y se vuelve a retroceder para que el siguiente asterisco se coloque a continuaciÛn del anterior.
		else if(passaux_1[i]==8 && i>0)
		{
		    putchar(8);
		    putchar(' ');
		    putchar(8);
		    i--; 
		}
	}
	passaux_1[i]='\0';
		   
	/*if(strcmp(passaux_1,nom)==0)
		printf("\n\n\n\n\n\t\tACCESO PERMITIDO");
	else
		printf("\n\n\n\n\n\t\t**ACCESO DENEGADO**");*/
	getch();
	
	strcpy(passaux,passaux_1);
	
	rewind(arch);
	fread(&reg,sizeof(auth),1,arch);
	while(!feof(arch))
	{
		if(strcmp(useraux,reg.user)==0)
		{
			if(strcmp(passaux,reg.password)==0)
            { 
				if (reg.modulo == 2)
                {
                	strcpy(auxiliar.password,reg.password);
                	strcpy(auxiliar.user,reg.user);
                	auxiliar.modulo = reg.modulo;
                	strcpy(auxiliar.names,reg.names);
                	auxiliar.matricula = reg.matricula;
                	
     	           	fseek(archaux,0,2);
					fwrite(&auxiliar, sizeof(aux), 1, archaux);
                	found=1;
                	found_2=reg.modulo;
				}
				if (reg.modulo == 1)
				{
                	found=1;
                	found_2=reg.modulo;				
				}
				if (reg.modulo == 3)
				{
					strcpy(auxiliar.password,reg.password);
                	strcpy(auxiliar.user,reg.user);
                	auxiliar.modulo = reg.modulo;
                	strcpy(auxiliar.names,reg.names);
                	
     	           	fseek(archaux,0,2);
					fwrite(&auxiliar, sizeof(aux), 1, archaux);
					found=1;
                	found_2=reg.modulo;
				}
            }
            else
            {
                printf ("\n\t\t\t\t\t\t\tLa contraseÒa ingresada es incorrecta.\n");
            }
		}
		fread(&reg,sizeof(auth),1,arch);
	}
    
	if(found==1)
    {
    	return found_2;	
	}
	else
	{
		printf("\n\t\t\t\t\t\t\tEl usuario no fue encontrado o no existe\n");
    	system("PAUSE");
    	return 0;
	}
}
void gotoxy(int x,int y)//La funcion gotoxy se utiliza para posicionar algun valor en pantalla
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
void color(int X)//Se utiliza para cambiar de color la pantalla
{
 	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void AltEnter()//Se utiliza para poner la pantalla completa
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}
// Establecer el idioma a espa√±ol
void Spanish()
{
	setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para m√°quinas Linux
	SetConsoleCP(1252); // Cambiar STDIN -  Para m√°quinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para m√°quinas Windows
}

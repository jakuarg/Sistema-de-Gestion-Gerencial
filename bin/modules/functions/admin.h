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
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef char userlen[12];
typedef char passlen[34];

struct auth
{
    userlen     user;
    passlen     password;
    char        names[60];
    int         modulo;
    int         matricula;
};

FILE*arch_admin;

int SignUp(int registrado)//funcion que devuelve 1 si se pudo registrar y 0 si no. Sirve para registrar
{
	//ALTA DEL ARCHIVO
	arch_admin=fopen("Usuarios.dat","a+b");
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
    do
    {
        //Resetear variables
		aprobado=0,i=0;
        udig=0,umay=0,usim=0,uexiste=0,ubandera=0;
		cmay=0,cmin=0,cdig=0,calfa=0,cleng=0,cccon=0,calfc=0,cbandera=0;
		//INGRESO
        _flushall();
        printf("Usuario: ");
        gets(useraux);
        _flushall();
        printf("Contrasenia: ");
        gets(passaux);
        //printf("inicia-");printf("\n\n");//DEPURACION
        //Validacion de usuario
		if(strlen(useraux)>=6 && strlen(useraux)<=10)
        {
            //printf("cond1-");printf("\n\n");//DEPURACION
            if(islower(useraux[0])!=0)
            {
                //printf("cond2-");printf("\n\n");//DEPURACION
				//printf("\n****%d****\n",strlen(useraux));printf("\n\n");//DEPURACION
				for(i=0 ; i < strlen(useraux) ; i++)
                {
                    //printf("\n#%d for[%c]-",i,useraux[i]);
					if(isupper(useraux[i])!=0)
                    {
                        //printf("\n#%d Fcond3-",i);printf("\n\n");//DEPURACION
						umay++;
                    }
                    else
                    {
                    	if(isdigit(useraux[i])!=0)
	                    {
	                        //printf("\n#%d Fcond4-",i);printf("\n\n");//DEPURACION
							udig++;
	                    }
	                    else
	                    {
	                    	if(useraux[i]=='+' || useraux[i]=='-' || useraux[i]=='*' || useraux[i]=='?' || useraux[i]=='�' || useraux[i]=='!' || useraux[i]=='�')
		                    {
		                        //printf("\n#%d caracter admitido-",i);printf("\n\n");//DEPURACION
		                    }
		                    else 
							{
								if(isalnum(useraux[i])==0)
								{
									usim++;
									//printf("\n#%d Fcond5-",i);printf("\n\n");//DEPURACION
								}
							}
						}
					}
                }//Fin del for
                
                if(umay>=2 && udig<=3 && usim==0)
                {
                    ubandera=1;
					//printf("\n\nFAPROBADO USUARIO-");printf("\n\n");//DEPURACION
                }
            }
        }
        if(ubandera==1)
        {
            rewind(arch_admin);
            fread(&reg, sizeof(reg.user), 1, arch_admin);
            while(!feof(arch_admin))
            {
                if(strcmp(useraux,reg.user)==0)
                {
                    uexiste=1;
                    printf("\nEl usuario ya existe.\n");
                    fclose(arch_admin);
					return 0;
                    break;
                }else uexiste=0;
            }
        }
        //printf("\n\n");//DEPURACION
        //printf("\nINICIA CONTRASENIA %d - %d",uexiste,ubandera);//DEPURACION
        if(uexiste==0 && ubandera==1)
        {
            //Validacion de contrasenia
            for(i=0;i<strlen(passaux);i++)
            {
                //printf("\nFor (%d) [%c]",i,passaux[i]);//DEPURACION
				if(isupper(passaux[i])!=0)
                {
                    //printf("\nMAY");//DEPURACION
					cmay++;
                }
                if(islower(passaux[i])!=0)
                {
                    //printf("\nes minuscula");//DEPURACION
					cmin++;
                }
                if(isdigit(passaux[i])!=0)
                {
                    //printf("\nes digito");//DEPURACION
					cdig++;
                }
                if(isalnum(passaux[i])==0)
                {
                    //printf("\n no es alfanumerico");//DEPURACION
					calfa++;
                }
                if(passaux[i]==passaux[i+1]-1 && passaux[i]==passaux[i+2]-2)
                {
                    //printf("\nnumeros consecutivos");//DEPURACION
					cccon++;
                }
                if(passaux[i]+1==passaux[i+1] && passaux[i+1]+1==passaux[i+2])
                {
                    calfc++;
                    //printf("\n [%d]=%c,[%d]=%c,[%d]=%c",i,passaux[i],i+1,passaux[i+1]+1,i+2,passaux[i+2]+2);//DEPURACION
                }
            }
            if(cmay>=1 && cmin>=1 && cdig>=1 && calfa==0 && cccon==0 && calfc==0)
            {
                cbandera=1;
            }
        }

        //Validacion final

        if(cbandera==1 && ubandera==1)
        {
            aprobado=1;
        }
        else
        {
            aprobado=0;printf("\nEl usuario o Contrasenia no cumplen con los requisitos.\n");
        }

    } while (aprobado==0);

    if(aprobado==1)
    {
        printf("Apellido y Nombre:      ");
        _flushall();
        gets(reg.names);
        
        if(registrado==1)//Admin
        {
        	//printf("\nModulo:	1 (Se ingreso automaticamente debido a que el primer usuario debe ser un administrador)");
            reg.modulo=1;
		}
		if(registrado==2)//Veterinario
        {
            printf("Matricula:      ");
            scanf("%d",&reg.matricula);
            reg.modulo=2;
        }
        if(registrado==3)//Asistente
        {
            reg.modulo=3;
        }
        /*{
			error=1;
			while(error==1)
			{
				printf("\n	Modulo\n");
				printf("		1.-Administracion.\n");
				printf("		2.-Consultorio.\n");
				printf("		3.-Asistente.\n");
        		scanf("%d",&reg.modulo);
        		if(reg.modulo==1 || reg.modulo==2 || reg.modulo==3)
        		{
        			printf("\nIngrese una opcion correcta.");
					error=0;
				}
			}
		}*/

        strcpy(reg.user,useraux);
        strcpy(reg.password,passaux);
		/*printf("\nUSUARIO: %s",reg.user);
		printf("\nCONTRASENIA: %s",reg.password);
		printf("\nNOMBRES: %s",reg.names);
		printf("\nMATRICULA: %s",reg.matricula);
		printf("\nMODULO: %s",reg.modulo);*/
		
        fwrite(&reg, sizeof(auth),1,arch_admin);
        fclose(arch_admin);
        return 1;
    }else fclose(arch_admin);return 0;

}

int LogIn(FILE *arch)//funcion que devuelve 1 si se pudo logear y 0 si no. Sirve para logear
{
    //No hace falta abrir el archivo ya que lo abrimos en main.
	//Declaramos auxiliares
	userlen	useraux;
    passlen	passaux;
    //Abrimos registro
    auth reg;
    
    int found=0;//encontrado
    _flushall();
	printf("Usuario: ");
	gets(useraux);
	_flushall();
	printf("Contrasenia:");
	gets(passaux);
	printf("s1");
	
	rewind(arch);
	fread(&reg,sizeof(auth),1,arch);
	while(!feof(arch))
	{
		printf(",s2\n");
        printf("%s,%s\n",useraux,reg.user);
        printf("%s,%s\n",passaux,reg.password);
		if(strcmp(useraux,reg.user)==0);
		{
			printf("\nEl usuario pertenece al modulo %d\n",reg.modulo);
            if(strcmp(passaux,reg.password)==0)
            {
                return reg.modulo;
            }
            else
            {
                printf ("\nLa contraseña ingresada es incorrecta.\n");
            }
            
		}
		fread(&reg,sizeof(auth),1,arch);
	}
    printf("\nEl usuario no fue encontrado o no existe\n");
    system("PAUSE");
    system("CLS");
    return 0;
}
/*
int accexists(userlen  usuario,userlen contrasenia)//Determina si la cuenta existe o no. Devuelve un 1 si existe y un 0 si no.
{
;
}
int changepass(userlen  usuario,userlen contrasenia)//Cambia la contrasenia.
{
    ;
}*/

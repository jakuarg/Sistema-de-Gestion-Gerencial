/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***s
  **  Grupo N 					   **
  *   Veterinaria					*
  ***********************************
  **********RECEPCION****************
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
#include "functions/admin.h"

/******** Funciones *******/

int menu_principal();
void reg_pet();
void reg_turno(FILE *ArchTurno);
void listado(FILE *ArchTurno);


main()
{
   AltEnter();
   color(252);
   // Establecer el idioma a español
   setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
   SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
   SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
   int menu; // Variable de ingreso al menu
    
    FILE *ArchTurno = fopen("bin/modules/Turno.dat","r+b");
    if(ArchTurno == NULL){
          
          fclose(ArchTurno);
          ArchTurno = fopen("bin/modules/Turno.dat","w+b");
     } 
       
     do{
           menu = menu_principal();
         
           switch (menu)
            {
                case 1:
                {
                    system ("CLS");
                     reg_pet();
                     break;
                }
                case 2: 
                {   
                    system ("CLS");
                     reg_turno(ArchTurno);
                     break;
                }
                case 3: 
                {   
                    system ("CLS");
                      listado(ArchTurno);
                      break;
                }
                case 4: 
                {
					system("PAUSE");              	
                	remove("Auxiliar.dat");	
                     printf("Saliendo del Sistema.....");
                      break;
                }

          	    default:
                printf("\n\n El valor ingresado no es valido");
                system ("PAUSE");
                break;
         }

         }while (menu!=4);

       fclose(ArchTurno);
     
}

// Funcion para realizar menu

int menu_principal()
{
	int auxx = 1;
	aux auxiliar;
	auth reg;
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	do{
		if (reg.modulo == auxiliar.modulo)	
		{
			auxx = 0;
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
		}
		
	}while(!feof(arch_admin) && !feof(archaux1) && auxx == 1);
     int opcion;
     system("CLS");
	printf("\n\t\t\t\t\t\t\t    ==================================================    ");
	printf("\n\t\t\t\t\t\t\t               Modulo %d Del Asistente", auxiliar.modulo);
	printf("\n\t\t\t\t\t\t\t    ==================================================    ");
    printf("\n\t\t\t\t\t\t\t           Asistente:%s               ", auxiliar.names);
	printf("\n\t\t\t\t\t\t\t    1.- Registrar Mascota                             ");
	printf("\n\t\t\t\t\t\t\t    2.- Registrar turno                               ");
	printf("\n\t\t\t\t\t\t\t    3.- Listado de Atenciones por Veterinario y Fecha ");
    printf("\n\t\t\t\t\t\t\t    4.- Cerrar la aplicacion.                         ");
	printf("\n\t\t\t\t\t\t\t   ===================================================    ");
	printf("\n\t\t\t\t\t\t\t   Ingrese una opcion: "); 
	scanf("%d", &opcion);
    return opcion;
	fclose(archaux1);  
}

// Funcion para registrar Mascota

void reg_pet(){
	
	int auxx = 1;
	aux auxiliar;
	auth reg;
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	do{
		if (reg.modulo == auxiliar.modulo)	
		{
			auxx = 0;
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
		}
		
	}while(!feof(arch_admin) && !feof(archaux1) && auxx == 1);
	
    FILE *archMascotas = fopen("bin/modules/Mascotas.dat", "a+b");
    if(archMascotas == NULL){
          
          fclose(archMascotas);
          printf("\nERROR");
          system ("pause");
    } 
    Datos_pet pet;

    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       REGISTRO DE MASCOTAS     ");
    printf("\n\t\t\t================================");
    printf("\n\t\tASISTENTE A CARGO DEL TURNO : %s ",auxiliar.names);

    printf("\nApellido y Nombre de la Mascota (El apellido es el del Duenio o Familia):");
    _flushall();
    gets(pet.Apeynom_pet);

    printf("\nLocalidad:"); gets(pet.localidad);
    printf("\nDomicilio:"); gets(pet.domicilio);
    printf("\nDni del dueño:"); scanf("%d", &pet.DNI_DUENIO);
    printf("\nPeso en KG:"); scanf("%f", &pet.peso);
    printf("\nTelefono");_flushall(); gets(pet.telefono);

    printf("\nFecha de nacimiento dd/mm/aaaa");
    printf("\nDia:"); scanf("%2d", &pet.de_nacimiento.dia);
    printf("\nMes:"); scanf("%2d", &pet.de_nacimiento.mes);
    printf("\nAnio:"); scanf("%4d", &pet.de_nacimiento.anio);

    fwrite(&pet, sizeof(Datos_pet), 1, archMascotas);
    fclose(archMascotas);
    
    printf("\n");
    system("pause");

}


// Funcion para registrar Turno 

void reg_turno(FILE *ArchTurno){
    Turno reg;
    reg.borradoTurno = false;
	auth reg1;
	Datos_pet pet;
	int bandera,matricula,aux1 = 0;
    FILE *archMascotas = fopen("bin/modules/Mascotas.dat", "r+b");
    arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       REGISTRO DE TURNO        ");
    printf("\n\t\t\t================================");
    int salir = 1;
   	printf("\n\n\t\tMatricula de medico:");
    scanf ("%d", &matricula);
	rewind (arch_admin);
	fread(&reg1,sizeof(auth),1,arch_admin);
    bandera=0;
    while(!feof(arch_admin) && bandera==0)
    {
 
		if (reg1.matricula==matricula && reg1.modulo == 2)
		{
			bandera=1;
			break;
		}
		else
		{
	 		fread(&reg1,sizeof(auth),1,arch_admin);	
		}
       if (!feof(arch_admin)==0)
        {
            bandera = 2;
        }
	}
	if (bandera == 2)
	{
		printf ("La matricula ingresada no coincide con ningun veterinario...");
		system("PAUSE");
		salir = 2;
	}
    rewind (archMascotas);
	fread(&pet,sizeof(Datos_pet),1,archMascotas);
	
	do{
	if (bandera == 1)
	{
		printf ("El veterinario que atendera el turno es : %s", reg1.names);
	    printf("\nFecha de turno");
	    printf("\nDIA:"); scanf("%2d", &reg.fec.dia);
	    printf("MES:"); scanf("%2d", &reg.fec.mes);
	    printf("ANIO:"); scanf("%4d", &reg.fec.anio);
        reg.matricula_de_veterinario = reg1.matricula;
        reg.atenciones = aux1 ;
        if (reg.atenciones != 0){
        	reg.atenciones = reg.atenciones + aux1;
		}
		reg.borradoTurno = false;
		
     	printf("\nDNI del Dueno:");
     	
  	  	scanf("%d", &reg.DNI_DUENIO);
    do
	{
  	  	
    	if (pet.DNI_DUENIO == reg.DNI_DUENIO && pet.DNI_DUENIO != NULL)
    	{
            system("CLS");
    		printf ("\nSu mascota es %s ", pet.Apeynom_pet);
            strcpy(reg.mascota,pet.Apeynom_pet);
    		salir = 0;
    		break;
		}
		else
		{
			printf ("%d", pet.DNI_DUENIO);
			system("CLS");
	        if(pet.DNI_DUENIO == 0 and feof(archMascotas)==0){
	                printf("\nDNI del dueño inexistente, porfavor registrar un Dueño");
	                system("PAUSE");
	                salir = 2;
	                break;
	        }
			else
	        {
				salir = 1;
	        } 
            if(salir!=0 && reg.DNI_DUENIO != pet.DNI_DUENIO)
            {
                printf ("El DNI Del duenio ingresado no es valido, Ingrese nuevamente.....");
            } 
		}
		fread(&pet,sizeof(Datos_pet),1,archMascotas);
        
		
	}while(salir==1);
 }  
    if(salir == 0){
 
        printf("\nSituacion de la Mascota:");   //Descripcion de lo que le sucede a la mascota
        _flushall();
        gets(reg.detalle_de_atencion);
        strcpy(reg.veterinario,reg1.names);
        fseek(ArchTurno,0,2);
        fwrite(&reg, sizeof(Turno), 1, ArchTurno);  
        printf("\n");
        system("pause");
        break;
 } 
   
 }while(!feof(archMascotas) && salir != 2);
}

// Funcion para listar la atencion de medico con fecha

void listado(FILE *ArchTurno){
	
    arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
    Turno reg;
	auth reg1;
    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       LISTADO DE ATENCION      ");
    printf("\n\t\t\t================================"); 
    rewind (arch_admin);
    rewind(ArchTurno);
    fread(&reg, sizeof(Turno), 1,ArchTurno);
	fread(&reg1,sizeof(auth),1,arch_admin);
    while(!feof(ArchTurno) && !feof(arch_admin) && reg.borradoTurno==false){
        printf("\n\n================================"); 
		printf("\nEl turno pertenece al veterinario : %s(%d)",reg.veterinario,reg.matricula_de_veterinario);
		printf ("\nMascota: %s",reg.mascota);
        if (reg.borradoTurno == 0)
        {
            printf ("(NO ATENDIDO)");
        }
        else
        {
            printf ("(ATENDIDO)");
        }
        
        printf("\nFECHA:");
        printf("%d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);
		fread(&reg1,sizeof(auth),1,arch_admin);
        fread(&reg, sizeof(Turno), 1,ArchTurno);
    }    
    printf("\n");
    system("PAUSE");
}


/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
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
    system ("colorF0");
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
                     printf("Saliendo del Sistema.....");
                      break;
                }

               default:
                printf("\n\n El valor ingrsado no es valido");
                system ("PAUSE");
                break;
         }

         }while (menu!=4);

       fclose(ArchTurno);
     
}

// Funcion para realizar menu

int menu_principal()
{
     int opcion;
     system("CLS");
	printf("\n\t\t\t    =============================================     ");
	printf("\n\t\t\t               Modulo Del Asistente                   ");
	printf("\n\t\t\t  	==============================================    ");
	printf("\n\t\t\t    1.- Registrar Mascota                             ");
	printf("\n\t\t\t  	2.- Registrar turno                               ");
	printf("\n\t\t\t    3.- Listado de Atenciones por Veterinario y Fecha ");
    printf("\n\t\t\t    4.- Cerrar la aplicacion.                         ");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t\t 	 Ingrese una opcion: "); 
	scanf("%d", &opcion);
    return opcion;

}

// Funcion para registrar Mascota

void reg_pet(){

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
	auth reg1;
	Datos_pet pet;
	int bandera,matricula;
    FILE *archMascotas = fopen("bin/modules/Mascotas.dat", "r+b");
    arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       REGISTRO DE TURNO        ");
    printf("\n\t\t\t================================");
   	printf("\n\n\t\tMatricula de medico:");
    scanf ("%d", &matricula);
	rewind (arch_admin);
	fread(&reg1,sizeof(auth),1,arch_admin);
    bandera=0;
    while(!feof(arch_admin) && bandera==0)
    {
 
		if (reg1.matricula==matricula)
		{
			bandera=1;
			break;
		}
 		fread(&reg1,sizeof(auth),1,arch_admin);
	
	}
	fread(&pet,sizeof(Datos_pet),1,archMascotas);
	  int salir = 1;
do{
if (bandera == 1)
{
    printf("\nFecha de turno");
    printf("DIA:"); scanf("%2d", &reg.fec.dia);
    printf("MES:"); scanf("%2d", &reg.fec.mes);
    printf("ANIO:"); scanf("%4d", &reg.fec.anio);

  
    do{
   		printf("\nDNI del Dueno:");
  	  	scanf("%d", &reg.DNI_DUENIO);
    	if (pet.DNI_DUENIO == reg.DNI_DUENIO)
    	{
    		printf ("\nSu mascota es %s ", pet.Apeynom_pet);
    		salir = 0;
    		break;
		}
		else
		{
			printf ("El DNI Del duenio ingresado no es valido, Ingrese nuevamente.....");
			salir = 1;
		}
	}while(salir==1);

 }  
 }while(!feof(archMascotas) and salir==1); 
    printf("\nSituacion de la Mascota:");   //Descripcion de lo que le sucede a la mascota
    _flushall();
    gets(reg.detalle_de_atencion);

    fseek(ArchTurno,0,2);
    fwrite(&reg, sizeof(Turno), 1, ArchTurno);  
    printf("\n");
    system("pause");
    
}

// Funcion para listar la atencion de medico con fecha

void listado(FILE *ArchTurno){
	
    arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
     Turno reg;
     rewind(ArchTurno);
     fread(&reg, sizeof(Turno), 1,ArchTurno);
	auth reg1;
    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       LISTADO DE ATENCION      ");
    printf("\n\t\t\t================================"); 
    rewind (arch_admin);
	fread(&reg1,sizeof(auth),1,arch_admin);
    while(!feof(ArchTurno) and !feof(arch_admin)){

        printf("\nMatricula de medico:%d",reg.matricula_de_veterinario);
        printf("\nFECHA:");
        printf("%d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);
		fread(&reg1,sizeof(auth),1,arch_admin);
        fread(&reg, sizeof(Turno), 1,ArchTurno);
    }
      
     printf("\n");
     system("pause");
}


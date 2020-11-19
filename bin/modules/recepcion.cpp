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

struct fecha{

int dia;
int mes;
int anio;

};

struct Turno{

int matricula_de_veterinario; 
fecha fec;       // fecha del turno
int DNI_DUENIO; // dni due�o
char detalle_de_atencion[380];     //pronostico de lo que le sucede a la mascota

};

struct Datos_pet{

char Apeynom_pet[60];   // Apellido y Nombre de la mascota (El Apellido igual del dueño)
char domicilio[60];
int DNI_DUENIO;
char localidad[60];
fecha de_nacimiento;   //fecha de nacimiento de la mascota
float peso; // Cantidad en kilogramos 
char telefono[25];  //telefono celular/fijo del dueño

};


/******** Funciones *******/

int menu_principal();

main()
{
    system ("colorF0");
   int menu; // Variable de ingreso al menu
    
    FILE *ArchTurno = fopen("Turno.dat","r+b");
    if(ArchTurno == NULL){
          
          fclose(ArchTurno);
          ArchTurno = fopen("Turno.dat","w+b");

    } 
     
     do{
           menu = menu_principal();
         
           switch (menu)
            {
                case 1:
                {
                    system ("CLS");
         
                     break;
                }
                case 2:
                {
                    system ("CLS");

                     break;
                }
                case 3: 
                {   
                    system ("CLS");
         
                     break;
                }
                case 4: 
                {   
                    system ("CLS");
        
                      break;
                }
                case 5: 
                {
                     printf("Saliendo del Sistema.....");
                      break;
                }

               default:
                printf("\n\n El valor ingrsado no es valido");
                system ("PAUSE");
                break;
         }

         }while (menu!=5);

}


int menu_principal()
{
     int opcion;
     system("CLS");
	printf("\n\t\t\t    =============================================     ");
	printf("\n\t\t\t               Modulo Del Asistente                   ");
	printf("\n\t\t\t  	==============================================    ");
	printf("\n\t\t\t  	1.- Iniciar Sesion                                ");
	printf("\n\t\t\t    2.- Registrar Mascota                             ");
	printf("\n\t\t\t  	3.- Registrar turno                               ");
	printf("\n\t\t\t    4.- Listado de Atenciones por Veterinario y Fecha ");
    printf("\n\t\t\t    5.- Cerrar la aplicacion.                         ");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t\t 	 Ingrese una opcion: 	"); 
	scanf("%d", &opcion);
    return opcion;

}

// Funcion para registrar Mascota

void reg_pet(){

    Datos_pet pet;

    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       REGISTRO DE MASCOTAS     ");
    printf("\n\t\t\t================================");

    printf("\nApellido y Nombre de la Mascota (El apellido es el del Duenio o Familia):");
    gets(pet.Apeynom_pet);

    printf("\nLocalidad:"); gets(pet.localidad);
    printf("\nDomicilio:"); gets(pet.domicilio);
    printf("\nDni del dueño:"); scanf("%d", &pet.DNI_DUENIO);
    printf("\nPeso en KG:"); scanf("%f", &pet.peso);
    printf("\nTelefono"); gets(pet.telefono);

    printf("\nFecha de nacimiento dd/mm/aaaa");
    printf("\nDia:"); scanf("%2d", &pet.de_nacimiento.dia);
    printf("\nMes:"); scanf("%2d", &pet.de_nacimiento.mes);
    printf("\nAnio:"); scanf("%2d", &pet.de_nacimiento.anio);
    
}




// Funcion para registrar Turno 

void reg_turno(FILE *ArchTurno){
    Turno reg;

    
    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       REGISTRO DE TURNO        ");
    printf("\n\t\t\t================================"); 
    printf("\n\n\t\tMatricula de medico:");

    scanf ("%d", &reg.matricula_de_veterinario);
    printf("\nFecha de turno");
    printf("DIA:"); scanf("%2d", &reg.fec.dia);
    printf("MES:"); scanf("%2d", &reg.fec.mes);
    printf("ANIO:"); scanf("%4d", &reg.fec.anio);
    printf("\nDNI del Dueño:");
    scanf("%d", &reg.DNI_DUENIO);
    printf("\nSituacion de la Mascota:");   //Descripcion de lo que le sucede a la mascota
    scanf("%s", &reg.detalle_de_atencion);

    fseek(ArchTurno,0,2);
    fwrite(&reg, sizeof(Turno), 1, ArchTurno);
    
}

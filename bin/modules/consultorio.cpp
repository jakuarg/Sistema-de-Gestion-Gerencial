/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo N 					   **
  *   Veterinaria					*
  ***********************************
  **********CONSULTORIO**************
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


int menuprincipal();
void evolucionMascota(FILE *archMascota,int &pn);
void Listaespera();

main()
{
	setlocale(LC_ALL, "es_ES"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    
    auth reg;
    
	int matricula,pn;
	int opc,aux; //variable declarada para acceder a las opciones 
	
	FILE *archMascota = fopen("bin/modules/Mascotas.dat", "r+b");
	if (archMascota == NULL)
	{
		fclose(archMascota);
		archMascota = fopen("bin/modules/Mascotas.dat", "w+b");
	}
	
	do{
		opc = menuprincipal();
		switch(opc){
			case 1:{

				Listaespera();
				system("PAUSE");
				break;
			}
			case 2:{
				evolucionMascota(archMascota,pn);
				system("PAUSE");						
				break;		
			}
			case 3:{
				system("PAUSE");
				remove("Auxiliar.dat");	
				break;
				
			}
			default:{
				exit(1);
			}
		}
	}while(opc!=3);

	fclose(archMascota);
}


int menuprincipal()
{
	auth reg;
	
	int auxx = 1;
	aux auxiliar;
	
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	do
	{
		if (reg.modulo == auxiliar.modulo)	
		{
			auxx = 0;
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
		}
		
	}while(!feof(arch_admin) and !feof(archaux1) and auxx == 1);
	{
		system("CLS");
		int op;
		system("CLS");
		printf("\n\t\t\t    =============================================     ");
		printf("\n\t\t\t          Modulo %d Consultorio Veterinario           ",auxiliar.modulo);
		printf("\n\t\t\t  	==============================================    ");
		printf("\n  				    Veterinario a cargo : %s              ",auxiliar.names);
		printf("\n\t\t\t    1.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n\t\t\t	2.- Registrar Evolucion de la Mascota             ");
		printf("\n\t\t\t    3.- Cerrar la aplicacion.                         ");
		printf("\n\t\t\t =======================================");
		printf("\n\t\t\t\t 	 Ingrese una opcion: 	"); 
		scanf("%d", &op);
		return op;
	}	

}

void evolucionMascota(FILE *archMascota,int &pn)
{
	
	Datos_pet pet;
	Turno reg1;
	aux auxiliar;
	auth reg;
	
	int edadDuenio;
	int auxx = 1,salir=0;
	char nom[60],nombreaux[50];
	_flushall();
	printf ("\nIngrese el Apellido y nombre de la mascota : ");
	gets(nom);	
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	FILE *archturno = fopen("bin/modules/Turno.dat", "r+b"); 
	rewind(archturno);
	rewind (archaux1);
	rewind (arch_admin);
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	fread(&reg1,sizeof(Turno),1,archturno);
	do{
		printf ("%d , %d, %d, %d",reg.modulo,auxiliar.modulo,reg.matricula,reg1.matricula_de_veterinario);
		if (reg.modulo == auxiliar.modulo && reg.matricula == reg1.matricula_de_veterinario)	
		{
				rewind(archMascota);
				rewind(archturno);
				fread(&reg1,sizeof(Turno),1,archturno);
				fread(&pet,sizeof(Datos_pet),1,archMascota);
				do
				{	
					printf ("primera condicion : %s y %s, segunda condicion = %d y %d, tercera condicion %s %s",nom,pet.Apeynom_pet,reg1.matricula_de_veterinario,auxiliar.matricula,pet.Apeynom_pet,reg1.mascota);	
					if(strcmp(pet.Apeynom_pet,nom)== 0 && reg1.matricula_de_veterinario == auxiliar.matricula && strcmp(pet.Apeynom_pet,reg1.mascota)==0)
					{
						printf ("entro? nashe");
						if (reg1.borradoTurno == false && strcmp(pet.Apeynom_pet,nom)== 0)
						{
							printf ("\nel dni del dueno de la mascota %d", pet.DNI_DUENIO);
							printf ("\nla localidad del dueno : ");
							puts(pet.localidad);	
							printf ("Se guardo !");					
							auxx = 0;
							salir = 1;
								if (auxx == 0 and salir == 1 )
								{
										reg1.borradoTurno = true;
										reg1.atenciones = reg1.atenciones + 1;
										fseek(archturno,0,2);
										fwrite(&reg1,sizeof(Turno),1,archturno);  //guarda
										printf ("\nIngrese la evolucion de la mascota : ");
										_flushall();
										gets(pet.informeMascota);
										fseek(archMascota,0,2);															
										fwrite(&pet,sizeof(Datos_pet),1,archMascota); 	//guarda		
								}
								
							break;
						}else{
							fread(&pet,sizeof(Datos_pet),1,archMascota);
							fread(&reg1,sizeof(Turno),1,archturno);		
						}if (!feof(archturno) && !feof(archMascota)){
							auxx = 2;
						}
					}
					fread(&pet,sizeof(Datos_pet),1,archMascota);
					fread(&reg1,sizeof(Turno),1,archturno);							
				}while(auxx==1);	
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&auxiliar,sizeof(aux),1,archaux1);
			fread(&reg1,sizeof(Turno),1,archturno);
		}
		if (!feof(arch_admin) && !feof(archaux1) && !feof(archturno) && !feof(archMascota)){
			auxx == 2;
		}
	}while(auxx == 1);
	if (auxx==2)
	{
		printf ("\nNo se encontro ninguna mascota ");
	}
	printf ("salio re piola aux = %d", auxx);
	system("PAUSE");
	printf("%d",feof(archMascota));

	fclose(archturno);
	fclose(archaux1);
	fclose(arch_admin);
}

void Listaespera()
{
	FILE *ArchTurno = fopen("bin/modules/Turno.dat","r+b");
	FILE *archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	if (ArchTurno == NULL)
	{
		printf ("soy NULL Archturno");
	}else
	if (archaux1 == NULL){
		printf ("SOY NULL CULIAO archaux1");
	}
	int auxx = 1,salgo=1;
	Turno reg;
	auth reg1;
	aux auxiliar;
	rewind (archaux1);	
	rewind (ArchTurno);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	fread(&reg,sizeof(Turno),1,ArchTurno);		
	printf ("ESTOY ACA %d %d", feof(archaux1),feof(ArchTurno));
	system("PAUSE");
	do
	{	
		printf ("ENTRO AL WHILE");
		printf ("%d y  %d", reg.matricula_de_veterinario, auxiliar.matricula);
		if (reg.matricula_de_veterinario == auxiliar.matricula)	
		{
			printf ("Entro ?? ");
			rewind (ArchTurno);
			fread(&reg,sizeof(Turno),1,ArchTurno);		
			while (!feof(ArchTurno) and reg.borradoTurno==false){
				if (reg.matricula_de_veterinario == auxiliar.matricula){
					printf ("\nEl nombre del veterinario a cargo del turno: ");
					puts(reg.veterinario);
					printf("\nFecha de turno");
					printf("DIA: %2d", reg.fec.dia);
					printf("MES: %2d", reg.fec.mes);
					printf("AniO: %4d", reg.fec.anio);
					printf("\nDNI del Due�o: %d", reg.DNI_DUENIO);
					printf ("\nDetalle de atencion : ");
					puts(reg.detalle_de_atencion);
					fread(&reg,sizeof(Turno),1,ArchTurno);
				}
				else
				{
					break;
				}

		}
		}else {
			fread(&auxiliar,sizeof(aux),1,archaux1);	
			fread(&reg,sizeof(Turno),1,ArchTurno);		
		}
		if (!feof(ArchTurno) and !feof(archaux1))
		{
			salgo=0;
			break;
		}			
	}while(salgo == 1);
	if (salgo == 0)
	{			
		printf("\nNo existen turnos para este veterinario ");
	}
	else if (salgo == 2){
		printf ("");
	}
	system("PAUSE");
	
}
    

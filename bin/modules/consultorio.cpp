/*
  ***********************************
  *** Trabajo Practico Grupal No2 ***
  **  Grupo 2 					   **
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
	AltEnter();
	color(241);
	Spanish();
    
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
				system("CLS");
				printf("\n\t\t\t\t\t\t\t=============================");
				printf("\n\t\t\t\t\t\t\t        Lista de Espera");
				printf("\n\t\t\t\t\t\t\t=============================");
				Listaespera();
				break;
			}
			case 2:{
				evolucionMascota(archMascota,pn);						
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
		printf("\n\t\t\t\t\t\t\t   ===================================================    ");
		printf("\n\t\t\t\t\t\t\t              Módulo %d Consultorio Veterinario         ",auxiliar.modulo);
		printf("\n\t\t\t\t\t\t\t   ===================================================    ");
		printf("\n\t\t\t\t\t\t\t              Veterinario a cargo : %s             ",auxiliar.names);
		printf("\n\t\t\t\t\t\t\t   1.- Visualizar Lísta de Espera de Turnos (informe)");
		printf("\n\t\t\t\t\t\t\t   2.- Registrar Evolución de la Mascota             ");
		printf("\n\t\t\t\t\t\t\t   3.- Cerrar la aplicación.                         ");
		printf("\n\t\t\t\t\t\t\t  ===================================================    ");
		printf("\n\t\t\t\t\t\t\t   Ingrese una opción: 	"); 
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
	int auxx = 1,salir=0,recorrer=0;
	char nom[60],nombreaux[50];
	
	archaux1 = fopen("bin/modules/Auxiliar.dat", "r+b");
	arch_admin = fopen("bin/modules/Usuarios.dat", "r+b");
	FILE *archturno = fopen("bin/modules/Turno.dat", "r+b"); 
	
	rewind(archturno);
	rewind (archaux1);
	rewind (arch_admin);
	
	fread(&reg,sizeof(auth),1,arch_admin);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	fread(&reg1,sizeof(Turno),1,archturno);
	
	while(recorrer==0){
		//printf ("reg.modulo = %d ,auxiliar.modulo = %d,reg.matricula =  %d,auxiliar.matricula =  %d\n",reg.modulo,auxiliar.modulo,reg.matricula,auxiliar.matricula);
		if (reg.modulo == auxiliar.modulo && reg.matricula == auxiliar.matricula)	
		{
			rewind(archturno);
			fread(&reg1,sizeof(Turno),1,archturno);
			while(!feof(archturno) && recorrer==0){
			//printf ("auxiliar matricula = %d reg1.matricula_de_veterinario = %d",auxiliar.matricula,reg1.matricula_de_veterinario);
			if (auxiliar.matricula == reg1.matricula_de_veterinario){
				//printf ("ENTRO?");
				//system("PAUSE");
				_flushall();
				printf ("\nApellido y Nombre(Mascota): ");
				gets(nom);	
				rewind(archMascota);
				rewind(archturno);
				fread(&reg1,sizeof(Turno),1,archturno);
				fread(&pet,sizeof(Datos_pet),1,archMascota);
				do
				{
					while(!feof(archturno) and recorrer==0){
					//printf ("primera condicion : %s y %s",nom,pet.Apeynom_pet);	
					if(strcmp(pet.Apeynom_pet,nom)== 0 )
					{
						//printf ("entro? nashe");
						if (reg1.borradoTurno == false && strcmp(pet.Apeynom_pet,nom)== 0)
						{
							printf ("\nD.N.I del Dueño: %d", pet.DNI_DUENIO);
							printf ("\nLocalidad: ");
							puts(pet.localidad);	
							//printf ("Se guardo !");					
							auxx = 0;
							salir = 1;
								if (auxx == 0 and salir == 1 )
								{
									reg1.borradoTurno = true;
									reg1.atenciones = reg1.atenciones + 1;
									
									fseek(archturno,0,2);
									fwrite(&reg1,sizeof(Turno),1,archturno);  //guarda
									
									printf ("\nEvolucion de la mascota: ");
									_flushall();
									gets(pet.informeMascota);
									fseek(archMascota,0,2);															
									fwrite(&pet,sizeof(Datos_pet),1,archMascota); 	//guarda
									recorrer=1;	
									auxx=3;
									//printf ("%d y %d",recorrer,auxx);
								}
								
							break;
						}else{
							fread(&pet,sizeof(Datos_pet),1,archMascota);
							fread(&reg1,sizeof(Turno),1,archturno);		
						}if (!feof(archturno) && !feof(archMascota)){
							auxx = 2;
						}
					}
					else
					{
						fread(&pet,sizeof(Datos_pet),1,archMascota);
						fread(&reg1,sizeof(Turno),1,archturno);				
					}
					if (strcmp(pet.Apeynom_pet,nom)!=0 and feof(archturno)){
						auxx= 2;
					}
									
					}	

				}while(auxx==1);									
			}else
			{
				fread(&reg1,sizeof(Turno),1,archturno);
			}		
			}
		}
		else
		{
			fread(&reg,sizeof(auth),1,arch_admin);
			fread(&reg1,sizeof(Turno),1,archturno);
		}
		if (feof(archturno) && feof(arch_admin)){
			recorrer = 1;
		}
	}
	if (auxx==2)
	{
		printf ("\nNo se han encontrado mascotas cargadas.");
	}
	system("PAUSE");
	//printf("%d",feof(archMascota));

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
		printf ("\nNo se han encontrado turnos cargados.");
	}else
	if (archaux1 == NULL){
		printf ("\nNo se ha encontrado el Archivo Auxiliar.");
	}
	int auxx = 1,salgo=1;
	Turno reg;
	auth reg1;
	aux auxiliar;
	
	rewind (archaux1);	
	rewind (ArchTurno);
	
	fread(&auxiliar,sizeof(aux),1,archaux1);
	fread(&reg,sizeof(Turno),1,ArchTurno);		
	
	while(!feof(ArchTurno))
	{		
		//printf ("ENTRO AL WHILE");
		//printf ("%d y  %d", reg.matricula_de_veterinario, auxiliar.matricula);
		if (reg.matricula_de_veterinario == auxiliar.matricula)	
		{
			//printf ("Entro ?? ");
			//system("PAUSE");
			rewind (ArchTurno);
			fread(&reg,sizeof(Turno),1,ArchTurno);		
			while (!feof(ArchTurno) and reg.borradoTurno==false){
				if (reg.matricula_de_veterinario == auxiliar.matricula)	{
					printf ("\n\t\t\t\t\t\t\tEl veterinario a cargo es: ");puts(reg.veterinario);
					printf("\nFecha de turno: ");
					printf("%2d", reg.fec.dia);
					printf("/%2d", reg.fec.mes);
					printf("/%4d", reg.fec.anio);
					printf("\nD.N.I del Dueño: %d", reg.DNI_DUENIO);
					printf ("\nDetalle de atención : ");
					puts(reg.detalle_de_atencion);
					fread(&reg,sizeof(Turno),1,ArchTurno);	
				}
				fread(&reg,sizeof(Turno),1,ArchTurno);	
		}
		}	
			fread(&reg,sizeof(Turno),1,ArchTurno);		
		
	}
	if (salgo == 0)
	{			
		printf("\nNo existen turnos para este veterinario ");
	}
	else if (salgo == 2){
		//printf ("");
	}
	system("PAUSE");
	
}
    

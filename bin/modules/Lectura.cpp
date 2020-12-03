#include <stdio.h>
#include <stdlib.h>
#include "functions/admin.h"
int menuprincipal();
void mascotadat();
void usuariosdat();
void regturno();
void auxiliar();
main()
{
	int menu;
	do{
		menu = menuprincipal();
		switch(menu){
			case 1:{
				usuariosdat();
				system("PAUSE");
				break;
			}
			case 2:{
				mascotadat();
				system("PAUSE");
				break;
			}
			case 3:{
				regturno();
				system("PAUSE");
				break;
			}
			case 4:{
				auxiliar();
				system("PAUSE");
				break;
			}
		}
	}while(menu!=5);
}

int menuprincipal(){
	int op;
	system("CLS");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t           MENU PRINCIPAL               ");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t    1- Usuarios.dat lectura                ");
	printf("\n\t\t\t    2- Mascota.dat lectura                ");
	printf("\n\t\t\t    3- Turno.dat lectura                ");
	printf("\n\t\t\t    3- auxiliar.dat lectura                ");
	printf("\n\t\t\t =======================================");
	printf("\n\t\t\t\t Ingrese o Selecione opcion: "); 
	scanf("%d", &op);
	return op;	
}

void mascotadat(){
	FILE *arch1;
	Datos_pet reg2;
	arch1 = fopen("Mascotas.dat", "r+b");
	printf ("%d", feof(arch1));
	rewind(arch1);
	fread(&reg2,sizeof(Datos_pet),1,arch1);
	printf ("Los datos ingresados 2: \n");
	while (!feof(arch1))
	{
		puts(reg2.Apeynom_pet);
   		puts(reg2.localidad);
   		puts(reg2.domicilio);
    	printf("\nDni del dueño: %d", reg2.DNI_DUENIO);
    	printf("\nPeso en KG: %f", reg2.peso);
		puts(reg2.telefono);
    	printf("\nDia: %2d", reg2.de_nacimiento.dia);
    	printf("\nMes: %2d", reg2.de_nacimiento.mes);
    	printf("\nAnio:%4d", reg2.de_nacimiento.anio);
    	printf ("\n Evolucion de la mascota : ");
    	puts(reg2.informeMascota);
		fread(&reg2,sizeof(Datos_pet),1,arch1);
	}	
}

void usuariosdat()
{
	auth reg;
	Turno reg1;
	documentacion reg3;
	FILE *arch;
	arch = fopen("Usuarios.dat", "r+b");
	rewind(arch);
	fread(&reg,sizeof(auth),1,arch);
	printf ("Los datos ingresados : \n");
	while (!feof(arch))
	{
		puts(reg.user);
		puts(reg.password);	
		puts(reg.names);
		printf ("Reg veterinario : %d\n", reg.veterinario);
		printf ("Modulo : %d \n", reg.modulo);	
		printf ("Matricula : %d \n", reg.matricula);
		printf ("\n");
		fread(&reg,sizeof(auth),1,arch);
	}
}

void regturno()
{
	FILE *arch;
	arch = fopen("Turno.dat", "r+b");
     Turno reg;
     rewind(arch);
     fread(&reg, sizeof(Turno), 1,arch);

    printf("\n\t\t\t================================"); 
    printf("\n\t\t\t       LISTADO DE ATENCION      ");
    printf("\n\t\t\t================================"); 

    while(!feof(arch)){

        printf("\nMatricula de medico:%d",reg.matricula_de_veterinario);
        printf("\nFECHA:");
        printf("%d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);

        fread(&reg, sizeof(Turno), 1,arch);
    }
      
     printf("\n");
}

void auxiliar()
{
	FILE *archaux1=fopen("Auxiliar.dat","r+b");
	aux auxiliar;
	rewind(archaux1);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	while(!feof(archaux1))
	{
		printf ("%d", auxiliar.modulo);
		puts(auxiliar.user);
		puts(auxiliar.password);
		puts(auxiliar.names);
		printf ("%d", auxiliar.matricula);		
		fread(&auxiliar,sizeof(aux),1,archaux1);
	}

}



#include <stdio.h>
#include <stdlib.h>
#include "functions/admin.h"
int menuprincipal();
void mascotadat();
void usuariosdat();
void regturno();
void auxiliar();
void ranking1();
main()
{
	Spanish();
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
	}while(menu!=6);
}

int menuprincipal(){
	int op;
	system("CLS");
	printf("\t\t\t\t\t\t\t =========================================");
	printf("\n\t\t\t\t\t\t\t           MENU PRINCIPAL               ");
	printf("\n\t\t\t\t\t\t\t =======================================");
	printf("\n\t\t\t\t\t\t\t    1- Usuarios.dat lectura                ");
	printf("\n\t\t\t\t\t\t\t    2- Mascota.dat lectura                ");
	printf("\n\t\t\t\t\t\t\t    3- Turno.dat lectura                ");
	printf("\n\t\t\t\t\t\t\t    4- auxiliar.dat lectura                ");
	printf("\n\t\t\t\t\t\t\t =======================================");
	printf("\n\t\t\t\t\t\t\t\t Ingrese o Selecione opcion: "); 
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
		printf ("\n");
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
		printf ("\n");
		puts(reg.user);
		puts(reg.password);	
		puts(reg.names);
		printf ("\nReg veterinario : %d\n", reg.veterinario);
		printf ("\nModulo : %d \n", reg.modulo);	
		printf ("\nMatricula : %d \n", reg.matricula);
		printf ("\n");
		fread(&reg,sizeof(auth),1,arch);
	}
}

void regturno()
{
	FILE *arch;
	arch = fopen("Turno.dat", "r+b");
    if(arch==NULL)
    {
    	printf("\nNo hay turnos\n");
	}
	else
	{
		Turno reg;
	    rewind(arch);
	    fread(&reg, sizeof(Turno), 1,arch);
	
	    printf("\n\t\t\t================================"); 
	    printf("\n\t\t\t       LISTADO DE ATENCION      ");
	    printf("\n\t\t\t================================"); 
	
	    while(!feof(arch))
	    {
	    	printf ("\n");
			puts(reg.veterinario);
			puts(reg.mascota);
	        printf("\nMatricula de veterinario:%d",reg.matricula_de_veterinario);
	        printf("\nFECHA: ");
	        printf("%d/%d/%d",reg.fec.dia,reg.fec.mes,reg.fec.anio);
			printf ("\nBorrado turno = %d", reg.borradoTurno);
			printf ("\nAtenciones realizadas : %d ", reg.atenciones);
			printf("\ndetalle de atencion : ");puts(reg.detalle_de_atencion);
	        fread(&reg, sizeof(Turno), 1,arch);
		}
	}
}

void auxiliar()
{
	FILE *archaux1=fopen("Auxiliar.dat","r+b");
	aux auxiliar;
	rewind(archaux1);
	fread(&auxiliar,sizeof(aux),1,archaux1);
	while(!feof(archaux1))
	{
		printf ("\n");
		printf ("%d", auxiliar.modulo);
		puts(auxiliar.user);
		puts(auxiliar.password);
		puts(auxiliar.names);
		printf ("%d", auxiliar.matricula);		
		fread(&auxiliar,sizeof(aux),1,archaux1);
	}

}

void ranking1()
{
	ranking reg;
	FILE *arch;
	arch = fopen ("ranking.dat", "r+b");
	rewind (arch);
	fread(&reg,sizeof(ranking),1,arch);
	while(!feof(arch))
	{
		printf ("\n");
		printf ("\natencion : %d", reg.atencion);
		printf ("\nnombre : %s", reg.nom);
		fread(&reg,sizeof(ranking),1,arch);	
	}
	system("PAUSE");
	
}



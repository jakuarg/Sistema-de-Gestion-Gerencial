#include<stdio.h>
#include<stdlib.h>


main()
{
	printf("Bienvenido al software de la veterinaria\n");
	printf("========================================\n");
	FILE*arch_admin;
	arch_admin=fopen("bin\\modules\\Usuarios.dat","rb")
	if(arch_admin==NULL)
	{
		arch_admin=fopen("bin\\modules\\Usuarios.dat","a+b");
		if(arch_admin==NULL)
		{
			system("CLS");
			printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
			system("PAUSE");
			exit(1);
		}
		
	}
	
	//ALTA
	FILE*arch_admin;//Archivo donde se guardan el usuario y la constrasenia
	arch_admin=fopen("bin\\modules\\Usuarios.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO\n\n");
		system("PAUSE");
		exit(1);
	}
	//FIN DE ALTA

}

#include<stdio.h>
#include<stdlib.h>


main()
{
	printf("Bienvenido al software de la veterinaria\n");
	printf("========================================\n");
	
	//ALTA
	FILE*arch_admin;//Archivo donde se guardan el usuario y la constrasenia
	arch_admin=fopen("Usuarios.dat","a+b");
	if(arch_admin==NULL)
	{
		system("CLS");
		printf("\n\n SE PRODUJO UN ERROR AL INTENTAR ABRIR EL ARCHIVO");
		system("PAUSE");
		exit(1);
	}
	//FIN DE ALTA
}

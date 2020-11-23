/*Menu Principal*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"bin\modules\functions\admin.h\"//Login,SignUp

main()
{
    system("CLS");
    int m;//Guarda el modulo proveniente del login
	arch_admin=fopen("Usuarios.dat","rb");//Se abre en modo lectura para verificar si ya existe el archivo //    bin\\modules
	printf("Bienvenido al menu principal.\n");
    printf("=============================\n");
	if(arch_admin==NULL)//Si no existe el archivo...
	{
		fclose(arch_admin);//...Lo cierra...
		system("CLS");
		printf("ES LA PRIMERA SESION, POR LO TANTO SE CREARA EL PRIMER USUARIO ADMIN\n");
		system("PAUSE");
		system("CLS");
		/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
        do{;}while(SignUp(1)==0);
        m=1;
        system("CLS");
		printf("\nPor ser primera sesion, se ejecutara el modulo de administracion para poder ingresar nuevos usuarios.");
        system("PAUSE");
        system("CLS");
		fclose(arch_admin);//...Lo cierra
    }
    else//Si existe el archivo...
    {
    	m=LogIn(arch_admin);//Se ejecuta el login
    	fclose(arch_admin);
	}
	switch(m)
    {
    	case 1:
    		printf("\nEjecutando Modulo de Administracion...");
			break;
    	case 2:
    		printf("\nEjecutando Modulo de Consultorio");
    		break;
		case 3:
			printf("\nEjecutando Modulo de ...");
			break;
		default: break;	
	};
    
}

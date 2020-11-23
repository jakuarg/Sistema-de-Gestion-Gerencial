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
	arch_admin=fopen("Usuarios.dat","r+b");//Se abre en modo lectura para verificar si ya existe el archivo //    bin\\modules
	printf("Bienvenido al menu principal.\n");
    printf("=============================\n");
	if(arch_admin==NULL)//Si no existe el archivo...
	{
		fclose(arch_admin);//...Lo cierra...
		system("CLS");
		printf("ES LA PRIMERA SESION, POR LO TANTO SE CREARA EL PRIMER Y UNICO ADMINISTRADOR\n");
		system("PAUSE");
		system("CLS");
		/****************PRIMER REGISTRO DE USUARIO ADMIN******************/
        do{printf("Primer Registro");printf("\n=======================");}while(SignUp(1)==0);
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
    		printf("\nEjecutando Modulo de Administracion...\n");
			system("start bin\\modules\\administracion.exe");
			break;
    	case 2:
    		printf("\nEjecutando Modulo de Consultorio\n");
			system("start bin\\modules\\consultorio.exe");
    		break;
		case 3:
			printf("\nEjecutando Modulo de Asistente\n");
			system("start bin\\modules\\asistente.exe");
			break;
		default: break;	
	};
    
}

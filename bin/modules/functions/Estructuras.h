
//Admin.h Estructuras
typedef char userlen[12];
typedef char passlen[34];

struct auth
{
    userlen     user;
    passlen     password;
    char        names[60];
    int         modulo;
    int         matricula;
};

//estructura de recepcion
struct fecha{

	int		 dia;
	int		 mes;
	int		 anio;

};

struct Turno
{

	int		 matricula_de_veterinario; 
	fecha	 fec;       // fecha del turno
	int		 DNI_DUENIO; // dni due�o
	char	 detalle_de_atencion[380];     //pronostico de lo que le sucede a la mascota

};

struct Datos_pet
{
	char	 Apeynom_pet[60];   // Apellido y Nombre de la mascota (El Apellido igual del dueño)
	char	 domicilio[60];
	int		 DNI_DUENIO;
	char	 localidad[60];
	fecha	 de_nacimiento;   //fecha de nacimiento de la mascota
	float	 peso; // Cantidad en kilogramos 
	char	 telefono[25];  //telefono celular/fijo del dueño
};
// Estructura de consultorio
struct documentacion{ // Documentacion del due�o del animal.

	char	Apeynom[30];
	int		dni;
	char	Localidad[20];
	char	informeMascota[380];
	bool	borrado=false;
	fecha	fec;
};

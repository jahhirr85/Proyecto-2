#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include <iostream>

using namespace std;

/***********************************************************************************************///variabes globales
int a, sc=0, db=0, ps=0, ai=0 , z=0, cp=0, ci=0; 
int lav1=0, lav2=0;
char condi[20];
string placa[100], marca[100], modelo[100], tipo[100], lavado[100]; // array para ingresar datos
float prom_lav1=0, prom_lav2=0;
float pp=0,pi=0, monto_sencillo=0, monto_doble=0, monto_pesado=0, monto_lav1=0, monto_lav2=0;


/***********************************************************************************************/
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
/***********************************************************************************************/
void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void ingresar_datos();
void hacer_graficos(int a,int y);
void graficos();
void estadisticas();
/***********************************************************************************************/

void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
/***********************************************************************************************/
void pintarfondo(int fondo, int frente) {
    int color = (fondo << 4) + frente;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

void cuadropintado(int x1, int y1, int x2, int y2, int fondocolor)
{
	int i;
	pintarfondo(fondocolor, 0);
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}
float costo()
	{
	float precio=0;
	if (tipo[z]=="SENCILLO" && lavado[z]=="SOLO LAVADO"){
		precio=3000;
		sc++; lav1++;
		monto_sencillo=monto_sencillo+precio;
		monto_lav1=monto_lav1+precio;
	}else if (tipo[z]=="SENCILLO" && lavado[z]=="LAVADO Y ENCERADO"){
		precio=5000;
		sc++; lav2++;
		monto_sencillo=monto_sencillo+precio;
		monto_lav2=monto_lav2+precio;
	}else if (tipo[z]=="4x4" && lavado[z]=="SOLO LAVADO"){
		precio=5000;
		db++; lav1++;
		monto_doble=monto_doble+precio;
		monto_lav1=monto_lav1+precio;
	}else if (tipo[z]=="4x4" && lavado[z]=="LAVADO Y ENCERADO"){
		precio=7000;
		db++; lav2++;
		monto_doble=monto_doble+precio;
		monto_lav2=monto_lav2+precio;
	}else if (tipo[z]=="MICROBUS O CAMION" && lavado[z]=="SOLO LAVADO"){
		precio=7000;
		ps++; lav1++;
		monto_pesado=monto_pesado+precio;
		monto_lav1=monto_lav1+precio;
	}else if (tipo[z]=="MICROBUS O CAMION" && lavado[z]=="LAVADO Y ENCERADO"){
		precio=12000;
		ps++; lav2++;
		monto_pesado=monto_pesado+precio;
		monto_lav2=monto_lav2+precio;
	}
	prom_lav1=monto_lav1/lav1;
	prom_lav2=monto_lav2/lav2;
	return(precio);
	}
/**********************************************************************************************/
void factura() {
	int fact=0;
	fact=z+1;
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 2);
	cuadro(2,2,50,20);
	SetConsoleTextAttribute (hConsoleHandle, 14); 
	gotoxy (3,3); cout<<" ****************** FACTURA ******************";
	gotoxy (6,6); cout << "NUMERO DE FACTURA:	0000" << fact <<endl;
	gotoxy (6,7);cout << "PLACA DEL VEHICULO:	" <<placa[z] <<endl;
	gotoxy (6,8);cout << "MARCA DEL VEHICULO:	" <<marca[z] <<endl;
	gotoxy (6,9);cout << "MODELO DEL VEHICULO:	" <<modelo[z] <<endl;
	gotoxy (6,10);cout << "TIPO DE VEHICULO:		" <<tipo[z] <<endl;
	gotoxy (6,11);cout << "TIPO DE LAVADO:		" <<lavado[z] <<endl;	
	gotoxy (6,12);cout << "PRECIO DEL LAVADO:	" << costo();
}
/***********************************************************************************************/
void ingresar_datos()
{
	char sigue, opcion1, opcion2, opcion3;
	 
	do{
		do{
		
		system("cls");
		
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(10,5,85,28);
		cuadro(33,1,65,3);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(35,02); cout<<"INGRESANDO DATOS DE VEHICULOS";
	
			
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,6); cout<<"INGRESE NUMERO DE PLACA --> ";
		cin >> placa[z];
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,8); cout<<"INGRESE MARCA DEL VEHICULO --> ";
		cin >> marca[z];
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,10); cout<<"INGRESE MODELO DEL VEHICULO --> ";
		cin >> modelo[z];
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,12); cout<<"SELECCIONE EL TIPO DE VEHICULO";
		
		cuadro(13,14,35,16);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(15,15); cout<<"[1] --> SENCILLO";
		
		cuadro(38,14,59,16);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(42,15); cout<<"[2] --> 4x4";
		
		cuadro(62,14,83,16);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(63,15); cout<<"[3] --> VEH. PESADO";
		opcion1=getch();
		
		if (opcion1=='1')
			{
				tipo[z]="SENCILLO";
				cuadropintado(13,14,35,16,2);
				
			}else if (opcion1=='2'){
				tipo[z]="4x4";
				
				cuadropintado(38,14,59,16,2);
			}else if (opcion1=='3'){
				tipo[z]="MICROBUS O CAMION";
				cuadropintado(62,14,83,16,2);
			}
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,18); cout<<"SELECCIONE EL TIPO DE LAVADO";	
		
		cuadro(13,20,35,22);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(15,21); cout<<"[1] --> SOLO LAVADO";
		
		cuadro(38,20,69,22);
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(42,21); cout<<"[2] --> LAVADO Y ENCERADO";
		
		opcion2=getch();
		if (opcion2=='1')
			{
				lavado[z]="SOLO LAVADO";
				cuadropintado(13,20,35,22,2);
			}else if (opcion2=='2'){
				lavado[z]="LAVADO Y ENCERADO";
				cuadropintado(38,20,69,22,2);
			}
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,25); cout<<"LOS DATOS SON CORRECTOS:	(S/N)";
		opcion3=getch();
		if (toupper(opcion3)=='S'){	
			factura();
		}

	}while (toupper(opcion3)=='N');
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,28); cout<<"Desea Continuar S/N";
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
	z++;	
	}while (tolower(sigue)=='s');	
}

/***********************************************************************************************/
void hacer_graficos(int a,int y)
{
int i;int j=25;
for (i=1; i<=a; i++)
	{
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}
/***********************************************************************************************/
void graficos_tipo()
{    
	system("cls");
   	cuadro (2,1,59,5);
   	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(4,3); cout<<"********** GRAFICOS SEGUN TIPO DE VEHICULO ***********";
	SetConsoleTextAttribute (hConsoleHandle, 14);
	cuadro(2,9,19,11);
	cuadro(2,12,19,14); 
	cuadro(2,15,19,17); 
	cuadro(2,19,33,21);
	
	gotoxy(4,10);	cout<<"VEH. SENCILLOS";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(sc,10);
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(4,13);	cout<<"VEH. 4x4";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(db,13);
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(4,16);	cout<<"VEH. PESADOS";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(ps,16);


	gotoxy(4,20);	cout<<"<Pulse tecla para Abandonar> ";
	getch();
}
/***********************************************************************************************/
void graficos_lavado()
	{    
	system("cls");
	cuadro (2,1,57,5);
	gotoxy(4,3); cout<<"********** GRAFICOS SEGUN TIPO DE LAVADO ***********";
	cuadro(2,9,15,11);
	cuadro(2,12,15,14);
	cuadro(2,19,33,21);
	gotoxy(4,10);	cout<<"SENCILLO";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(lav1,10);
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(4,13);	cout<<"COMPLETO";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(lav2,13);
	gotoxy(4,20);	cout<<"<Pulse tecla para Abandonar> ";
	getch();
	}

/***********************************************************************************************/
void estadisticas_tipo()
	{	
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(25,2,55,4);
	cuadro(2,8,75,12);
	cuadro(2,13,75,17);
	cuadro(2,18,75,22); 
	cuadro(25,24,56,26);
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(27,3); cout<<"*****VER ESTADISTICAS*****";             
	gotoxy(4,9);  cout<<"CANTIDAD DE VEHICULOS TIPO SENCILLO:	" <<sc;
	gotoxy(4,11); cout<<"DINERO RECAUDADO:				" << monto_sencillo;
	gotoxy(4,14);  cout<<"CANTIDAD DE VEHICULOS TIPO 4x4:		" <<db;
	gotoxy(4,16); cout<<"DINERO RECAUDADO:				" <<monto_doble;
	gotoxy(4,19); cout<<"CANTIDAD DE VEHICULOS TIPO VEH. PESADO:	" <<ps;
	gotoxy(4,21); cout<<"DINERO RECAUDADO:				"<<monto_pesado;
	
	gotoxy(27,25); cout<<"<Pulse tecla para Abandonar>";
	getch();
	}

/***********************************************************************************************/
void estadisticas_lavado()
	{
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(25,2,55,4);
	cuadro(2,8,75,14);
	cuadro(2,15,75,21);
	cuadro(25,24,56,26); 
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(27,3); cout<<"*****VER ESTADISTICAS*****";             
	gotoxy(4,9);  cout<<"CANTIDAD DE VEHICULOS CON SOLO LAVADO:		" <<lav1;
	gotoxy(4,11); cout<<"DINERO RECAUDADO:					" <<monto_lav1;
	gotoxy(4,13); cout<<"PROMEDIO DE DINERO:					" <<prom_lav1;
	
	gotoxy(4,16);  cout<<"CANTIDAD DE VEHICULOS CON LAVADO y ENCERADO:	" <<lav2;
	gotoxy(4,18); cout<<"DINERO RECAUDADO:					" <<monto_lav2;
	gotoxy(4,20); cout<<"PROMEDIO DE DINERO:					" <<prom_lav2;
	
	
	gotoxy(27,25); cout<<"<Pulse tecla para Abandonar>";
	getch();
	}
/***********************************************************************************************/

void menu()

{
	char opc,conti;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6); //primer cuadro de arriba hacia abajo
		cuadro(8,8,72,23);//grande
		cuadro(8,24,72,26); //cuadro de abajo opcion es
		cuadro(15,20,27,22); //cuadro peque o salir
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(22,4);cout<<"	     ******* LAVACAR *******";
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);cout<<"[1]  INGRESAR DATOS VEHICULOS";
		gotoxy(15,12);cout<<"[2]  ESTADISTICAS LAVADOS SEGUN TIPO DE VEHICULO";
		gotoxy(15,14);cout<<"[3]  ESTADISTICAS LAVADOS SEGUN TIPO DE LAVADO";
		gotoxy(15,16);cout<<"[4]  GRAFICOS LAVADOS SEGUN TIPO DE VEHICULO";
		gotoxy(15,18);cout<<"[5]  GRAFICOS LAVADOS SEGUN TIPO DE LAVADO";
		gotoxy(16,21);cout<<"<[6] SALIR>";
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);cout<<"Su opcion es: ";
		opc=getch();

		switch(opc)
			{
			case '1': ingresar_datos();break;
			case '2': estadisticas_tipo(); break;
			case '3': estadisticas_lavado(); break;
			case '4': graficos_tipo(); break;
			case '5': graficos_lavado(); break;
			case '6': 
				
			system("cls");
			gotoxy(20,10);cout<<"Estas seguro Que Deseas Salir del Sistema";
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);cout<<"Desea Continuar S/N";
			conti=getch();

			if (conti=='N' || conti=='n')
			menu();
			else if (conti=='S' || conti=='s')
			break; 
			}
		}while(opc!='6');
}
/********************************************************************************************/

int main(int argc, char** argv) {
	menu();
	return 0;
}

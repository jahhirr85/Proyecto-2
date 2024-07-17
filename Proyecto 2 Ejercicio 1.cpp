#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdio.h>
#include<locale.h>

using namespace std;

// variables globales
const int YEAR=2024;
int sc=0, db=0, ps=0;
string cedula[100], nombre[100];
int z=0, year[100], mate[100], espa[100], ciencias[100], est[100], nota[100];
int edad=0, promedioc=0, promediocc=0, porcentajeadd=0, promedioadd=0, admitido=0, espera=0, noadm=0;
/*******************************************************/
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
/********************************/
void resultados();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void hacer_graficos();
/*******************************/
void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
/*******************************/
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

/*******************************/
void ingresodatos()
{
	
	char opcion1, sigue;
	
	do{
		
		do{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(10,5,100,28);
		cuadro(33,1,80,3);
		SetConsoleTextAttribute (hConsoleHandle, 15);	
       gotoxy(40,02); cout << " Ingrese los Datos del estudiante:	" <<endl;
     	
     	
 	   SetConsoleTextAttribute (hConsoleHandle, 15);
	   gotoxy(12,6); cout << " Ingrese la cedula del estudiante:	" ;
 	   cin >> cedula[z];
	
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,8);cout << " Ingrese el nombre del estudiante:	";
    	cin >> nombre[z];
		setlocale(LC_CTYPE,"spanish");
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,10);cout << " Ingrese el año de nacimiento del estudiante:  " ;
       cin >> year[z];
		setlocale( LC_ALL, "C" );
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,12);cout << " Ingrese los promedios finales de las siguientes materias del estudiante:	" ;
	
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,14);cout << " Matematicas:	" ;
	   cin >> mate[z];

	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,16);cout << " Espanol:		";
	   cin >> espa[z];

	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,18);cout << " Ciencias:		";
	   cin >> ciencias[z];

	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,20);cout << " Estudios sociales:	" ;
	   cin >> est[z];

	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,22);cout << " Nota del examen de admision de la UTC:	";
	   cin >> nota[z];
	
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,25);cout << "LOS DATOS SON CORRECTOS:	(S/N)";
	   opcion1=getch();
	    if (toupper(opcion1)=='S'){
           resultados();
	    }
	 
	 }while (toupper(opcion1)=='N');
	    do{
	       SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,28);cout<<"Desea Continuar S/N";
	       sigue=getch();
	       
	    }while (toupper(sigue)!='S' && toupper(sigue)!='N');
    }while (tolower(sigue)=='s');
}	

int promedioad()
{
	promedioadd = promediocc + porcentajeadd;
	return(promedioadd);
}

int porcentajead()
{
	porcentajeadd = nota[z] * 0.60;
	return(porcentajeadd);
}

int porcentajecc()
{
	promediocc = promedioc * 0.40;
	return(promediocc);
}

int promediocole()
{
	promedioc = mate[z] + espa[z] + ciencias[z] + est[z];
	promedioc = promedioc / 4;
	return (promedioc);
}

int Edad()
{
	edad=YEAR-year[z];
	return(edad);
}
   
   void calificacion()
   {
   	if (promedioadd>=85){
   		cout << "El estudiante esta admitido" <<endl;
   		admitido = admitido + 1;
   		sc++;
	   }else if (promedioadd>=75 && promedioadd<85){
	   	cout << "El estudiante esta en espera" <<endl;
	   	db++;
	   	espera = espera + 1;
	   }else if (promedioadd<75){
	   	cout << "El estudiante NO esta admitido" <<endl;
	   	noadm = noadm + 1;
	   	ps++;
	   }
   }



void resultados()
{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 2);
	cuadro(2,2,80,20);
	SetConsoleTextAttribute (hConsoleHandle, 14); 
	gotoxy (25,3); cout << "****** Resultados del Estudiante ******" <<endl;
	
	gotoxy (4,6); cout << " Cedula del estudiante:.........................." << cedula[z] <<endl;
	gotoxy (4,7); cout << " Nombre del estudiante:.........................." << nombre[z] <<endl;
	setlocale(LC_CTYPE,"spanish");
	gotoxy (4,8); cout << " Año de nacimiento del estudiante:..............." << year[z] <<endl;
	setlocale( LC_ALL, "C" );
	gotoxy (4,9); cout << " Edad del estudiante:............................" << Edad() <<endl; // 
	gotoxy (4,10); cout << " Promedios de las materias del estudiante" <<endl;
	gotoxy (4,11); cout << " Matematicas:...................................." << mate[z] <<endl;
	gotoxy (4,12); cout << " Espanol:........................................" << espa[z] <<endl;
	gotoxy (4,13); cout << " Ciencias:......................................." << ciencias[z] <<endl;
	gotoxy (4,14); cout << " Estudios sociales:.............................." << est[z] <<endl;
	gotoxy (4,15); cout << " Promedio colegio del estudiante:................" << promediocole() <<endl;
	gotoxy (4,16); cout << " Porcentaje criterio colegio del estudiante:....." << porcentajecc(); cout<<"%"<<endl;
	gotoxy (4,17); cout << " Porcentaje Examen admision del estudiante:......" << porcentajead() cout<<"%"<<endl;
	gotoxy (4,18); cout << " Promedio admision del estudiante:..............." << promedioad() cout<<"%"<<endl;
    gotoxy (4,19); cout << " Calificacion del estudiante:	"; calificacion();	
}

void estadisticas()
{
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(25,2,80,4);
	cuadro(2,8,75,12);
	cuadro(2,13,75,17);
	cuadro(2,18,75,22); 
	cuadro(25,24,56,26);
	
	
    SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(27,3); cout<<"**** Estadisticas de los estudiantes ingresados ****";  
	           
	gotoxy(4,9); cout<<"Cantidad de estudiantes admitidos: " <<admitido;
	gotoxy(4,11); cout<<"Promedio de estudiantes admitidos: " <<admitido;
	
	gotoxy(4,14); cout<<"Cantidad de estudiantes en espera: " <<espera;
	gotoxy(4,16); cout<<"Promedio de estudiantes en espera: " <<espera;
	
	gotoxy(4,19); cout<<"Cantidad de estudiantes NO admitidos: " <<noadm;
	gotoxy(4,21); cout<<"Promedio de estudiantes NO admitidos: " <<noadm;
	
	gotoxy(27,25); cout<<"<Pulse tecla para Abandonar>";
	getch();
}

void hacer_graficos(int a,int y)
{
int i;int j=25;
for (i=1; i<=a; i++)
	{
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}

void grafico()
{    
	system("cls");
    cuadro (2,1,59,5);
   	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(4,3); cout<<" Graficos de estudiantes segun sus calificaciones ";
	SetConsoleTextAttribute (hConsoleHandle, 14);
	cuadro(2,9,19,11);
	cuadro(2,12,19,14); 
	cuadro(2,15,19,17); 
	cuadro(2,19,33,21);
	
	gotoxy(4,10);	cout<<" Admitidos ";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(sc,10);
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(4,13);	cout<<" En espera ";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(db,13);
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(4,16);	cout<<" NO admitidos ";
	SetConsoleTextAttribute (hConsoleHandle, 10);
	hacer_graficos(ps,16);


	gotoxy(4,20);	cout<<"<Pulse tecla para Abandonar> ";
	getch();
}

menu()
{
	char opc,conti;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6); 
		cuadro(8,8,72,23);
		cuadro(8,24,72,26); 
		cuadro(15,20,27,22); 
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(28,4);printf(" Ingreso de estudiantes ");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);printf("[1]  Ingresar datos del estudiante ");
		gotoxy(15,12);printf("[2]  Estadisticas de los estudiantes ingresados");
		gotoxy(15,14);printf("[3]  Grafico de estudiantes segun sus calificaciones");
		gotoxy(16,21);printf("<[4] Salir>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);printf("Su opcion es: ");
		opc=getch();

		switch(opc)
			{
			case '1': ingresodatos();break;
			case '2': estadisticas(); break;
			case '3': grafico(); break;
			case '4': 
				
			system("cls");
			gotoxy(20,10);printf("Estas seguro Que Deseas Salir del Sistema");
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);printf("Desea Continuar S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
			menu();
			else if (conti=='S' || conti=='s')
			break; 
			}
		}while(opc!='4');
}

int main(int argc, char** argv) {
menu();
	return 0;
}

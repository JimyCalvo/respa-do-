#include <iostream>
#include <fstream>
#include <iomanip>
#include "Archivos/ordenamiento.h"
#include "Archivos/busqueda.h"
#define globalTam 1240
using namespace std;

/*
PROGRAMA DESARROLLADO POR:
> Raúl Tenorio
> Leonel Molina
> Manuel Auqui
> Jimy Calvo
> Jhael Nicolalde
*/

void menu();
int lecturaSolucion(int op);
void mostrarArchivo(string nombreArchivo);
string fixespacio(string palabra, int max);

int main() {
  fstream archivo;
  string usuarioLogin, passwordLogin, confirmarPassword;
  string usuario, password, nombre, apellido, telf;
  bool correcto = false;
  int numlineas = 0;
  int op;
  do
  {
    cout<<"\n\t\t[SISTEMA]\n"<<endl;
    cout<<"1. Ingresar"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Ingrese una opción: ";
    cin>>op;
    lecturaSolucion(op);
    switch(op)
    {
      case 1:
      {
        cout<<"\n\t[INGRESO]"<<endl;
        cout<<"Usuario: ";
        getline(cin, usuarioLogin);
        cout<<"Contraseña: ";
        getline(cin, passwordLogin);
        archivo.clear();
        archivo.open("Archivos/login.txt", ios::in);
        if (archivo.fail()) 
        {
          cout << "\nNO SE HA REGISTRADO NINGÚN USUARIO\n";
        } 
        else 
        {
          while(!archivo.eof()) 
          {
            getline(archivo, usuario);
            getline(archivo, password);
            numlineas++;
            if (usuario == usuarioLogin && password == passwordLogin) {
                correcto = true;
                break;
            }
          }
          archivo.close();
          if (correcto == false)
            cout << "\nUsuario y/o contraseña incorrectos.\n";
          else
            menu();
          if (numlineas == 0)
            cout << "\nARCHIVO VACÍO!\n";
        }
        archivo.close();
      }
      break;
      case 2:
      {
        cout<<"\n\t[REGISTRO]"<<endl;
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"Apellido: ";
        cin>>apellido;
        cout<<"Numero de teléfono: ";
        cin>>telf;
        cout<<"Usuario: ";
        cin>>usuario;
        cout<<"Contraseña: ";
        cin>>password;
        cout<<"Confirmar contraseña: ";
        cin>>confirmarPassword;
        if(password!=confirmarPassword)
        {
          do
          {
            cout<<"\nConfirmación incorrecta!"<<endl;
            cout<<"Vuelva a ingresar su contraseña: ";
            cin>>confirmarPassword;
          }
          while(password!=confirmarPassword);
        }
        cout<<"\n\tUSUARIO REGISTRADO!"<<endl;
        // Escritura
        archivo.clear();
        archivo.open("Archivos/login.txt", ios::out);
        archivo << usuario << "\n" << password << "\n";
        archivo.close();
        // Registro
        archivo.clear();
        archivo.open("Usuario.txt", ios::out);
        archivo << "NOMBRE: " <<nombre<<" "<<apellido<<endl;
        archivo << "TELÉFONO: "<<telf<<endl;
        archivo << "USUARIO: " << usuario <<endl;
        archivo << "PASSWORD: " << password <<endl;
        archivo.close();
      }
      break;
      case 3:
      {
       cout<<"\nSaliendo..."<<endl;
      }
      break;
      default:
      cout<<"\nEsta opción no existe!\nPor favor, vuelva a ingresar."<<endl;
      break;
    }
  }
  while(op!=3);
}

void menu()
{
  int op=0, numEstudiantes=0, numNotas=0, i, j, aprobados=0, suspenso=0, reprobados=0, ordenamiento=0;
  string docente, cedula, materia;
  string nombre[globalTam], apellido[globalTam], correo[globalTam];  
  float notas[globalTam][globalTam], promedioEstudiante[globalTam], notasCurso, promedioCurso, notasEstudiante;
  ofstream archivoEscritura;
  do
  {
    cout<<"\n\t\t  [BIENVENIDO]"<<endl;
    cout<<"\n\tGESTIÓN DE CALIFICACIONES\n"<<endl;
    cout<<"1. Ingresar datos del docente"<<endl;
    cout<<"2. Ingresar materia"<<endl;
    cout<<"3. Ingresar el número de estudiantes y rango de notas"<<endl;
    cout<<"4. Ingresar notas por estudiante"<<endl;
    cout<<"5. Ver reporte de calificaciones"<<endl;
    cout<<"6. Ordenar calificaciones"<<endl;
    cout<<"7. Ver registro de calificaciones ordenadas"<<endl;
    cout<<"8. Buscar calificación"<<endl;
    cout<<"9. Cerrar Sesión"<<endl;
    cout<<"Ingrese una opción: ";
    cin>>op;
    lecturaSolucion(op);
    switch(op)
    {
      case 1:
      {
        cout<<"\n[DATOS DEL DOCENTE]\n";
        cout<<"Ingrese su nombre y apellido: ";
        getline(cin, docente);
        cout<<"Ingrese su número de cédula: ";
        getline(cin, cedula);
      }
      break;
      case 2:
      {
        cout<<"\n[MATERIA]\n";
        cout<<"Ingrese la materia: ";
        getline(cin, materia);
      }
      break;
      case 3:
      {
        cout<<"\n[RANGOS]\n";
        cout<<"Ingrese el número de estudiantes: ";
        cin>>numEstudiantes;
        cout<<"Ingrese el número de notas a registrar: ";
        cin>>numNotas;
      }
      break;
      case 4:
      {
        //INGRESO DE NOTAS Y CÁLCULO DEL PROMEDIO
        cout<<"\n[ESTUDIANTES]\n";
        for(i=0;i<numEstudiantes;i++)
        {
          cout<<"\nESTUDIANTE N°"<<i+1<<endl;
          cout<<"Ingrese el nombre del estudiante: ";
          getline(cin,nombre[i]);
          cout<<"Ingrese el apellido del estudiante: ";
          getline(cin,apellido[i]);
          cout<<"Ingrese el correo del estudiante: ";
          getline(cin,correo[i]);
          notasEstudiante= 0;
          for(j=0;j<numNotas;j++)
          { 
            cout<<"Ingrese nota N°"<<j+1<<" : ";
            cin>>notas[i][j];
            notasEstudiante+=notas[i][j];
          }
          promedioEstudiante[i]=notasEstudiante/numNotas;
          if(promedioEstudiante[i]<=20 && promedioEstudiante[i]>=14)
          {
            aprobados++;
          }
          else if (promedioEstudiante[i]<13 && promedioEstudiante[i]>=9)
          {
            suspenso++;
          }
          else if (promedioEstudiante[i]<=8 && promedioEstudiante[i]>=1)
          {
            reprobados++;
          }
          notasCurso+=promedioEstudiante[i];
          cin.ignore();
        }
        promedioCurso=notasCurso/numEstudiantes;
        //CREACIÓN DEL ARCHIVO DE REGISTRO
        archivoEscritura.open("Colegio/Calificaciones.txt",ios::out);
        archivoEscritura<<"\n\t\t\t\t\t\t\t  ESCUELA POLITÉCNICA NACIONAL\n";
        archivoEscritura<<"\t\t\t\t\t\t\t\tREPORTE DE CALIFICACIONES\n";
        archivoEscritura<<"Año electivo: 2020-2021\n";
        archivoEscritura<<"Materia: "<<materia<<endl<<endl;
        //SUBTITULOS
        archivoEscritura << fixespacio("N°", 1) << fixespacio("Estudiante", 4) << fixespacio("Apellido", 4) << fixespacio("Correo", 8);
        for(j=0;j<numNotas;j++)
        {
          archivoEscritura<<fixespacio("Nota " + to_string(j+1), 2);
        }
        archivoEscritura << "Total" << endl;
        //REGISTRO
        for(i=0;i<numEstudiantes;i++)
        {
          archivoEscritura << fixespacio(to_string(i+1), 1) << fixespacio(nombre[i], 4) << fixespacio(apellido[i], 4) << fixespacio(correo[i], 8);
          for(j=0;j<numNotas;j++)
          {
            archivoEscritura << fixed << setprecision(2) << notas[i][j] << "\t";
          }
          archivoEscritura << fixed << setprecision(2) << promedioEstudiante[i] << endl;
        }

        archivoEscritura<<"\nRESUMEN"<<endl;
        archivoEscritura<<"Promedio del curso: "<<fixed<<setprecision(2)<<promedioCurso<<endl<<endl;
        archivoEscritura<<"      │ \t\t\t\t\t\tAprobados(14-20)\t\t\t\t\t\t"<<aprobados<<endl;
        archivoEscritura<<"TOTAL │ \t\t\t\t\t\tSuspenso(9-13)  \t\t\t\t\t\t"<<suspenso<<endl;
        archivoEscritura<<"      │ \t\t\t\t\t\tReprobados(1-8) \t\t\t\t\t\t"<<reprobados<<endl;
        archivoEscritura<<"\n\t\t\t\t\t\t\t\t  Docente"<<endl;
        archivoEscritura<<"\t\t\t\t\t\t\t\t"<<docente<<endl;
        archivoEscritura<<"\t\t\t\t\t\t\t\t "<<cedula<<""<<endl;
        archivoEscritura.close();
      }
      break;
      case 5:
      {
        mostrarArchivo("Colegio/Calificaciones.txt");
      }
      break;
      case 6:
      {
        cout<<"\n[ORDENAMIENTO]\n";
        cout<<"1. Ordenamiento Burbuja (Bubblesort)\n";
        cout<<"2. Ordenamiento por Selección\n";
        cout<<"3. Ordenamiento por Insercción\n";
        cout<<"4. Ordenamiento Rápido (Quicksort)\n";
        cout<<"5. Ordenamiento por Mezcla (MergeSort)\n";
        cout<<"\nIngrese el tipo de ordenamiento que desea realizar: ";
        cin>>ordenamiento;
        lecturaSolucion(ordenamiento);
        switch (ordenamiento)
        {
          case 1:
          {
            ordenarBurbuja(promedioEstudiante,numEstudiantes);  
          }
          break;
          case 2:
          {
            ordenarSeleccion(promedioEstudiante,numEstudiantes);
          }
          break;
          case 3:
          { 
          }
          break;
          case 4:
          { 
          }
          break;
          case 5:
          { 
          }
          break;
          default:
          {
            cout<<"\nEsta opción no existe!\n"<<endl;
          }
          break;
        }
      }
      break;
      case 7:
      {

      }
      break;
      case 8:
      {

      }
      break;
      case 9:
      {
        cout<<"\nHASTA PRONTO!"<<endl;
      }
      break;
      default:
      cout<<"\nEsta opcion no existe!\nPor favor, vuelva a ingresar."<<endl;
      break;
    }
  }
  while(op!=9);
}

int lecturaSolucion(int op)
{
  int opc;
  if (cin.fail() || cin.get() != '\n')
  {
    cin.clear();
    while (cin.get() != '\n');
    opc = -1;
  }
  return op;
}

void mostrarArchivo(string nombreArchivo)
{
  ifstream archivoLectura;
  string texto;
  archivoLectura.open(nombreArchivo,ios::in);
  if (archivoLectura.fail())
  {
    cout<<"\nEL ARCHIVO NO SE PUDO ABRIR\n";
  }
  else 
  {
    while(!archivoLectura.eof())
    {
      getline(archivoLectura,texto);
      cout<<texto<<endl;
    }
  }
  archivoLectura.close();
}

string fixespacio(string palabra, int max)
{
  max *= 4;
  string espacios = "";
  if (max > palabra.length())
  {
    int tabs = ((max - palabra.length() + 3) / 4);
    for (int i=0; i<tabs; i++)
    {
      espacios += "\t";
    }
  }
  return (palabra + espacios);
}
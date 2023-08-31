#include <iostream>
#include <iomanip>

using namespace std;
//---FUNCIONES---
void altas();
void inventario();
void consultas();
int buscar(string nombre_tp);

//---VARIABLES GLOBALES---
string nombre_p[100] = {"leche","pan","agua","refresco","huevos"};
string usuario1 = "victor";
string pass_usuario1 = "3826";
string usuario2 = "univa";
string pass_usuario2 = "1234";
string usuario;
string password;
float precio_cp[100] = {12.35, 5.5, 13.39, 10.99, 22.40};
float precio_vp[100] = {15.5, 7.95, 18.55, 14.75, 30.39};
int id_p[100] = {2,4,1,5,3};
int existencias_p[100] = {16, 18, 12, 30, 20};
int reorden_p[100] = {5, 6, 4, 8, 7};
int estatus_p[100] = {1, 1, 0, 1, 1};
int total = 5;
bool user_pass = true;


//---MENU---
int main(){
  int opcion;
    do{ 
      
      cout<<endl<<"Por favor ingrese su nombre de usuario:  ";
      cin>>usuario;
      cout<<"Por favor ingrese su contraseña:  ";
      cin>>password;
      cout<<endl;
    
      if (usuario == usuario1  && password == pass_usuario1 ){
        cout<<"---Bienvenido al menú de administrador---"<<endl;
        user_pass = true;
        }
      else if (usuario == usuario2 && password == pass_usuario2){
        cout<<"---Bienvenido al menú de administrador---"<<endl;
        user_pass = true;
      }
      else {
        cout<<"¡Usuario o contraseña incorrecta! Por favor intentelo nuevamente"<<endl;
        user_pass = false;
        }
      
    } while (user_pass == false);
    do{
        cout<<endl<<"Menu"<<endl;
        cout<<"1.- Altas"<< endl;
        cout<<"2.- Inventario"<<endl;
        cout<<"3.- Consultas"<<endl; 
        cout<<"4.- Salir"<<endl;
        cout<<"Elige una opcion: ";
        cin>>opcion;
        cout<<endl;
      
        switch(opcion){
            case 1: altas();
            break;
            case 2: inventario();
            break;
            case 3: consultas();
            break;
            case 4:
                cout <<"---Cerrando sistema---"<<endl;
            break;
            default: 
                cout<<"Opcion invalida, por favor ingresa una opcion del menú"<<endl;
        }    
    }while(opcion != 4);

	return 0;
}

//---FUNCION DE ALTAS---
void altas(){
  int opcion;
  int i = total;
  int found;
  int existencias_tp;
  int reorden_tp;
  string nombre_tp;
  float precio_cpt;
  float precio_vpt;
  
  cout<<"---Sistema de Altas---"<<endl;

  do{
    cout<<"Escribe el nombre del producto: ";
		cin>>nombre_tp;
    found = buscar(nombre_tp);
    if (found == -1) {
      nombre_p[i] = nombre_tp;
      cout<<"Escribe el ID del producto: ";
		  cin>>id_p[i];
      do {
  		  cout<<"Escribe el precio de compra del producto: ";
    		cin>>precio_cpt; 
        cout<<"Escribe el precio de venta del producto: ";
        cin>>precio_vpt;
        if (precio_cpt >= precio_vpt)
          cout<<"El precio de compra debe ser menor al precio de venta, intente nuvamente "<<endl;
      } while (precio_cpt >= precio_vpt);
      precio_cp[i] = precio_cpt;
      precio_vp[i] = precio_vpt;
      do {
        cout<<"Escribe el numero de existencias del producto: ";
        cin>>existencias_tp;
        cout<<"Escribe el nivel de reorden: ";
        cin>>reorden_tp;
        if (reorden_tp >= existencias_tp)
            cout<<"El número de existencias debe ser mayor al número de reorden, intente nuvamente "<<endl;
      } while (reorden_tp >= existencias_tp);
      reorden_p[i] = reorden_tp;
      existencias_p[i] = existencias_tp;
      estatus_p[i] = 1;
      i++;
    }
    else {
      cout<<"Producto ya existente"<<endl<<endl;
    }
    cout<<endl<<"¿Desea agregar otro producto?   (1)SI ó (2)NO"<<endl;
    cout<<"Elija opción:  ";
    cin >> opcion; 
    cout<<endl;
  }while(opcion == 1);
    total = i;
}


//---FUNCION DE BUSCAR EN ALTAS---
int buscar(string nombre_tp) {
  int i = 0;
  while (i<total && nombre_p[i]!=nombre_tp)
    i++;
  if (i==total)
    return -1;
  else 
    return 1;
}

//--FUNCION DE MOSTRAR---
void inventario(){
  int i;
  cout<<"---Inventario---"<<endl<<endl;
  cout<<setw(10)<<"Producto"<<setw(12)<<"ID"<<setw(12)<<"Precio C"<<setw(12)<<"Precio V"<<setw(10)<<"Existencias"<<setw(7)<<"NR"<<setw(10)<<"Estatus"<<endl;
  for(i=0; i < total; i++){
    if (estatus_p[i] == 1){
      cout<<setw(10)<<nombre_p[i]<<setw(10)<<id_p[i]<<setw(10)<<precio_cp[i]<<setw(15)<<precio_vp[i]<<setw(10)<<existencias_p[i]<<setw(10)<<reorden_p[i]<<setw(10)<<estatus_p[i]<<endl;
    }
  }
}

//---FUNCION DE CONSULTAS---
void consultas (){
  string nombre_tp;
  int found;
  int i = 0;
  int ret = 1;
  int opcion = 0;

  cout<<endl<<"---Sistema de consultas---"<<endl<<endl;
  do{
    cout<<"¿Qué producto desea buscar?  ";
    cin>>nombre_tp;
    i=0;
    opcion = 0;
    while (i<total && nombre_p[i]!=nombre_tp)
      i++;
    if (i==total){
      cout<<"No se encontró el producto, intente nuevamente"<<endl;
      cout<<"¿Desea buscar otro producto?   (1)SI ó (2)NO"<<endl;
      cout<<"Elija opción:  ";
      cin >> opcion; 
      }
    else {
      cout<<nombre_p[i]<<"  "; 
      cout<<id_p[i]<<"  "; 
      cout<<"$"<<precio_cp[i]<<"  ";
      cout<<"$"<<precio_vp[i]<<"  ";
      cout<<existencias_p[i]<<"  ";
      cout<<reorden_p[i]<<"  ";
      cout<<estatus_p[i]<<"  "<<endl<<endl;
      cout<<"¿Desea buscar otro producto?   (1)SI ó (2)NO"<<endl;
      cout<<"Elija opción:  ";
      cin >> opcion; 
      cout<<endl;
    }
  } while (opcion == 1);
  
}
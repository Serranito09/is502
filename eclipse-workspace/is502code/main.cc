#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main()
{
    int tecla;
    int opcion;
    bool repetir = true;
    
    do {
        
        // Texto del menú que se verá cada vez
        cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
        cout << "1. VER CURSOS" << endl;
        cout << "2. AÑADIR CURSOS" << endl;
        cout << "3. ELIMINAR CURSOS" << endl;
        cout << "4. INSCRIPCIÓN EN CURSOS" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
         system("clear");
        
        switch (opcion) {
            case 1:   
              cout << "\n\nCURSOS DE EXTENSIÓN" << endl;          
                //FUNCION DE MOSTRAR CURSOS
                 cout << "0. SALIR" << endl;
                cout << "\nIngrese una opcion: ";
                cin>>tecla;
                if(tecla==0){
                break;
                }
                
            case 2:
              cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
               //funcion de añadir cursos
                 cout << "0. SALIR" << endl;
                cout << "\nIngrese una opcion: ";
                cin>>tecla;
                if(tecla==0){
                break;
                }
                
            case 3:
              cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
                //eliminar cursos
                 cout << "0. SALIR" << endl;
                cout << "\nIngrese una opcion: ";
                cin>>tecla;
                  system("clear");
                if(tecla==0){
                break;
                }
                
            case 4:
              cout << "\n\nCURSOS DE EXTENSIÓN" << endl;
                //funcion de inscribir en cursos               
                 cout << "0. SALIR" << endl;
                cout << "\nIngrese una opcion: ";
                cin>>tecla;
                  system("clear");
                if(tecla==0){
                break;
                }
            
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	 
    return 0;
}
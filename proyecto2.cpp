#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct  Ciudad{
    string nombre;
};

void carciudades(const string& ciudades, unordered_map<string, int>& mapaCiudades, vector<Ciudad>& ciu) {
    ifstream archivo(ciudades);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    // Variables para leer líneas del archivo
    string linea;
    int indice = 0;

    // Leer y validar la primera línea (títulos de las columnas)
    if (getline(archivo, linea)) {
        // Validar el formato de la primera línea (en este ejemplo, solo texto)
        // Puedes agregar más validaciones según tus necesidades
        for (char c : linea) {
            if (!isalpha(c) && !isspace(c)) {
                cerr << "Error de formato en la primera línea." << endl;
                archivo.close();
                return;
            }
        }
    } else {
        cerr << "Error: El archivo está vacío." << endl;
        archivo.close();
        return;
    }

    // Leer el resto del archivo
    while (getline(archivo, linea)) {
        // Validar el formato de la línea (en este ejemplo, solo texto)
        // Puedes agregar más validaciones según tus necesidades
        for (char c : linea) {
            if (!isalpha(c) && !isspace(c)) {
                cerr << "Error de formato en la línea." << endl;
                archivo.close();
                return;
            }
        }

        // Agregar la ciudad al mapa y al vector
        Ciudad ciudad;
        ciudad.nombre = linea;
        mapaCiudades[linea] = indice;
        ciu.push_back(ciudad);

        // Incrementar el índice
        indice++;
    }

    // Cerrar el archivo
    archivo.close();
}

void cargarciudad(){
  unordered_map<string, int> mapaCiudades;

   
                 vector<Ciudad> ciu;

    
                string ciudades = "ciudades.txt";

    
    carciudades(ciudades, mapaCiudades, ciu);
    cout << "Lista de Ciudades:" << endl;
    for (const auto& ciudad : ciu) {
    cout << "Nombre: " << ciudad.nombre << ", Índice: " << mapaCiudades[ciudad.nombre] << endl; 
}

}



struct Guardian {
    string name;
    int PowerLevel;
    Ciudad city;
    string Master;
    vector<Guardian> Aprendices;  
};

void cargarYValidarGuardianes(const string& guardianes, const unordered_map<string, int>& mapaCiudades, vector<Guardian>& guar) {
    ifstream archivo(guardianes);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    // Variables para leer líneas del archivo
    string linea;

    // Leer el resto del archivo
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        Guardian guard;
        ss >> guard.PowerLevel;

        
        ss >> guard.name;

        
        ss >> guard.city.nombre;

        
        if (mapaCiudades.find(guard.city.nombre) == mapaCiudades.end()) {
            cerr << "Error: El guardián vive en una ciudad que no existe." << endl;
            archivo.close();
            return;
        }

        // Leer el nombre del maestro
        ss >> guard.Master;

        // Agregar el guardián al vector
        guar.push_back(guard);
    }

    // Cerrar el archivo
    archivo.close();
}




int main() {
    int opcion;

    do {
        // Mostrar el menú
        cout << "----- Menu -----" << endl;
        cout << "1. Descubrir mapa" << endl;
        cout << "2. Viajar" << endl;
        cout << "3. Batalla" << endl;
        cout << "4. ver candidatos" << endl;
        cout << "5. Salir" << endl;

        // Solicitar la elección al usuario
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        // Validar la opción utilizando un switch
        switch(opcion) {
            case 1:
                cout << "Has seleccionadoi descubrir mapa" << endl;
                cargarciudad;
                break;
            case 2:
                cout << "Has seleccionado viajar." << endl;
                
                break;
            case 3:
                cout << "Has seleccionado batalla." << endl;
            
                break;

             case 4:
                cout << "has seleccionado ver candidatos" << endl;
            
                break;
            case 5:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
        }

        
    } while(opcion != 5);

    return 0;
}
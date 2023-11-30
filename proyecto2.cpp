#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

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

class Grafo {
public:
    void agregarArista(const Ciudad& ciudad1, const Ciudad& ciudad2);
    void imprimirGrafo();

private:
    unordered_map<string, list<string>> listaAdyacencia;
};

void Grafo::agregarArista(const Ciudad& ciudad1, const Ciudad& ciudad2) {
    listaAdyacencia[ciudad1.nombre].push_back(ciudad2.nombre);
    listaAdyacencia[ciudad2.nombre].push_back(ciudad1.nombre);
}

void Grafo::imprimirGrafo() {
    for (const auto& ciudad : listaAdyacencia) {
        cout << "Ciudad: " << ciudad.first << " -> Conectada con: ";
        for (const auto& vecina : ciudad.second) {
            cout << vecina << " ";
        }
        cout << endl;
    }
}

void cargarciudad(){
  unordered_map<string, int> mapaCiudades;

   
                 vector<Ciudad> ciu;

    
                string ciudades = "ciudades.txt";

    
    carciudades(ciudades, mapaCiudades, ciu);
    cout << "Lista de Ciudades:" << endl;
    for (const auto& ciudad : ciu) {
    cout << "Nombre: " << ciudad.nombre << ", Índice: " << mapaCiudades[ciudad.nombre] << endl; 

    Grafo grafo;

    // Imprimir el grafo
    grafo.imprimirGrafo();

    
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

struct TreeNode {
    Guardian guardian;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Guardian& g) : guardian(g), left(nullptr), right(nullptr) {}
};

class GuardianRankingTree {
public:
    // Funciones del árbol
    void insertarGuardian(const Guardian& guardian);
    void imprimirRanking();

private:
    // Funciones auxiliares
    void insertarGuardianRec(TreeNode*& root, const Guardian& guardian);
    void imprimirRankingRec(TreeNode* root, int& contador);
    void liberarMemoria(TreeNode* root);

    // Raíz del árbol
    TreeNode* raiz = nullptr;
};

void GuardianRankingTree::insertarGuardian(const Guardian& guardian) {
    insertarGuardianRec(raiz, guardian);
}

void GuardianRankingTree::insertarGuardianRec(TreeNode*& root, const Guardian& guardian) {
    if (root == nullptr) {
        root = new TreeNode(guardian);
    } else if (guardian.PowerLevel <= root->guardian.PowerLevel) {
        insertarGuardianRec(root->left, guardian);
    } else {
        insertarGuardianRec(root->right, guardian);
    }
}

void GuardianRankingTree::imprimirRanking() {
    int contador = 1; // Contador para el ranking
    imprimirRankingRec(raiz, contador);
}

void GuardianRankingTree::imprimirRankingRec(TreeNode* root, int& contador) {
    if (root != nullptr) {
        // Imprimir nodos en orden inverso para tener el ranking desde el mayor al menor
        imprimirRankingRec(root->right, contador);
        cout << "Ranking #" << contador << ": " << root->guardian.name << " (Poder: " << root->guardian.PowerLevel << ")" << endl;
        contador++;
        imprimirRankingRec(root->left, contador);
    }
}

void GuardianRankingTree::liberarMemoria(TreeNode* root) {
    if (root != nullptr) {
        liberarMemoria(root->left);
        liberarMemoria(root->right);
        delete root;
    }
}

void cargarguardian(){


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



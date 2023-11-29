#include <iostream>

using namespace std;

int main() {
    int opcion;

    do {
        // Mostrar el menú
        cout << "----- Menu -----" << endl;
        cout << "1. Opcion 1" << endl;
        cout << "2. Opcion 2" << endl;
        cout << "3. Opcion 3" << endl;
        cout << "4. Salir" << endl;

        // Solicitar la elección al usuario
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        // Validar la opción utilizando un switch
        switch(opcion) {
            case 1:
                cout << "Ha seleccionado la Opcion 1." << endl;
                // Aquí puedes colocar el código correspondiente a la Opción 1
                break;
            case 2:
                cout << "Ha seleccionado la Opcion 2." << endl;
                // Aquí puedes colocar el código correspondiente a la Opción 2
                break;
            case 3:
                cout << "Ha seleccionado la Opcion 3." << endl;
                // Aquí puedes colocar el código correspondiente a la Opción 3
                break;
            case 4:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
        }

        // Continuar ejecutando el bucle do-while mientras la opción no sea 4 (Salir)
    } while(opcion != 4);

    return 0;
}
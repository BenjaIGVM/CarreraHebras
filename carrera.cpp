#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

class Auto {// Clase que representa un auto en la carrera
public:
    Auto(int id) : id(id), distanciaRecorrida(0), posicionFinal(0), ultimoAvance(0) {}

    void avanzar(int distancia) {// Hace avanzar el auto una distancia dada
        distanciaRecorrida += distancia;
        ultimoAvance = distancia;
    }

    int obtenerDistancia() const {
        return distanciaRecorrida;
    }

    void establecerPosicion(int pos) {
        posicionFinal = pos;
    }

    int obtenerId() const {
        return id;
    }

    int obtenerPosicion() const {
        return posicionFinal;
    }

    int obtenerUltimoAvance() const {
        return ultimoAvance;
    }

private:
    int id;
    int distanciaRecorrida;
    int posicionFinal;
    int ultimoAvance;
};

std::mutex mtx; // Mutex para sincronización
std::vector<Auto> autos; // Vector que almacena todos los autos
int autosTerminados = 0;

void mostrarProgreso(int distanciaTotal)// Función para mostrar el progreso de la carrera
 {
    std::lock_guard<std::mutex> lock(mtx);// Bloqueo para evitar escrituras simultáneas
    std::cout << "\033[2J\033[H";  // Limpia la pantalla
    for (const auto& auto_ : autos) {
        int progresoEscalado = (auto_.obtenerDistancia() * 100) / distanciaTotal; // Calcula el progreso en porcentaje

        // Muestra la barra de progreso y la información del auto
        std::cout << "Auto " << auto_.obtenerId() << ": "
                  << std::string(progresoEscalado, '=') << ">"
                  << std::string(100 - progresoEscalado, ' ')
                  << " " << auto_.obtenerDistancia() << "m"
                  << " avance: " << auto_.obtenerUltimoAvance() << "m";
                  << (auto_.obtenerDistancia() >= distanciaTotal ? " \033[1;32m(Auto " + std::to_string(auto_.obtenerId()) + " termin   la carrera!)\033[0m" : "") << "\n";
  }
    std::cout << std::flush;// Asegura que la salida se muestre inmediatamente
}

void carrera(Auto& auto_, int distanciaTotal) // Función que simula la carrera para un auto
 {  // Configuración de generadores de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distDist(1, 10); // Distribución para el avance entre 1 y 10
    std::uniform_int_distribution<> tiempoDist(100, 500);// Distribución para el tiempo de espera entre 100 y 500

    while (auto_.obtenerDistancia() < distanciaTotal) {
        // Calcula el avance, asegurándose de no sobrepasar la meta
        int avance = std::min(distDist(gen), distanciaTotal - auto_.obtenerDistancia());
        auto_.avanzar(avance);

        mostrarProgreso(distanciaTotal);
        // Espera un tiempo aleatorio antes del siguiente avance
        std::this_thread::sleep_for(std::chrono::milliseconds(tiempoDist(gen)));
    }

    {// Al terminar, actualiza la posición final del auto
        std::lock_guard<std::mutex> lock(mtx);
        autosTerminados++;
        auto_.establecerPosicion(autosTerminados);
    }
}

int main(int argc, char* argv[]) 
{   // Verifica que se proporcionen los argumentos correctos
    if (argc != 3) {
        std::cout << "Uso: ./carrera <distancia_total> <numero_autos>" << std::endl;
        return 1;
    }

    int distanciaTotal = std::stoi(argv[1]);
    int numeroAutos = std::stoi(argv[2]);

    // Crea los objetos Auto
    for (int i = 0; i < numeroAutos; ++i) {
        autos.emplace_back(i);
    }

    // Crea y lanza un hilo para cada auto
    std::vector<std::thread> hebras;
    for (auto& auto_ : autos) {
        hebras.emplace_back(carrera, std::ref(auto_), distanciaTotal);
    }

    // Espera a que todos los hilos terminen
    for (auto& hebra : hebras) {
        hebra.join();
    }

    
    std::cout << "\nResultados finales:\n";
    
    // Ordena los autos por su posición final
    std::sort(autos.begin(), autos.end(),
              [](const Auto& a, const Auto& b) { return a.obtenerPosicion() < b.obtenerPosicion(); });

    // Muestra la clasificación final
    for (const auto& auto_ : autos) {
         std::cout << "\033[1;34mLugar " << auto_.obtenerPosicion() << ":\033[0m \033[97mAuto " << auto_.obtenerId() << "\033[0m\n";
    }

    return 0;
}
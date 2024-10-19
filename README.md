# 🏎️ Carrera de Autos usando Hebras

Este programa simula una carrera de autos utilizando la librería estándar de hebras en C++. Cada auto avanza en su propia hebra, recorriendo una distancia aleatoria de "metros" y haciendo pausas aleatorias para simular diferentes velocidades. La carrera concluye cuando todos los autos cruzan la meta, mostrando una lista con las posiciones finales.

## 🚀 Compilación

### Prerequisitos

Asegúrate de tener instalado Git en tu sistema. Si no lo tienes, sigue estas instrucciones:

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install git
```

#### Fedora
```bash
sudo dnf install git
```

### Pasos para compilar

1. Clona el repositorio:
   ```bash
   git clone https://github.com/BenjaIGVM/CarreraHebras.git
   ```

2. Navega al directorio del proyecto:
   ```bash
   cd CarreraHebras
   ```

3. Compila el programa:
   ```bash
   make
   ```

   Si el comando anterior no funciona, intenta:
   ```bash
   make carrera
   ```

## 🏁 Ejecución 🏆

Para ejecutar el programa, utiliza el siguiente formato:

```bash
./carrera [metros_de_la_carrera] [cantidad_de_autos]
```

- `metros_de_la_carrera`: Distancia total de la carrera en metros.
- `cantidad_de_autos`: Número de autos que participarán en la carrera.

### Ejemplo

```bash
./carrera 100 4
```

Este comando iniciará una carrera de 100 metros con 4 autos compitiendo.

⚠️ **Nota**: Si no se proporcionan los argumentos correctos o se ingresan más de los necesarios, el programa mostrará un mensaje con las instrucciones de uso adecuadas.

---

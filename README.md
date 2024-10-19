# Carrera de autos usando hebras 

Este programa simula una carrera de autos usando la libreria estándar de hebras en C++. Cada auto avanza en una hebra distinta, una cantidad aleatoria de "metros" deteniendose cada cierto tiempo, también aleatorio, para representar la velocidad. La carrera finaliza cuando todos los autos hayan llegado a la meta, mostrando una lista con los lugares correspondientes.

# Compilar
Primero que nada se debe clonar este repositorio en el directorio destino usando el comando `git clone https://github.com/BenjaIGVM/CarreraHebras.git`, una vez hecho esto, posicionarse en la carpeta que se clonará, la cual contiene todos los archivos necesarios.

Para compilar este programa se debe usar el comando `make` en la terminal. Opcionalmente si eso no funciona, probar con `make carrera`.

# Ejecutar

La ejecución se hace con el comando `./carrera` añadiendo como argumento los metros totales que tendrá la carera y la cantidad de autos que van a competir, **separados por un espacio y en ese orden**. Si no se ingresan los parametros indicados o se intenta ingresar más, el programa simplemente imprimirá un mensaje sobre como es el correcto uso del comando.

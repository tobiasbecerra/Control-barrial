# control de entrada y salida - countries
Para comenzar voy a dar una explicación general del software.Charlando con mis compañeros de equipo se nos ocurrió hacer un software que se encargue de controlar el ingreso y egreso de INVITADOS a un barrio privado, tomando como referencia La Rufina.

Nuestro software incluye funciones que permiten al guardia del barrio cargar ingresos y egresos en auto, a pie y buscar el historial de ingresos y egresos cargando un DNI o nombre.

Al iniciar el programa, se le pide al usuario cargar un usuario y contraseña (puede ser cualquier cosa), iniciado el programa, se despliega un menú de opciones que le permiten al guardia de seguridad hacer todo lo que nombré anteriormente.

Obviamente que los barrios privados de hoy en día tienen todo este proceso automatizado pero nos pareció buena idea plantearlo a lo "básico" para hacer algo mas interesante y distinto de los empleados, alumnos, tiendas, stocks, etc...

La mayoría de librerías utilizadas son las básicas iostream, fstream, sstream, string... En nuestro software te vas a encontrar con dos librerías mas que nosotros por lo menos no estábamos acostumbrados a leer ni escuchar, que son locale.h y colors.h. La primera fue utilizada para poder mostrar los caracteres especiales como la "ñ" y los acentos en consola y la otra es una descargada de un repositorio de GitHub que permite personalizar la consola con ciertos colores, para que quede mas llamativo nomas jajaja.

Para realizar todo el desarrollo del software decidimos crear un archivo de encabezado llamado "funciones.h", en ese archivo vas a encontrar todas las funciones que permite al software funcionar. Dentro de este archivo, al inicio, hay 5 funciones que permiten no romper el funcionamiento del programa, controlando el ingreso de caracteres y números, tal que si en el nombre del visitante se pone un numero, no va a dejar ingresarlo y va a volver a pedirte que lo ingreses.

Bien, ahora el programa en si: El programa te permite realizar un ingreso de un visitante al barrio preguntándote: Nombre, DNI, patente del auto (en caso de que entre en auto, si entra a pie no lo pide), nombre del residente, lote del residente, fecha de ingreso y hora de ingreso... Lo mismo para el egreso.

Además, permite realizar una búsqueda de ingresos y egresos que tuvo una persona, se puede elegir entre buscar por DNI o por nombre, obviamente que estos tienen que coincidir con un visitante.

Me faltó agregar, hemos utilizado accesos directos, únicamente uno, para situar el puntero al final de los archivos para que se escriban por debajo de los datos que ya estaban cargados. (seekp(0, ios::end))

En el programa utilizamos estructuras de datos volátil y no volátil, como registro y archivos

En estructuras de programación, utilizamos de tipo control, repetitivos como el ciclo while para leer los archivos, ciclos for para las funciones que controlan los caracteres, y condicionales de tipo if, if else para todo lo que es verificar apertura de archivos, comparaciones, etc... y de tipo switch para realizar el menú de opciones.

Para terminar con la explicacion, me gustaria compartir unos problemas que hemos tenido a lo largo del desarrollo pero que al final pudimos resolver:

Por nuestra parte, nos falta mejorar la identacion, quizá por ser tan largo el código, tener tantas líneas, se nos hacia confusa la lectura y teníamos problemas con los nombres de los archivos, las llaves, etc...

Eso seria todo, muchas gracias profe y el nombre del barrio es en honor a usted, esperamos que no se ofenda!

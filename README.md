# MentorBitBH1750

Esta librería está diseñada para que puedas medir la luz de tu entorno de una forma muy sencilla usando tu placa MentorBit y el módulo de sensor de luz BH1750.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de Luxómetro.](https://github.com/DigitalCodesign/MentorBit-BH1750/blob/main/assets/AmbientLight_Module.png)

Con esta librería, podrás saber cuánta luz hay en una habitación y usar esa información para crear proyectos increíbles.

## Descripción
### ¿Qué es un sensor de luminosidad?

Imagina que tu móvil ajusta el brillo de la pantalla automáticamente cuando entras en una habitación oscura. O que las farolas de la calle se encienden solas al anochecer. ¡Eso es gracias a un sensor de luminosidad!

El BH1750 es un pequeño sensor digital que mide la cantidad de luz en el ambiente y nos da un valor en una unidad llamada lux. Es mucho más preciso que otros sensores más simples (como las fotorresistencias o LDRs), permitiéndote crear proyectos más fiables.

### ¿Qué hace esta librería?

La librería MentorBitBH1750 actúa como un "traductor" entre el sensor BH1750 y tu placa MentorBit. Se encarga de toda la comunicación y los cálculos complejos para que tú solo tengas que usar un par de comandos sencillos para obtener la medición de luz.

Gracias a ella, podrás centrarte en lo más importante: ¡la creatividad de tu proyecto!

### ¿Qué puedes construir con este sensor?

- Una lámpara inteligente que se encienda o apague según la luz del día.
- Un sistema que ajuste automáticamente la iluminación de una maqueta.
- Una estación meteorológica que registre los niveles de luz a lo largo del día.
- Alarmas o alertas que se activen cuando se detecte luz (por ejemplo, si alguien abre una caja que debería estar a oscuras).

Esta librería es el primer paso para integrar el control de la iluminación en tus proyectos con MentorBit de una manera sencilla y profesional.

## Cómo empezar

Usar la librería es muy sencillo. Solo sigue estos pasos para tener tu sensor midiendo luz en pocos minutos.

1. **Conexión del Módulo**

Antes que nada, conecta tu módulo de sensor BH1750 al puerto marcado como ***I2C*** dentro de la zona de ***Comunicaciones*** en tu placa MentorBit. ¡Y listo! No necesitas más cables.

2. **Instalación de las Librerías**

Para que tu placa MentorBit pueda comunicarse con el sensor, solo necesitas instalar una librería. El gestor del IDE de Arduino se encargará del resto.

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBitBH1750*** y haz clic en "Instalar".
- El IDE detectará que esta librería necesita otra para funcionar y te preguntará si quieres instalarla también. Haz clic en "Install all" o "Instalar todo".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-BH1750/blob/main/assets/library_instalation_example.png)

¡Y ya está! Con eso tienes todo lo necesario para empezar a programar.

## Ejemplo Básico: Leer y Mostrar la Luz

El siguiente código es todo lo que necesitas para tomar una lectura de luz cada segundo y mostrarla en tu ordenador.

### Copia y pega este código en tu IDE:

```c++
// 1. Incluimos la librería que acabamos de instalar.
#include <MentorBitBH1750.h>

// 2. Creamos un objeto llamado 'sensorLuz' para poder controlar nuestro sensor.
MentorBit_BH1750 sensorLuz;

void setup() {
    // Inicializamos la comunicación con el ordenador para poder ver los mensajes.
    Serial.begin(9600);

    // 3. Inicializamos el sensor. Esto lo prepara para empezar a medir.
    sensorLuz.begin();
    Serial.println("Sensor BH1750 listo para medir.");
}

void loop() {
    // 4. Usamos la función leerLux() para obtener la medida de luz.
    // La guardamos en una variable llamada 'lux' que puede tener decimales (float).
    float lux = sensorLuz.leerLux();

    // 5. Mostramos el resultado en el monitor serie.
    Serial.print("Luminosidad detectada: ");
    Serial.print(lux);
    Serial.println(" lux");

    // Esperamos un segundo (1000 milisegundos) antes de tomar la siguiente medida.
    delay(1000);
}
```

### Para ver el resultado:

1. Carga el código en tu placa MentorBit.
2. Abre el **Monitor Serie** del IDE de Arduino.
3. ¡Verás cómo aparecen las lecturas de luz cada segundo!

## Funciones Principales

Esta librería está diseñada para ser minimalista y fácil de usar. Solo necesitas conocer dos funciones:

- <code>void begin()</code>
   - **¿Qué hace?** Inicializa y calibra el sensor para que esté lista para funcionar.
   - **¿Cuándo se usa?** Debes llamarla siempre una vez dentro de la función <code>setup()</code> de tu programa.

- <code>float leerLux()</code>
   - **¿Qué hace?** Le pide al sensor una medición de luz y te la devuelve como un número decimal (de tipo <code>float</code>).
   - **¿Cuándo se usa?** La llamarás cada vez que quieras saber cuánta luz hay, normalmente dentro de la función <code>loop()</code>.

## Recursos Adicionales

¿Quieres saber más sobre el módulo o necesitas comprar uno? Aquí tienes algunos enlaces que te serán de utilidad:

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial de Módulo MentorBit de Luxómetro](#)
- [Manual de usuario del Módulo](#)

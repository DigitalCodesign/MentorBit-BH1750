# MentorBitBH1750

Librería para la lectura de datos de luminosidad utilizando el sensor BH1750 en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitBH1750` facilita la lectura de datos de luminosidad (lux) desde el sensor BH1750 en módulos compatibles con MentorBit. Permite obtener mediciones precisas para aplicaciones de control de iluminación, monitoreo ambiental y sistemas de automatización.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitBH1750" e instálala.
    * **Nota:** Esta librería depende de la librería `BH1750`. Asegúrate de que también esté instalada.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitBH1750.h>

    MentorBit_BH1750 bh1750;

    void setup() {
        bh1750.begin();
        Serial.begin(9600);
        Serial.println("Sensor BH1750 inicializado.");
    }

    void loop() {
        float lux = bh1750.leerLux();

        Serial.print("Luminosidad: ");
        Serial.print(lux);
        Serial.println(" lux");

        delay(1000);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBit_BH1750()`: Crea un objeto `MentorBit_BH1750`.

### Métodos

* `void begin()`: Inicializa el sensor BH1750.
* `float leerLux()`: Lee la luminosidad en lux.

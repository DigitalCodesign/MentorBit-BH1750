/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.1.0
    Fecha de creación: Enero de 2024
    Fecha de version: Febrero de 2026
    Repositorio: https://github.com/DigitalCodesign/MentorBit-BH1750
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit BH1750. En esta versión se eliminan dependencias de 
        terceros (lectura directa por I2C nativo) para mayor eficiencia y menor 
        consumo de memoria.

    Metodos principales:
        MentorBit_BH1750(uint8_t i2c_addr) -> Constructor de la clase. Permite cambiar la dirección I2C (0x23 por defecto).
        begin() -> Inicializa el bus I2C y el sensor en modo continuo. Debe colocarse en el setup(). Devuelve 'true' si lo encuentra.
        leerLux() -> Devuelve el nivel de iluminación en Lux (float). Devuelve -1.0 si hay un error de conexión.
*/

#ifndef MentorBitBH1750_h
#define MentorBitBH1750_h

#include <Arduino.h>
#include <Wire.h>

    class MentorBit_BH1750
    {

        public:

            MentorBit_BH1750(uint8_t i2c_addr = 0x23);

            bool begin();

            float leerLux();

        private:

            uint8_t _i2c_addr;
            const uint8_t CMD_POWER_ON = 0x01;
            const uint8_t CMD_RESET = 0x07;
            const uint8_t CMD_CONT_HIGH_RES = 0x10;

    };

#endif

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
    Version: 1.0.0
    Fecha de creación: Enero de 2024
    Fecha de version: Enero de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-BH1750
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit BH1750
    Metodos principales:
        MentorBitBH1750 -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup
        leerTVOC -> lee el valor de TVOC del sensor

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

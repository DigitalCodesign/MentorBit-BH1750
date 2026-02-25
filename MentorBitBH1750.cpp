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

#include "MentorBitBH1750.h"

/**
 * @brief Constructor de la clase.
 */
MentorBit_BH1750::MentorBit_BH1750(uint8_t i2c_addr)
{

    _i2c_addr = i2c_addr;

}

/**
 * @brief Método para inicializar y configurar el sensor BH1750.
 * @return True si se inicializa correctamente, False en caso contrario.
 */
bool MentorBit_BH1750::begin()
{

    Wire.begin();
    // Comprobamos si el dispositivo responde
    Wire.beginTransmission(_i2c_addr);
    if (Wire.endTrasmission() != 0) return false;
    // Encendemos el sensor
    Wire.beginTransmission(_i2c_addr);
    Wire.write(CMD_POWER_ON);
    Wire.endTransmission();
    // Configuramos el sensor en Modo Continuo de Alta Resolución
    Wire.beginTransmission(_i2c_addr);
    Wire.write(CMD_CONT_HIGH_RES);
    Wire.endTransmission();
    // La primera medición tarda unos 120ms en completarse
    delay(150);
    return true;

}

/**
 * @brief Método para obtener la lectura en Lux del sensor.
 * @return Devuelve un float con la medición de la luz en Lux.
 */
float MentorBit_BH1750::leerLux()
{

    uint16_t lux = 0;
    // Pedimos al sensor los dos bytes de la medición
    Wire.requestFrom(_i2c_addr, (uint8_t)2);
    // Comprobamos que efectivamente hemos recibido 2 bytes
    if (Wire.available() == 2)
    {
        lux = Wire.read();
        lux = lux << 8;
        lux = lux | Wire.read();
    } else return -1.0;
    // El valor crudo dado por el sensor debe dividirse por 1.2 para obtener el real
    return lux / 1.2;

}

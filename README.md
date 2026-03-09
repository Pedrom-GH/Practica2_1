# ESP32: Interrupciones Externas mediante GPIO (Práctica 2A)

Este proyecto implementa el uso de interrupciones de hardware en un microcontrolador ESP32 utilizando el entorno de desarrollo PlatformIO y el framework Arduino. [cite_start]El objetivo es capturar eventos externos de forma inmediata sin comprometer el rendimiento del procesador[cite: 1, 3, 53].

## Descripción General

[cite_start]La práctica demuestra la diferencia fundamental entre el método de verificación periódica (Polling) y el uso de interrupciones[cite: 23, 24]. [cite_start]Mientras que el Polling obliga al procesador a consultar constantemente el estado de un pin, la interrupción permite que el procesador ejecute otras tareas y solo atienda el evento cuando se detecta un cambio de señal en el hardware[cite: 14, 25].



## Especificaciones de Hardware

* [cite_start]**Microcontrolador**: ESP32 DevKit V1 o compatible[cite: 49].
* [cite_start]**Entrada**: Pulsador físico[cite: 94].
* [cite_start]**Configuración de Pin**: GPIO 18 configurado como entrada con resistencia interna Pull-up[cite: 102, 110].
* [cite_start]**Modo de Disparo**: FALLING (se activa cuando la señal pasa de HIGH a LOW)[cite: 66, 111].

## Conexiones Realizadas

* [cite_start]**Terminal 1 del Pulsador**: Conectado al pin GPIO 18 del ESP32[cite: 102].
* [cite_start]**Terminal 2 del Pulsador**: Conectado al pin GND (Tierra) del ESP32[cite: 94].



## Estructura del Software

El código utiliza elementos críticos para la gestión eficiente de interrupciones en el ESP32:

* [cite_start]**IRAM_ATTR**: Identificador utilizado en la Rutina de Servicio de Interrupción (ISR) para alojar el código en la memoria RAM interna, acelerando la respuesta del sistema[cite: 73, 77].
* **attachInterrupt()**: Función que vincula el pin físico con la función de servicio y el modo de disparo[cite: 53, 55].
* [cite_start]**Control de estado**: Se emplea una estructura para almacenar el número de pulsaciones y un indicador booleano para gestionar la impresión en el bucle principal[cite: 97, 113].
* [cite_start]**detachInterrupt()**: El programa incluye una función de seguridad que desconecta la interrupción tras 60 segundos de ejecución para liberar recursos[cite: 121, 125].

## Configuración del Proyecto (platformio.ini)

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200


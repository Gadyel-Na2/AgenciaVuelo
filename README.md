Sistema completo de gestión de reservaciones aéreas desarrollado en C++ con programación orientada a objetos, complementado con visualización web utilizando Google Sheets como base de datos en la nube.
Descripción:
ViajandoAndo es un sistema de reservaciones que permite gestionar vuelos, clientes y reservaciones con un programa de lealtad integrado. Los clientes que acumulan más de 50,000 kilómetros reciben automáticamente un descuento del 40% en sus próximas reservaciones.
El proyecto incluye:

Backend en C++: Sistema completo orientado a objetos con menú interactivo en consola
Frontend Web: Interfaz HTML/CSS/JavaScript para visualizar vuelos en tiempo real
Integración Cloud: Uso de Google Sheets API como base de datos accesible desde internet

Características Principales
Sistema C++:
Gestión completa de Clientes, Vuelos y Reservaciones
Programa de lealtad con descuentos automáticos (40% para clientes VIP)
Validación exhaustiva de datos (IDs únicos, límites, disponibilidad)
Acumulación automática de kilómetros por reservación
Control de asientos disponibles en tiempo real
Arquitectura modular con separación de responsabilidades

Visualización Web:
Interfaz responsive (móvil y escritorio)
Sistema de filtros dinámicos (origen, destino, fecha)
Estadísticas en tiempo real(editando hoja de cálculo)
Actualización automática de datos cada 60 segundos

Backend:
C++ (Standard Library)
Programación Orientada a Objetos
Gestión de memoria con arreglos estáticos

Frontend:
HTML5 - Estructura semántica
CSS3 - Diseño responsive, Grid
JavaScript ES6+ - Fetch API, async/await
Google Sheets API - Base de datos en la nube

Deployment:
Netlify - Hosting del frontend
Google Sheets - Almacenamiento de datos

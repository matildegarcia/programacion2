#include "../include/evento.h"

struct rep_evento { 
    int id;
    char descripcion[MAX_DESCRIPCION];
    TFecha fecha;
};

//**************************************************************************************+

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha) {
    
    TEvento nuevoEvento = NULL;
     nuevoEvento = new rep_evento;
      nuevoEvento->id = id;
      strcpy(nuevoEvento->descripcion, descripcion); //funcion especial 
      nuevoEvento->fecha = fecha;

    return nuevoEvento;
}
//**************************************************************************************+

void imprimirTEvento(TEvento evento) {

 if (evento != NULL) {
 printf("Evento %d: %s\n", evento->id, evento->descripcion);
 printf("Fecha: " );
 imprimirTFecha(evento->fecha);
   
    }
}
//**************************************************************************************+


void liberarTEvento(TEvento &evento) {
  liberarTFecha(evento->fecha);
    delete evento;
    evento = NULL; 
}

//**************************************************************************************+

int idTEvento(TEvento evento) {

  int res = evento->id;
    return res;
    }

//**************************************************************************************+

TFecha fechaTEvento(TEvento evento) {
    TFecha fecha = NULL;

fecha = evento->fecha; 
    return fecha;
}
//**************************************************************************************+


void posponerTEvento(TEvento &evento, int dias) {
    aumentarTFecha(evento->fecha, dias);
}

//**************************************************************************************+
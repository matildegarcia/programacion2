 #include "../include/agenda.h"

struct rep_agenda {
  TEvento eventos[MAX_EVENTOS];
  int tope;
};

//**************************************************************************************+

TAgenda crearTAgenda() {
   
 TAgenda nuevaAgenda = NULL;
      nuevaAgenda = new rep_agenda;
       nuevaAgenda->tope= 0; 
 return nuevaAgenda;

}  

//**************************************************************************************

void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    if (agenda->tope < MAX_EVENTOS) {
        int posicion = agenda->tope;
        bool encontreposicion = false;

        while (posicion > 0 && !encontreposicion) {
            TEvento eventoActual = agenda->eventos[posicion - 1];

            if (compararTFechas(fechaTEvento(evento), fechaTEvento(eventoActual)) <= 0) {
                agenda->eventos[posicion] = eventoActual;
                posicion--;
            } else {
                encontreposicion = true;  
            }
        }

        agenda->eventos[posicion] = evento;
        agenda->tope++;
    }
}

//**************************************************************************************+


void liberarTAgenda(TAgenda& agenda) {
    if (agenda != NULL) {
        for (int i = 0; i < agenda->tope; i++) {
            if (agenda->eventos[i] != NULL) {
                liberarTEvento(agenda->eventos[i]);
            }
        }
        
        delete agenda; 
        agenda = NULL; 
    }
}

//**************************************************************************************+


void imprimirTAgenda(TAgenda agenda) {
    if (agenda!= NULL){
for (int i = 0; i < agenda->tope; i++) {
      
imprimirTEvento(agenda->eventos[i]);
    }
  }  
}

//**************************************************************************************+

bool estaEnAgenda(TAgenda agenda, int id) {
   
    bool res = false;
   
     if (agenda != NULL) {
        int j = 0;
        while (!res && j < agenda->tope) {
            if (agenda->eventos[j] != NULL && idTEvento(agenda->eventos[j]) == id) {
                res = true; 
            }
            j++;
        }
    }
    return res;
}   

//**************************************************************************************+

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    TEvento res = NULL;
   
    if (agenda != NULL) {
        int i = 0;
        while (i < agenda->tope) {
            if (agenda->eventos[i] != NULL && idTEvento(agenda->eventos[i]) == id) {
                res = agenda->eventos[i];
            
            }
            i++;
        }
    }

    return res;
}

//**************************************************************************************+
void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    TEvento evento = obtenerDeAgenda(agenda, id);
    posponerTEvento(evento, n);

    int i = 0;
    bool encontrado = false;

    while (i < agenda->tope && !encontrado) {
        if (idTEvento(agenda->eventos[i]) == id) {
            encontrado = true;
            for (int k = i; k < agenda->tope - 1; k++) {
                agenda->eventos[k] = agenda->eventos[k + 1];
            }
            agenda->tope--;
            agregarEnAgenda(agenda, evento);
        }
        i++;
    }
}

//**************************************************************************************+


void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    if (agenda != NULL) {
        for (int i = 0; i < agenda->tope; i++) {  
            if (agenda->eventos[i] != NULL && compararTFechas(fechaTEvento(agenda->eventos[i]), fecha) == 0) {
                imprimirTEvento(agenda->eventos[i]);
            }
        }
    }
}

//**************************************************************************************+

bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    int derecha = 0;
    int izquierda = agenda->tope - 1;
    bool encontrado = false;

    while (derecha < izquierda) {
        int mitad = (derecha + izquierda) / 2;

        int comparacion = compararTFechas(fechaTEvento(agenda->eventos[mitad]), fecha);

        if (comparacion == 0) {
            encontrado = true;
            break;
        } else if (comparacion > 0) {
            izquierda = mitad - 1;
        } else {
            derecha = mitad + 1;
        }
    }

    return encontrado;
}

//***************************************************************************************

void removerDeAgenda(TAgenda &agenda, int id) {

 if (agenda != NULL) {
    
  int indicevento = -1; 

  for (int i = 0; i < agenda->tope; i++) {
    if (agenda->eventos[i] != NULL && idTEvento(agenda->eventos[i])== id) {
      indicevento = i;
    
    }
  }

 if (indicevento != -1) {
  liberarTEvento(agenda->eventos[indicevento]); 
  
  for (int k = indicevento; k < agenda->tope - 1; k++) {
    agenda->eventos[k] = agenda->eventos[k + 1];
  }

  agenda->tope--; 
  
  }

  }
}
//***************************************************************************************
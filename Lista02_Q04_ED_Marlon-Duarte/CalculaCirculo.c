#include "CalculaCirculo.h"

float circumferencia (float pi, float raio){
    float calculo;

    calculo = 2*(pi*raio);

    return calculo;
}
float area (float pi, float raio){
    float calculo;

    calculo = pi*(raio*raio);

    return calculo;
}

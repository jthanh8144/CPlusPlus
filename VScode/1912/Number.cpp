#include "Number.h"

Number::Number(double x):data(x){

}

Number::~Number(){

}

Number::operator int(){
    return int(this->data);
}

Number::operator double(){
    return this->data;
}
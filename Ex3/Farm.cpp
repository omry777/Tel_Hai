#include "Farm.h"

ostream &operator<<(ostream &out, const Farm &obj){
    return out << (Structure)obj << ", crops/h= " << obj.growRate;
}
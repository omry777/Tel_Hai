#include "Structure.h"

ostream &operator<<(ostream &out, const Structure &obj){
    return out << (Sim_object)obj << " ,Inventory: " << obj.crops;
}
#include "Sim_object.h"

ostream &operator<<(ostream &out, const Sim_object &obj) { return (out << obj.name << " at: " << obj.loc); }
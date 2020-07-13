#include "Model.h"

void Model::addAgent() { cout << "HI\n"; try { new Sim_object(); } catch (void *e){cout << "OH NO!\n"; } cout << "ALL GOOD!\n";}
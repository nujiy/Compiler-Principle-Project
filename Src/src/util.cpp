#include "../include/util.h"
map<int,string> typeMap;
map<int,string> opMap;
void setMap()
{
    typeMap[VALUEBOOL] = "Bool";
    typeMap[VALUEINT] = "Int";
    typeMap[VALUEFLOAT] = "Float";
    typeMap[VALUEVOID] = "Void";
    opMap[OPADD] = "+";
    opMap[OPSUB] = "-";
    opMap[OPDIV] = "/";
    opMap[OPMUL] = "*";
    opMap[OPMOD] = "%";
    opMap[OPPOW] = "^";
    opMap[OPEQ] = "==";
    opMap[OPGT] = ">";
    opMap[OPLT] = "<";
    opMap[OPELT] = "<=";
    opMap[OPEGT] = ">=";
    opMap[OPNEQ] = "<>";
     opMap[OPAND] = "&&";
    opMap[OPOR] = "|";
}

string& getTypeMap(int index)
{
    return typeMap[index];
}

string& getOpMap(int index){
    return opMap[index];
}
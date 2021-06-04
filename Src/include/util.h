#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H
#include <map>

using namespace std;

#define OPADD 0
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPMOD 4
#define OPPOW 5
#define OPGT 6    // larger than
#define OPLT 7    // less than
#define OPEQ 8    // equal
#define OPNEQ 9   // not equal
#define OPELT 10  // less than or equal
#define OPEGT 11  // larger than or equal
#define OPAND 12
#define OPOR 13

#define VALUEBOOL 0     // determine the type of expression value
#define VALUEINT 1
#define VALUEFLOAT 2
#define VALUECHAR 3
#define VALUEVOID 4
#define VALUEARRAY 5

#define EXPRID 0    // determine the expr type variable | literal | binary-expression to be calculate
#define EXPRVALUE 1
#define EXPRBINARY 2
#define EXPRFUNCCALL 3

#define DECLVARIABLE 0
#define DECLPROTO 1
#define DECLPARAM 2
#define DECLARRAY 3

#define STMTEXPR 0
#define STMTASSIGN 1
#define STMTDECL 2
#define STMTRETURN 3
#define STMTFOR 4
#define STMTWHILE 5
#define STMTCONDITION 6
#define STMTCONDITION_WITH_OTHERWISE 7
void setMap();
string& getTypeMap(int index);
string& getOpMap(int index);
#endif //COMPILER_UTIL_H

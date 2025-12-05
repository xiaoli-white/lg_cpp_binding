grammar LGIRGrammar;

program: (globalVariable | structure | function)* EOF;

globalVariable: attribute* EXTERN? CONST? GLOBAL IDENTIFIER ('=' constant)? (':' type)?;
structure: attribute* STRUCTURE IDENTIFIER '{' fields '}';
fields: field (',' field)* |;
field: type IDENTIFIER;
function: attribute* EXTERN? FUNCTION type IDENTIFIER '(' localVariables ')' ('{' localVariables '}' '{' (basicBlock)* '}')?;
localVariables: localVariable (',' localVariable)* |;
localVariable: type IDENTIFIER;
basicBlock: IDENTIFIER ':' (statement)*;
statement: nop | stackAlloc | load | store | asm | goto | invoke | return | setRegister | getElementPointer | cmp | conditionalJump | unaryOperates | binaryOperates | typeCast | phi | switch;
nop: NOP;
stackAlloc: registerName '=' STACK_ALLOC type (',' value)?;
load: registerName '=' LOAD value;
store: STORE value value;
asm: ASM STRING_LITERAL ',' STRING_LITERAL '(' values ')';
goto: GOTO label;
invoke: (registerName '=')? INVOKE type value '(' values ')';
return: RETURN value?;
setRegister: registerName '=' value;
getElementPointer: registerName '=' GETELEMENTPTR value (',' value)+;
cmp: registerName '=' CMP condition ',' value ',' value;
conditionalJump: CONDITIONAL_JUMP condition ',' value (',' value)? ',' label;
unaryOperates: registerName '=' unaryOperator value;
binaryOperates: registerName '=' binaryOperator value ',' value;
typeCast: registerName '=' typeCastKind value 'to' type;
phi: registerName '=' PHI (',' phiValue)*;
switch: SWITCH value ',' label (',' switchCase)*;

phiValue: '[' label ',' value ']';
switchCase: '[' integerConstant ',' label ']';

type: baseType MULTIPLY*;
baseType: integerType | decimalType | arrayType | voidType | structureType | functionReferenceType;
integerType: I1 | I8 | U8 | I16 | U16 | I32 | U32 | I64 | U64;
decimalType: FLOAT | DOUBLE;
arrayType: '[' INT_NUMBER 'x' type ']';
voidType: VOID;
structureType: STRUCTURE IDENTIFIER;
functionReferenceType: '(' types (',' ELLIPSIS)? ')' '->' type;
types: type (',' type)* | ;
values: value (',' value)* | ;
value: register | constant | localReference;
constants: constant (',' constant)* | ;
constant: integerConstant | decimalConstant | arrayConstant | structureInitializer | stringConstant | functionReference | globalReference;
integerConstant: integerType INT_NUMBER;
decimalConstant: decimalType DECIMAL_NUMBER;
arrayConstant: arrayType '[' constants ']';
structureInitializer: CONSTANT structureType '{' constants '}';
stringConstant: STRING STRING_LITERAL;
functionReference: FUNCREF IDENTIFIER;
globalReference: GLOBALREF IDENTIFIER;
localReference: LOCALREF IDENTIFIER;

register: type registerName;
registerName: '%' (IDENTIFIER | INT_NUMBER);

label: LABEL IDENTIFIER;
condition: 'if_true' | 'if_false' | 'e' | 'ne' | 'ne' | 'l' | 'le' | 'g' | 'ge';

unaryOperator: INC | DEC | NOT | NEG;
binaryOperator: ADD | SUB | MUL | DIV | MOD | AND | OR | XOR | SHL | SHR | USHR;
typeCastKind: ZEXT | SEXT | TRUNC | INTTOF | FTOINT | INTTOPTR | PTRTOINT | PTRTOPTR | FEXT | FTRUNC | BITCAST;

attribute: ATTRIBUTE '(' STRING_LITERAL ')';

I1: 'i1';
I8: 'i8';
U8: 'u8';
I16: 'i16';
U16: 'u16';
I32: 'i32';
U32: 'u32';
I64: 'i64';
U64: 'u64';
FLOAT: 'float';
DOUBLE: 'double';
VOID: 'void';

CONST: 'const';
GLOBAL: 'global';
STRUCTURE: 'structure';
EXTERN: 'extern';
FUNCTION: 'function';

NOP: 'nop';
STACK_ALLOC: 'stack_alloc';
LOAD: 'load';
STORE: 'store';
ASM: 'asm';
GOTO: 'goto';
INVOKE: 'invoke';
RETURN: 'return';
GETELEMENTPTR: 'getelementptr';
CMP: 'cmp';
CONDITIONAL_JUMP: 'conditional_jump';
PHI: 'phi';
SWITCH: 'switch';
INC: 'inc';
DEC: 'dec';
NOT: 'not';
NEG: 'neg';
ADD: 'add';
SUB: 'sub';
MUL: 'mul';
DIV: 'div';
MOD: 'mod';
AND: 'and';
OR: 'or';
XOR: 'xor';
SHL: 'shl';
SHR: 'shr';
USHR: 'ushr';

ZEXT: 'zext';
SEXT: 'sext';
TRUNC: 'trunc';
INTTOF: 'inttof';
FTOINT: 'ftoint';
INTTOPTR: 'inttoptr';
PTRTOINT: 'ptrtoint';
PTRTOPTR: 'ptrtoptr';
FEXT: 'fext';
FTRUNC: 'ftrunc';
BITCAST: 'bitcast';

FUNCREF: 'funcref';
GLOBALREF: 'globalref';
LOCALREF: 'localref';
CONSTANT: 'constant';
LABEL: 'label';

STRING: 'string';

ELLIPSIS: '...';
MULTIPLY: '*';

ATTRIBUTE: '__attribute__';

INT_NUMBER : [0-9]+;
DECIMAL_NUMBER: [0-9]+ '.' [0-9]+;
WS : [ \t\r\n]+ -> skip;

STRING_LITERAL: '"' (~["\\] | '\\' .)* '"';
IDENTIFIER: [\p{L}_] [\p{L}0-9_]* | STRING_LITERAL;
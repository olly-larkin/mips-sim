#ifndef MIPS_instructions_hpp
#define MIPS_instructions_hpp

#include <iostream>

#define ADDR_NULL_P 0x00000000
#define ADDR_INSTR_P 0x10000000
#define ADDR_DATA_P 0x20000000
#define ADDR_GETC_P 0x30000000
#define ADDR_PUTC_P 0x30000004

#define ADDR_INSTR_LIMIT 0x11000000

typedef void (*rTypeFunc)(char,char,char,char);
typedef void (*iTypeFunc)(char,char,int16_t);
typedef void (*jTypeFunc)(int32_t);

void executeR(char fn, char s1, char s2, char dest, char shAmt);
void executeI(char op, char s1, char dest, int16_t data);
void executeJ(char op, int32_t addr);
char* executeMem();
int32_t pcLocation();
int32_t getNextInstr();
int32_t get32(const char* arr);
char returnCode();
void exitError(std::string msg, int errCode);
char* memMap(int32_t pc);
void successfulExit();

//************************** MIPS INSTRUCTIONS **************************

//----- R TYPE -----

void mfhi(char s1, char s2, char dest, char shAmt);
void mflo(char s1, char s2, char dest, char shAmt);
void div(char s1, char s2, char dest, char shAmt);
void addu(char s1, char s2, char dest, char shAmt);
void and_instr(char s1, char s2, char dest, char shAmt);

//----- I TYPE -----

void addiu(char s1, char dest, int16_t data);
void andi(char s1, char dest, int16_t data);

//----- J TYPE -----

void j(int32_t addr);
void jal(int32_t addr);

#endif /* MIPS_instructions_hpp */

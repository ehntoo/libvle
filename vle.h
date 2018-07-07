/* LGPL - Copyright 2017-2018 - wargio */
#ifndef LIB_PPCVLE
#define LIB_PPCVLE
#include <stdint.h>

#ifdef __cplusplus
  extern "C" {
#endif

enum field_type {
  TYPE_NONE = 0,
  TYPE_REG  = 1,
  TYPE_IMM  = 2,
  TYPE_MEM  = 3,
  TYPE_JMP  = 4,
  TYPE_CR   = 5
};

enum op_type {
  OP_TYPE_ILL,

  OP_TYPE_ADD,
  OP_TYPE_SUB,
  OP_TYPE_MUL,
  OP_TYPE_DIV,
  OP_TYPE_SHR,
  OP_TYPE_SHL,
  OP_TYPE_ROR,

  OP_TYPE_AND,
  OP_TYPE_OR,
  OP_TYPE_XOR,
  OP_TYPE_NOR,
  OP_TYPE_NOT,

  OP_TYPE_IO,
  OP_TYPE_LOAD,
  OP_TYPE_STORE,
  OP_TYPE_MOV,

  OP_TYPE_CMP,
  OP_TYPE_JMP,
  OP_TYPE_CJMP,
  OP_TYPE_CALL,
  OP_TYPE_CCALL,
  OP_TYPE_RJMP,
  OP_TYPE_RCALL,
  OP_TYPE_RET,

  OP_TYPE_SYNC,
  OP_TYPE_SWI,
  OP_TYPE_TRAP
};

enum op_condition {
  COND_AL,
  COND_GE,
  COND_LE,
  COND_NE,
  COND_VC,
  COND_LT,
  COND_GT,
  COND_EQ,
  COND_VS,
  COND_NV
};

typedef struct {
  const uint8_t* end;
  const uint8_t* pos;
  uint16_t inc;
} vle_handle;

typedef struct {
  uint32_t value;
  enum field_type type;
} vle_field_t;

typedef struct {
  const char* name;
  vle_field_t fields[10];
  uint16_t n;
  uint16_t size;
  enum op_type op_type;
  enum op_condition cond;
} vle_t;

int vle_init(vle_handle* handle, const uint8_t* buffer, const uint32_t size);
int vle_next(vle_handle* handle, vle_t* out);
void vle_snprint(char* str, int size, uint32_t addr, vle_t* instr);

#ifdef __cplusplus
}
#endif

#endif

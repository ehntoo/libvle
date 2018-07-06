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
  uint32_t op;
  int cond;
} vle_t;

int vle_init(vle_handle* handle, const uint8_t* buffer, const uint32_t size);
int vle_next(vle_handle* handle, vle_t* out);
void vle_snprint(char* str, int size, uint64_t addr, vle_t* instr);

#ifdef __cplusplus
}
#endif

#endif

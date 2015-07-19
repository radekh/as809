#include "as68.h"

extern int none(), load(), load2(), memory(), store(), branch(),
	org(), rmb(), equ(), fcb(),
	fdb(), fcc(), nam(), endop(), page(), spc(), library();

#ifdef	MC6809
extern int ccr(), lbranch(), stacks(), stacku(), lea(), transfer(), setdp();
#endif

OPTABLE optab[] = {
#ifndef	MC6809
	{ "ABA",	0,	0x1b,	0,	none	},
#endif
	{ "ABX",	0,	0x3a,	MC6801,	none	},
	{ "ADCA",	0,	0x89,	0,	load	},
	{ "ADCB",	0,	0xc9,	0,	load	},
	{ "ADDA",	0,	0x8b,	0,	load	},
	{ "ADDB",	0,	0xcb,	0,	load	},
	{ "ADDD",	0,	0xc3,	MC6801,	load2	},
	{ "ANDA",	0,	0x84,	0,	load	},
	{ "ANDB",	0,	0xc4,	0,	load	},
#ifdef	MC6809
	{ "ANDCC",	0,	0x1c,	0,	ccr	},
#endif
	{ "ASL",	0,	0x08,	0,	memory	},
	{ "ASLA",	0,	0x48,	0,	none	},
	{ "ASLB",	0,	0x58,	0,	none	},
#ifndef	MC6809
	{ "ASLD",	0,	0x05,	MC6801,	none	},
#endif
	{ "ASR",	0,	0x07,	0,	memory	},
	{ "ASRA",	0,	0x47,	0,	none	},
	{ "ASRB",	0,	0x57,	0,	none	},

	{ "BCC",	0,	0x24,	0,	branch	},
	{ "BCS",	0,	0x25,	0,	branch	},
	{ "BEQ",	0,	0x27,	0,	branch	},
	{ "BGE",	0,	0x2c,	0,	branch	},
	{ "BGT",	0,	0x2e,	0,	branch	},
	{ "BHI",	0,	0x22,	0,	branch	},
	{ "BHS",	0,	0x24,	0,	branch	},
	{ "BITA",	0,	0x85,	0,	load	},
	{ "BITB",	0,	0xc5,	0,	load	},
	{ "BLE",	0,	0x2f,	0,	branch	},
	{ "BLO",	0,	0x25,	MC6801,	branch	},
	{ "BLS",	0,	0x23,	0,	branch	},
	{ "BLT",	0,	0x2d,	0,	branch	},
	{ "BMI",	0,	0x2b,	0,	branch	},
	{ "BNE",	0,	0x26,	0,	branch	},
	{ "BPL",	0,	0x2a,	0,	branch	},
	{ "BRA",	0,	0x20,	0,	branch	},
	{ "BRN",	0,	0x21,	MC6801,	branch	},
	{ "BSR",	0,	0x8d,	0,	branch	},
	{ "BVC",	0,	0x28,	0,	branch	},
	{ "BVS",	0,	0x29,	0,	branch	},

#ifndef	MC6809
	{ "CBA",	0,	0x11,	0,	none	},
	{ "CLC",	0,	0x0c,	0,	none	},
	{ "CLI",	0,	0x0e,	0,	none	},
#endif
	{ "CLR",	0,	0x0f,	0,	memory	},
	{ "CLRA",	0,	0x4f,	0,	none	},
	{ "CLRB",	0,	0x5f,	0,	none	},
#ifndef	MC6809
	{ "CLV",	0,	0x0a,	0,	none	},
#endif
	{ "CMPA",	0,	0x81,	0,	load	},
	{ "CMPB",	0,	0xc1,	0,	load	},
#ifdef	MC6809
	{ "CMPD",	0x10,	0x83,	0,	load2	},
	{ "CMPS",	0x11,	0x8c,	0,	load2	},
	{ "CMPU",	0x11,	0x83,	0,	load2	},
	{ "CMPX",	0,	0x8c,	0,	load2	},
	{ "CMPY",	0x10,	0x8c,	0,	load2	},
#endif
	{ "COM",	0,	0x03,	0,	memory	},
	{ "COMA",	0,	0x43,	0,	none	},
	{ "COMB",	0,	0x53,	0,	none	},
#ifndef	MC6809
	{ "CPX",	0,	0x8c,	0,	load2	},
#endif
#ifdef	MC6809
	{ "CWAI",	0,	0x3c,	0,	ccr	},
#endif

	{ "DAA",	0,	0x19,	0,	none	},
	{ "DEC",	0,	0x0a,	0,	memory	},
	{ "DECA",	0,	0x4a,	0,	none	},
	{ "DECB",	0,	0x5a,	0,	none	},
#ifndef	MC6809
	{ "DES",	0,	0x34,	0,	none	},
	{ "DEX",	0,	0x09,	0,	none	},
#endif

	{ "END",	0,	0,	0,	endop	},
	{ "EORA",	0,	0x88,	0,	load	},
	{ "EORB",	0,	0xc8,	0,	load	},
	{ "EQU",	0,	0,	0,	equ	},
#ifdef	MC6809
	{ "EXG",	0,	0x1e,	0,	transfer	},
#endif

	{ "FCB",	0,	0,	0,	fcb	},
	{ "FCC",	0,	0,	0,	fcc	},
	{ "FDB",	0,	0,	0,	fdb	},

	{ "INC",	0,	0x0c,	0,	memory	},
	{ "INCA",	0,	0x4c,	0,	none	},
	{ "INCB",	0,	0x5c,	0,	none	},
#ifndef	MC6809
	{ "INS",	0,	0x31,	0,	none	},
	{ "INX",	0,	0x08,	0,	none	},
#endif

	{ "JMP",	0,	0x0e,	0,	memory	},
	{ "JSR",	0,	0x8d,	0,	store	},

#ifdef	MC6809
	{ "LBCC",	0x10,	0x24,	0,	lbranch	},
	{ "LBCS",	0x10,	0x25,	0,	lbranch	},
	{ "LBEQ",	0x10,	0x27,	0,	lbranch	},
	{ "LBGE",	0x10,	0x2c,	0,	lbranch	},
	{ "LBGT",	0x10,	0x2e,	0,	lbranch	},
	{ "LBHI",	0x10,	0x22,	0,	lbranch	},
	{ "LBHS",	0x10,	0x24,	0,	lbranch	},
	{ "LBLE",	0x10,	0x2f,	0,	lbranch	},
	{ "LBLO",	0x10,	0x25,	0,	lbranch	},
	{ "LBLS",	0x10,	0x23,	0,	lbranch	},
	{ "LBLT",	0x10,	0x2d,	0,	lbranch	},
	{ "LBMI",	0x10,	0x2b,	0,	lbranch	},
	{ "LBNE",	0x10,	0x26,	0,	lbranch	},
	{ "LBPL",	0x10,	0x2a,	0,	lbranch	},
	{ "LBRA",	0,	0x16,	0,	lbranch	},
	{ "LBRN",	0x10,	0x21,	0,	lbranch	},
	{ "LBSR",	0,	0x17,	0,	lbranch	},
	{ "LBVC",	0x10,	0x28,	0,	lbranch	},
	{ "LBVS",	0x10,	0x29,	0,	lbranch	},
#endif
#ifdef	MC6809
	{ "LDA",	0,	0x86,	0,	load	},
	{ "LDB",	0,	0xc6,	0,	load	},
#else
	{ "LDAA",	0,	0x86,	0,	load	},
	{ "LDAB",	0,	0xc6,	0,	load	},
#endif
	{ "LDD",	0,	0xcc,	MC6801,	load2	},
#ifdef	MC6809
	{ "LDS",	0x10,	0xce,	0,	load2	},
	{ "LDU",	0,	0xce,	0,	load2	},
	{ "LDX",	0,	0x8e,	0,	load2	},
	{ "LDY",	0x10,	0x8e,	0,	load2	},
	{ "LEAS",	0,	0x32,	0,	lea	},
	{ "LEAU",	0,	0x33,	0,	lea	},
	{ "LEAX",	0,	0x30,	0,	lea	},
	{ "LEAY",	0,	0x31,	0,	lea	},
#else
	{ "LDS",	0,	0x8e,	0,	load2	},
	{ "LDX",	0,	0xce,	0,	load2	},
#endif
	{ "LIB",	0,	0,	0,	library	},
	{ "LSL",	0,	0x08,	0,	memory	},
	{ "LSLA",	0,	0x48,	0,	none	},
	{ "LSLB",	0,	0x58,	0,	none	},
#ifndef	MC6809
	{ "LSLD",	0,	0x05,	MC6801,	none	},
#endif
	{ "LSR",	0,	0x04,	0,	memory	},
	{ "LSRA",	0,	0x44,	0,	none	},
	{ "LSRB",	0,	0x54,	0,	none	},
#ifndef	MC6809
	{ "LSRD",	0,	0x04,	MC6801,	none	},
#endif

	{ "MUL",	0,	0x3d,	MC6801,	none	},
	{ "NAM",	0,	0,	0,	nam	},

	{ "NEG",	0,	0x00,	0,	memory	},
	{ "NEGA",	0,	0x40,	0,	none	},
	{ "NEGB",	0,	0x50,	0,	none	},
#ifdef	MC6809
	{ "NOP",	0,	0x12,	0,	none	},
#else
	{ "NOP",	0,	0x01,	0,	none	},
#endif

#ifdef	MC6809
	{ "ORA",	0,	0x8a,	0,	load	},
	{ "ORB",	0,	0xca,	0,	load	},
	{ "ORCC",	0,	0x1a,	0,	ccr	},
#else
	{ "ORAA",	0,	0x8a,	0,	load	},
	{ "ORAB",	0,	0xca,	0,	load	},
#endif
	{ "ORG",	0,	0,	0,	org	},

	{ "PAGE",	0,	0,	0,	page	},
#ifdef	MC6809
	{ "PSHS",	0,	0x34,	0,	stacks	},
	{ "PSHU",	0,	0x36,	0,	stacku	},
	{ "PULS",	0,	0x35,	0,	stacks	},
	{ "PULU",	0,	0x37,	0,	stacku	},
#else
	{ "PSHA",	0,	0x36,	0,	none	},
	{ "PSHB",	0,	0x37,	0,	none	},
	{ "PSHX",	0,	0x3c,	MC6801,	none	},
	{ "PULA",	0,	0x32,	0,	none	},
	{ "PULB",	0,	0x33,	0,	none	},
	{ "PULX",	0,	0x38,	MC6801,	none	},
#endif

	{ "RMB",	0,	0,	0,	rmb	},
	{ "ROL",	0,	0x09,	0,	memory	},
	{ "ROLA",	0,	0x49,	0,	none	},
	{ "ROLB",	0,	0x59,	0,	none	},
	{ "ROR",	0,	0x06,	0,	memory	},
	{ "RORA",	0,	0x46,	0,	none	},
	{ "RORB",	0,	0x56,	0,	none	},
	{ "RTI",	0,	0x3b,	0,	none	},
	{ "RTS",	0,	0x39,	0,	none	},

#ifndef	MC6809
	{ "SBA",	0,	0x10,	0,	none	},
#endif
	{ "SBCA",	0,	0x82,	0,	load	},
	{ "SBCB",	0,	0xc2,	0,	load	},
#ifndef	MC6809
	{ "SEC",	0,	0x0d,	0,	none	},
	{ "SEI",	0,	0x0f,	0,	none	},
	{ "SEV",	0,	0x0b,	0,	none	},
#endif
#ifdef	MC6809
	{ "SETDP",	0,	0,	0,	setdp	},
	{ "SEX",	0,	0x1d,	0,	none	},
#endif
	{ "SPC",	0,	0,	0,	spc	},
#ifdef	MC6809
	{ "STA",	0,	0x87,	0,	store	},
	{ "STB",	0,	0xc7,	0,	store	},
#else
	{ "STAA",	0,	0x87,	0,	store	},
	{ "STAB",	0,	0xc7,	0,	store	},
#endif
	{ "STD",	0,	0xcd,	MC6801,	store	},
#ifdef	MC6809
	{ "STS",	0x10,	0xcf,	0,	store	},
	{ "STU",	0,	0xcf,	0,	store	},
	{ "STX",	0,	0x8f,	0,	store	},
	{ "STY",	0x10,	0x8f,	0,	store	},
#else
	{ "STS",	0,	0x8f,	0,	store	},
	{ "STX",	0,	0xcf,	0,	store	},
#endif
	{ "SUBA",	0,	0x80,	0,	load	},
	{ "SUBB",	0,	0xc0,	0,	load	},
	{ "SUBD",	0,	0x83,	MC6801,	load2	},
	{ "SWI",	0,	0x3f,	0,	none	},
#ifdef	MC6809
	{ "SWI2",	0x10,	0x3f,	0,	none	},
	{ "SWI3",	0x11,	0x3f,	0,	none	},
	{ "SYNC",	0,	0x13,	0,	none	},
#endif

#ifdef	MC6809
	{ "TFR",	0,	0x1f,	0,	transfer	},
#else
	{ "TAB",	0,	0x16,	0,	none	},
	{ "TAP",	0,	0x06,	0,	none	},
	{ "TBA",	0,	0x17,	0,	none	},
	{ "TPA",	0,	0x07,	0,	none	},
#endif
	{ "TST",	0,	0x0d,	0,	memory	},
	{ "TSTA",	0,	0x4d,	0,	none	},
	{ "TSTB",	0,	0x5d,	0,	none	},
#ifndef	MC6809
	{ "TSX",	0,	0x30,	0,	none	},
	{ "TXS",	0,	0x35,	0,	none	},
#endif

#ifndef	MC6809
	{ "WAI",	0,	0x3e,	0,	none	},
#endif

	{ "",		0,	0,	0,	none	} };

/* opcode table hash */
OPTABLE *ophash[256];

/* addressing mode offset table 'offset[group][mode]' */
int	offset[3][4] = {
		{ 0,	0,	0,	0	},
		{ 0,	0,	0x60,	0x70	},
		{ 0,	0x10,	0x20,	0x30	} };

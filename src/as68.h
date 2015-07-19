/************************************************
 *						*
 *	MC6800/6801/6803/6809 corss assembler	*
 *						*
 ************************************************/

#ifdef	DEBUG
#undef	DEBUG
#define	DEBUG(x)	if (debug) {x;}
#else
#define	DEBUG(x)
#endif

#define	MC6801		1

/* buffer size */
#define	LBLSIZE		15
#define	MAXLABEL	256
#define	MNEMOSIZE	7
#define	MAXCHAR		256
#define	LINEHEAD	24
#define	OBJSIZE		32
#define	FNAMESZ		MAXCHAR
#define	MAXLIB		8

/* register notation */
#define	NONE		0
#define	CC		0x01
#define	A		0x02
#define	B		0x04
#define	D		0x06
#define	DP		0x08
#define	X		0x10
#define	Y		0x20
#define	U		0x40
#define	S		0x80
#define	PC		0x100
#define	PCR		0x200
#define INDEXREG	(X|Y|U|S)
#define	ALLREG		(CC|A|B|D|DP|X|Y|U|S|PC)

/* addressing mode */
#define	IMMEDIATE	0x01
#define	IMMEDIATE2	0x02
#define	DIRECT		0x04
#define	INDEX		0x08
#define	EXTEND		0x10
#define	LOAD		(IMMEDIATE|DIRECT|INDEX|EXTEND)
#define	LOAD2		(IMMEDIATE2|DIRECT|INDEX|EXTEND)
#define	STORE		(DIRECT|INDEX|EXTEND)
#ifdef	MC6809
#define	MEMORY		(DIRECT|INDEX|EXTEND)
#else
#define	MEMORY		(INDEX|EXTEND)
#endif

/* addressing mode variation group */
#define	GROUP0		0
#define	GROUP1		1
#define	GROUP2		2

/* mode offset */
#define	NO_MODE		0
#define	IMMEDIATE_MODE	0
#define	DIRECT_MODE	1
#define	INDEX_MODE	2
#define	EXTEND_MODE	3

/* opcode table */
typedef	struct opt {
		char mnemonic[MNEMOSIZE + 1];
		unsigned char prefix;
		unsigned char opcode;
		unsigned char option;
		int (*process)();
		struct opt *nl; } OPTABLE;

/* label table */
typedef	struct lt {
		char name[LBLSIZE + 1];
		int line;
		int value;
		struct lt *left,*right; } LBLTABLE;


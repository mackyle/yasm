/**
 * \file coretype.h
 * \brief YASM core type definitions.
 *
 * $IdPath$
 *
 *  Copyright (C) 2001  Peter Johnson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND OTHER CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR OTHER CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef YASM_CORETYPE_H
#define YASM_CORETYPE_H

/** Architecture interface.  \see arch.h for details. */
typedef struct yasm_arch yasm_arch;
/** Preprocessor interface.  \see preproc.h for details. */
typedef struct yasm_preproc yasm_preproc;
/** Parser interface.  \see parser.h for details. */
typedef struct yasm_parser yasm_parser;
/** Optimizer interface.  \see optimizer.h for details. */
typedef struct yasm_optimizer yasm_optimizer;
/** Object format interface.  \see objfmt.h for details. */
typedef struct yasm_objfmt yasm_objfmt;
/** Debug format interface.  \see dbgfmt.h for details. */
typedef struct yasm_dbgfmt yasm_dbgfmt;

/** Bytecode (opaque type).
 * \see bytecode.h for related functions.
 * Define YASM_BC_INTERNAL to get visible internals.
 */
typedef struct yasm_bytecode yasm_bytecode;
/** List of bytecodes (opaque type).  \see bytecode.h for related functions. */
typedef struct yasm_bytecodehead yasm_bytecodehead;

/** Section (opaque type).  \see section.h for related functions. */
typedef struct yasm_section yasm_section;
/** List of sections (opaque type).  \see section.h for related functions. */
typedef struct yasm_sectionhead yasm_sectionhead;

/** Symbol record (opaque type).  \see symrec.h for related functions. */
typedef struct yasm_symrec yasm_symrec;

/** Expression (opaque type).
 * \see expr.h for related functions.
 * Define YASM_EXPR_INTERNAL to get visible internals.
 */
typedef struct yasm_expr yasm_expr;
/** Integer value (opaque type).  \see intnum.h for related functions. */
typedef struct yasm_intnum yasm_intnum;
/** Floating point value (opaque type).
 * \see floatnum.h for related functions.
 */
typedef struct yasm_floatnum yasm_floatnum;

/** Line number management interface.  \see linemgr.h for more details. */
typedef struct yasm_linemgr yasm_linemgr;

/** Value/parameter pair (opaque type).
 * \see valparam.h for related functions.
 */
typedef struct yasm_valparam yasm_valparam;
/** List of value/parameters (opaque type).
 * \see valparam.h for related functions.
 */
typedef struct yasm_valparamhead yasm_valparamhead;

/** Expression operators usable in #yasm_expr expressions. */
typedef enum {
    YASM_EXPR_IDENT,	/**< No operation, just a value. */
    YASM_EXPR_ADD,	/**< Arithmetic addition (+). */
    YASM_EXPR_SUB,	/**< Arithmetic subtraction (-). */
    YASM_EXPR_MUL,	/**< Arithmetic multiplication (*). */
    YASM_EXPR_DIV,	/**< Arithmetic unsigned division. */
    YASM_EXPR_SIGNDIV,	/**< Arithmetic signed division. */
    YASM_EXPR_MOD,	/**< Arithmetic unsigned modulus. */
    YASM_EXPR_SIGNMOD,	/**< Arithmetic signed modulus. */
    YASM_EXPR_NEG,	/**< Arithmetic negation (-). */
    YASM_EXPR_NOT,	/**< Bitwise negation. */
    YASM_EXPR_OR,	/**< Bitwise OR. */
    YASM_EXPR_AND,	/**< Bitwise AND. */
    YASM_EXPR_XOR,	/**< Bitwise XOR. */
    YASM_EXPR_SHL,	/**< Shift left (logical). */
    YASM_EXPR_SHR,	/**< Shift right (logical). */
    YASM_EXPR_LOR,	/**< Logical OR. */
    YASM_EXPR_LAND,	/**< Logical AND. */
    YASM_EXPR_LNOT,	/**< Logical negation. */
    YASM_EXPR_LT,	/**< Less than comparison. */
    YASM_EXPR_GT,	/**< Greater than comparison. */
    YASM_EXPR_EQ,	/**< Equality comparison. */
    YASM_EXPR_LE,	/**< Less than or equal to comparison. */
    YASM_EXPR_GE,	/**< Greater than or equal to comparison. */
    YASM_EXPR_NE,	/**< Not equal comparison. */
    YASM_EXPR_NONNUM,	/**< Start of non-numeric operations (not an op). */
    YASM_EXPR_SEG,	/**< SEG operator (gets segment portion of address). */
    YASM_EXPR_WRT,	/**< WRT operator (gets offset of address relative to
			 *   some other segment). */
    YASM_EXPR_SEGOFF	/**< The ':' in segment:offset. */
} yasm_expr_op;

/** Symbol record visibility.
 * \see symrec.h for related functions.
 * \note YASM_SYM_EXTERN and YASM_SYM_COMMON are mutually exclusive.
 */
typedef enum {
    YASM_SYM_LOCAL = 0,		/**< Default, local only */
    YASM_SYM_GLOBAL = 1 << 0,	/**< If symbol is declared GLOBAL */
    YASM_SYM_COMMON = 1 << 1,	/**< If symbol is declared COMMON */
    YASM_SYM_EXTERN = 1 << 2	/**< If symbol is declared EXTERN */
} yasm_sym_vis;

/** Determine the distance between the starting offsets of two bytecodes in a
 * section.
 * \param sect		section containing the two bytecodes
 * \param precbc1	preceding bytecode to the first bytecode (NULL
 *			indicates first bytecode in section)
 * \param precbc2	preceding bytecode to the second bytecode (NULL
 *			indicates first bytecode in section)
 * \return Distance in bytes between the two bytecodes (bc2-bc1), or NULL if
 *	   the distance was indeterminate.
 */
typedef /*@null@*/ yasm_intnum * (*yasm_calc_bc_dist_func)
    (yasm_section *sect, /*@null@*/ yasm_bytecode *precbc1,
     /*@null@*/ yasm_bytecode *precbc2);

/** Convert yasm_expr to its byte representation.  Usually implemented by
 * object formats to keep track of relocations and verify legal expressions.
 * \param ep		(double) pointer to expression
 * \param bufp		(double) pointer to buffer for byte representation
 * \param valsize	size (in bytes) of the byte representation
 * \param offset	offset (in bytes) of the expr contents from the start
 *			of the bytecode (sometimes needed for conditional jumps)
 * \param sect		current section (usually passed into higher-level
 *			calling function)
 * \param bc		current bytecode (usually passed into higher-level
 *			calling function)
 * \param rel		if nonzero, expr should be treated as PC/IP-relative
 * \param d		objfmt-specific data (passed into higher-level calling
 *			function)
 * \return Nonzero if an error occurred, 0 otherwise.
 */
typedef int (*yasm_output_expr_func)
    (yasm_expr **ep, unsigned char **bufp, unsigned long valsize,
     unsigned long offset, /*@observer@*/ const yasm_section *sect,
     yasm_bytecode *bc, int rel, /*@null@*/ void *d)
    /*@uses *ep@*/ /*@sets **bufp@*/;

/** Convert a yasm_objfmt-specific data bytecode into its byte representation.
 * Usually implemented by object formats to output their own generated data.
 * \param type		yasm_objfmt-specific type
 * \param data		data
 * \param bufp		(double) pointer to buffer for byte representation
 * \note bufp is guaranteed to have enough space to store the data into (as
 *	 given by the original yasm_bc_new_objfmt_data() call).
 * \return Nonzero if an error occurred, 0 otherwise.
 */
typedef int (*yasm_output_bc_objfmt_data_func)
    (unsigned int type, /*@observer@*/ void *data, unsigned char **bufp)
    /*@sets **bufp@*/;
#endif
# $IdPath$

TESTS += modules/objfmts/elf/tests/elf_test.sh

EXTRA_DIST += modules/objfmts/elf/tests/elf_test.sh
EXTRA_DIST += modules/objfmts/elf/tests/elfsectalign.asm
EXTRA_DIST += modules/objfmts/elf/tests/elfsectalign.hex
EXTRA_DIST += modules/objfmts/elf/tests/elfsectalign.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elftest.c
EXTRA_DIST += modules/objfmts/elf/tests/elftest.asm
EXTRA_DIST += modules/objfmts/elf/tests/elftest.hex
EXTRA_DIST += modules/objfmts/elf/tests/elftest.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elftimes.asm
EXTRA_DIST += modules/objfmts/elf/tests/elftimes.hex
EXTRA_DIST += modules/objfmts/elf/tests/elftimes.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elf-x86id.asm
EXTRA_DIST += modules/objfmts/elf/tests/elf-x86id.hex
EXTRA_DIST += modules/objfmts/elf/tests/elf-x86id.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elfreloc.asm
EXTRA_DIST += modules/objfmts/elf/tests/elfreloc.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elfreloc.hex
EXTRA_DIST += modules/objfmts/elf/tests/elfglobal.asm
EXTRA_DIST += modules/objfmts/elf/tests/elfglobal.errwarn
EXTRA_DIST += modules/objfmts/elf/tests/elfglobal.hex
EXTRA_DIST += modules/objfmts/elf/tests/elfreloc-err.asm
EXTRA_DIST += modules/objfmts/elf/tests/elfreloc-err.errwarn

EXTRA_DIST += modules/objfmts/elf/tests/amd64/Makefile.inc

include modules/objfmts/elf/tests/amd64/Makefile.inc
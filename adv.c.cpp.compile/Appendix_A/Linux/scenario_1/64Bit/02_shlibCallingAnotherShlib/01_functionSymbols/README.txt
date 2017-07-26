Important findings:

The Scenario 1 implementation within the shared libraries
may have two flavors:
- PIC approach, based on plt / got.plt
- LTR approach, i.e. direct substitution of function address

LTR: pay attention: symbol to resolve is in rel.dyn section
============================================================
$ readelf -r libfirst.so

Relocation section '.rel.dyn' at offset 0x30c contains 5 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00002008  00000008 R_386_RELATIVE   
00000473  00000402 R_386_PC32        00000000   second_shlib_function
00001fe8  00000106 R_386_GLOB_DAT    00000000   __cxa_finalize
00001fec  00000206 R_386_GLOB_DAT    00000000   __gmon_start__
00001ff0  00000306 R_386_GLOB_DAT    00000000   _Jv_RegisterClasses

Relocation section '.rel.plt' at offset 0x334 contains 2 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00002000  00000107 R_386_JUMP_SLOT   00000000   __cxa_finalize
00002004  00000207 R_386_JUMP_SLOT   00000000   __gmon_start__

disassembled code: the @plt is nowhere to be found
--------------------------------------------------------------------------
$ objdump -d -S -M intel libfirst.so | grep -A 10 shlib_function


0000046c <shlib_function>:
 46c:	55                   	push   ebp
 46d:	89 e5                	mov    ebp,esp
 46f:	83 ec 08             	sub    esp,0x8
 472:	e8 fc ff ff ff       	call   473 <shlib_function+0x7>
 477:	c9                   	leave  
 478:	c3                   	ret    
 479:	90                   	nop
 47a:	90                   	nop
 47b:	90                   	nop
 47c:	90                   	nop
 47d:	90                   	nop
 47e:	90                   	nop
 47f:	90                   	nop

PIC: pay attention: symbol to resolve is in rel.plt section
============================================================
$ readelf -r libfirst.so

Relocation section '.rel.dyn' at offset 0x30c contains 4 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0000200c  00000008 R_386_RELATIVE   
00001fe8  00000106 R_386_GLOB_DAT    00000000   __cxa_finalize
00001fec  00000206 R_386_GLOB_DAT    00000000   __gmon_start__
00001ff0  00000306 R_386_GLOB_DAT    00000000   _Jv_RegisterClasses

Relocation section '.rel.plt' at offset 0x32c contains 3 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00002000  00000107 R_386_JUMP_SLOT   00000000   __cxa_finalize
00002004  00000207 R_386_JUMP_SLOT   00000000   __gmon_start__
00002008  00000407 R_386_JUMP_SLOT   00000000   second_shlib_function
000003b0 <second_shlib_function@plt>:
 3b0:	ff a3 14 00 00 00    	jmp    DWORD PTR [ebx+0x14]
 3b6:	68 10 00 00 00       	push   0x10
 3bb:	e9 c0 ff ff ff       	jmp    380 <_init+0x3c>

disassembled code: the presence of @plt is obvious in the call instruction
--------------------------------------------------------------------------
$ objdump -d -S -M intel libfirst.so | grep -A 10 shlib_function

Disassembly of section .text:
0000047c <shlib_function>:
 47c:	55                   	push   ebp
 47d:	89 e5                	mov    ebp,esp
 47f:	53                   	push   ebx
 480:	83 ec 04             	sub    esp,0x4
 483:	e8 ef ff ff ff       	call   477 <__i686.get_pc_thunk.bx>
 488:	81 c3 6c 1b 00 00    	add    ebx,0x1b6c
 48e:	e8 1d ff ff ff       	call   3b0 <second_shlib_function@plt>
 493:	83 c4 04             	add    esp,0x4
 496:	5b                   	pop    ebx
 497:	5d                   	pop    ebp
 498:	c3                   	ret    
 499:	90                   	nop
 49a:	90                   	nop
 49b:	90                   	nop
 49c:	90                   	nop
 49d:	90                   	nop
 49e:	90                   	nop


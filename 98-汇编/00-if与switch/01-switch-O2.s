	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	ldr	x8, [x1]
	ldrsb	x8, [x8]
	sub	x8, x8, #1
	cmp	w8, #2
	b.hi	LBB0_2
; %bb.1:
Lloh0:
	adrp	x9, l_switch.table.main@PAGE
Lloh1:
	add	x9, x9, l_switch.table.main@PAGEOFF
	ldr	x0, [x9, x8, lsl #3]
	b	LBB0_3
LBB0_2:
Lloh2:
	adrp	x0, l_str.6@PAGE
Lloh3:
	add	x0, x0, l_str.6@PAGEOFF
LBB0_3:
	bl	_puts
	mov	w0, #0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.loh AdrpAdd	Lloh0, Lloh1
	.loh AdrpAdd	Lloh2, Lloh3
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_str:                                  ; @str
	.asciz	"Number is 3"

l_str.4:                                ; @str.4
	.asciz	"Number is 2"

l_str.5:                                ; @str.5
	.asciz	"Number is 1"

l_str.6:                                ; @str.6
	.asciz	"Number is not 1, 2, or 3"

	.section	__DATA,__const
	.p2align	3, 0x0                          ; @switch.table.main
l_switch.table.main:
	.quad	l_str.5
	.quad	l_str.4
	.quad	l_str

.subsections_via_symbols

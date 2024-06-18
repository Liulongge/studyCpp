	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	str	x1, [sp, #16]
	ldr	x8, [sp, #16]
	ldr	x8, [x8]
	ldrb	w8, [x8]
	strb	w8, [sp, #15]
	ldrsb	w8, [sp, #15]
	str	w8, [sp, #8]                    ; 4-byte Folded Spill
	subs	w8, w8, #1
	cset	w8, eq
	tbnz	w8, #0, LBB0_3
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	subs	w8, w8, #2
	cset	w8, eq
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	subs	w8, w8, #3
	cset	w8, eq
	tbnz	w8, #0, LBB0_5
	b	LBB0_6
LBB0_3:
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB0_7
LBB0_4:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB0_7
LBB0_5:
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB0_7
LBB0_6:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	b	LBB0_7
LBB0_7:
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Number is 1\n"

l_.str.1:                               ; @.str.1
	.asciz	"Number is 2\n"

l_.str.2:                               ; @.str.2
	.asciz	"Number is 3\n"

l_.str.3:                               ; @.str.3
	.asciz	"Number is not 1, 2, or 3\n"

.subsections_via_symbols

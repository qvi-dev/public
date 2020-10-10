	.file	1 "test_LIW.c"

	.section .mdebug.abi32

	.previous

	.nan	2008

	.module	fp=64

	.module	oddspreg

	.abicalls

	.text

	.align	2

	.globl	func

	.set	nomips16

	.set	nomicromips

	.ent	func

	.type	func, @function

func:

	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0

	.mask	0x00000000,0

	.fmask	0x00000000,0

#APP

 # 20 "/home/zhliu/project/inndk/inni/simdTest/source/test_LIW.c" 1

	.word	0x4b205040
 # 0 "" 2

 # 21 "/home/zhliu/project/inndk/inni/simdTest/source/test_LIW.c" 1

	.word	0x708008d5
 # 0 "" 2

 # 22 "/home/zhliu/project/inndk/inni/simdTest/source/test_LIW.c" 1

	.word	0x70810ad5
 # 0 "" 2

#NO_APP

	j	$31

	.end	func

	.size	func, .-func

	.ident	"GCC: (Ingenic r3.2.0-gcc520 2017.08-24) 5.2.0"


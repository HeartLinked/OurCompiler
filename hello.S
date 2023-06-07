	.text
	.globl getnum
getnum:
  addi  sp, sp, -16
  sw    ra, 12(sp)
  call getint
  sw    a0, 0(sp)
  lw    t0, 0(sp)
  sw    t0, 4(sp)
  lw    t0, 4(sp)
  sw    t0, 8(sp)
  lw    a0, 8(sp)
  lw    ra, 12(sp)
  addi  sp, sp, 16
  ret


	.text
	.globl main
main:
  addi  sp, sp, -16
  sw    ra, 12(sp)
  call getnum
  sw    a0, 0(sp)
  lw    t0, 0(sp)
  sw    t0, 4(sp)
  lw    t0, 4(sp)
  sw    t0, 8(sp)
  lw    a0, 8(sp)
  call putint
  li    a0, 10
  call putch
  li    a0, 0
  lw    ra, 12(sp)
  addi  sp, sp, 16
  ret



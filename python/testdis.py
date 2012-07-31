#!/usr/bin/python3
# -*- coding: utf-8 -*-

from beafork import *
from binascii import unhexlify, hexlify

code = unhexlify(b"55803da0092000004889e5415453756248833d4809200000740c488b3d7f092000e87affffff488d1d6b0720004c8d255c072000488b05750920004c29e348c1fb034883eb014839d873200f1f4400004883c0014889055509200041ff14c4488b054a0920004839d872e5c60536092000015b415c5dc3")

inss = disassemble_generator(code, 0x400000, 64)
for ins in inss:
    print("%08x: %-18s %s" % (ins.address, hexlify(ins.raw_bytes).decode(), ins))
    pass


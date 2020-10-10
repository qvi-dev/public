#!/usr/local/bin/python3
##        (C) COPYRIGHT Ingenic Limited.
##             ALL RIGHTS RESERVED
##
## File       : simd512_asm.py
## Authors    : tyliu@boaz.ic.jz.com
## Create Time: 2018-08-31:14:47:08
## Description:
## 
##
import os
import sys
import re
import string

sys.path.append("./")
from def_mxu3_asm import *
from def_mxu3_disasm import *

def usage():
    print("mxu3_disasm.py <insn(0x00000000)>")
    sys.exit()

class asm_msg:
    def __init__(self):
        self.guid           = 0
        self.name           = ''
        self.field          = []
        self.comment        = ''
        self.asm_str        = ''
        self.code           = 0
    
if __name__=="__main__":
    if len(sys.argv) != 2:
        usage()
    elif(sys.argv[1]=="--help" or sys.argv[1]=="-h" ):
        usage()

    asm = asm_msg();
    asm.code = int(sys.argv[1], 16)

    def_mxu3_disasm(asm)

    sys.exit()
        

E001:   LDX	#01F4
        STX         81
        CLR         009C
        LDAB            0217
        LDAA           0216
TTTT:
        ADDB            #38
        ADCA            #E9
		DEX
		BCC				TTTT
        STAB            85
        STAA            84
  yb:      JSR            yb1
        LDX             88
        STX             0200
yb1:        STX             8B,x
        STX             8E
        JSR             yb
        STAB            0202
        LDAA            8B
        ;SQAA            0203


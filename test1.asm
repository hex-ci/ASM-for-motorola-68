    @e310
    @[sg1test.dmp]
    ;@[sc6zt.dmp]
    aa=e310

    ldaa #11
    staa 8d
    clra
    clrb
    clr 0083
 aa2:   bcc aa1
    psha
    ldaa 83
    adda 6f
    staa 83
    adcb 8f
    pula
    adca 8e
 aa1:   rora
    rorb
    ror 0083
    ror 00b8
    ror 008c
    dec 008d
    bne aa2
    rts

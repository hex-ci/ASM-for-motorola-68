              @E0A0
              @[SC6ZT.dmp]

              CSCX=E480
              FD8D=FD8D
              TZ=FA2C
              JT=F9AE
              KPTM=E467

              ;kkkkkkddddaaaaa;ffffffasf
              ; bbbbb          bbbb
              ldaa 0a
         FS:  JSR FD8D
              jmp fs
              FCB 5B
              FCB 0F
              FCB 1D
              FCB 05
              FCB 4F
              FCB 80
              LDX #B3
              STX EC
              LDX B5
              STX EE
              LDX EC
              LDAA EE
              LDAB EF
              SUBB ED
              SBCA EC
              jsr tz
              JSR FD8D
              FCB 4F
              FCB 15
              FCB 3D
              FCB 00
              FCB 00
              FCB 80
              RTS
              NOP
              NOP
              NOP
         DTF: LDAA 1800
              ORAA #01
              STAA 1800
              LDAB #01
        DTF1: LDX #FFFF
        DTF2: DEX
              BNE DTF2
              DECB
              BNE DTF1
              RTS
         DTS: LDAA 1800
              ANDA #FE
              STAA 1800
              RTS
           JS:JSR JT
              JSR KPTM
              RTS
          PTM:LDAA #00
              STAA 6001
              LDX #00FC
              STX 6002
              LDX #270F
              STX 6006
              LDAA #82
              STAA 6000
              LDAA #01
              STAA 6001
              LDAA #40
              STAA 6000
              RTS
        IRQ1: LDAA 6001
              LDAA 6002
              JSR CSCX
              LDAA #01
              STAA B2
              CLI
              RTI
              RTI
	aa: 
	 	asl 79,X


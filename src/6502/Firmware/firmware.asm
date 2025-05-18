.segment "CODE"

_start:
    .org $C000
    ; Setup System vectors
    LDA #$C0
    STA $FFFA
    STA $FFFC
    LDA #$00
    STA $FFFB
    STA $FFFD
    LDA #$0
    STA $FFFE
    LDA #$0
    STA $FFFF

    
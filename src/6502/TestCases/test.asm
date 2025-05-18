.segment "CODE"

_start:
    LDX #$35
    LDA #$25
    STA $50,X
    LDA #$20
    STA $51,X
    LDA #$10
    STA $2025
    LDA #$16
    SEC
    SBC ($50,X)
    rts
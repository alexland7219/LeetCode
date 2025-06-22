IsPrime ← {2=+/0=(⍳⍵)|⍵}
CheckPrimeFreqs ←  {∨/IsPrime¨+/∘.=⍨⍵}
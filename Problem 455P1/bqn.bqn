IsPrime ← {2=+´0=(1+↕)⊸|𝕩} # from BQN Crate

CheckPrimeFreq ← ∨´·IsPrime¨·+´˘=⌜˜

•Show CheckPrimeFreq 1‿2‿3‿4‿5‿4
•Show CheckPrimeFreq 1‿2‿3‿4‿5
CheckPrimeFreq 2‿2‿2‿4‿4
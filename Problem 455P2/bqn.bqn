FindCoins ← {
    res ← ⟨⟩
    aux ← (≠𝕩)⥊0
    {
      i ← ⊑⌽𝕩
      p ← ⊑𝕩
      q ← i⊑aux
      p -◶{𝕤}‿{
        𝕤 ⋄ aux↩1⊸+⌾(i⊸⊑)aux
        res ∾↩ ⋈1+i
        j ← 0
        { 𝕤 ⋄ k ← 1+i+j
          aux↩(j⊑aux)⊸+⌾(k⊸⊑) aux
          j +↩ 1
        }⍟(≠aux)⎊{𝕤} @
      } q
      
    }¨(𝕩∾¨↕≠𝕩)
    
    res
}⎊(⟨⟩˙)

FindCoins 0‿1‿2
# Hamming Code (12,8)

---

# Step 1: Original Data (8 bits)

```
Data = 10110010
```

---

# Step 2: Place Bits in Hamming Positions   

Parity bits go at powers of 2.   

| Pos  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |
| ---- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| Type | P1 | P2 | D1 | P4 | D2 | D3 | D4 | P8 | D5 | D6 | D7 | D8 |

Now place data bits (10110010):   

| Pos | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
| --- | - | - | - | - | - | - | - | - | - | -- | -- | -- |
| Val | ? | ? | 1 | ? | 0 | 1 | 1 | ? | 0 | 0  | 1  | 0  |

---

# Step 3: Calculate Parity Bits

Each parity bit checks positions where its binary bit is `1`.   
## Pattern of Parity Bits

### Rule:

A parity bit at position `2^k` checks all positions whose binary representation has bit `k = 1`.

---

### Binary Position Table

| Position | Binary |
| -------- | ------ |
| 1        | 0001   |
| 2        | 0010   |
| 3        | 0011   |
| 4        | 0100   |
| 5        | 0101   |
| 6        | 0110   |
| 7        | 0111   |
| 8        | 1000   |
| 9        | 1001   |
| 10       | 1010   |
| 11       | 1011   |
| 12       | 1100   |

---

## P1 checks positions: (P1 placed at $2^0$=1; 1 = 0001)

1(000`1`), 3(001`1`), 5(010`1`), 7(011`1`), 9(100`1`), 11(101`1`)

```
= bits at 3,5,7,9,11
= 1 ⊕ 0 ⊕ 1 ⊕ 0 ⊕ 1
```

Number of 1s = 3 (odd)
So:

```
P1 = 1
```

---

## P2 checks positions: (P2 placed at $2^1$ = 2; 2 = 0010)

2(00`1`0), 3(00`1`1), 6(01`1`0), 7(01`1`1), 10(10`1`0), 11(10`1`1)

```
= 1 ⊕ 1 ⊕ 1 ⊕ 0 ⊕ 1
```

Number of 1s = 4 (even)
So:

```
P2 = 0
```

---

## P4 checks positions: (P4 placed at $2^2$ = 4; 4 = 0100)

4(0`1`00), 5(0`1`01), 6(0`1`10), 7(0`1`11), 12(1`1`00)

```
= 0 ⊕ 1 ⊕ 1 ⊕ 0
```

Number of 1s = 2 (even)
So:

```
P4 = 0
```

---

## P8 checks positions: (P8 placed at $2^3$ = 8; 8 = 1000)

8(`1`000), 9(`1`001), 10(`1`010), 11(`1`011), 12(`1`100)

```
= 0 ⊕ 0 ⊕ 1 ⊕ 0
```

Number of 1s = 1 (odd)
So:

```
P8 = 1
```

---

# Step 4: Final Transmitted Code

| Pos | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
| --- | - | - | - | - | - | - | - | - | - | -- | -- | -- |
| Val | 1 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 0 | 0  | 1  | 0  |

Transmitted:

```
101001110010
```

---

# Step 5: Real Error Happens

Assume bit at position 6 flips.

Original bit 6 = 1
Flipped → 0

Received:

```
101000110010
```

---

# Step 6: Receiver Recalculates Parity (Syndrome)

---

## Recalculate P1

Check positions 1, 3, 5, 7, 9, 11

```
1 ⊕ 1 ⊕ 0 ⊕ 1 ⊕ 0 ⊕ 1
```

Number of 1s = 4 (even)

```
S1 = 0
```

---

## Recalculate P2

Check 2, 3, 6, 7, 10, 11

```
0 ⊕ 1 ⊕ 0 ⊕ 1 ⊕ 0 ⊕ 1
```

Number of 1s = 3 (odd)

```
S2 = 1
```

---

## Recalculate P4

Check 4, 5, 6, 7, 12

```
0 ⊕ 0 ⊕ 0 ⊕ 1 ⊕ 0
```

Number of 1s = 1 (odd)

```
S4 = 1
```

---

## Recalculate P8

Check 8, 9, 10, 11, 12

```
1 ⊕ 0 ⊕ 0 ⊕ 1 ⊕ 0
```

Number of 1s = 2 (even)

```
S8 = 0
```

---

# Step 7: Form Syndrome

Write in order:

```
S8 S4 S2 S1
0   1  1  0
```

Binary:

```
0110
```

Convert to decimal:

```
0×8 + 1×4 + 1×2 + 0×1
= 4 + 2
= 6
```

Error position:

```
6
```

---

# Step 8: Correct It

Flip bit at position 6:

```
0 → 1
```

Corrected message:

```
101001110010
```

Original restored.

---
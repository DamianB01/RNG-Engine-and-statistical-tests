# 🎲 RNG Benchmark – Pseudorandom Number Generator Comparison

A high-performance C++ benchmark that generates **1,000,000 pseudorandom numbers** using two different algorithms and compares their **speed and statistical quality**.

---

## 📁 Project Structure
├── 🧠 main.cpp              # entry point, benchmark
├── 🎰 rng.h / rng.cpp       # LCG and MT19937 implementations
├── 📊 stats.h / stats.cpp   # statistical tests + histogram
├── 💾 csv.h / csv.cpp       # CSV export utilities
└── 📈 plot.py               # Python visualization (matplotlib)

---

## ⚙️ Generators

### 🔵 LCG (Linear Congruential Generator)

A classic and lightweight RNG defined by:

*Xₙ₊₁ = (a · Xₙ + c) mod m*

Implemented using `std::linear_congruential_engine`.

**✨ Properties:**
- ⚡ Extremely fast  
- 📉 Lower randomness quality  
- ⏳ Short period  

---

### 🟣 MT19937 (Mersenne Twister)

A modern high-quality pseudorandom generator with a huge period:

2¹⁹⁹³⁷ − 1

Implemented using `std::mt19937`.

**✨ Properties:**
- 🧠 High-quality randomness  
- 🐢 ~3.5× slower than LCG  
- 🔁 Extremely long period  

---

## 📊 Statistical Tests

📦 Chi-square - Uniformity across bins
📉 Kolmogorov–Smirnov - Deviation from U(0,1)
🔗 Serial correlation - Dependency between values

---

## 📈 Example Results (seed = 12345)

### 🔵 LCG
⏱️ Time: 0.0089s
📦 Chi-square: 16.02
📉 KS test: 0.000944
🔗 Serial correlation: 0.00115

### 🟣 MT19937

⏱️ Time: 0.0311s
📦 Chi-square: 7.06
📉 KS test: 0.000513
🔗 Serial correlation: 0.000260

---

## 🏆 Conclusion

- 🟣 **MT19937** → better statistical quality  
- 🔵 **LCG** → much faster (~3.5× speed advantage)  
- ⚖️ Trade-off between speed and randomness quality  

---

## 🔁 Seed (Reproducibility)

The program uses a fixed seed:
*seed = 12345*
This ensures:
- 🔒 identical results on every run  
- 🔁 reproducible benchmarks  
- 🧪 consistent statistical comparison  

---

💾 Output Files

After execution:

LCG_data.csv
MT19937_data.csv

---

📊 Visualization (Optional):

Run plots:
*python plot.py*

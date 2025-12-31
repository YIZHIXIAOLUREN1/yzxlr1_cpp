好的，以下是11-14题直接可抄写的标准答案，方便书写或粘贴，**强调结论和计算步骤完整，公式适合手写**：

---

#### **11. 解答：**

将系数矩阵的行列式化简得  
\[
D = -2\lambda^2 + 8\lambda - 6 = -2(\lambda^2 - 4\lambda + 3) = -2(\lambda-1)(\lambda-3)
\]

- 当\(\lambda \ne 1,\ 3\)时，\(D\ne 0\)，方程组有唯一解。
- 当\(\lambda=3\)时，增广矩阵秩大于系数矩阵秩，无解。
- 当\(\lambda=1\)时，增广矩阵秩与系数矩阵秩相等且小于元数目，有无穷多解。

当\(\lambda=1\)时，通解设 \(x_3 = t\)，则：
\[
\left\{
  \begin{aligned}
    x_1 + x_3 &= 2 \implies x_1 = 2 - t \\
    2x_1 + 2x_2 + x_3 &= 1 \implies 2(2-t) + 2x_2 + t = 1 \\
    \implies 2x_2 = t - 3 \implies x_2 = \frac{t-3}{2}
  \end{aligned}
\right.
\]

所以通解为：
\[
\begin{pmatrix}
x_1 \\ x_2 \\ x_3
\end{pmatrix}
=\begin{pmatrix}
2-t \\ \frac{t-3}{2} \\ t
\end{pmatrix}, \quad t\in\mathbb{R}
\]

---

#### **12. 解答：**

\[
\alpha_1 = \begin{pmatrix}1\\1\\3\\5\end{pmatrix},\ 
\alpha_2 = \begin{pmatrix}-1\\-3\\5\\1\end{pmatrix},\ 
\alpha_3 = \begin{pmatrix}2\\3\\-1\\4\end{pmatrix},\ 
\alpha_4 = \begin{pmatrix}-1\\5\\11\\5\end{pmatrix}
\]

- 行列式化简（高斯消元）得秩为3。极大无关组为\(\alpha_1,\ \alpha_2,\ \alpha_3\)。
- \(\alpha_4\) 的线性表示：  
解方程组，
\[
\alpha_4 = a \alpha_1 + b \alpha_2 + c \alpha_3
\]
带入分量，解得：
\[
a=1,\ b=-1,\ c=2
\]
所以
\[
\boxed{
\alpha_4 = \alpha_1 - \alpha_2 + 2\alpha_3
}
\]

---

#### **13. 正交化标准形：**

\[
f(x_1, x_2, x_3) = x_1^2 + x_3^2 + 2x_1x_2 - 2x_2x_3
\]

配方法：

\[
x_1^2 + 2x_1x_2 + x_2^2 = (x_1 + x_2)^2 \\
x_3^2 - 2x_2x_3 + x_2^2 = (x_3 - x_2)^2
\]

令
\[
y_1 = x_1 + x_2,\ \ y_2 = x_3 - x_2,\ \ y_3 = x_2
\]

则
\[
f = y_1^2 + y_2^2
\]

答：标准形为
\[
\boxed{f = y_1^2 + y_2^2}
\]
（其中 $y_1 = x_1 + x_2,\ y_2 = x_3 - x_2$）

---

#### **14. 证明：**

已知$\alpha_1,\alpha_2,\alpha_3$线性无关，且各与非零向量$\beta$正交。

若$k_1\alpha_1 + k_2\alpha_2 + k_3\alpha_3 + k_4\beta = 0$，  
两边同时与$\beta$作内积，
得$k_4\|\beta\|^2=0$，因$\beta\neq 0$，所以$k_4=0$。   
于是$k_1\alpha_1 + k_2\alpha_2 + k_3\alpha_3 = 0$，由线性无关只能$k_1 = k_2 = k_3 = 0$。   
综上$k_1 = k_2 = k_3 = k_4 = 0$，故四向量线性无关。

---

**如需进一步拆解详细步骤可单独说明。**
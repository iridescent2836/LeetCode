
同样，我们用参数表达来对交点进行表示：P+tR（投射点为P，投射方向为R）。

Triangle类的实现由三个点和各自的法向量以及材质组成，对于三角形ABC 内的任意一点Q， 向量AQ 、AB 、AC 线性相关，那么Q的坐标可以表示为如下的公式：

Q = ( 1 − u − v ) A + u B + v C = P + t R

u ( B − A ) + v ( C − A ) − t R = P − A

$T=\begin{bmatrix} B-A & C-A & -R \ \end{bmatrix}$

$x=\begin{bmatrix} u \ v \ t \end{bmatrix}$

T x = P − A ，则$x=T^{-1}(P-A)$

保证Q在三角形内，那么Q必须满足三个系数都在0到1之间，即u>0,v>0,u+v<1。并且t要满足在相交范围（>tmin）内。

最后返回hit的所需参数分别是t，材质和单位法向，单位法向由三个点的法向系数插值后单位化得到。


把公式显示给我
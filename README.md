# DigitalAlbumBasedOnSSE
基于SSE指令的相册，完成图片间渐变转变，通过SSE指令和多线程进行加速处理。


----------


## SSE指令
SSE(Streaming SIMD Extensions)是英特尔在其计算机芯片Pentium III中引入的SIMD指令集，即单指令可处理多数据。</br>
SSE支持多个128位寄存器。</br>
在目前主流的编程语言中，只有C和C++支持SSE指令。</br>
本项目中主要使用[SSE2中的函数][1]。
## 图片渐变
两幅图片进行变换的公式为：</br>
<a href="https://www.codecogs.com/eqnedit.php?latex=Result&space;Pixle&space;=&space;APixel&space;\times&space;fade&space;&plus;&space;BPixel&space;\times&space;(1&space;-&space;fade)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Result&space;Pixle&space;=&space;APixel&space;\times&space;fade&space;&plus;&space;BPixel&space;\times&space;(1&space;-&space;fade)" title="Result Pixle = APixel \times fade + BPixel \times (1 - fade)" /></a></br>
将公式进行如下变换，可减少一次乘法操作：</br>
<a href="https://www.codecogs.com/eqnedit.php?latex=Result&space;Pixle&space;=&space;(APixel&space;&plus;&space;BPixel)&space;\times&space;fade&space;&plus;&space;BPixel" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Result&space;Pixle&space;=&space;(APixel&space;&plus;&space;BPixel)&space;\times&space;fade&space;&plus;&space;BPixel" title="Result Pixle = (APixel + BPixel) \times fade + BPixel" /></a></br>
fade是渐变因子，当其从1逐渐变为0时，A图像就渐变至B图像。</br>
在实际的计算过程中，为了方便计算，fade从128逐渐变为0，且在每一次乘法计算后，将计算结果右移7位，这样就实现了fade从1逐渐变为0。


  [1]: https://www.cnblogs.com/galoishelley/p/4033254.html

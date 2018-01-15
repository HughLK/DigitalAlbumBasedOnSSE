# DigitalAlbumBasedOnSSE
基于SSE指令的相册，完成图片间渐变转变，通过SSE指令和多线程进行加速处理。


----------


## SSE指令
SSE(Streaming SIMD Extensions)是英特尔在其计算机芯片Pentium III中引入的SIMD指令集，即单指令可处理多数据。
SSE支持多个128位寄存器。
本项目中主要使用[SSE2中的函数][1]。
## 图片渐变
两幅图片进行变换的公式为：
$$Result Pixle = APixel \times fade + BPixel \times (1 - fade)$$
将公式进行如下变换，可减少一次乘法操作：
$$Result Pixle = （APixel + BPixel） \times fade + BPixel$$
fade是渐变因子，当其从1逐渐变为0时，A图像就渐变至B图像。
在实际的计算过程中，为了方便计算，fade从128逐渐变为0，且在每一次乘法计算后，将计算结果右移7位，这样就实现了fade从1逐渐变为0。


  [1]: https://www.cnblogs.com/galoishelley/p/4033254.html

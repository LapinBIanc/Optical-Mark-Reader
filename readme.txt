Team Members: Yunus Emre KÜTÜK,Hasan KARACA
Our project is accelarating a function in Optical Mark Reader application.

Content of the Folders:
doc folder contains: Project Final Report
hw folder contains: Hardware Platform Design Wrapper
ip folder contains: the IP core that we have designed on Vivado HLS
sw folder contains: necessary files on the SDK side

After importing the necessary files from the given folders,
1- You need to desing the block diagram. But first, the custom IP core must bu added
to IP repsitory from the project settings under the flow navigator.
2- Validate the design without any error.
3- Create output products, create HDL wrapper.
5- Write bitsream.
4- Export hardware including the bitstream.
On the SDK side:
1- You need to define header file that contains a represantation of our input image as an
array.
2- Finally you just need to assing memory addresses of the input and output array as
arguments to ip_handle function and it does the rest.


YouTube Link: https://youtu.be/bGizXE-Kc7k
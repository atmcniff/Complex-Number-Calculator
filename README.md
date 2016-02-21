# Complex-Number-Calculator
Read complex numbers from txt files and calculate them!

A [complex number](https://en.wikipedia.org/wiki/Complex_number) appears in the format...

[real number][+ or -][imaginary number]

...and there should only be one complex number per line.

This program isn't too picky with how complex numbers are respresented, but as long as there is at least some 
kind of resemblence to a complex number in the input file, everything should be fine. Small errors or weird looking 
complex numbers in the input file will be dealt with, but to know the extent to which errors can be made, remember this...

1. Either a real number is first or an "i" is last
2. NO SPACES 

...and once all complex numbers are read, it will printed out in the cleanest, most beautiful form possible.

##Input

This should give you an idea the possibilities


| Possible       |     Impossible |
| :---:         | :---:         |
|     3+4i      | 4i+2 |
| -6+i          |  -6    +    i |
| -33.54-69i    |    2+5-6i+2i |
|Happy Birthday!|  ii     |
| i      |   i^2           |
|-i             |       i*i        |
| 0     |     6/7+2/2i    |       
|0i     |  3/7i  |
|1i|   |

The deal with most of the numbers under the "Impossible" side have to do with not getting the result you expect, 
so try to stay away from that side.

##Usage and Installation

1. Download the .zip 
2. Have your desired txt files in the same location as the ComplexNumberCalculator.exe
3. Run the ComplexNumberCalculator.exe




# LED-Fire-lava-effects-
Sketches for individually addressable led strips with fire lava and other effects.

This will create a fire effect based on the fastLED libary.

Example:
https://www.youtube.com/watch?v=ZS9jl44mSj0

It uses a 3 dimensional Matrix. It has the normal x-axis and y-axis, in addition it has a Z-axis in which the 3 value for HSV Colors is stored. I decided to use HSV instead of RGB because it is much easier to, for example, dim the strength or saturation. You can also make a color shift fairly easily. (I also found this tip somewhere on the internet)
A drawback, however, is that the use of color pallets has become much more difficult.

In this example I use WS2812B strip which is wrapped around a tube. The alignment was not entirely correct, but due to the diffusion of the outer tube, this is almost not visible.
I ended up with a matrix of 8 x 72 pixels.
When the matrix is defined, the fire effect is actually quite easy to make.

Step 1: create the bottem row. Fire is always yellow with white at the bottom.
Step 2: Move all row and 1 row up. Make sure the color changes slightly to red and let the brightness and saturation decrease slightly.
also add some random to these steps.
remark : If you want to use this effect on a flat surface, it is smart to let the sides fade out faster.
Step 3: Make sure random rows can shift left or right.
Step 4: Add some sparks by adding random pixels to the matrix.
Step 5: draw the matrix to the fastled-matrix in RGB format.
Step 6: write the matrix to the led strip

You can play with the random values yourself to get other effects.

Have Fun
Hans Hovenier

This is my first upload, so please be nice.

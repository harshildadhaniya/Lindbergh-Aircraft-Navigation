# Lindbergh Aircraft Navigation

In preparation for his historic flight across the Atlantic Ocean, Charles Lindbergh would like to navigate from point A (latitude latA and longitude longA) to point B (latitude latB and longitude longB). The task it to compute heading θ (in degrees) and flying distance d (in nautical miles (nmi)). Using the Haversine formula for the loxodrome, the (approximate) values of d and θ are given by the following formulas, using intermediate value a and the radius of the earth R = 3,440 nmi:

![image](https://user-images.githubusercontent.com/70550648/109085476-97592e00-76be-11eb-942a-ea1c40f980c9.png)

This C program creates a function that computes the proper heading and distance between point A and point B, for any pair of points on the planet.

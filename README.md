# gtest-example
Example of TDD with GoogleTest

open project with CLion to use GoogleTest features :
  - open file ./Google_tests/EmptyTest.cpp
  - click on the green arrow at the left of a TEST() to run it
OR
  - right-click on EmptyTest.cpp and "Run 'All in EmptyTest.cpp'"

EXERCICE : Rover
  - initial starting point (x,y) and direction {N,S,E,W} it is facing
  - the rover receives a character array of commands
  => implement commands that move the rover forward/backward {f,b}
  => implement commands that move the rover left/right {l,r}
BONUS :
  => implement wrapping form one edge of the grid to another
  => implement obstacle detection before each move to a new square
     if a given sequence of commands encounters and obstacle, the rover
     moves up to the last possible point and reports the obstacle.
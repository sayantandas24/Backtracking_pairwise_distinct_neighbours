The idea is to use the Backtracking approach. For a grid with given size we will find the number of neighbours maximum possible. Then for each cell we have to find out the number is valid or not.

/*
 # # # # #
 # # U # #
 # L X R _
 _ _ D _ _
 _ _ _ _ _
*/

The cell X it is neighbour to the cells L, R, U and D. So the number we want to put in X should be pairwise distinct with all the neighbours of L, R, U and D. As the right neighbour of R, left, right and down neighbour of D can not be filled before X so we don't need to worry about them.
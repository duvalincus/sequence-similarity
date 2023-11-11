# sequence-similarity



Problem 2: Sequence similarity measure. Let x and y be two given DNA sequences, represented as
strings with characters in the set {A, G, C, T }. The similarity measure of x and y is defined as the maximum
score of any alignment of x and y, where the score for an alignment is computed by adding substitution
score and deletion and insertion scores, as explained below. (Some operations have negative scores.)
The score for changing a character xi into a character yj is σ(xi, yj ), where σ(·, ·) is defined as follows:


Let now x = GT GAACGCT GGCGGCGT GCT and y = AGCT AAT ACCCCAT ACGT T C.
You need to compute the similarity score and find the alignment of x and y using dynamic programming:
1. Write the recurrence.
2. Fill the first three rows of the table (you will use it for testing).
3. Write a program (in C++) that performs DNA sequence alignment using dynamic programming.
4. Compute and report the similarity score.
5. Show the alignments (using back-tracking) in your table; report all the alignments.
6. Attach a picture of your code with the input and output.
7. Upload your code (cpp file) on Gradescope into HW3 code for testing and autograding.

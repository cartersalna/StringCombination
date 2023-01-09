# StringCombination
(CPP). Combine strings to shorten a line. For example, "In this issue" would become "In thissue".

Linguists have often noticed that natural languages can be compressed, but they are still fairly easy to understand because humans are fairly good at pattern seeking. For instances, if I mistyped the phrase "in this issue here" as "in thissue here", you can still understand what I was trying to say.

The input (from standard input) will consist of a sentence on each line, you can assume that single spaces separate each word. Squeeze each individual line and output the result (each on their own line). You should not squeeze across lines. Your program should process all input until the End-Of-File (EOF) is encountered.

Example Input:
Ferrets are really super cool. 
But they aren't great at eating dessert. 
I like triking around campus with my dog Mal but he likes scaring squirrels. 
Things can get tricky yet, time me means answer error. 

Expected Output:
Ferrets areally super cool. 
Buthey aren't greating dessert. 
I like triking around campus with my dog Mal but he likescaring squirrels. 
Things can getrickyet, timeanswerror.

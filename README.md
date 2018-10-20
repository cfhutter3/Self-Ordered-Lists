# Self-Ordered-Lists
# When I read the assignment instructions, my first thought was to make three separate classes inheriting from SelfOrderedListADT, and that is exactly what I did.

# I made some changes to llist.h and link.h.  My changes to llist.h consist of a few functions to help with the heuristic process.  My changes to link.h consist of the addition of a new data member called frequencyAccessed that keeps track of the frequency of that link being accessed.

# I used my modified version of the linked list supplied in all of the three self-ordering list classes.

# The three classes are very similar, but the shared difference between all of them is the doHeuristic() function.  The doHeuristic function is called by find() and implements the different self-ordering heuristics for each class.

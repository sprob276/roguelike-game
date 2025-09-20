# README REQUIREMENTS ARE IN THE ASSIGNMENT DESCRIPTION

Author
Name: Robert Spataru


UoG login name: rspataru

Test Strategy
- make test

Explain: 
- Which API functions you tested and how. - Types of cases: normal, edge, negative. 
    - each time I tested something I would just think what would be most likely to fail and I thought of checking instances where it would make sure that the binary tree was inserting nodes in order and I made sure to check for that
    - I tested the height function and made sure it gave the correct height for different nodes
    - I tried to see what would happen if the tree was empty when I would perform some functions
- Any patterns you used (e.g., build a tree, mutate it, check invariants).



Usage example
Include the final summary plus the last ~50 lines (trimmed) from one successful make test run in a fenced code block (cut/paste).
 
==> Running unit tests
Running suite(s): BalancedTree
100%: Checks: 17, Failures: 0, Errors: 0




Limitations

Known gaps or untested areas, if any: - Example: Did not test duplicate removal due to unclear spec. 
- when i was testing some functions at the start I was still remembering how binary trees worked and I didn't run a test correctly which caused it to fail on the correct implementation but let it pass on the buggy one, so majority of the time I spent trying to figure out why, but I am not sure.




Example: Did not explore performance under large inserts.
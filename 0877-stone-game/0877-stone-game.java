class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
// This is a special case of 486. Predict the Winner.

// Now, this problem introduces two important constraints:

// The length of the piles is always even.
// The total number of stones is odd, so a tie is impossible.
// Intuition
// We partition the piles into two groups according to their indices:

// Pink : Even index
// Blue : Odd index
// Screenshot 2026-08-022 085944.png

// Since both players play optimally, we can determine our strategy before the game begins:

// Alice moves first, so the two ends of the array always have opposite parity.
// Hence, on the first move, Alice always choose either the Pink, or the Blue piles (whichever has the larger sum).
// Observation:
// During Alice's turn:

// The two ends always have opposite parity.
// During Bob's turn:

// The two ends always have the same parity.
// Screenshot 2026-08-02 124110.png

// Since Alice always has a choice between the two parities, she can always obtain the parity with the larger total sum.
// Consequently, Bob is left with the parity having the smaller total sum.
// Summary
// Because the piles array has an even length, Alice can always force taking either all even, or all odd indexed piles.
// Since the total number of stones is odd, then one parity has a strictly larger total sum.
// Therefore, Alice is  
// guaranteed
// ​
//   to collect more stones than Bob, so the answer is always:

// true
// ​
 
// Time Complexity: O(1)
// Space Complexity: O(1)
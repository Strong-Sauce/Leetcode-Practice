class Solution {
    public boolean wordPattern(String p, String s) {
        String[] sa = s.trim().split("\\s+");
        if (p.length() != sa.length) return false;
        
        Map<Character, String> pToWord = new HashMap<>();
        Map<String, Character> wordToP = new HashMap<>();
        for (int i = 0; i < p.length(); i++) {
            char ch = p.charAt(i);
            String word = sa[i];
            
            if (pToWord.containsKey(ch) && !pToWord.get(ch).equals(word)) return false;
            if (wordToP.containsKey(word) && wordToP.get(word) != ch) return false;

            pToWord.put(ch, word);
            wordToP.put(word, ch);
        }
        return true;
    }
}
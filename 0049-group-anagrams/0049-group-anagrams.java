class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();

        for (String s : strs) {
            int[] frq = new int[26];

            for (int i = 0; i < s.length(); i++) 
                frq[s.charAt(i) - 'a']++;

            StringBuilder key = new StringBuilder();

            for (int x : frq) 
                key.append(x).append('#');

            mp.computeIfAbsent(key.toString(), k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(mp.values());
    }

    // public List<List<String>> groupAnagrams(String[] strs) {
    //     int n = strs.length;

    //     HashMap<String, List<String>> ans = new HashMap<>();
    //     for(int i=0;i<n;i++){
    //         char[] chars = strs[i].toCharArray(); // i=1 -> eat
    //         Arrays.sort(chars); // aet
    //         String key = new String(chars); // a e t
            
    //         if(!ans.containsKey(key)) ans.put(key, new ArrayList<>());
    //         ans.get(key).add(strs[i]);
    //     }
    //     return new ArrayList<>(ans.values());
    // }

    // public List<List<String>> groupAnagrams(String[] strs) {
    //     int n = strs.length;

    //     String[][] s = new String[n][2];

    //     for (int i = 0; i < n; i++) {
    //         char[] arr = strs[i].toCharArray();
    //         Arrays.sort(arr);

    //         s[i][0] = new String(arr);
    //         s[i][1] = String.valueOf(i);
    //     }
    //     Arrays.sort(s, (a, b) -> a[0].compareTo(b[0]));

    //     List<List<String>> ans = new ArrayList<>();

    //     for (int i = 0; i < n; i++) {
    //         if (i == 0 || !s[i][0].equals(s[i - 1][0])) 
    //             ans.add(new ArrayList<>());

    //         ans.get(ans.size() - 1).add(strs[Integer.parseInt(s[i][1])]);
    //     }
    //     return ans;
    // }
}
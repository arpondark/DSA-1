class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> arpon = new HashMap<>();  //cpp with is hard so using java instead
        for (int x : arr) {
            arpon.merge(x, 1, Integer::sum);
        }
        return new HashSet<>(arpon.values()).size() == arpon.size();
    }
}



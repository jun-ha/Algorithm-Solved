class Solution {
    public int solution(String my_string, String is_suffix) {
        int idx = my_string.lastIndexOf(is_suffix);
        return idx < 0 ? 0 : idx + is_suffix.length() == my_string.length() ? 1 : 0;
    }
}
class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        int idx = 0;
        while(k-->0) {
            for(int i = idx; i < sb.length() - 1; i++) {
                if(sb.charAt(i) < sb.charAt(i + 1)) {
                    sb.deleteCharAt(i);
                    idx = i == 0 ? 0 : i - 1;
                    break;
                }
                if(i == sb.length() - 2) {
                    sb.deleteCharAt(sb.length()-1);       
                }
            }
        }
        return sb.toString();
    }
}
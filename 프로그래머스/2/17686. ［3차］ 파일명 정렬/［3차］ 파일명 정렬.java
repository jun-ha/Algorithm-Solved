import java.util.*;

class Solution {
    private String[] split(String file) {
        String[] result = new String[2];
        
        int headLast = 0;
        for(int i = 0; i < file.length(); i++) {
            if(Character.isDigit(file.charAt(i))) {
                result[0] = file.substring(0, i);
                headLast = i - 1;
                break;
            }    
        }
        int numberLast;
        for(numberLast = headLast + 1; numberLast < file.length(); numberLast++) {
            if(!Character.isDigit(file.charAt(numberLast))) {
                break;
            }
        }
        result[1] = file.substring(headLast + 1 , numberLast);
        
        
        return result;
    }
    
    public String[] solution(String[] files) {
        Arrays.sort(files, (a, b) -> {
            String[] aa = split(a);
            String[] bb = split(b);
            
            String ah = aa[0].toLowerCase();
            String bh = bb[0].toLowerCase();
            if(!ah.equals(bh)) return ah.compareTo(bh);
            
            int an = Integer.parseInt(aa[1]);
            int bn = Integer.parseInt(bb[1]);
            
            if(an != bn) return an - bn;
            
            return 0;
        });
        return files; 
    }
}
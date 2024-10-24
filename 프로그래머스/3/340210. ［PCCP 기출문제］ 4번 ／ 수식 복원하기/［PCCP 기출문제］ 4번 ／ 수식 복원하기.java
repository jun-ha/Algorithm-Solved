import java.util.*;

class Calculator {
    static int act(int a, boolean op, int b, int jinbub) {
        int[] aa = new int[3];
        int[] bb = new int[3];
        int[] result = new int[3];
        
        int idx = 0;
        while(a > 0) {
            aa[idx++] = a % 10;
            a /= 10;
        }
        idx = 0;
        while(b > 0) {
            bb[idx++] = b % 10;
            b /= 10;
        }
        
        for(int i = 0; i < 3; i++) {
            if(op) result[i] = aa[i] + bb[i];
            else result[i] = aa[i] - bb[i];
        }
        
        for(int i = 0; i < 3; i++) {
            if(result[i] < 0) {
                result[i + 1]--;
                result[i] += jinbub; 
            }
            if(result[i] >= jinbub) {
                result[i] -= jinbub;
                result[i + 1]++;
            }
        }
        
        int answer = 0;
        int tmp = 1;
        for(int r : result) {
            answer += r * tmp;
            tmp *= 10;
        }
        
        return answer;
    }
}

class Expression {
    int first;
    boolean op; // true == +, false == -
    int second;
    
    Expression(int f, boolean op, int s) {
        this.first = f;
        this.op = op;
        this.second = s;
    }
    
    boolean validate(int jinbub) {
        int f = first;
        int s = second;
        
        while(f > 0) {
            if(f%10 >= jinbub) return false;
            f /= 10;
        }
        
        while(s > 0) {
            if(s%10 >= jinbub) return false;
            s /= 10;
        }
        
        return true;
    }
}

class Information extends Expression {
    int answer;
    
    Information(int f, boolean op, int s, int a) {
        super(f, op, s);
        this.answer = a;
    }
    
    boolean validate(int jinbub) {
        if(!super.validate(jinbub)) return false;
        
        int a = answer;
        while(a > 0) {
            if(a%10 >= jinbub) return false;
            a /= 10;
        }
        
        if(Calculator.act(first, op, second, jinbub) != answer) return false;
        
        return true;
    }
}

class Question extends Expression {
    int finalResult = -1;
    
    Question(int f, boolean op, int s) {
        super(f, op, s);
    }
    
    int calculate(int jinbub) { 
        return Calculator.act(first, op, second, jinbub);
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(first)
            .append(op ? " + " : " - ")
            .append(second)
            .append(" = ")
            .append(finalResult >= 0 ? finalResult : "?");
        
        return sb.toString();
    }
}


class Solution {
    public String[] solution(String[] expressions) {
        Expression[] exprs = new Expression[expressions.length];
        List<Integer> possibles = new ArrayList<>();
        
        int idx = 0;
        
        for(String e : expressions) {
            StringTokenizer st = new StringTokenizer(e);
            int first = Integer.parseInt(st.nextToken());
            String op = st.nextToken();
            int second = Integer.parseInt(st.nextToken());
            String equals = st.nextToken();
            String answer = st.nextToken();
            
            if(answer.equals("X")) {
                exprs[idx++] = new Question(first, op.equals("+"), second);
            } else {
                exprs[idx++] = new Information(first, op.equals("+"), second, Integer.parseInt(answer));
            }
        }
        
        List<Integer> possibleJinbubs = new ArrayList<>();
        for(int jinbub = 2; jinbub <= 9; jinbub++) {
            boolean flag = true;
            for(Expression e : exprs) {
                if(!e.validate(jinbub)) {
                    flag = false; 
                    break;
                }
            }
            if(flag) possibleJinbubs.add(jinbub);
        }
        
        possibleJinbubs.forEach(n -> System.out.println(n));
        
        List<String> answer = new ArrayList<>();
        
        for(Expression e : exprs) {
            if(e instanceof Information) continue;
            Question q = (Question) e;
            
            boolean allSame = true;
            int before = -1;
            for(int j : possibleJinbubs) {
                if(before == -1) before = q.calculate(j);
                if(before != q.calculate(j)) {
                    allSame = false;
                    break;
                }
            }
            if(allSame) {
                q.finalResult = before;   
            }    
            answer.add(q.toString());
        }
        
        return answer.toArray(new String[0]);
    }
}
public class Circle {
    private double r;
    private int num;
    public void get(double r,int num){
            this.r=r;
            this.num=num;
    }
    public double S(){
        return Math.PI*r*r;
    }
    public double C(){
        return 2*Math.PI*r*r;
    }

}

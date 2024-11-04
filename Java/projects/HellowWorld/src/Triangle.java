
public class Triangle {
    public double length;
    public int number;
    public void get(double length,int number){
        this.length=length;
        this.number=number;
    }

    public double getTotalArea(){
         return   Math.sqrt(3.0)/4.0*length*length*number;
    }
}

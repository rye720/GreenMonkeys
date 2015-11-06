
public class Vector {

    protected double x;
    protected double y;
    protected double z;

    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public double DotProduct(Vector v) {
        return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    }

    public double DotProduct(Vector v1, Vector v2) {
        return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
    }
    
    public double DotRadProduct(Vector v1, Vector v2){
        double x = 0.0;
        x = Math.acos((DotProduct(v1,v2))/(Magnitude(v1)*Magnitude(v2)));
        return x;
    }

    public double Magnitude(Vector v) {
        return Math.sqrt(DotProduct(v));
    }
    
    public Vector VecAddition(Vector v1, Vector v2){
        Vector newV = new Vector(0,0,0);
        newV.x = (v1.x+v2.x);
        newV.y = (v1.y+v2.y);
        newV.z = (v1.z+v2.z);
        return newV;
    }
    
    public Vector VecSubtraction(Vector v1, Vector v2){
        Vector newV = new Vector(0,0,0);
        newV.x = (v1.x-v2.x);
        newV.y = (v1.y-v2.y);
        newV.z = (v1.z-v2.z);
        return newV;
    }
    
    public double ScalarVecProjection(Vector v1, Vector v2){    
        return ((DotProduct(v1,v2))/Magnitude(v2));
    }
    
    public Vector ScalarMultVector(Vector v, double x) {
        Vector newV = new Vector(v.x * x, v.y * x, v.z * x);
        return newV;
    }

    public double DirectionDegree(Vector v) {
        return Math.toDegrees(Math.atan(v.x / v.y));
    }

    public Vector DirectionVector(Vector v) {
        return ScalarMultVector(v, 1 / Magnitude(v));
    }

    public boolean isOrthogonal(Vector v1, Vector v2) {
        boolean orth = false;
        if (DotProduct(v1, v2) == 0) {
            orth = true;
        }
        return orth;
    }
    
    public double VectorDist(Vector v1, Vector v2){
        return Math.sqrt(Math.pow(v2.x-v1.x, 2)+Math.pow(v2.y-v1.y,2)
                +Math.pow(v2.z-v1.z,2));
    }

    public Vector VectorNegate(Vector v){
        v.x = (-1*v.x);
        v.y = (-1*v.y);
        v.z = (-1*v.z);       
        return v;
    }
    
    public Vector CrossProduct(Vector v1, Vector v2) {
        Vector crossV = new Vector((v1.y * v2.z) - (v1.z * v2.y),
                -1 * ((v1.x * v2.z) - (v1.z * v2.x)), (v1.x * v2.y) - (v1.y * v2.x));
        return crossV;
    }

    public Vector RotateAboutZ(Vector v, double deg) {
        double x = v.x;
        v.x = (x * Math.cos(Math.toRadians(deg) - v.y * Math.sin(Math.toRadians(deg))));
        v.y = (x * Math.sin(Math.toRadians(deg) + v.y * Math.cos(Math.toRadians(deg))));
        return v;
    }

    public Vector NormalizeVector(Vector v) {
        Vector vNormal = new Vector(0, 0, 0);
        double mag = Magnitude(v);
        if (mag != 0) {
            vNormal.x = (v.x / mag);
            vNormal.y = (v.y / mag);
            vNormal.z = (v.z / mag);
            return vNormal;
        } else {
            return v;
        }
    }
}

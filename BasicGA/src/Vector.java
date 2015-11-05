
public class Vector {

    protected double x;
    protected double y;
    protected double z;

    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public double dotProduct(Vector v) {
        return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    }

    public double dotProduct(Vector v1, Vector v2) {
        return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
    }

    public double magnitude(Vector v) {
        return Math.sqrt(this.dotProduct(v));
    }

    public Vector scalarMultVector(Vector v, double x) {
        Vector newV = new Vector(v.x * x, v.y * x, v.z * x);
        return newV;
    }

    public double directionDegree(Vector v) {
        return Math.toDegrees(Math.atan(v.x / v.y));
    }

    public Vector directionVector(Vector v) {
        return scalarMultVector(v, 1 / magnitude(v));
    }

    public boolean isOrthogonal(Vector v1, Vector v2) {
        boolean orth = false;
        if (dotProduct(v1, v2) == 0) {
            orth = true;
        }
        return orth;
    }

    public Vector CrossProduct(Vector v1, Vector v2) {
        Vector crossV = new Vector((v1.y * v2.z) - (v1.z * v2.y),
                -1 * ((v1.x * v2.z) - (v1.z * v2.x)), (v1.x * v2.y) - (v1.y * v2.x));
        return crossV;
    }

    public Vector normalizeVector(Vector v) {
        Vector vNormal = new Vector(0, 0, 0);
        double mag = Math.sqrt(dotProduct(v));
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

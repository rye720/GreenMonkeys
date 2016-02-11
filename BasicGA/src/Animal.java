
/**
 * @author The Green Monkeys Inc.
 */
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;

public class Animal {

    protected String species;
    protected int[] genes;
    protected char sex;
    protected float fitness;
    protected int generation;
    protected int age;
    protected String tag;
    protected Vector position;
    protected Vector direction;//direction not currently used?

    public Animal(String s, int[] g, char c, float f, int ge, String t, Vector v, int a) {
        this.species = s;
        this.genes = g;
        this.sex = c;
        this.fitness = f;
        this.generation = ge;
        this.tag = t;
        this.position = v;
        this.age = a;
    }

    public float getFitness() {
        return fitness;
    }

    @Override
    public String toString() {
        NumberFormat f = new DecimalFormat("#0.00");
        return "Species: " + species + " Genes: " + Arrays.toString(genes) + " Sex: " + sex
                + " Fitness: " + f.format(fitness) + " Age: " + age + " Generation " + generation + " Tag: " + tag;
    }

}//animal

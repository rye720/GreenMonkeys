
/**
 * @author The Green Monkeys Inc.
 */
import java.util.*;

public class Animal {

    protected String species;
    protected int[] genes;
    protected char sex;
    protected float fitness;

    public Animal(String s, int[] g, char c, float f) {
        this.species = s;
        this.genes = g;
        this.sex = c;
        this.fitness = f;
    }

    public float getFitness() {     
        return fitness;
    }

    @Override
    public String toString() {
        return "Species: " + species + " Genes: " + Arrays.toString(genes) + " Sex: " + sex
                + " Fitness: " + fitness;
    }
       
}//animal
// blah

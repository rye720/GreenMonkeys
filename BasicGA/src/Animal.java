
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
    protected String tag;
    protected Vector position;
    protected Vector direction;

    public Animal(
          String species, int[] genes, char sex, float fitness, int generation, String tag,
          Vector position) {
        // You don't need to use different variable names; the "this" quantifier disambiguates them.
        this.species = species;
        this.genes = genes;
        this.sex = sex;
        this.fitness = fitness;
        this.generation = generation;
        this.tag = tag;
        this.position = position;
    }

    public float getFitness() {
        return fitness;
    }

    @Override
    public String toString() {
        NumberFormat f = new DecimalFormat("#0.00");
        return "Species: " + species + " Genes: " + Arrays.toString(genes) + " Sex: " + sex
                + " Fitness: " + f.format(fitness) + " Generation " + generation + " Tag: " + tag;
    }

}//animal

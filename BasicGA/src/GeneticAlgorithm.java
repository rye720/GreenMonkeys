
/**
 * @author The Green Monkeys Inc.
 */
import java.lang.*;
import java.util.*;

/**
 *
 * @author jawarth
 */
public class GeneticAlgorithm {

    /**
     *
     * @param t
     * @param x
     * @param y
     * @param z
     * @return random population
     */
    public List<Animal> GeneratePop(String t, int x, int y, int z) {
        GAUtils gau = new GAUtils();
        List<Animal> newPop = new ArrayList<>();

        for (int i = 0; i < x; i++) {
            int x1[] = gau.RandGene(y);
            double fn = calcFitness(x1);
            // Vector pos = new Vector( (calcFitness(x1)*100) + 5,
            //      (Math.random() * calcFitness(x1)*150) + 5,
            //      (Math.random() * calcFitness(x1)*100) + 5);
            Vector pos = new Vector((((fn / 10) + (fn % 10)) * 350) + 5,
                    (((fn / 10) + (fn % 10)) * 350) + 5,
                    (fn * 100) + 5);
            Animal a = new Animal(t, gau.RandGene(y), gau.GetSex(), 0, z, t+"_" + z+"_" + i+"_", pos);
            newPop.add(a);
        }
        return newPop;
    }

    /**
     *
     * @param pop
     * @param x
     * @return
     */
    public List<Animal> Selection(List<Animal> pop, int x) {
        int i = (x / 4);
        for (; i > 0; x--, i--) {
            //System.out.println(pop.remove(x).tag + " Removed.");
            pop.remove(x);
        }
        return pop;
    }

    /**
     *
     * @param pop
     * @param x
     * @return
     */
    public List<Animal> Combination(List<Animal> pop, int x) {
        GAUtils gau = new GAUtils();
//     in the future, will want to define exception for when two
//     animals with incompatible genes attempt to mate
        List<Animal> newPop = new ArrayList<>();

        while (pop.size() > 1) {
            //generate sex of animal
            char sex;
            int sexRand = (int) (Math.random() * 10 + 1);
            if (sexRand > 5) {
                sex = 'm';
            } else {
                sex = 'f';
            }

            //More diverse combination to avoide local maxima's
            Animal d;
            Animal m;
            if (pop.size() >= 8) {
                d = pop.remove((int) (Math.random() * 6));
                m = pop.remove((int) (Math.random() * 6));
            } else if (pop.size() >= 7) {
                d = pop.remove((int) (Math.random() * 5));
                m = pop.remove((int) (Math.random() * 5));
            } else if (pop.size() >= 6) {
                d = pop.remove((int) (Math.random() * 4));
                m = pop.remove((int) (Math.random() * 4));
            } else if (pop.size() >= 5) {
                d = pop.remove((int) (Math.random() * 3));
                m = pop.remove((int) (Math.random() * 3));
            } else if (pop.size() >= 4) {
                d = pop.remove((int) (Math.random() * 2));
                m = pop.remove((int) (Math.random() * 2));
            } else if (pop.size() >= 3) {
                d = pop.remove((int) (Math.random() * 1));
                m = pop.remove((int) (Math.random() * 1));
            } else {
                d = pop.remove(0);
                m = pop.remove(0);
            }

            //generate crossover point
            int cp = (int) (Math.random() * d.genes.length + 1);
            //System.out.println("Crossover pt: " + cp);

            //initialize child genes
            int[] childGenes = new int[d.genes.length];

            //next two loops populate child gene set
            for (int i = 0; i < cp; i++) {
                //pass down some mom genes
                childGenes[i] = d.genes[i];
            }

            for (int i = cp; i < m.genes.length; i++) {
                //pass down some dad genes
                childGenes[i] = m.genes[i];
            }

            //Mutation if sexRand is a prime number
            //if (gau.isPrime(sexRand)) {
            Boolean hasMutation = false;//use this to identify mutated childGenes
            if (Math.random() <= .20) {
                Mutation(childGenes);
                hasMutation = true;
            }
            //}
            //Future use for 3d graphics and visulization

            double fn = calcFitness(childGenes);
            //Vector pos = new Vector( (calcFitness(childGenes)*100) + 5,
            //     (Math.random() * calcFitness(childGenes)*150) + 5,
            //     (Math.random() * calcFitness(childGenes)*100) + 5);
            Vector pos = new Vector((((fn / 10) + (fn % 10)) * 350) + 5,
                    (((fn / 10) + (fn % 10)) * 350) + 5,
                    (fn * 100) + 5);

            
            //building the tag name
            //appends an 'm' if individual has mutated gene
            StringBuilder tag = new StringBuilder();
            tag.append(m.species);
            tag.append("_");
            tag.append(m.generation + 1);
            tag.append("_");
            tag.append(x);
            if (hasMutation) {
                tag.append("m");
            }

            Animal child = new Animal(m.species, childGenes, sex, calcFitness(childGenes),
                    (m.generation + 1), tag.toString(), pos);
            x++;
            Collections.addAll(newPop, m, d, child);
        }
        if (pop.size() == 1) {
            newPop.add(pop.remove(0));
        }
        return newPop;

    }

    //Random gene mutation
    private int[] Mutation(int[] x) {
        x[(int) (Math.random() * (x.length - 1))] = (int) (Math.random() * 9 + 1);
        return x;
    }

    /**
     *
     * @param pop
     * @return population with their fitness number evaluated
     */
    public List<Animal> EvalPopFitness(List<Animal> pop) {
        for (int i = 0, y = pop.size(); y > i; i++) {
            pop.get(i).fitness = calcFitness(pop.get(i).genes);
        }
        return pop;
    }

    //Calcualte the fitness
    /**
     *
     * @param genes
     * @return fitness number
     */
    public float calcFitness(int[] genes) {
        float x = 0;
        //Summation precentage of each gene
        for (int i = 0; genes.length > i; i++) {
            x += (genes[i] / 10.0);
        }
        //Average summation percentage
        x /= (float) genes.length;
        return x;
    }
}

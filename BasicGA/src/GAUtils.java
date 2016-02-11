
/**
 *
 * @author The Green Monkeys Inc.
 */
import java.util.*;

/**
 *
 * @author jawarth
 */
public class GAUtils implements Comparator<Animal> {


    /**
     *
     * @param pop
     */
        public void PopOut(List<Animal> pop) {
        int i = 0;
        while (pop.size() > i) {
            System.out.println(pop.get(i));
            i++;
        }
    }

    /**
     *
     * @param pop
     * @return sorted population, highest fitness at the top
     */
        public List<Animal> ranking(List<Animal> pop) {
        Collections.sort(pop, new GAUtils());
        return pop;
    }

    //compares the fitness for the sorting method above

    /**
     *
     * @param t
     * @param t1
     * @return compares two animals, higher fitness first
     */
        @Override
    public int compare(Animal t, Animal t1) {
        int x = 0;
        if (t.getFitness() > t1.getFitness()) {
            x = -1;
        } else if (t.getFitness() < t1.getFitness()) {
            x = 1;
        } else {
            x = 0;
        }
        return x;
    }

    /**
     *
     * @param x
     * @return random mutation gene
     */
    public int[] RandGene(int x) {
        int[] genes = new int[x];
        for (int i = 0; i < x; i++) {
            genes[i] = (int) (Math.random() * 9 + 1);
        }
        return genes;
    }
       
    /**
     *
     * @param x
     * @return if x is prime or not
     */
    public boolean isPrime(int x){
        boolean prime = false;
        if(x==2 || x==3 || x==5 || x==7)
            prime = true;
        return prime;
    }
    
    /**
     *
     * @return random sex
     */
    public char GetSex() {
        char c;
        int sexRand = (int) (Math.random() * 10 + 1);
        if (sexRand > 5) {
            c = 'm';
        } else {
            c = 'f';
        }
        return c;
    }
    
    /**
     *
     * @return advance age of each individual in population by n years
     */
    public List<Animal> agePopulation(List<Animal> pop, int n){
        for(int x = 0; x < pop.size(); x++){
            pop.get(x).age += n;
        }
        return pop;
    }
    
   /**
     *
     * @return kill bears if they are older than 23
     */
    public List<Animal> removeSeniorCitizens(List<Animal> pop){
            for(int x = 0; x < pop.size(); x++){
            if(pop.get(x).age > 23){
                pop.remove(x);
            }
        }
        return pop;
    }
}

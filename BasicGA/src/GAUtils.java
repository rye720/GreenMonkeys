
/**
 *
 * @author The Green Monkeys Inc.
 */
import java.util.*;

public class GAUtils implements Comparator<Animal> {
   
    //Outputs the current population
    public void PopOut(List<Animal> pop) {
        int i = 0;
        while (pop.size() > i) {
            System.out.println(pop.get(i));
            i++;
        }
    }

    //Ranks the animals from highest to lowest via fitness
    public List<Animal> ranking(List<Animal> pop) {
        Collections.sort(pop, new GAUtils());
        return pop;
    }

    //compares the fitness for the sorting method above
    @Override
    public int compare(Animal t, Animal t1) {
        int x = 0;
        if(t.getFitness() > t1.getFitness()){
            x = -1;
        } else if (t.getFitness() < t1.getFitness()){
            x = 1;
        } else {
            x = 0;
        }
        return x;
    }

}

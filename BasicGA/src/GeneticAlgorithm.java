/**
 * @author The Green Monkeys Inc.
 */
import java.lang.*;
import java.util.*;

public class GeneticAlgorithm {
    
   /**
    * @param m mom animal
    * @param d dad animal
    * @return offspring of two parents
    */
    public List<Animal> Combination(List<Animal> pop){
        
//     in the future, will want to define exception for when two
//     animals with incompatible genes attempt to mate
       List<Animal> newPop = new ArrayList<Animal>();
        
        while (pop.size() > 1){
            //generate sex of animal
            char sex;
            int sexRand = (int)(Math.random() * 10 + 1);
            if(sexRand > 5){
                sex = 'm';
            }else{
                sex = 'f';
            }
            
            Animal d = pop.remove(0);
            Animal m = pop.remove(0);
            
            //generate crossover point
            int cp = (int)(Math.random() * d.genes.length + 1);
            System.out.println("Crossover pt: "+cp);
            
            //initialize child genes
            int[] childGenes = new int[d.genes.length];
            
            //next two loops populate child gene set
            for(int i=0; i<cp;i++){
                //pass down some mom genes
                childGenes[i] = d.genes[i]; 
            }
            
            for(int i=cp; i<m.genes.length;i++){
                //pass down some dad genes
                childGenes[i] = m.genes[i];
            }
            
            Animal child = new Animal(m.species, childGenes, sex, calcFitness(childGenes));
            Collections.addAll(newPop, m, d, child);
        }
            return newPop;
            
    }   
    
    //Loops through the population changing each animals' fitness number
    public List<Animal> EvalPopFitness(List<Animal> pop){           
        for(int i = 0, y = pop.size();y > i; i++){
            pop.get(i).fitness = calcFitness(pop.get(i).genes);
        }     
        return pop;
    }
    
    //Calcualte the fitness
    public float calcFitness(int[] genes){
        float x = 0;
        //Summation precentage of each gene
        for(int i = 0; genes.length > i; i++){
            x += (genes[i]/10.0);
        }
        //Average summation percentage
        x /= (float)genes.length;      
        return x;
    }
}


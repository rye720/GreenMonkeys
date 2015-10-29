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
    public Animal Combination(Animal m, Animal d){
        
//     in the future, will want to define exception for when two
//     animals with incompatible genes attempt to mate
            
            //generate sex of animal
            char sex;
            int sexRand = (int)(Math.random() * 10 + 1);
            if(sexRand > 5){
                sex = 'm';
            }else{
                sex = 'f';
            }
            
            //generate crossover point
            int cp = (int)(Math.random() * m.genes.length + 1);
            System.out.println("Crossover pt: "+cp);
            
            //initialize child genes
            int[] childGenes = new int[m.genes.length];
            
            //next two loops populate child gene set
            for(int i=0; i<cp;i++){
                //pass down some mom genes
                childGenes[i] = m.genes[i]; 
            }
            
            for(int i=cp; i<d.genes.length;i++){
                //pass down some dad genes
                childGenes[i] = d.genes[i];
            }
            
            Animal child = new Animal(m.species, childGenes, sex);
        
            return child;
            
    }
    
}


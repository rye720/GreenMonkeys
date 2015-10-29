/**
 * @author The Green Monkeys Inc.
 */
import java.util.*;

    public class Animal{
        
        protected String species;
        protected int[] genes;
        protected char sex;
        
        public Animal(String s, int[] g, char c){
            this.species = s;
            this.genes = g;
            this.sex = c;
        }
        
        public String toString(){
            return "Species: "+species+" Genes: "+Arrays.toString(genes)+" Sex: "+sex;
        }
    }//animal

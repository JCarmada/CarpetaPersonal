/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package recursividadeje;

/**
 *
 * @author alumno
 */
public class RecursividadEje2 {
    
     public static void main(String[] args) {
         
         System.out.println(power(3,3));
     }
     
     private static int power(int base,int exponente){
         if(exponente==0){
              return 1;
              
         }
         
         
        return base*(power(base,exponente-1)); 
     }
     
     
     
}

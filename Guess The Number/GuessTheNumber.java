//Guess the correct NUMBER.

import java.util.Scanner;

class GuessTheNumber
{
    public static void main(String args[]){
        
        Scanner sc = new Scanner(System.in);
        int num =(int)(Math.random()*100);
        int user_number=0;
    
        do{
            System.out.print("Guess a number in b/w 1-100:  ");
            user_number = sc.nextInt();

            if(user_number == num){
                System.out.println("Hurray You Guessed the correct number.");
                break;
            }
            else if(user_number > num){
                System.out.println("Your number is too LARGE.\n");
            }
            else{
                System.out.println("Your number is too SMALL.\n");
            }
        }while(user_number>=0);

        System.out.println("My number was: "+ num+"\n\nTHANKS FOR PLAYING\n\n");
    }
}
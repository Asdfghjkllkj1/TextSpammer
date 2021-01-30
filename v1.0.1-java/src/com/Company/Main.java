package com.Company;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

import static java.lang.Math.round;

public class Main {
    public static void spammer(String pathname, int buffer, boolean difLine) throws java.awt.AWTException, IOException, InterruptedException {
        //buffer in ms
        System.out.println("Run.");
        BufferedReader br = new BufferedReader(new FileReader(pathname));
        ArrayList<String> lines = new ArrayList<>();
        String l;
        if (difLine) {while((l = br.readLine()) != null) { lines.add(l+"\n"); }}
        else {while ((l=br.readLine())!=null){lines.add(l);}}
        TimeUnit.SECONDS.sleep(5);
        for (String line:lines){
            for (String c : line.split("")) { new Robot().keyPress(c.charAt(0)); }
            TimeUnit.MILLISECONDS.sleep(buffer);
        }
        new Robot().keyPress('\n');
    }
    public static void spam(String body, int buffer, int rep) throws java.awt.AWTException, InterruptedException {
        Robot rob = new Robot();
        System.out.println("Run. ");
        TimeUnit.SECONDS.sleep(5);
        if (body.length()!=0) {
            for (int i = 0; i < rep; i++) {
                for (String c : body.split("")) {
                    rob.keyPress(c.charAt(0));
                }
                rob.keyPress('\n');
                TimeUnit.MILLISECONDS.sleep(buffer);
            }
        }
    }
    public static void main(String[] args) throws Exception {
	    System.out.println("Spammer v1.0.1 Java by AJ; 1/29/2021\nNOTE: *The author* is not responsible for any actions preformed using this script.\nModes:\ns: prints every line from text file with enters in between\nb: concatenates all lines in text file into one big line and press enter\nm: manual; you enter what you want spammed and how many times you need it spammed");
        Scanner inp = new Scanner(System.in);
        inp.useDelimiter("\n");
        System.out.print("Enter mode: ");
        String mode = inp.nextLine();
        System.out.print("Time between enter-presses (in seconds): ");
        float buffer = inp.nextFloat();
        int buf = round(buffer*100);
        if (mode.equals("s") || mode.equals("b")) {
            System.out.print("Enter file (to use to spam): ");
            String filename = inp.next();
            spammer(filename, buf, mode.equals("s"));
        }
        else if (mode.equals("m")) {
            System.out.print("What to be spammed? ");
            String body = inp.next();
            System.out.print("How many times should '"+body+"' be spammed? ");
            int rep = inp.nextInt();
            spam(body, buf, rep);
        }
        else {
            System.out.println("Unrecognized command. Exiting...");
        }
    }
}

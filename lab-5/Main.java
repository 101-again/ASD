package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    //private static String serialMark = "---";
    public static String whereTo = null;
    static int compare;
    static int toFile;

    static void fibonacciSort(String data, int n){

        String[] files = new String[3];
        files[0] = "file1.txt";
        files[1] = "file2.txt";
        files[2] = "file3.txt";

        for (int i = 0; i <3; i++) {
            File fileDel = new File(files[i]);
            fileDel.delete();
        }

        int prev1 = 1;
        int current = 1;
        int ex;
        compare++;
        while(n > current){
            compare++;
            ex = prev1 + current;
            prev1 = current;
            current = ex;
        }

        int fibNum = current;
        int first = prev1;
        int emptyCeils = fibNum-n;

        int[] seriesCount = new int[3];

        try{

            String str;
            int t = 1;
            //первый проход
            BufferedReader reader0 = new BufferedReader(new FileReader(data));
            BufferedWriter writer0;
            String numb0;
            int counter = 1;
            for(int i=0;i<3;i++){
                seriesCount[i]=0;
            }
            while ((numb0 = reader0.readLine()) != null) {
                toFile++;
                compare++;
                if(counter<=first){
                    while(emptyCeils!=0){
                        writer0 = new BufferedWriter(new FileWriter(files[0], true));
                        writer0.write("empty" + "\n");
                        toFile++;
                        writer0.write("---" + "\n");
                        toFile++;
                        emptyCeils--;
                        counter++;
                        seriesCount[0]++;
                        writer0.close();
                    }
                        writer0 = new BufferedWriter(new FileWriter(files[0], true));
                        writer0.write(numb0 + "\n");
                        toFile++;
                        writer0.write("---" + "\n");
                        toFile++;
                        writer0.close();
                        seriesCount[0]++;
                }
                if(counter>first){
                    writer0 = new BufferedWriter(new FileWriter(files[1], true));
                    writer0.write(numb0 + "\n");
                    toFile++;
                    writer0.write("---" + "\n");
                    toFile++;
                    writer0.close();
                    seriesCount[1]++;
                }
                counter++;
            }
            reader0.close();

            ArrayList<Integer> File1=new ArrayList<>();
            ArrayList<Integer> File2=new ArrayList<>();
            ArrayList<Integer> File3=new ArrayList<>();


            ArrayList<String> FileTemp1=new ArrayList<>();
            ArrayList<String> FileTemp2=new ArrayList<>();

            String numb1;
            String numb2;

            int count=0;
            while(seriesCount[0] + seriesCount[1] + seriesCount[2] > 1){
                int firstNotEmpty=0;
                int secondNotEmpty=0;
                int firstEmpty=0;

                count = 0;
                for(int i =0;i<3;i++){                    // поиск файлов с сериями и файла без них
                    compare++;
                    if(seriesCount[i]>0){
                        count++;
                        compare++;
                        if(count==1){
                            firstNotEmpty=i;
                        }
                        else if(count==2){
                            secondNotEmpty=i;
                        }
                    }
                    else{
                        firstEmpty=i;
                    }
                }

                int maxSize=0;
                compare++;
                if(seriesCount[firstNotEmpty]>=seriesCount[secondNotEmpty]){          //Сколько серий считывать
                    maxSize = seriesCount[secondNotEmpty];
                }
                else if(seriesCount[firstNotEmpty]<seriesCount[secondNotEmpty]){
                    maxSize = seriesCount[firstNotEmpty];
                }

                while(maxSize!=0){
                    BufferedReader reader1 = new BufferedReader(new FileReader(files[firstNotEmpty]));
                    BufferedReader reader2 = new BufferedReader(new FileReader(files[secondNotEmpty]));

                    while((numb1 = reader1.readLine()) != null){
                        toFile++;
                        FileTemp1.add(numb1);
                    }
                    reader1.close();

                    while((numb2 = reader2.readLine()) != null){
                        toFile++;
                        FileTemp2.add(numb2);
                    }
                    reader2.close();


                    reader1 = new BufferedReader(new FileReader(files[firstNotEmpty]));
                    reader2 = new BufferedReader(new FileReader(files[secondNotEmpty]));

                    while((numb1 = reader1.readLine()) != null) {  //считываем серию из файла
                        toFile++;
                        FileTemp1.remove(0);
                        compare++;
                        if(numb1.equals("---")){
                            seriesCount[firstNotEmpty]--;
                            break;
                        }
                        if(numb1.equals("empty")){
                            continue;
                        }
                        File1.add(Integer.parseInt(numb1));
                    }
                    reader1.close();

                    while((numb2 = reader2.readLine()) != null) {  //считываем серию из файла
                        toFile++;
                        FileTemp2.remove(0);
                        compare++;
                        if(numb2.equals("---")){
                            seriesCount[secondNotEmpty]--;
                            break;
                        }
                        if(numb2.equals("empty")){
                            continue;
                        }
                        File2.add(Integer.parseInt(numb2));
                    }
                    reader2.close();

                    File3.addAll(File1); //Обединяем серии из двух файлов
                    File3.addAll(File2);

                    Collections.sort(File3);

                    BufferedWriter writerEmpty;
                    BufferedWriter writerFirst;
                    BufferedWriter writerSecond;

                    File fileDel = new File(files[firstNotEmpty]);
                    fileDel.delete();
                    fileDel.createNewFile();
                    fileDel = new File(files[secondNotEmpty]);
                    fileDel.delete();
                    fileDel.createNewFile();


                    writerEmpty = new BufferedWriter(new FileWriter(files[firstEmpty], true)); //записываем серию в пустой файл
                    for(int i=0;i<File3.size();i++){
                        writerEmpty.write(File3.get(i) + "\n");
                        toFile++;
                    }
                    writerEmpty.write("---" + "\n");
                    toFile++;

                    seriesCount[firstEmpty]++;

                    writerEmpty.close();

                    writerFirst = new BufferedWriter(new FileWriter(files[firstNotEmpty], true)); //перезаписываем  файл
                    for(int i=0;i<FileTemp1.size();i++){
                        writerFirst.write(FileTemp1.get(i) + "\n");
                        toFile++;
                    }

                    writerFirst.close();

                    writerSecond = new BufferedWriter(new FileWriter(files[secondNotEmpty], true)); //перезаписываем файл
                    for(int i=0;i<FileTemp2.size();i++){
                        writerSecond.write(FileTemp2.get(i) + "\n");
                        toFile++;
                    }

                    writerSecond.close();

                    FileTemp1.clear();
                    FileTemp2.clear();
                    File1.clear();
                    File2.clear();
                    File3.clear();

                    maxSize--;
                }



            }

        }
        catch(FileNotFoundException e){
            System.out.println("File not found.");
        }
        catch (IOException e) {
            System.out.println("I/O error detected.");
        }

    }



    public static void main(String[] args) {
        try {
            String file = "data.txt";
            File data = new File("data.txt");
            BufferedWriter writer = new BufferedWriter(new FileWriter(data));
            Scanner scanner = new Scanner(System.in);
            System.out.println("Введите количество элементов: ");
            int size = scanner.nextInt();

            for (int i = 0; i < size; i++) {
                writer.write(String.valueOf(i) + "\n");
            }
            writer.close();

            double end = 0;
            long start = System.currentTimeMillis();
            fibonacciSort(file, size);
            long finish = System.currentTimeMillis();
            long time = finish - start;
            System.out.println("По возрастанию");
            System.out.println("Time: " + time);
            System.out.println("Compares: " + compare);
            System.out.println("File usages: " + toFile);

            new FileWriter(data, false).close();
            BufferedWriter writer1 = new BufferedWriter(new FileWriter(data));

            int k = size;
            for (int i = 0; i < size; i++) {
                writer1.write(String.valueOf(k) + "\n");
                k--;
            }
            writer1.close();

            time = 0;
            compare = 0;
            toFile = 0;
            start = System.currentTimeMillis();
            fibonacciSort(file, size);
            finish = System.currentTimeMillis();
            time = finish - start;
            System.out.println("По убыванию");
            System.out.println("Time: " + time);
            System.out.println("Compares: " + compare);
            System.out.println("File usages: " + toFile);

            new FileWriter(data, false).close();
            BufferedWriter writer2 = new BufferedWriter(new FileWriter(data));

            for (int i = 0; i < size; i++) {
                writer2.write(String.valueOf(Math.round(Math.random() * 2000) - 1000) + "\n");
            }
            writer2.close();

            time = 0;
            compare = 0;
            toFile = 0;
            start = System.currentTimeMillis();
            fibonacciSort(file, size);
            finish = System.currentTimeMillis();
            time = finish - start;
            System.out.println("Случайный порядок");
            System.out.println("Time: " + time);
            System.out.println("Compares: " + compare);
            System.out.println("File usages: " + toFile);
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
